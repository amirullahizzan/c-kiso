#pragma once
// =====================================================
//	GuūMūvNXiwb_[t@Cj
//	 ¶EÉŚ®·éGNX
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