#pragma once

class Scene3 : public SceneBase
{
public :
	void init() override;
	int timer = 5;
private:
	void updateBody()override;
	void renderBody() override;
};
