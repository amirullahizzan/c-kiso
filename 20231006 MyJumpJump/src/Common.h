#pragma once
// ���ʃt�@�C���i�w�b�_�[�t�@�C��/Common.h�j

// =====================================================
//	�\����
// =====================================================
class Box
{
public:
	float x = 0;
	float y = 0;
	float w = 0;
	float h = 0;
	unsigned int color = 0;
};

extern int player_damage_frame;
extern const int PLAYER_DAMAGE_FRAME_MAX;	// �_���[�W����
extern bool isImmune;

// =====================================================
//	�֐�
// =====================================================
// ���ƍ������w�肵�Ďl�p�̒��S�����W�Ƃ���l�p��`�悷��֐�
void drawBox(const Box& box);

//int EnemyWaitReroll(int i);



