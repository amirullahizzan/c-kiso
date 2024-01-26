#include "WinMain.h"
#include "Tree.h"
#include "RedBall.h"
#include "Hit.h"

// =====================================================
//	�O���[�o���ϐ�
//	�����̊֐��ŋ��ʂ��Ďg�������ϐ��͂����ɏ���
// =====================================================
namespace
{
	const int OBJ_NUM = 15;
	int obj_count = 0;

	Tree* tree = nullptr;
	RedBall* redball[OBJ_NUM] = {};
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
	int randomizer = GetRand(3);
	switch (randomizer)
	{
	case 0:
		redball = new RedBall(mousePos);
		break;
	case 1:
		redball = new RedBall(mousePos);
		break;
	case 2:
		redball = new RedBall(mousePos);
		break;
	}
}

void GameUpdate()
{
	tree->Update();
	if (obj_count >= OBJ_NUM) return;

	if(IsMouseOn(MOUSE_INPUT_LEFT))
	{
		Pos mousePos = { static_cast<float>(GetMouseX()) ,static_cast<float>(GetMouseY() )};
	}

	if (redball) 
	{ redball->Update(); }
	
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
	if (redball) 
	{ redball->Draw(); }
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

