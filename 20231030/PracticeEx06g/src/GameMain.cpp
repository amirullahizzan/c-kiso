//#include <cstdlib>
#include "WinMain.h"
#include "Pos2.h"
#include "Hit.h"
#include "../add/Player.h"
#include "../add/Bullet.h"
#include "../add/Enemy.h"

// =====================================================
//	�O���[�o���ϐ�
//	�����̊֐��ŋ��ʂ��Ďg�������ϐ��͂����ɏ���
// =====================================================
static Player player;
#define MAX_BULLETS 25
static Bullet bullet[MAX_BULLETS];
Pos2 bulletleft;
Pos2 bulletright;
#define MAX_ENEMY 9
static Enemy enemy[MAX_ENEMY];

int enemywaveType = 0;
// =====================================================
//		������
//	�Q�[���J�n����ɍŏ���1�񂾂����s�����֐�
//	�ŏ��̒l��ϐ��ɓ��ꂽ���Ƃ��Ɏg��
// =====================================================
void GameInit()
{
	player.init();
	for (int i = 0; i<MAX_BULLETS ;i++)
	{
	bullet[i].init();
	}

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		enemy[i].init();
	}
}
// =====================================================
//		�X�V
//	�Q�[�����I�������܂Ŏ��s�����֐�
//	1�b�Ԃɖ�60��Ă΂��
//	1�t���[���ōs�������������ɏ���
// =====================================================
void GameUpdate()
{
	player.update();
	for (int i = 0;i < MAX_ENEMY;i++)
	{
		enemy[i].moveWave();

	if (
		isHit(player.getPos(),player.getR(), enemy[i].getPos(), player.getR())
		&& !enemy[i].getIsDestroyed()
	   )
			{
			player.setDamage();
			}
	}

	bulletleft.x = player.getX() - 25;
	bulletright.x = player.getX() + 25;
	bulletleft.y = player.getY();
	bulletright.y = player.getY();

	for (int i = 0;i < MAX_BULLETS;i++)
	{
		bullet[i].update();

		if (IsKeyOn(KEY_INPUT_SPACE) && !bullet[i].isShot())
		{
			bullet[i].setShot(bulletleft);
			break;
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{

		if (IsKeyOn(KEY_INPUT_SPACE) && !bullet[i].isShot())
		{
			//if shot, move on to the next bullet
			if (bullet[i].isShot())
			{
				continue;
			}
			bullet[i].setShot(bulletright);
			break;
		}
	}


	switch (enemywaveType)
	{
	case 0:
	//Init Wave
		for (int i = 0 ;i<MAX_ENEMY;i++)
		{
		enemy[i].spawn();
		}
		enemywaveType+=1;
		break;
	case 1:
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (
				isHit	(bullet[i].getPos(), bullet[i].getR(), enemy[i].getPos(), enemy[i].getR()	)
				&& !enemy[i].getIsDestroyed()
				)
			{
				bullet[i].setErase();
				enemy[i].destroy();
			}
		}
		break;
	case 2:
		break;
	}


	
}
// =====================================================
//		�`��
//	�Q�[�����I�������܂Ŏ��s�����֐�
//	1�b�Ԃɖ�60��Ă΂��
//	GameUpdate�֐������s���ꂽ��Ɏ��s�����֐�
// =====================================================
void GameDraw()
{
	player.render();
	for (int i = 0; i < MAX_BULLETS; i++)
	{
	bullet[i].render();
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullet[i].render();
	}
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		enemy[i].render();
	}

	printfDx(" pos : %f\n",bulletleft.x);
	printfDx(" pos : %f\n", bulletright.x);
	printfDx(" wavetype : %d\n", enemywaveType);
}
// =====================================================
//		�I��
//	�Q�[�����I������O��1�񂾂����s�����֐�
//	�����Ō�Ɍ�Еt�����s���Ƃ��Ɏg��
// =====================================================
void GameExit()
{
	player.exit();
	for (int i = 0; i < MAX_BULLETS; i++)

	{
	bullet[i].exit();
	}

}
