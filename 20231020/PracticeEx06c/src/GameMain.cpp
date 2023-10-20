#include "WinMain.h"
#include "Circle.h"

// =====================================================
//	�O���[�o���ϐ�
//	�����̊֐��ŋ��ʂ��Ďg�������ϐ��͂����ɏ���
// =====================================================
const int CIRCLE_NUM = 10;
Circle circle[CIRCLE_NUM];

// =====================================================
//		������
//	�Q�[���J�n����ɍŏ���1�񂾂����s�����֐�
//	�ŏ��̒l��ϐ��ɓ��ꂽ���Ƃ��Ɏg��
// =====================================================
void GameInit()
{

	

}
// =====================================================
//		�X�V
//	�Q�[�����I�������܂Ŏ��s�����֐�
//	1�b�Ԃɖ�60��Ă΂��
//	1�t���[���ōs�������������ɏ���
// =====================================================
void GameUpdate()
{

	for (int i = 0; i < CIRCLE_NUM; i++)
	{
		
		if (IsKeyOn(KEY_INPUT_SPACE))
		{
			if (circle[i].isSpawn())
			{
				continue;
			}
			circle[i].spawn();
			break;
		}
	}
	for (int i = 0; i < CIRCLE_NUM; i++)
	{
		circle[i].update();
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
	for (int i = 0; i < CIRCLE_NUM; i++)
	{
		circle[i].render();
	}

	//clsDx();
	circle[0].debuglog();
	

}
// =====================================================
//		�I��
//	�Q�[�����I������O��1�񂾂����s�����֐�
//	�����Ō�Ɍ�Еt�����s���Ƃ��Ɏg��
// =====================================================
void GameExit()
{


}