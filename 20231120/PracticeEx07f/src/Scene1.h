#pragma once

class Scene1 : public SceneBase
{
public:
	void init() override;
private:
	void updateBody() override;
	void renderBody() override;
};