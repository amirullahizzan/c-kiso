#include "WinMain.h"
#include "Common.h"
#include "Player.h"
// ���ʃt�@�C���i�w�b�_�[�t�@�C��/Common.h�j

// ���ƍ������w�肵�Ďl�p�̒��S�����W�Ƃ���l�p��`�悷��֐�


void drawBox(const Box& box)
{
	DrawBoxAA(box.x - box.w / 2, box.y - box.h / 2,	// ������W
		box.x + box.w / 2, box.y + box.h / 2,	// �E����W
		box.color,				// �F
			  TRUE);				// �h��Ԃ�����
}



