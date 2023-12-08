#pragma once
// =====================================================
//	拡縮する円クラス（ヘッダーファイル）
//	 拡大縮小する円
// =====================================================
class CircleScaling :
	public CircleBase
{
private:
	const float MAX_SIZE;
	float angle_ = 0;

public:
	CircleScaling(float size = 50.0f);

	void update() override;

};