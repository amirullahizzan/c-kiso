#pragma once

#include "ofMain.h"

#define ENEMY_MAX 10
#define BULLET_MAX 40

class ofApp;

// �e�N���X Actor
class Actor {
public:
	//�@���z�֐� virtual = �q�ǂ��Ɍp���ł���
	virtual void Init() {
		x = y = vx = vy = 0.0f;
		sizeW = sizeH = 10.0f;
		isActive = false;
	};
	virtual void Update() {
		// �s������ԂȂ牽�����Ȃ�
		if (!isActive) {
			return;
		}
		// �ړ�����
		x += vx;
		y += vy;
	};
	virtual void Draw() {
		// ���W�𒆐S�Ɏl�p�`��`�悷��
		ofSetColor(color);
		ofDrawRectangle(x - sizeW / 2, y - sizeH / 2, sizeW, sizeH);
	};
	bool IsActive() {
		return isActive;
	}
	void Activate(float _x, float _y)
	{
		x = _x;
		y = _y;
		isActive = true;
	}

protected:
	float x;
	float y;
	float vx;	// �ړ����x = Velocity
	float vy;
	float sizeW;	// �傫����
	float sizeH;	// �傫������
	ofColor color;	// �F
	bool  isActive;	// ��������Ԃ� true = ������
};


// �v���C���[�N���X
class Player : public Actor {
public:
	void Init();
	void Update(ofApp *app);
	void Draw();

protected:
	int   shotCount; // �A�˃J�E���^
};


// �e�̃N���X
class Bullet : public Actor {
public:
	void Init();
	void Update();
};

// �G�N���X(�e�N���X�� Actor)
struct Enemy : public Actor {
public:
	void Init();
	void Update();
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		Player	*pl;		// �v���C���[
		Bullet bullets[BULLET_MAX];	// �e�\���̂̔z��
		Enemy	enemies[ENEMY_MAX];	// �G�\���̂̔z��

		float scrollX;	// ��ʂ̍���̂w���W
		float scrollY;	//           Y���W

		void Shoot(float x, float y);		// �e�𔭎˂��郁�\�b�h
};
