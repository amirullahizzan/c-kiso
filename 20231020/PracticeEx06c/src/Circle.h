#pragma once

class Circle
{
protected:
	//anything this one cannot be 
	//inherited by other class
	//also counts as a private 

	int protectedint = 0;

private:
	// --------------------------
	//	�����o�ϐ�
	// --------------------------
			 float x_ = 0, y_ = 0;		// ���W
			 float r_ = 0;				// ���a
			 float target_y_ = 0;		// �ڕW���W�iY�j
	unsigned int   color_    = 0;		// �F
			 bool  is_spawn_  = false;	// �o���������ǂ���
			 int dirstate_ = 0;
			 int maxbouncecount = 0;
			 int currentbouncecount = 0;
			 int randforce = 0;
			 
			 void bounce(); //goes in update
public:
			 

	Circle();		// �R���X�g���N�^
	~Circle();		// �f�X�g���N�^ //�e�B���_�@�`���_

	// --------------------------
	//	�����o�֐�
	// --------------------------
	void spawn();	// �o������(�o������1�񂾂��Ă�)
	void update();	// �X�V����
	void render();	// �`�揈��

	void debuglog();

	bool isSpawn() const;	// �o�����Ă��邩�ǂ���

};