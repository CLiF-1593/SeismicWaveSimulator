#include <SDL.h>
#include <iostream>
#include <Window.h>
#include <Scene.h>
#include <MainScene.h>
#include <FileManager.h>
#include <Log.h>
using namespace std;

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	string path = FileManager::OpenFile(CONFIG);

	Window* win = new Window({"Seismic Wave Simulator", 1280, 720, 60});
	win->Rendering();

	Scene* scene;
	scene = new MainScene(path, 1);
	win->AddScene(scene, 0);

	bool run = true;
	while (run) {
		switch (win->PollEvent()) {
		case Event::QUIT:
			run = false;
			break;
		}
	}

	delete win;
	SDL_Quit();
	return 0;
}