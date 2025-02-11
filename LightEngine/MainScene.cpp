#include "MainScene.h"

#include "Debug.h"

#pragma region Entities

#include "TowerEntity.h"
#include "BulletEntity.h"
#include <iostream>
#include "EnemyEntity.h"

#pragma endregion

#define TOWER_COUNT 3

void MainScene::OnInitialize() {
	m_diameter = GetWindowHeight() / TOWER_COUNT;
	m_radius = m_diameter / 2;

	for (int i = 0; i < TOWER_COUNT; i++) {
		TowerEntity* tower = CreateEntity<TowerEntity>(m_radius, sf::Color::Green);
		tower->SetPosition(tower->GetRadius(), m_radius + m_diameter * i);
	}
}

void MainScene::OnEvent(const sf::Event& event) {
	if (event.type == sf::Event::EventType::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Button::Left) {
			sf::Vector2i mousePosition(event.mouseButton.x, event.mouseButton.y);
			Debug::DrawCircle(mousePosition.x, mousePosition.y, 16, sf::Color::Cyan);

			if (mousePosition.x < m_diameter * 1.5f) { return; }
			for (int i = 0; i < TOWER_COUNT; i++) {
				if (mousePosition.y < m_diameter + m_diameter * i) {
					EnemyEntity* enemy = CreateEntity<EnemyEntity>(m_radius, sf::Color::Red);
					enemy->SetPosition(mousePosition.x, m_radius + m_diameter * i);
					break;
				}
			}
		}
	}
}

void MainScene::OnUpdate() {
	Debug::DrawText(16, 16, "FPS: " + std::to_string(1/GetDeltaTime()), sf::Color::Red);
}