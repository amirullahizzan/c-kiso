#include "WinMain.h"
#include "SceneBase.h"
// =====================================================
//	�S�ẴV�[���̊��N���X�i�\�[�X�t�@�C���j
//	 �e�V�[���ł�update��render���I�[�o�[���C�h����
// =====================================================
// �R���X�g���N�^
//	�V�[�������w�肷��
SceneBase::SceneBase(std::string name) :
	name_(name)
{

}
// �f�X�g���N�^
SceneBase::~SceneBase()
{

}

// �`�揈��
void SceneBase::render()
{
#ifndef NDEBUG
	//printfDx("�V�[��: %s\n", name_.c_str());
#endif // !NDEBUG

}

// ���̃V�[���ԍ���Ԃ�
SCENE SceneBase::getNext() const
{
	return SCENE::TITLE;
}
