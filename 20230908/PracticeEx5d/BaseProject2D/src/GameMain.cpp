#include "WinMain.h"

// =====================================================
//	�񋓑�
//	���܂����l��������邱�Ƃ̂ł��Ȃ��ϐ�
// =====================================================



// =====================================================
//	�萔
//	�ŏ����猈�܂��Ă��Ă��Ƃ���ς��邱�Ƃ��ł��Ȃ��ϐ�
// =====================================================



// =====================================================
//	�\����
//	�ϐ����ЂƂ܂Ƃ߂ɂ��ĐV�����ϐ������
// =====================================================
class Reel
{
	int reel_timer = 0;
	int slot_image = 0;
	int TOTALSEQUENCE = 21;
	int slot_sequence[21] = {};
public:
	void SetSlotImage(int NewSlot)
	{
		slot_image = NewSlot;
	}
	int GetSlotImage()
	{
		return slot_image;
	}
	void RollReel()
	{
		reel_timer++;
		if (reel_timer % 10 == 0)
		{
			//change reel image
		}
	}
	void SetSequence(int newsequence[])
	{
		for (int i = 0;i<TOTALSEQUENCE;i++)
		{
			slot_sequence[i] = newsequence[i];
		}
	}
	
};

Reel reel1;
Reel reel2;
Reel reel3;


// =====================================================
//	�O���[�o���ϐ�
//	�����̊֐��ŋ��ʂ��Ďg�������ϐ��͂����ɏ���
// =====================================================
#define SLOTS_TYPES_COUNT 8

int slot_handler[SLOTS_TYPES_COUNT] = {};

// =====================================================
//	�֐��v���g�^�C�v
//	�֐��̐錾�̂݁E��`�͌�ōs��
// =====================================================



void GameInit()
{

	for (int i = 0; i < 8; i++)
	{
	char slot_filename[128];
	sprintfDx(slot_filename, "data/slot_img%02d.png", (i+1));
	slot_handler[i] = LoadGraph(slot_filename); //258 x 258
	}
	//slot_handler[1] = LoadGraph("data/slot_img02.png"); //258 x 258
	//slot_handler[2] = LoadGraph("data/slot_img03.png"); //258 x 258
	//slot_handler[3] = LoadGraph("data/slot_img04.png"); //258 x 258
	//slot_handler[4] = LoadGraph("data/slot_img05.png"); //258 x 258
	//slot_handler[5] = LoadGraph("data/slot_img06.png"); //258 x 258
	//slot_handler[6] = LoadGraph("data/slot_img07.png"); //258 x 258
	//slot_handler[7] = LoadGraph("data/slot_img08.png"); //258 x 258

	reel1.SetSlotImage(slot_handler[0]);
	reel2.SetSlotImage(slot_handler[1]);
	reel3.SetSlotImage(slot_handler[2]);

	reel1.SetSequence();
}

void GameUpdate()
{

	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		//roll 3 
		reel1.RollReel();
	}
	if (IsKeyOn(KEY_INPUT_A))
	{
		//stop
	}

	int game_frame = 0;
	game_frame++;

}
// =====================================================
//		�`��
//	�Q�[�����I�������܂Ŏ��s�����֐�
//	1�b�Ԃɖ�60��Ă΂��
//	GameUpdate�֐������s���ꂽ��Ɏ��s�����֐�
// =====================================================


void GameDraw()
{
	DrawGraph(0, (WINDOW_H / 2)-(IMG_SIZE/2),reel1.GetSlotImage(), 1);
	DrawGraph(IMG_SIZE, (WINDOW_H / 2)-(IMG_SIZE/2),reel2.GetSlotImage(), 1);
	DrawGraph(IMG_SIZE*2, (WINDOW_H / 2)-(IMG_SIZE/2),reel3.GetSlotImage(), 1);



}
// =====================================================
//		�I��
//	�Q�[�����I������O��1�񂾂����s�����֐�
//	�����Ō�Ɍ�Еt�����s���Ƃ��Ɏg��
// =====================================================
void GameExit()
{



}
