#pragma once
// --------------------------------------------------------
//	WeaponTwinSwordクラス（ヘッダーファイル）
//	 武器「双剣」クラス
//	 攻撃力は「10」、1回の攻撃で2回の攻撃力がダメージ量として入る
// --------------------------------------------------------
class WeaponTwinSword :
	public WeaponBase
{
public:
	WeaponTwinSword();
	~WeaponTwinSword();

private:
	void AttackMain() override;

	const int ATTACK_NUM = 2;
};
