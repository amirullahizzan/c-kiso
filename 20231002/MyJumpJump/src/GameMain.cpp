#include "WinMain.h"
#include "Common.h"
#include "Hit.h"

// �����K��
//	��{�I�ɂ��ꂼ��̖��̂́A�����Ȃ��Ă������̂�
//	�Ӗ��̂���A�܂����ꂼ��̎g�p�p�r��\���P��ɂ���
//	�֎~�����F�ua�v�uspeed�v�Ȃǂ̒N�̂��̂���ꂪ������Ȃ����̂ɂ��邱��
//	�ϐ�(����)	�c dog_and_cat
//	����֐�		�c dogAndCat
//	�\����		�c DogAndCat
//	�萔(�񋓑�)	�c DOG_AND_CAT

// =====================================================
//	�萔
// =====================================================
const float GROUND_Y = (float)WINDOW_H - 60;	// �n�ʂ̍��W
const int	ENEMY_MAX_NUM = 10;						// �G�̐�
const int	ENEMY_SPEED = 1;						// �G�̈ړ����x

// =====================================================
//	�񋓑�
// =====================================================
enum JUMP_STATE
{
	NONE = 0,
	STEP1, STEP2,
};

static Box player;
static Box enemy[ENEMY_MAX_NUM];

// =====================================================
//	�O���[�o���ϐ�
//	 ���������P�[�W�ɂ���̂ŁA
//	 �ϐ��̐錾���Ɂustatic�v������
// =====================================================
// -----------------------------------------------------
//	�v���C���[�p�ϐ�
// -----------------------------------------------------
//static float		player_x	 = 0;	// X���W
//static float		player_y	 = 0;	// Y���W
//static float		player_w	 = 0;	// ��
//static float		player_h	 = 0;	// ����
//static unsigned int player_color = 0;	// �F
// �W�����v�����p
static int	 player_jump_state = JUMP_STATE::NONE;	 // ���
static float player_jump_power = 0;				 // �W�����v��
const static float PLAYER_JUMP_POWER_STEP1 = 20.0f;				 // �W�����v��
const static float PLAYER_JUMP_POWER_STEP2 = 25.0f;				 // �W�����v��
// �_���[�W�����p
//	�_���[�W���͓_�ł�����
int player_damage_frame = 0;	// �_���[�W����
const  int PLAYER_DAMAGE_FRAME_MAX = 60;	// �_���[�W����
static bool isImmune = false;

int playerhp = 100;

// -----------------------------------------------------
//	�G�p�ϐ�
// -----------------------------------------------------
//static float		enemy_x[ENEMY_MAX_NUM]	   = { 0 };	// X���W
//static float		enemy_y[ENEMY_MAX_NUM]	   = { 0 };	// Y���W
//static float		enemy_w[ENEMY_MAX_NUM]	   = { 0 };	// ��
//static float		enemy_h[ENEMY_MAX_NUM]	   = { 0 };	// ����
//static unsigned int enemy_color[ENEMY_MAX_NUM] = { 0 };	// �F
// �o�������p
static int enemy_wait_frame[ENEMY_MAX_NUM] = { 0 };


