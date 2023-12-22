#include "WinMain.h"

// =====================================================
//	�O���[�o���ϐ�
//	�����̊֐��ŋ��ʂ��Ďg�������ϐ��͂����ɏ���
// =====================================================
namespace
{
	class Circle
	{

	public:
		int circle_spawntimer = 200;

		static int circle_count;
		static int circle_timer;
		static const int circle_CD = 60;

		Circle()
		{
			circle_count++;
			InitRandomForce();
		}
		~Circle()
		{
			circle_count--;
		}

		void Update()
		{
			if (pos_y >= WINDOW_H - radius)
			{
				pos_y = WINDOW_H - radius;
				return;
			}
			pos_y -= force_y;
			pos_x -= force_x;
			force_y -= 0.5f;
		}

		void Render()
		{
			DrawCircleAA(pos_x, pos_y, radius, 64, GetColor(255, 255, 255), 1);
		}

	private :

		float pos_x = WINDOW_W *0.5f;
		float pos_y = WINDOW_H + 0.0f;
		float force_x = 10.0f;
		float force_y = 10.0f;
		float radius = 35;

		float gravity = 2.0f;

		void InitRandomForce()
		{
			pos_x = WINDOW_W * 0.5f;
			pos_y = WINDOW_H * 0.5f;

			radius = GetRand(35) + 5.0f;

			force_x = GetRand(-20) + 10.0f;
			force_y = GetRand(10) + 1.0f;
		}

	};

	Circle* circle_ptr = nullptr;
	int Circle::circle_count = 0;
	int Circle::circle_spawntimer = 0;

	int* circles = nullptr;
	int* tempcircles = nullptr;
	int size = 0;
}

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

	circles = new int[size + 1];

	

	if (Circle::circle_timer <= 0)
	{
		for (int i = 0; i < size; i++)
		{
			size++;
			tempcircles = new int[size];
			// change to NEW CIRCLES[]
			tempcircles[i] = circles[i];
			circles[i] =
		}

		/*delete circle_ptr;
		circle_ptr = nullptr;
		circle_ptr = new Circle;*/
		Circle::circle_spawntimer = Circle::circle_CD;
	}

	for (int i = 0; i < size; i++)
	{
	circles[i]->circle_timer--;
	circle_ptr->Update();
	if (circles[i]->)
	{
	delete circles[i];
	}
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
	circle_ptr->Render();
	DrawFormatString(20,20, WHITE," Circles : %d", Circle::circle_count);
}
// =====================================================
//		�I��
//	�Q�[�����I������O��1�񂾂����s�����֐�
//	�����Ō�Ɍ�Еt�����s���Ƃ��Ɏg��
// =====================================================
void GameExit()
{

}
