#pragma once
// =====================================================
//	敵「北川」クラス（ヘッダーファイル）
//	 
// =====================================================
class Enemy11Mishima :
	public EnemyBase
{
private:
	void attack() override;


public:
	Enemy11Mishima();
	virtual ~Enemy11Mishima();

};