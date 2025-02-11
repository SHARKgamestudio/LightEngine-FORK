#pragma once

#pragma region Local Dependencies

#include "Scene.h"

#pragma endregion

class MainScene : public Scene {
public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
private:
	float m_diameter;
	float m_radius;
};