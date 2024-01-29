#include "WinMain.h"
#include "SceneBase.h"
#include "SceneTitle.h"
#include <fstream>
// =====================================================
//	�^�C�g���V�[���N���X�i�\�[�X�t�@�C���j
//	 Enter�L�[�����Ŏ��̃V�[���֐؂�ւ���
// =====================================================
// �R���X�g���N�^
SceneTitle::SceneTitle() :
	SceneBase("�^�C�g��")
{
	select_no_ = 0;

	select_left_.y = (float)(MENU_START_Y + select_no_ * (MENU_FONT_SIZE + 10));
	select_left_.y += 15;
	select_left_.x = 390;

	select_right_.y = select_left_.y;
	select_right_.x = select_left_.x + 175;

	select_count_ = 0;

	is_score_find_ = false;
	int score = getScoreTxt();
	is_score_find_ = (score != -1);
	select_max_ = (is_score_find_ == true) ? MENU_NUM : 1;
}

// �f�X�g���N�^
SceneTitle::~SceneTitle()
{

}

// �X�V����
//	Enter�L�[�����Ŏ��̃V�[���ɂ��邽�߂�true��Ԃ�
bool SceneTitle::update()
{
	if (IsKeyOn(KEY_INPUT_RETURN))
	{
		return true;
	}
	++select_count_;
	if (IsKeyOn(KEY_INPUT_DOWN))
	{
		++select_no_;
		//select_no_ = max(select_no_, MENU_NUM);
		if (select_no_ >= select_max_)
		{
			select_no_ = 0;
		}
		select_count_ = 0;
	}
	if (IsKeyOn(KEY_INPUT_UP))
	{
		--select_no_;
		//select_no_ = min(select_no_, 0);
		if (select_no_ < 0)
		{
			select_no_ = select_max_ - 1;
		}
		select_count_ = 0;
	}
	select_left_.y  = (float)(MENU_START_Y + select_no_ * (MENU_FONT_SIZE + 10));
	select_left_.y += 15;
	select_right_.y = select_left_.y;

	return false;
}

// �`�揈��
void SceneTitle::render()
{
	__super::render();

	DrawCenterString(100, "Battle Fighters", 32, SKYBLUE);

	for (int i = 0; i < select_max_; ++i)
	{
		DrawCenterString(
			MENU_START_Y + i * (MENU_FONT_SIZE + 10),
			MENU_STR[i],
			MENU_FONT_SIZE, WHITE
		);
	}
	float floating = (float)PI * 2 / 60 * select_count_;
	DrawCircleAA(select_right_.x + cosf(floating) * -5.0f,
				 select_right_.y,
				 12, 64, WHITE, FALSE);
	DrawCircleAA(select_left_.x  + cosf(floating) * 5.0f,
				 select_left_.y,
				 12, 64, WHITE, FALSE);
}

// ���̃V�[���ԍ���Ԃ�
//	�J�[�\���ʒu�ɂ���āA���̃V�[���ԍ���ς���
SCENE SceneTitle::getNext() const
{
	switch (select_no_)
	{
	case 0:
		return SCENE::GAME_MAIN;
	case 1:
		return SCENE::CREDIT;
	}

	// ����ȊO���Ԃ邱�Ƃ͂Ȃ�
	return SCENE::TITLE;
}
// �n�C�X�R�A�擾����
int SceneTitle::getScoreTxt()
{
	int tmp_score = -1;

	std::ifstream file(SCORE_FILE_NAME);
	if (file.is_open() == true)
	{
		file >> tmp_score;
		file.close();
	}
	return tmp_score;
}
