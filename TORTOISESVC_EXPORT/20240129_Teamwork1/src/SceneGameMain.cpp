#include "WinMain.h"
#include "FontManager.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "Player.h"
#include "Enemies.h"
#include "EnemyManager.h"
#include "SceneBase.h"
#include "SceneGameMain.h"
#include <fstream>
// =====================================================
//	ゲームメインシーンクラス（ソースファイル）
//	 プレイヤーのHPがなくなるまで耐える
// =====================================================
// コンストラクタ
SceneGameMain::SceneGameMain() :
	SceneBase("メイン")
{
	player_	   = new Player();
	enemy_mgr_ = new EnemyManager();
	enemy_mgr_->setTarget(player_);

	// ゲームオーバー処理
	is_game_end_		 = false;
	flash_count_		 = 0;
	is_end_message_disp_ = false;

	// UI初期化処理
	font_ = new FontManager();
	font_->create(FONT::PIXEL_M);
	player_hp_anim_.load("data/effect/pipo-hikarimono008.png");
	player_hp_anim_.attach({ { 0, 1, 2, 1 }, 30, true });

	high_score_ = getScoreTxt();
}

// デストラクタ
SceneGameMain::~SceneGameMain()
{
	if (player_ != nullptr)
	{
		delete player_;
		player_ = nullptr;
	}
	if (enemy_mgr_ != nullptr)
	{
		delete enemy_mgr_;
		enemy_mgr_ = nullptr;
	}
	if (font_ != nullptr)
	{
		delete font_;
		font_ = nullptr;
	}
}

// 更新処理
//	プレイヤーのHPが0になったらゲームオーバーシーンへ
bool SceneGameMain::update()
{
	assert(player_ != nullptr);

	if (is_game_end_ == true)
	{
		return updateGameEnd();
	}

	player_->update();
	enemy_mgr_->update();

	updateUI();

	// ゲームの終了判定
	if (player_->isDead() == true)
	{
		is_game_end_ = true;
		updateScoreTxt();
	}
	return false;
}

//	ゲーム本編の描画
void SceneGameMain::render()
{
	__super::render();

	player_->render();
	enemy_mgr_->render();

	// UIが最前面に描画されるようにrenderUI関数を最後に呼び出す
	renderUI();

	renderGameEnd();
}

// 次シーンの取得
SCENE SceneGameMain::getNext() const
{
	return SCENE::CREDIT;
}

// --------------------------------
// UI処理
// --------------------------------
// 更新処理
void SceneGameMain::updateUI()
{
	player_hp_anim_.update();
	// ハイスコア更新処理
	if (high_score_ == -1)
		return;

	if (high_score_ < player_->getMoveNum())
	{
		high_score_ = (int)player_->getMoveNum();
	}
}
// 描画処理
void SceneGameMain::renderUI()
{
	// HPの描画
	DrawString(5, 5, "プレイヤーHP", WHITE);
	for (int i = 0; i < player_->getHp(); ++i)
	{
		DrawRectRotaGraph
		(
			20 + (32 * 1) * i, 40,
			32 * player_hp_anim_.get(),
			32 * 0,
			32, 32,
			1.5, 0,
			player_hp_anim_.getGhandle(), TRUE
		);
	}
	// 移動距離の描画
	DrawString(5, 60, "移動距離", WHITE);
	int font_size = GetFontSize();
	SetFontSize(24);
	int tmp_score = (int)player_->getMoveNum();
	if (tmp_score > 999999999)
	{
		tmp_score = 999999999;
	}
	DrawFormatString(5, 80, WHITE, "%09dm\n", tmp_score);
	SetFontSize(font_size);

	// ハイスコア
	if (high_score_ != -1)
	{
		int font_size = GetFontSize();
		SetFontSize(18);
		DrawString(5, 115, "HIGH SCORE", WHITE);
		DrawFormatString(5, 135, WHITE, "%09dm\n", high_score_);
		SetFontSize(font_size);
	}
}

// --------------------------------
// ゲームオーバー処理
// --------------------------------
// 更新処理
bool SceneGameMain::updateGameEnd()
{
	++flash_count_;
	flash_count_ %= 60;
	if (flash_count_ == 0)
	{
		is_end_message_disp_ = !is_end_message_disp_;
	}

	if (IsKeyOn(KEY_INPUT_RETURN))
	{
		return true;
	}

	return false;
}
// 描画処理
void SceneGameMain::renderGameEnd()
{
	if (is_game_end_ == false)
		return;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawBox(0, 0, WINDOW_W, WINDOW_H, BLACK, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	// スコアの描画
	DrawCenterString(WINDOW_H / 2 - 90, "ゲーム終了", 48, WHITE);
	DrawCenterString(WINDOW_H / 2 - 32, "移動距離", 32, WHITE);
	char score[64];
	sprintfDx(score, "%d", (int)player_->getMoveNum());
	DrawCenterString(WINDOW_H / 2 + 10, score, 64, WHITE);

	// キー入力の誘導メッセージ
	if (is_end_message_disp_ == true)
	{
		DrawCenterString(WINDOW_H - 100, "Press Enter Key", 32, WHITE);
	}
}

// --------------------------------
// ハイスコア処理
// --------------------------------
// ハイスコア取得処理
int SceneGameMain::getScoreTxt()
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
// ハイスコア上書き処理
void SceneGameMain::updateScoreTxt()
{
	int tmp_score = getScoreTxt();

	if (tmp_score >= player_->getMoveNum())
		return;

	// ハイスコア更新処理
	std::ofstream file(SCORE_FILE_NAME);
	if (file.is_open() == true)
	{
		file << (int)(player_->getMoveNum());
		file.close();
	}
}
