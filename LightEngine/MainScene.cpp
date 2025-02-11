#include "MainScene.h"

#include "Debug.h"

#pragma region Entities

#include "TowerEntity.h"
#include "BulletEntity.h"

#pragma endregion

#define TOWER_COUNT 3

void MainScene::OnInitialize() {
	float diameter = GetWindowHeight() / TOWER_COUNT;
	for (int i = 0; i < TOWER_COUNT; i++) {
		TowerEntity* tower = CreateEntity<TowerEntity>(diameter / 2, sf::Color::Green);
		tower->SetPosition(tower->GetRadius(), tower->GetRadius() + diameter * i);
	}
}

void MainScene::OnEvent(const sf::Event& event) {
	if (event.type == sf::Event::EventType::MouseMoved) {
		sf::Vector2i mousePosition(event.mouseButton.x, event.mouseButton.y);
		Debug::DrawCircle(mousePosition.x, mousePosition.y, 5, sf::Color::Blue);
	}
}

void MainScene::OnUpdate() {
	Debug::DrawText(16, 16, "FPS: " + std::to_string(1/GetDeltaTime()), sf::Color::Red);
}