// =====================================================
//		������
// =====================================================
void GameInit()
{
	// �v���C���[
	{
		player.w = 60;
		player.h = 60;
		player.x = 120;
		player.y = GROUND_Y - player.h / 2;
		player.color = BLUE;
	}
	// �G
	{
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			enemy[i].color = RED;
			// �������W�̐ݒ�
			//	�����������_���Ȃ̂ŁA�����_���ɐݒ肷��
			//	���������܂��Ă���AY���W�����܂�̂Ő�ɍ��������߂�
			enemy[i].w = 20;
			enemy[i].h = (float)(100 + GetRand(5) * 10);
			enemy[i].x = WINDOW_W + enemy[i].w / 2;		// ��ʉE�[�O�ɒu���i�E���獶�Ɉړ����邽�߁j
			enemy[i].y = GROUND_Y - enemy[i].h / 2;
			// �ҋ@���Ԃ̐ݒ�

			enemy_wait_frame[i] = (i + 1) * 160;
		}
	}

}
// =====================================================
//		�X�V
// =====================================================
int currentenemyIndex = 0;
int nextEnemy = 0;
void GameUpdate()
{
	
	// �v���C���[
	{
		if (player_jump_state != JUMP_STATE::NONE)
		{
			//Gravity when JUMP_STATE
			player.y		  -= player_jump_power;
			player_jump_power -= 1;
			if (player.y > (GROUND_Y - player.h / 2))
			{
				// ���ɐڒn������ēx�W�����v�ł���悤�ɂ���
				player.y		  = GROUND_Y - player.h / 2;
				player_jump_power = 0;
				player_jump_state = JUMP_STATE::NONE;
			

			}
		}

		if (IsKeyOn(KEY_INPUT_SPACE))
		{
			switch (player_jump_state)
			{
			case NONE:
				player_jump_state = JUMP_STATE::STEP1;
				player_jump_power = PLAYER_JUMP_POWER_STEP1;
				break;
			case STEP1:
				player_jump_state = JUMP_STATE::STEP2;
				player_jump_power = PLAYER_JUMP_POWER_STEP2;
				break;
			case STEP2:
				break;
			}
		}
		// ------------------------------------------
		// �_���[�W����
		//	�G�Ƃ̓����蔻��̏���������������A
		//	�L�[���͂ł͂Ȃ��A�G�Ɠ��������Ƃ��Ƀ_���[�W�������s��
		//	���݂̓f�o�b�O�̂��߁AA�L�[����������f�o�b�O�����ɂȂ�悤�ɂ���
		if (IsKeyOn(KEY_INPUT_A))
		{
			// �_���[�W�J�n
			SetPlayerFrameMax();
		}
		// �_���[�W������
		if (player_damage_frame > 0)
		{
			--player_damage_frame;
		}
		else
		{
			// �_���[�W�I��
			player_damage_frame = 0;
		}
		// ------------------------------------------

		for (int i = 0;i < ENEMY_MAX_NUM; i++)
		{
		if (CheckHitBox(player,enemy[i]) && isImmune == false)
		{
			SetPlayerFrameMax();
			playerhp -= 10;
			isImmune = true;
		}
		}

		if (player_damage_frame <= 0)
		{
			isImmune = false;
		}
	}

	// �G
	{
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			if (enemy_wait_frame[i] <= 0)
			{
				enemy[i].x -= ENEMY_SPEED;
				// �ړ���
				enemy_wait_frame[i] = 0;
				if (enemy[i].x < 0 - enemy[i].w / 2 && enemy_wait_frame[ENEMY_MAX_NUM-1] == 0)
				{
					// ���W�Ƒҋ@���Ԃ̍Đݒ�
					enemy[i].h			= (float)(50 + GetRand(5) * 10);
					enemy[i].x			= WINDOW_W + enemy[i].w / 2;
					enemy[i].y			= GROUND_Y - enemy[i].h / 2;
					enemy_wait_frame[i] = (i + 1) * 160;
				}
			}
			else
			{
				// �ҋ@��
				--enemy_wait_frame[i];
			}
		}
	}

}
// =====================================================
//		�`��
// =====================================================

void GameDraw()
{
	printfDx("player jump power : %f\n", player_jump_power);
	printfDx("player jump : %d\n", player_jump_state);
	printfDx("player hp : %d\n", playerhp);
	printfDx("currentenemy : %d\n", enemy_wait_frame[0]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[1]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[2]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[3]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[4]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[5]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[6]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[7]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[8]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[9]);

	// �w�i
	{
		DrawBoxAA(0, GROUND_Y, WINDOW_W, WINDOW_H, BLACK, TRUE);
	}

	// �v���C���[
	{
		if (player_damage_frame % 3 == 0)
		{
			// �_���[�W���iplayer_damage_frame��3�t���[����1��j�̂Ƃ��A
			// �܂��́A�_���[�W����Ȃ��iplayer_damage_frame��0�j�Ƃ��A
			// �v���C���[��`�悷��
			drawBox(player);
		}
		
	}

	// �G
	{
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			drawBox(enemy[i]);
		}
		// Debug
		int font_size = GetFontSize();
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			if (enemy_wait_frame[i] > 0)
				continue;

			DrawFormatStringF(enemy[i].x + enemy[i].w / 2 - 14, enemy[i].y - enemy[i].h / 2 - font_size, BLACK, "%d", i);
		}
	}
}
// =====================================================
//		�I��
// =====================================================
void GameExit()
{


}

int EnemyWaitReroll(int i)
{
	int wait_frame_rand = GetRand(1);
	switch (wait_frame_rand)
	{
	case 0:
		return enemy_wait_frame[i] = 160;
		break;
	case 1:
		return enemy_wait_frame[i] = 180;
		break;
	}

}