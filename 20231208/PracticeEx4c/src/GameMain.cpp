#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "Actor.h"
#include "CircleBase.h"
#include "CircleScaling.h"
#include "CircleMoving.h"
// =====================================================
//	�O���[�o���ϐ�
// =====================================================
namespace
{
	// ----------------------------------
	//	 �萔
	// ----------------------------------
	const char* ACTOR_IMAGES[] =	// �摜�t�@�C��
	{
		 "data/pipo-charachip019.png"
		,"data/pipo-charachip019a.png"
		,"data/pipo-charachip019b.png"
		,"data/pipo-charachip019c.png"
		,"data/pipo-charachip019d.png"
		,"data/pipo-charachip019e.png"
	};
	const int   ACTOR_IMAGES_SIZE = SIZE(ACTOR_IMAGES);	// �摜�t�@�C���̃T�C�Y
	const int	ACTOR_NUM		  = 4;					// ��ʏ�̃L�����N�^�[�̍ő吔
	const float ACTOR_MOVE_SPEED  = 3;					// �L�����N�^�[�̈ړ����x

	// ----------------------------------
	//	 �ϐ�
	// ----------------------------------
	Actor  actors[ACTOR_NUM];			// ��ʏ�̃L�����N�^�[
	Actor* target_actor	   = nullptr;	// �^�[�Q�b�g�̃L�����N�^�[�̃A�h���X�i�[�p
	int	   now_actor_index = 0;			// ���݂̃^�[�Q�b�g�L�����N�^�[�̔z��̔ԍ�

	CircleScaling target_circle;		// �^�[�Q�e�B���O�̊g�k����~
	CircleMoving moving_circle;		// �^�[�Q�e�B���O�̊g�k����~

	// ----------------------------------
	//	 �֐�
	// ----------------------------------
	void targetActorUpdate();	// �^�[�Q�b�g�݂̂̏����F�X�V
	void actorsInit();			// ��ʏ�̃L�����N�^�[�̈ꊇ�����F������
	void actorsUpdate();		// ��ʏ�̃L�����N�^�[�̈ꊇ�����F�X�V
	void actorsRender();		// ��ʏ�̃L�����N�^�[�̈ꊇ�����F�`��
	void actorsExit();			// ��ʏ�̃L�����N�^�[�̈ꊇ�����F�I��
}

// =====================================================
//		������
// =====================================================
void GameInit()
{
	actorsInit();
	target_actor = &actors[now_actor_index];
}

// =====================================================
//		�X�V
// =====================================================
void GameUpdate()
{
	actorsUpdate();
	targetActorUpdate();


	target_circle.update();
	moving_circle.update();
	
	moving_circle.setTarget(target_actor);
	target_circle.setTarget(target_actor);
	target_actor = &actors[now_actor_index];

	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		now_actor_index = GetRand(3);
	}

	if (IsKeyOn(KEY_INPUT_A))
	{
		now_actor_index+=1;
		if (now_actor_index >= ACTOR_NUM)
		{ now_actor_index = 0; }
	}

}

// =====================================================
//		�`��
// =====================================================
void GameDraw()
{
	printfDx("distance selector and actor : %f\n\n", getDist(target_actor->getPos(), moving_circle.getPos()));
	printfDx("distance selector and actor : %d\n\n", now_actor_index);
	target_circle.render();
	moving_circle.render();
	actorsRender();

}

// =====================================================
//		�I��
// =====================================================
void GameExit()
{
	actorsExit();

}

namespace
{
	// *************************************************************
	//	�ҏW�֎~
	// *************************************************************
	// �^�[�Q�b�g�݂̂̏����F�X�V
	void targetActorUpdate()
	{
		if (target_actor == nullptr)
		{
			return;
		}

		target_actor->setTarget();

		Pos now_pos = target_actor->getPos();
		if (IsKeyRepeat(KEY_INPUT_RIGHT))
		{
			now_pos.x += ACTOR_MOVE_SPEED;
		}
		else if (IsKeyRepeat(KEY_INPUT_LEFT))
		{
			now_pos.x -= ACTOR_MOVE_SPEED;
		}
		else if (IsKeyRepeat(KEY_INPUT_UP))
		{
			now_pos.y -= ACTOR_MOVE_SPEED;
		}
		else if (IsKeyRepeat(KEY_INPUT_DOWN))
		{
			now_pos.y += ACTOR_MOVE_SPEED;
		}

		// �͈͊O�̃`�F�b�N
		now_pos.x = max(now_pos.x, IMG_SIZE / 2);
		now_pos.y = max(now_pos.y, IMG_SIZE / 2);
		now_pos.x = min(now_pos.x, WINDOW_W - IMG_SIZE / 2);
		now_pos.y = min(now_pos.y, WINDOW_H - IMG_SIZE / 2);

		target_actor->setPos(now_pos);
	}
	// ��ʏ�̃L�����N�^�[�̈ꊇ�����F������
	void actorsInit()
	{
		for (int i = 0; i < ACTOR_NUM; ++i)
		{
			int x_space = i % (ACTOR_NUM / 2);
			int y_space = i / (ACTOR_NUM / 2);
			float start_x = (float)(0 + (WINDOW_W / 4) + WINDOW_W / 2 * x_space);
			float start_y = (float)(0 + (WINDOW_H / 4) + WINDOW_H / 2 * y_space);
			actors[i].init(ACTOR_IMAGES[GetRand(ACTOR_IMAGES_SIZE - 1)]);
			actors[i].setPos({ start_x, start_y });
		}
	}
	// ��ʏ�̃L�����N�^�[�̈ꊇ�����F�X�V
	void actorsUpdate()
	{
		for (int i = 0; i < ACTOR_NUM; ++i)
		{
			actors[i].update();
		}
	}
	// ��ʏ�̃L�����N�^�[�̈ꊇ�����F�`��
	void actorsRender()
	{
		for (int i = 0; i < ACTOR_NUM; ++i)
		{
			actors[i].render();
		}
	}
	// ��ʏ�̃L�����N�^�[�̈ꊇ�����F�I��
	void actorsExit()
	{
		for (int i = 0; i < ACTOR_NUM; ++i)
		{
			actors[i].exit();
		}
	}
	// *************************************************************
	//	�ҏW�֎~
	// *************************************************************
}