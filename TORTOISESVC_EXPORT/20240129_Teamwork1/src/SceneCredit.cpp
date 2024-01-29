#include "WinMain.h"
#include "FontManager.h"
#include "AnimationImage.h"
#include "SceneBase.h"
#include "SceneCredit.h"
#include <fstream>
// =====================================================
//	クレジットシーンクラス（ソースファイル）
//	 すべての名前が流れるか、スペースキーでタイトルへ
// =====================================================
// コンストラクタ
SceneCredit::SceneCredit() :
	SceneBase("クレジット")
{
	font_ = new FontManager();
	font_->create(FONT::PIXEL_M);

	messages_.emplace_back(std::string("THANK YOU FOR PLAYING."));
	// ファイルから名前の読み込み
	std::ifstream file("data/txt/PG_members.txt");
	if (file.is_open())
	{
		while (true)
		{
			std::string line;
			std::getline(file, line);
			if (file.eof())
				break;
			messages_.emplace_back(line);
		}
		file.close();
	}
	now_message_index_ = 0;

	messages_.emplace_back(std::string("SPECIAL THANKS"));
	messages_.emplace_back(std::string("金丸 先生"));
	messages_.emplace_back(std::string("王 先生"));

}

// デストラクタ
SceneCredit::~SceneCredit()
{
	if (font_ != nullptr)
	{
		delete font_;
		font_ = nullptr;
	}

}

// 更新処理
//	wait_frame_が1800(30*60)を超えたらtrueを返す
bool SceneCredit::update()
{
	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		return true;
	}

	switch (action_)
	{
	case 0:
		alpha_ += (255 - alpha_) * ALPHA_SPEED;
		if (alpha_ > 250)
		{
			alpha_ = 255;
			action_ = 1;
		}
		break;
	case 1:
		disp_frame_++;
		if (disp_frame_ >= DISP_FRAME)
		{
			disp_frame_ = 0;
			action_		= 2;
		}
		break;
	case 2:
		alpha_ += (0 - alpha_) * ALPHA_SPEED;
		if (alpha_ < 5)
		{
			alpha_  = 0;
			action_ = 0;
			++now_message_index_;
			if (now_message_index_ >= messages_.size())
			{
				now_message_index_ = -1;
			}
		}
		break;
	}

	// 全ての名前を出し終わったら-1にする
	return now_message_index_ == -1;
}

// 描画処理
void SceneCredit::render()
{
	__super::render();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)alpha_);
	if (now_message_index_ != -1)
	{
		DrawCenterString(WINDOW_H / 2 - 32, messages_[now_message_index_].c_str(), 64, WHITE);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
