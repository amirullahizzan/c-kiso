#include "WinMain.h"

// =====================================================
//	�񋓑�
//	���܂����l��������邱�Ƃ̂ł��Ȃ��ϐ�
// =====================================================



// =====================================================
//	�萔
//	�ŏ����猈�܂��Ă��Ă��Ƃ���ς��邱�Ƃ��ł��Ȃ��ϐ�
// =====================================================
#define SLOTS_TYPES_COUNT 8
#define MAX_PATTERN_LOOP 21
int reel_stop_num = 0;


// =====================================================
//	�\����
//	�ϐ����ЂƂ܂Ƃ߂ɂ��ĐV�����ϐ������
// =====================================================
class Reel
{
	enum
	{
		seven1 = 0,
		seven2,
		bell,
		cherry,
		watermelon,
		firework,
		crown,
		fish
	};


public:
	int reel_timer = 0;
	int slot_image = 0;
	int slot_image_number = 0;
	int slot_sequence1[21] = {firework,fish,seven1,bell,watermelon,seven1,watermelon,fish,watermelon,bell,crown,cherry,crown,bell,firework,seven2,watermelon,bell,firework,fish,bell};
	int slot_sequence2[21] = {cherry,seven1,cherry,firework,bell,cherry,fish,watermelon,cherry,watermelon,fish,firework,bell,crown,watermelon,seven2,firework,bell,fish,firework,bell};
	int slot_sequence3[21] = {cherry,seven1,firework,bell,watermelon,firework,fish,watermelon,cherry,seven2,firework,bell,fish,cherry,crown,firework,bell,watermelon,fish,bell,watermelon};
	int slot_handler[SLOTS_TYPES_COUNT] = {};
	bool isRolling = false;

	int GetSlotImage(int slotarray[])
	{
		return slot_handler[slotarray[slot_image_number]];
	}

	void Control()
	{

		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			isRolling = true;
			//roll 3 
		}

	}

	void RollReel()
	{
		Control();
		if (isRolling)
		{
			reel_timer++;
			if (reel_timer % 10 == 0)
			{
				slot_image_number++;
				if (slot_image_number > MAX_PATTERN_LOOP-1)
				{
					slot_image_number = 0;
				}
				//change reel image
			}
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


// =====================================================
//	�֐��v���g�^�C�v
//	�֐��̐錾�̂݁E��`�͌�ōs��
// =====================================================
void StopReel();

//void ReelDraw(const Reel& reel, reel_count)
//{
//	//drawin data continously
//	int tmp_image_index = ghandles[reel.slot_image]
//		DrawGraph(tmp_image_index);
//}

void GameInit()
{
	

	for (int i = 0; i < 8; i++)
	{
	char slot_filename[128];
	sprintfDx(slot_filename, "data/slot_img%02d.png", (i+1));
	reel1.slot_handler[i] = LoadGraph(slot_filename); //258 x 258
	reel2.slot_handler[i] = LoadGraph(slot_filename); //258 x 258
	reel3.slot_handler[i] = LoadGraph(slot_filename); //258 x 258
	}
	//slot_handler[1] = LoadGraph("data/slot_img02.png"); //258 x 258
	//slot_handler[2] = LoadGraph("data/slot_img03.png"); //258 x 258
	//slot_handler[3] = LoadGraph("data/slot_img04.png"); //258 x 258
	//slot_handler[4] = LoadGraph("data/slot_img05.png"); //258 x 258
	//slot_handler[5] = LoadGraph("data/slot_img06.png"); //258 x 258
	//slot_handler[6] = LoadGraph("data/slot_img07.png"); //258 x 258
	//slot_handler[7] = LoadGraph("data/slot_img08.png"); //258 x 258



}
void GameUpdate()
{
	reel1.RollReel();
	reel2.RollReel();
	reel3.RollReel();

	StopReel();
		
	

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
	DrawGraph(0, (WINDOW_H / 2)-(IMG_SIZE/2),reel1.GetSlotImage(reel1.slot_sequence1), 1);
	DrawGraph(IMG_SIZE, (WINDOW_H / 2)-(IMG_SIZE/2),reel2.GetSlotImage(reel1.slot_sequence2), 1);
	DrawGraph(IMG_SIZE*2, (WINDOW_H / 2)-(IMG_SIZE/2),reel3.GetSlotImage(reel1.slot_sequence3), 1);
	DrawFormatString(0,0,BLACK,"current : %d",reel_stop_num);


}
// =====================================================
//		�I��
//	�Q�[�����I������O��1�񂾂����s�����֐�
//	�����Ō�Ɍ�Еt�����s���Ƃ��Ɏg��
// =====================================================
void GameExit()
{



}

void StopReel()
{
	if (IsKeyOn(KEY_INPUT_A))
	{
		reel_stop_num++;
		//roll 3 
		switch (reel_stop_num)
		{
		case 1:
			reel1.isRolling = false;
			break;
		case 2:
			reel2.isRolling = false;
			break;
		case 3:
			reel3.isRolling = false;
			break;
		}
	}
}