#pragma once
// --------------------------------------------------------
//	WeaponSwordクラス（ヘッダーファイル）
//	 武器「基本の剣」クラス
//	 攻撃力は「10」、1回の攻撃で1回の攻撃力がダメージ量として入る
// --------------------------------------------------------
class WeaponSword :
	public WeaponBase
{
public:
	WeaponSword();
	~WeaponSword();

private:
	void AttackMain() override;

};
