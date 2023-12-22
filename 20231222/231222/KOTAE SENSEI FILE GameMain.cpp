#include "WinMain.h"

// =====================================================
//	�O���[�o���ϐ�
//	�����̊֐��ŋ��ʂ��Ďg�������ϐ��͂����ɏ���
// =====================================================
namespace
{
	class Circle
	{
	private:
		Color color_;
		Pos   pos_;
		float r_		 = 0;
		float vel_		 = 0;
		float acc_		 = 0;
		float move_x_	 = 0;
		int	  frame_	 = 0;
		bool  is_remove_ = false;

	public:
		Circle() {}
		virtual ~Circle() {}

		void init();
		void update();
		void render() const;

		bool isRemove() const
		{
			return is_remove_;
		}
	};
	void Circle::init()
	{
		r_		   = (float)(15 + (GetRand(5) * 5));
		pos_	   = { WINDOW_W / 2, WINDOW_H / 2 };
		frame_	   = 60 * (1 + GetRand(5));
		is_remove_ = false;
		color_	   = { (unsigned int)(127 + GetRand(128)), (unsigned int)(GetRand(128)), (unsigned int)(GetRand(255)) };
		vel_	   = (float)(10 + GetRand(10)) * -1;
		acc_	   = 1;
		move_x_	   = (float)(1 + GetRand(10));
		move_x_	   = (GetRand(100) % 2 == 0) ? move_x_ * -1 : move_x_;
	}
	void Circle::update()
	{
		if (is_remove_)
			return;

		--frame_;
		if (frame_ < 0)
		{
			is_remove_ = true;
		}
		vel_ += acc_;
		pos_.y += vel_;
		pos_.x += move_x_;

		if (pos_.y >= WINDOW_H - r_)
		{
			pos_.y	= WINDOW_H - r_;
			acc_	= 0;
			move_x_ = 0;
		}
	}
	void Circle::render() const
	{
		if (is_remove_)
			return;
		DrawCircleAA(pos_.x, pos_.y, r_, 64, color_.get(), TRUE);
	}

	Circle* circles	  = nullptr;
	int		size	  = 0;
	int		add_frame = 0;

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
	++add_frame;
	if (add_frame > 60)
	{
		add_frame = 0;
		// �~�̒ǉ��i�z��̉��Z�j
		if (size == 0)
		{
			++size;
			circles = new Circle[size];
			circles[size - 1].init();
		}
		else
		{
			Circle* tmp_circles = new Circle[size];
			for (int i = 0; i < size; ++i)
			{
				tmp_circles[i] = circles[i];
			}
			delete[] circles;
			circles = nullptr;
			circles = new Circle[size + 1];
			for (int i = 0; i < size; ++i)
			{
				circles[i] = tmp_circles[i];
			}
			circles[size] = Circle();
			++size;
			delete[] tmp_circles;
			tmp_circles = nullptr;

			circles[size - 1].init();
		}
	}

	for (int i = 0; i < size; ++i)
	{
		circles[i].update();
	}

	// �s�v�ȉ~�̍폜�i�z��̌����j
	int remove_count = 0;
	for (int i = 0; i < size; ++i)
	{
		if (circles[i].isRemove() == false)
			continue;
		remove_count++;
	}
	if (remove_count > 0)
	{
		int new_size = size - remove_count;
		Circle* tmp_circle = new Circle[new_size];

		for (int i = 0, j = 0; i < size; ++i)
		{
			if (circles[i].isRemove() != false)
				continue;
			tmp_circle[j] = circles[i];
			++j;
			if (j >= new_size)
			{
				break;
			}
		}
		delete[] circles;
		circles = nullptr;
		circles = new Circle[new_size];
		for (int i = 0; i < new_size; ++i)
		{
			circles[i] = tmp_circle[i];
		}
		size = new_size;
		delete[] tmp_circle;
		tmp_circle = nullptr;
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
	for (int i = 0; i < size; ++i)
	{
		circles[i].render();
	}

	DrawFormatString(5, 5, WHITE, "���݂̉~�̐�: %2d", size);
}
// =====================================================
//		�I��
//	�Q�[�����I������O��1�񂾂����s�����֐�
//	�����Ō�Ɍ�Еt�����s���Ƃ��Ɏg��
// =====================================================
void GameExit()
{
	if (circles != nullptr)
	{
		delete[] circles;
		circles = nullptr;
	}


}
