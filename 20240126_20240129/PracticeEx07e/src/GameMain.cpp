#include "WinMain.h"
#include "Tree.h"
#include "RedBall.h"
#include "SnowMan.h"
#include "SnowFlake.h"
#include "Hit.h"

// =====================================================
//	�O���[�o���ϐ�
//	�����̊֐��ŋ��ʂ��Ďg�������ϐ��͂����ɏ���
// =====================================================
namespace
{
	const int OBJ_NUM = 15;
	int obj_count = 0;
	
	enum TreeDecorationEnum
	{
		RedBallE = 0, 
		SnowFlakeE = 1, 
		SnowmanE = 2
	};
	int obj_type = RedBallE;


	Tree* tree = nullptr;
	BaseObj* baseobj[OBJ_NUM] = {};
	//RedBall* redball = {};
}

// =====================================================
//		������
//	�Q�[���J�n����ɍŏ���1�񂾂����s�����֐�
//	�ŏ��̒l��ϐ��ɓ��ꂽ���Ƃ��Ɏg��
// =====================================================
void GameInit()
{
	tree = new Tree();

}
// =====================================================
//		�X�V
//	�Q�[�����I�������܂Ŏ��s�����֐�
//	1�b�Ԃɖ�60��Ă΂��
//	1�t���[���ōs�������������ɏ���
// =====================================================

void SpawnRandomizeDecoration(Pos mousePos)
{
	int randomizeType = GetRand(2);
	obj_type = randomizeType;
	switch (obj_type)
	{
	case RedBallE:
		for (int i = 0; i < OBJ_NUM; i++)
		{
			if (baseobj[i]) continue;
			baseobj[i] = new RedBall(mousePos);
			break;
		}
		break;

	case SnowFlakeE:
		for (int i = 0; i < OBJ_NUM; i++)
		{
			if (baseobj[i]) continue;
			baseobj[i] = new SnowFlake(mousePos);
			break;
		}

		break;

	case SnowmanE:
		for (int i = 0; i < OBJ_NUM; i++)
		{
			if (baseobj[i]) continue;
			baseobj[i] = new SnowMan(mousePos);
			break;
		}

		break;

	default:
		break;
	}


}

void SpawnObj(BaseObj* objtype, Pos mousePos)
{

}

void GameUpdate()
{
	tree->Update();
	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		for (int i = 0; i < OBJ_NUM; i++)
		{
			delete baseobj[i];
			baseobj[i] = nullptr;
		}
	}


	for (int i = 0 ; i < OBJ_NUM;i++)
	{
	
	if (baseobj[i])
	{
		baseobj[i]->Update();
	}

	}

	if (obj_count >= OBJ_NUM) return;
	
	if (IsMouseOn(MOUSE_INPUT_LEFT))
	{
		obj_count++;
		Pos mousePos = { static_cast<float>(GetMouseX()) ,static_cast<float>(GetMouseY()) };
		SpawnRandomizeDecoration(mousePos);
	}
}
// =====================================================
//		�`��
//	�Q�[�����I�������܂Ŏ��s�����֐�
//	1�b�Ԃɖ�60��Ă΂��
//	GameUpdate�֐������s���ꂽ��Ɏ��s�����֐�
// =====================================================
void GameDraw()
{
	tree->Draw();
	for (int i = 0 ; i < OBJ_NUM; i++)
	{
		if (baseobj[i])
		{
		baseobj[i]->Draw();
		}
	}

	DrawFormatString(0,0,WHITE,"%d / 15 ", obj_count);
}
// =====================================================
//		�I��
//	�Q�[�����I������O��1�񂾂����s�����֐�
//	�����Ō�Ɍ�Еt�����s���Ƃ��Ɏg��
// =====================================================
void GameExit()
{
	if (tree != nullptr)
	{
		delete tree;
		tree = nullptr;
	}
}

