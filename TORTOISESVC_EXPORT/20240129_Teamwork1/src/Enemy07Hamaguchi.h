#pragma once
// =====================================================
//	敵「濵口」クラス（ヘッダーファイル）
//	 左右に移動する敵クラス
// =====================================================
class Enemy07Hamaguchi :
	public EnemyBase
{
private:
	void attack() override;

	float move_x = 3;
	float move_y = 8;
	
public:
	Enemy07Hamaguchi();
	virtual ~Enemy07Hamaguchi();

};