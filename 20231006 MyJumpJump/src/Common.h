#pragma once
// 共通ファイル（ヘッダーファイル/Common.h）

// =====================================================
//	構造体
// =====================================================
class Box
{
public:
	float x = 0;
	float y = 0;
	float w = 0;
	float h = 0;
	unsigned int color = 0;
};

extern int player_damage_frame;
extern const int PLAYER_DAMAGE_FRAME_MAX;	// ダメージ時間
extern bool isImmune;

// =====================================================
//	関数
// =====================================================
// 幅と高さを指定して四角の中心を座標とする四角を描画する関数
void drawBox(const Box& box);

//int EnemyWaitReroll(int i);



