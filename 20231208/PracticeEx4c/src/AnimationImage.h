#pragma once
// =====================================================
//	�A�j���[�V�����N���X�i�w�b�_�[�t�@�C���j
//	 1���ŃA�j���[�V��������摜���Ǘ�����N���X
// =====================================================
class AnimationImage
{
public:
	struct dest
	{
		int	orders[4] = { -1, -1, -1, -1 };	// �A�j���[�V�����̏���
		int	speed	  = 0;					// �Đ����x�i�t���[�����j
	};

	AnimationImage();
	virtual ~AnimationImage();

	void attach(const dest& anim_info);
	void load(const std::string& fname);
	void update();

	int get() const
	{
		return orders_[index_];
	}
	int size() const
	{
		return size_;
	}
	int getGhandle() const
	{
		assert(ghandle_ != -1);

		return ghandle_;
	}

private:
				int	   play_speed_	= 0;	 // �Đ����x
	std::array<int, 4> orders_		= { 0 }; // ����
	unsigned int	   size_		= -1;	 // orders�̃T�C�Y
				int	   index_		= -1;	 // �C���f�b�N�X
				int	   frame_		= 0;	 // �t���[����

	void initInfo();					     // ��L������������


	int ghandle_ = -1;			 // �A�j���[�V�����摜
};