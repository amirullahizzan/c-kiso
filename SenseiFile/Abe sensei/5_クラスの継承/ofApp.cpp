#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	pl = new(Player);	// プレイヤーを動的にメモリに生成する

	// プレイヤーの初期化
	pl->Init();

	// 弾の初期化
	for (int b = 0; b < BULLET_MAX; b++) {
		bullets[b].Init();
	}

	// 敵の初期化
	for (int e = 0; e < ENEMY_MAX; e++) {
		enemies[e].Init();
	}
}

// プレイヤークラスの初期化
void Player::Init()
{
	Actor::Init();
	x = 320;
	y = 400;
	sizeW = sizeH = 20;
	color = ofColor::red;
	shotCount = 5;
	isActive = true;
}

// 弾を初期化
void Bullet::Init()
{
	Actor::Init();
	vy = -4.0f;
	sizeW = 5;
	sizeH = 10;
	color = ofColor::yellow;
}

// 敵を初期化
void Enemy::Init()
{
	Actor::Init();	// 親の初期化

	x = ofRandom(0, 600);
	y = ofRandom(-500, -100);
	vy = ofRandom(2.0f, 4.0f);
	color = ofColor::cyan;
	sizeW = sizeH = ofRandom(10, 40);
	isActive = true;
}


//--------------------------------------------------------------
void ofApp::update(){
	// ６０分の１秒に１回、毎回呼ばれる関数

	// プレイヤーの更新
	pl->Update(this);		// ofApp を渡す

	// 弾の移動
	for (int b = 0; b < BULLET_MAX; b++) {
		bullets[b].Update();
	}

	// 敵の移動
	for (int e = 0; e < ENEMY_MAX; e++) {
		Enemy* enm = &enemies[e];
		enm->Update();
	}
}


void Player::Update(ofApp* app)
{
	Actor::Update();
	// 上下左右のキーでプレイヤーを移動
	if (ofGetKeyPressed(ofKey::OF_KEY_LEFT)) {
		// 左へ移動
		vx = -2;
	}
	else if (ofGetKeyPressed(ofKey::OF_KEY_RIGHT)) {
		// 右へ移動
		vx = 2;
	}
	else {
		vx = 0.0f;
	}
	if (ofGetKeyPressed(ofKey::OF_KEY_UP)) {
		// 上へ移動
		vy = -2;
	}
	else if (ofGetKeyPressed(ofKey::OF_KEY_DOWN)) {
		// 下へ移動
		vy = 2;
	}
	else {
		vy = 0.0f;
	}

	// スペースキーが押されたら弾を発射 (弾が画面の外に存在していたら発射可能)
	if (--shotCount <= 0 && ofGetKeyPressed((int)' ')) {
		shotCount = 5;
		app->Shoot(x, y);
	}
}


// 弾を発射するメソッド
void ofApp::Shoot(float x, float y)
{
	for (int b = 0; b < BULLET_MAX; b++) {
		Bullet* blt = &bullets[b];
		// 不活性状態の弾があったら、発射状態にする
		if ( !blt->IsActive() ) {
			blt->Activate(x, y);
			return;
		}
	}
}

void Bullet::Update()
{
	Actor::Update();
	if (y < -50.0f) {
		// 画面外に出たら、不活性状態
		isActive = false;
	}
}

// 敵の更新処理
void Enemy::Update()
{
	Actor::Update();
	// 敵が画面外に出たら、画面の上に戻す
	if (y > 480) {
		Init();
	}
}


//--------------------------------------------------------------
void ofApp::draw(){
	// 主人公
	pl->Draw();

	// 弾
	for (int b = 0; b < BULLET_MAX; b++) {
		bullets[b].Draw();
	}

	// 敵
	for (int e = 0; e < ENEMY_MAX; e++) {
		enemies[e].Draw();
	}
}

void Player::Draw()
{
	ofSetColor(color);
	ofCircle(x, y, sizeW);	// (X, Y, 半径)
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
