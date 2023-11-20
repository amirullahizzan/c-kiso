#pragma once

class Scene2 : public SceneBase
{
public:
	void init() override;
private:
	int A_pressed_counter = 0;
	void updateBody()override;
	void renderBody() override;
};