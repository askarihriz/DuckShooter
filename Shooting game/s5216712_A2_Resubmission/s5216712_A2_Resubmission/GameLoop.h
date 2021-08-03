#pragma once
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include"TextureManager.h"
#include"Background.h"
#include"MainMenu.h"
#include"Ducks.h"
#include"CollisionDetection.h"
#include"TextManager.h"
#include<cstdlib>


class GameLoop
{
private:
	SDL_Event evnt;
	const int HEIGHT = 768;
	const int WIDTH = 1024;
	int points = 0;
	int time = 0;
	int counter = 0;
	bool GameState;
	bool isHover1;
	bool isHover2;
	Mix_Music* Music;
	Mix_Chunk* Point;
	Mix_Chunk* Hit;
	Mix_Chunk* Button;
	Mix_Chunk* Hover;
	Mix_Chunk* GunShot;
	MainMenu menu;
	Background background;
	Background restartMenu;
	Background aim;
	Background gun;
	Ducks duck1;
	Ducks duck2;
	Ducks duck3;
	Ducks duck4;
	Ducks duck5;
	TextManager score;
	TextManager yourScore;
	TextManager timeleft;
	SDL_Window* window;
	SDL_Event event1;
	SDL_Renderer* renderer;
public:
	GameLoop();
	void MainMenu();
	void LowerMusic();
	bool getGameState();
	void Update();
	void Reset();
	int Restart();
	void Intialize();
	void Event();
	void Render();
	void Clear();
};

