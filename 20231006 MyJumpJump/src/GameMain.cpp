#include "WinMain.h"
#include "Common.h"
#include "Hit.h"
#include "Player.h"

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

//static Box player;
static Box enemy[ENEMY_MAX_NUM];

// =====================================================
//	�O���[�o���ϐ�
//	 ���������P�[�W�ɂ���̂ŁA
//	 �ϐ��̐錾���Ɂustatic�v������
// =====================================================


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
bool isShown[ENEMY_MAX_NUM];


// =====================================================
//		������
// =====================================================
void GameInit()
{
	// �v���C���[
	{
		playerInit();
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

			enemy_wait_frame[i] = (i + 1) * 160+GetRand(30);
			isShown[i] = true;

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
		playerUpdate();
		playerDamageUpdate();

	}

	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (CheckHitBox(getPlayer(), enemy[i]) )
		{
			playerSetDamage();
			//exit(0);
			//isShown[i] = false;
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
					enemy_wait_frame[i] = (i + 1) * 160+GetRand(30);
					isShown[i] = true;
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
	
	/*printfDx("currentenemy : %d\n", enemy_wait_frame[0]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[1]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[2]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[3]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[4]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[5]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[6]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[7]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[8]);
	printfDx("currentenemy : %d\n", enemy_wait_frame[9]);*/

	// �w�i
	{
		DrawBoxAA(0, GROUND_Y, WINDOW_W, WINDOW_H, BLACK, TRUE);
	}

	// �v���C���[
	{
		playerRender();
	}

	// �G
	{
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			if(isShown[i] == true)	drawBox(enemy[i]);
		}
		// Debug
		int font_size = GetFontSize();
		for (int i = 0; i < ENEMY_MAX_NUM; ++i)
		{
			if (enemy_wait_frame[i] > 0)
				continue;
			if (isShown[i] == true)
			{
			DrawFormatStringF(enemy[i].x + enemy[i].w / 2 - 14, enemy[i].y - enemy[i].h / 2 - font_size, BLACK, "%d", i);
			}
		}
	}
}
// =====================================================
//		�I��
// =====================================================
void GameExit()
{


}

//int EnemyWaitReroll(int i)
//{
//	int wait_frame_rand = GetRand(1);
//	switch (wait_frame_rand)
//	{
//	case 0:
//		return enemy_wait_frame[i] = 160;
//		break;
//	case 1:
//		return enemy_wait_frame[i] = 180;
//		break;
//	}
//
//}