#pragma once
// ------------------------------------------
//	�v���C���[�e�N���X�i�錾��: �w�b�_�t�@�C���j
// ------------------------------------------
class PlayerBullet
{
public:
	PlayerBullet();

	void Init();
	void Update();
	void Draw();

	void SetPos(float x, float y);

	float GetPosX() const;
	float GetPosY() const;
	float GetR()    const;

	bool IsShot() const;

private:
		   float x_		  = 0,
				 y_		  = 0,
				 r_		  = 0;
			 int hp_	  = 0;
	unsigned int color_	  = 0;
			bool is_shot_ = false;


};