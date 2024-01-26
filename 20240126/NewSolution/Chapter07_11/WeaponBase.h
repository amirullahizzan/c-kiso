#pragma once
// --------------------------------------------------------
//	WeaponBaseクラス（ヘッダーファイル）
//	 武器の基底クラス
//	 AttackMainメンバ関数を派生クラスでオーバーライドして使用する
// --------------------------------------------------------
class WeaponBase
{
public:
	WeaponBase(const char* name, int hp);	// コンストラクタ(武器の名称を引数に指定)
	virtual ~WeaponBase() ;							// デストラクタ

	void Show() const;						// 武器の名称と攻撃力を出力
	int  Attack();							// 攻撃（武器の使用）

protected:
	int attack_value_ = 0;					// 攻撃力
	int damage_value_ = 0;					// 与えるダメージ量
	virtual void AttackMain() = 0;			// 攻撃（damage_value_を増やす）

private:
	const char* NAME;						// 武器の名称
	int hp_			  = 0;					// 武器のHP（耐久性）

	void MissAttack() const;				// 攻撃失敗のメッセージ出力

};
