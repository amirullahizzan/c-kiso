#include "WinMain.h"
#include "Player.h"
#include "Enemy.h"
#include "PlayerBullet.h"

// =====================================================
//	�O���[�o���ϐ�
//	�����̊֐��ŋ��ʂ��Ďg�������ϐ��͂����ɏ���
// =====================================================
namespace
{
	const int PLAYER_BULLET_NUM = 15;
	constexpr int WINDOW_W_DIV3 = (WINDOW_W / 3);

	Player player;
	constexpr int MAX_ENEMY = 3;
	Enemy enemy[MAX_ENEMY];
	PlayerBullet player_bullets[PLAYER_BULLET_NUM];

	// �����蔻��p�֐�
	bool IsHit(float x1, float y1, float r1, float x2, float y2, float r2)
	{
		float dist_x = x1 - x2;
		float dist_y = y1 - y2;
		float dist   = sqrtf(dist_x * dist_x + dist_y * dist_y);

		return dist < (r1 + r2);
	}
	
	bool IsHit(const Player& player, const Enemy& enemy)
	{
		float dist_x = player.GetPosX() - enemy.GetPosX();
		float dist_y = player.GetPosY() - enemy.GetPosY();
		float dist = sqrtf(dist_x * dist_x + dist_y * dist_y);

		return dist < (player.GetR() + enemy.GetR() );
	}
	bool IsHit(const PlayerBullet& bullet, const Enemy& enemy)
	{
		float dist_x = bullet.GetPosX() - enemy.GetPosX();
		float dist_y = bullet.GetPosY() - enemy.GetPosY();
		float dist = sqrtf(dist_x * dist_x + dist_y * dist_y);

		return dist < (bullet.GetR() + enemy.GetR());
	}

}

// =====================================================
//		������
//	�Q�[���J�n����ɍŏ���1�񂾂����s�����֐�
//	�ŏ��̒l��ϐ��ɓ��ꂽ���Ƃ��Ɏg��
// =====================================================
void GameInit()
{
	player.Init();

	for (int i= 0;i<MAX_ENEMY ;i++)
	{
		constexpr static int ENEMY_Y_INIT = 50;
		enemy[i].Init();
		enemy[i].SetPos( i *WINDOW_W_DIV3 + (WINDOW_W_DIV3/2) ,ENEMY_Y_INIT);
	}

	for (int i = 0; i < PLAYER_BULLET_NUM; ++i)
	{
		player_bullets[i].Init();
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
	// �e�I�u�W�F�N�g�̍X�V����
	player.Update();
	for (int i = 0; i < PLAYER_BULLET_NUM; ++i)
	{
		player_bullets[i].Update();
	}

	for (int i = 0; i < MAX_ENEMY; i++)
	{
	enemy[i].Update();

		//if (IsHit(player.GetPosX(), player.GetPosY(), player.GetR(), enemy[i].GetPosX(), enemy[i].GetPosY(), enemy[i].GetR()))
		if (	IsHit(player,enemy[i])	)
		{
			player.SetDamage();
		}

	}

	// �e���ˏ���
	if (IsKeyOn(KEY_INPUT_SPACE))
	{
		for (int i = 0; i < PLAYER_BULLET_NUM; ++i)
		{
			if (player_bullets[i].IsShot())
				continue;
			// ��������Ԃ̒e����Ȃ�����甭��
			player_bullets[i].SetPos(player.GetPosX(), player.GetPosY());
		
			break;
		}
	}

	for (int i = 0; i < PLAYER_BULLET_NUM; ++i)
	{
		for (int j = 0; j < MAX_ENEMY; j++)
		{
			//if (IsHit(player_bullets[i].GetPosX(), player_bullets[i].GetPosY(), player_bullets[i].GetR(), enemy[j].GetPosX(), enemy[j].GetPosY(), enemy[j].GetR()))
			if (IsHit(	player_bullets[i], enemy[j] )	)
			{
				enemy[j].SetDamage();
			}
		}
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
	for (int i = 0; i < PLAYER_BULLET_NUM; ++i)
	{
		player_bullets[i].Draw();
	}
	player.Draw();
	for (int i = 0; i < MAX_ENEMY; i++)
	{
	enemy[i].Draw();
	}
}
// =====================================================
//		�I��
//	�Q�[�����I������O��1�񂾂����s�����֐�
//	�����Ō�Ɍ�Еt�����s���Ƃ��Ɏg��
// =====================================================
void GameExit()
{


}
