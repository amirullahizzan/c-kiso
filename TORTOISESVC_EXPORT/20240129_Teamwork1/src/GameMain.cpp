#include "WinMain.h"
#include "FontManager.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "Player.h"
#include "Enemies.h"
#include "EnemyManager.h"
#include "SceneBase.h"
#include "SceneTitle.h"
#include "SceneCredit.h"
#include "SceneGameMain.h"

// =====================================================
//	�O���[�o���ϐ�
// =====================================================
namespace
{
	// �ϐ�
	SceneBase* scene	= nullptr;		// ���݂̃V�[��
	SCENE	   scene_no = SCENE::TITLE;	// �V�[���ԍ�
	float	   alpha	= 0;			// �t�F�[�h�C��/�t�F�[�h�A�E�g�p�A���t�@�l
	int		   action	= 0;			// 0: �t�F�[�h�C��, 1: �X�V����, 2: �t�F�[�h�A�E�g

	// �֐�
	SceneBase* sceneFactory();			// �V�[���쐬

}

// =====================================================
//		������
// =====================================================
void GameInit()
{
	if (scene != nullptr)
	{
		GameExit();
	}

	scene	 = new SceneTitle();
	scene_no = SCENE::TITLE;
	alpha	 = 255;
	action	 = 0;
}
// =====================================================
//		�X�V
// =====================================================
void GameUpdate()
{
	SCENE tmp_scene_no = scene_no;	// ���݂̃V�[���ԍ�������
	switch (action)
	{
	case 0:
		alpha += (0 - alpha) * 0.075f;
		if (alpha < 10)
		{
			alpha  = 0;
			action = 1;
		}
		break;
	case 1:
		if (scene->update() == true)
		{
			scene_no = scene->getNext();
		}
		if (tmp_scene_no != scene_no)
		{
			// �X�V������ɁAtmp_scene_no�ƌ��݂�scene_no�ƈႤ�ꍇ�́A
			// �V�[���̐؂�ւ�����������
			action = 2;
		}
		break;
	case 2:
		alpha += (255 - alpha) * 0.075f;
		if (alpha > 250)
		{
			alpha  = 255;
			action = 0;
			delete scene;
			scene = nullptr;

			scene = sceneFactory();
		}
		break;
	}
}
// =====================================================
//		�`��
// =====================================================
void GameDraw()
{
	scene->render();

	// FO/FI�p
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)alpha);
	DrawFillBox(0, 0, WINDOW_W, WINDOW_H, BLACK);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
// =====================================================
//		�I��
// =====================================================
void GameExit()
{
	if (scene != nullptr)
	{
		delete scene;
		scene = nullptr;
	}
}

namespace
{
	// �V�[���쐬�p�֐�
	SceneBase* sceneFactory()
	{
		switch (scene_no)
		{
		case TITLE:
			return new SceneTitle();
		case CREDIT:
			return new SceneCredit();
		case GAME_MAIN:
			return new SceneGameMain();
		}

		return nullptr;
	}
}