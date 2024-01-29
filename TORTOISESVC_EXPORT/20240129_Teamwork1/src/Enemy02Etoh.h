#pragma once
// =====================================================
//	敵「江頭」クラス（ヘッダーファイル）
// =====================================================
class Enemy02Etoh :
	public EnemyBase
{
private:
	void attack() override;
	//ActorBase* act;
	//敵がどの方向に進むか決める列挙隊
	enum {
		ENEMY_UP,
		ENEMY_DOWN,
		ENEMY_RIGHT,
		ENEMY_LEFT
	};
	//敵がどの方向に進むか決める変数
	int enemy_mode;
	int enemy_frame;

public:
	Enemy02Etoh();
	virtual ~Enemy02Etoh();

};