#include "Winmain.h"
#include "Common.h"
#include "Player.h"
#include "Hit.h"


const float GROUND_Y = (float)WINDOW_H - 60;	// �n�ʂ̍��W
const int	ENEMY_MAX_NUM = 10;						// �G�̐�

static Box player;

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
static int player_damage_frame = 0;	// �_���[�W����
const static int PLAYER_DAMAGE_FRAME_MAX = 60;	// �_���[�W����

void playerInit()
{
	player.w = 60;
	player.h = 60;
	player.x = 120;
	player.y = GROUND_Y - player.h / 2;
	player.color = BLUE;
}


void playerRender()
{
if (player_damage_frame % 3 == 0)
{
	drawBox(player);
}
}

void playerUpdate()
{
	if (player_jump_state != JUMP_STATE::NONE)
	{
		//Gravity when JUMP_STATE
		player.y -= player_jump_power;
		player_jump_power -= 1;
		if (player.y > (GROUND_Y - player.h / 2))
		{
			// ���ɐڒn������ēx�W�����v�ł���悤�ɂ���
			player.y = GROUND_Y - player.h / 2;
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
		playerSetDamage();
	}
	// ------------------------------------------
	
	
}

void playerSetDamage()
{
	player_damage_frame = PLAYER_DAMAGE_FRAME_MAX;
}


void playerDamageUpdate()
{
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
}

Box getPlayer()
{
	return player;
}