#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	pl = new(Player);	// �v���C���[�𓮓I�Ƀ������ɐ�������

	// �v���C���[�̏�����
	pl->Init();

	// �e�̏�����
	for (int b = 0; b < BULLET_MAX; b++) {
		bullets[b].Init();
	}

	// �G�̏�����
	for (int e = 0; e < ENEMY_MAX; e++) {
		enemies[e].Init();
	}
}

// �v���C���[�N���X�̏�����
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

// �e��������
void Bullet::Init()
{
	Actor::Init();
	vy = -4.0f;
	sizeW = 5;
	sizeH = 10;
	color = ofColor::yellow;
}

// �G��������
void Enemy::Init()
{
	Actor::Init();	// �e�̏�����

	x = ofRandom(0, 600);
	y = ofRandom(-500, -100);
	vy = ofRandom(2.0f, 4.0f);
	color = ofColor::cyan;
	sizeW = sizeH = ofRandom(10, 40);
	isActive = true;
}


//--------------------------------------------------------------
void ofApp::update(){
	// �U�O���̂P�b�ɂP��A����Ă΂��֐�

	// �v���C���[�̍X�V
	pl->Update(this);		// ofApp ��n��

	// �e�̈ړ�
	for (int b = 0; b < BULLET_MAX; b++) {
		bullets[b].Update();
	}

	// �G�̈ړ�
	for (int e = 0; e < ENEMY_MAX; e++) {
		Enemy* enm = &enemies[e];
		enm->Update();
	}
}


void Player::Update(ofApp* app)
{
	Actor::Update();
	// �㉺���E�̃L�[�Ńv���C���[���ړ�
	if (ofGetKeyPressed(ofKey::OF_KEY_LEFT)) {
		// ���ֈړ�
		vx = -2;
	}
	else if (ofGetKeyPressed(ofKey::OF_KEY_RIGHT)) {
		// �E�ֈړ�
		vx = 2;
	}
	else {
		vx = 0.0f;
	}
	if (ofGetKeyPressed(ofKey::OF_KEY_UP)) {
		// ��ֈړ�
		vy = -2;
	}
	else if (ofGetKeyPressed(ofKey::OF_KEY_DOWN)) {
		// ���ֈړ�
		vy = 2;
	}
	else {
		vy = 0.0f;
	}

	// �X�y�[�X�L�[�������ꂽ��e�𔭎� (�e����ʂ̊O�ɑ��݂��Ă����甭�ˉ\)
	if (--shotCount <= 0 && ofGetKeyPressed((int)' ')) {
		shotCount = 5;
		app->Shoot(x, y);
	}
}


// �e�𔭎˂��郁�\�b�h
void ofApp::Shoot(float x, float y)
{
	for (int b = 0; b < BULLET_MAX; b++) {
		Bullet* blt = &bullets[b];
		// �s������Ԃ̒e����������A���ˏ�Ԃɂ���
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
		// ��ʊO�ɏo����A�s�������
		isActive = false;
	}
}

// �G�̍X�V����
void Enemy::Update()
{
	Actor::Update();
	// �G����ʊO�ɏo����A��ʂ̏�ɖ߂�
	if (y > 480) {
		Init();
	}
}


//--------------------------------------------------------------
void ofApp::draw(){
	// ��l��
	pl->Draw();

	// �e
	for (int b = 0; b < BULLET_MAX; b++) {
		bullets[b].Draw();
	}

	// �G
	for (int e = 0; e < ENEMY_MAX; e++) {
		enemies[e].Draw();
	}
}

void Player::Draw()
{
	ofSetColor(color);
	ofCircle(x, y, sizeW);	// (X, Y, ���a)
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
