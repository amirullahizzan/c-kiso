#pragma once

#include "ofMain.h"

#define ENEMY_MAX 10
#define BULLET_MAX 40

class ofApp;

// 親クラス Actor
class Actor {
public:
	//　仮想関数 virtual = 子どもに継承できる
	virtual void Init() {
		x = y = vx = vy = 0.0f;
		sizeW = sizeH = 10.0f;
		isActive = false;
	};
	virtual void Update() {
		// 不活性状態なら何もしない
		if (!isActive) {
			return;
		}
		// 移動処理
		x += vx;
		y += vy;
	};
	virtual void Draw() {
		// 座標を中心に四角形を描画する
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
	float vx;	// 移動速度 = Velocity
	float vy;
	float sizeW;	// 大きさ幅
	float sizeH;	// 大きさ高さ
	ofColor color;	// 色
	bool  isActive;	// 活性化状態か true = 活性化
};


// プレイヤークラス
class Player : public Actor {
public:
	void Init();
	void Update(ofApp *app);
	void Draw();

protected:
	int   shotCount; // 連射カウンタ
};


// 弾のクラス
class Bullet : public Actor {
public:
	void Init();
	void Update();
};

// 敵クラス(親クラスは Actor)
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
		
		Player	*pl;		// プレイヤー
		Bullet bullets[BULLET_MAX];	// 弾構造体の配列
		Enemy	enemies[ENEMY_MAX];	// 敵構造体の配列

		float scrollX;	// 画面の左上のＸ座標
		float scrollY;	//           Y座標

		void Shoot(float x, float y);		// 弾を発射するメソッド
};
