#include "MainScene.h"

#pragma region Local Dependencies

#include "TowerEntity.h"
#include "BulletEntity.h"
#include "EnemyEntity.h"
#include "Debug.h"
#include "Utils.h"

#pragma endregion

#define TOWER_COUNT 54

void MainScene::OnInitialize() {
	m_diameter = GetWindowHeight() / TOWER_COUNT;
	m_radius = m_diameter / 2;

	for (int i = 0; i < TOWER_COUNT; i++) {
		TowerEntity* tower = CreateEntity<TowerEntity>(m_radius, sf::Color::Green);
		tower->SetPosition(tower->GetRadius(), m_radius + m_diameter * i);
		m_towers.push_back(tower);
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

	for (TowerEntity* tower : m_towers) {
		if (!tower->IsAlive()) {
			m_towers.erase(std::remove(m_towers.begin(), m_towers.end(), tower), m_towers.end());
			break;
		}

		for (int i = 0; i < m_enemies.size(); i++) {
			if (tower->GetPosition().y == m_enemies[i]->GetPosition().y) {
				float distance = Utils::GetDistance(tower->GetPosition().x, 0, m_enemies[i]->GetPosition().x, 0);
				if(distance < 256) { tower->Shoot(); }
			}
		}
	}
}