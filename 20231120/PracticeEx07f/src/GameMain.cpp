#include "WinMain.h"
#include "SceneBase.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
// =====================================================
//	�O���[�o���ϐ�
//	�����̊֐��ŋ��ʂ��Ďg�������ϐ��͂����ɏ���
// =====================================================
namespace
{
	int sceneNum = 0;
	Scene1 scene1;
	Scene2 scene2;
	Scene3 scene3;

	void ChangeScene(SceneBase& now, SceneBase& next)
	{
		now.exit();
		next.init();
	}
	
}

// =====================================================
//		������
//	�Q�[���J�n����ɍŏ���1�񂾂����s�����֐�
//	�ŏ��̒l��ϐ��ɓ��ꂽ���Ƃ��Ɏg��
// =====================================================
void GameInit()
{
	scene1.init();
	scene2.init();
	scene3.init();

}
// =====================================================
//		�X�V
//	�Q�[�����I�������܂Ŏ��s�����֐�
//	1�b�Ԃɖ�60��Ă΂��
//	1�t���[���ōs�������������ɏ���
// =====================================================
void GameUpdate()
{
	switch (sceneNum)
	{
	case 0:
		scene1.init();
		if (scene1.update())
		{
			ChangeScene(scene1, scene2);
			sceneNum += 1;
		}
		break;
	case 1:
		if (scene2.update())
		{
			ChangeScene(scene2, scene3);
			sceneNum += 1;
		}
		break;
	case 2:
		if (scene3.update())
		{
			ChangeScene(scene3, scene1);
			sceneNum = 0;
		}
		break;
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
	switch (sceneNum)
	{
	case 0:
	scene1.render();
		break;
	case 1:
	scene2.render();
		break;
	case 2:
	scene3.render();
		break;
	}
	printfDx("timer %d",scene3.timer);
}
// =====================================================
//		�I��
//	�Q�[�����I������O��1�񂾂����s�����֐�
//	�����Ō�Ɍ�Еt�����s���Ƃ��Ɏg��
// =====================================================
void GameExit()
{

}
