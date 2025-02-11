#include "LEngine.h"

#pragma region Scenes

#include "MainScene.h"

#pragma endregion

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define WINDOW_TITLE "Light Engine"

int main() {
    GameManager* pInstance = GameManager::Get();
	pInstance->CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, 60, sf::Color::Black);
	pInstance->LaunchScene<MainScene>();
	return 0;
}