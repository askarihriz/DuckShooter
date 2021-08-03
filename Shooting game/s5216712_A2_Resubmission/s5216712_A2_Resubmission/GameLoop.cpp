#include "GameLoop.h"

GameLoop::GameLoop()
{
	window = NULL;
	renderer = NULL;
	GameState = true;
	points = 0;
}

bool GameLoop::getGameState()
{
	return GameState;
}

void GameLoop::Intialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	window = SDL_CreateWindow("Duck Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			GameState = true;
			Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
			Music = Mix_LoadMUS("Sound/UITheme.wav");
			Point = Mix_LoadWAV("Sound/point1.wav");
			Hit = Mix_LoadWAV("Sound/hit1.wav");
			Hover = Mix_LoadWAV("Sound/Hover.wav");
			Button = Mix_LoadWAV("Sound/button1.wav");
			GunShot = Mix_LoadWAV("Sound/kar.mp3");
			Mix_PlayMusic(Music, -1);
			Mix_VolumeMusic(50);
			Mix_VolumeChunk(Point, 64);
			Mix_VolumeChunk(Hit, 64);
			Mix_VolumeChunk(GunShot, 64);
			background.CreateTexture("Images/Forest.png", renderer);
			duck1.CreateTexture("Images/SpriteSheet1.png", renderer);
			duck1.Initialize();
			duck2.CreateTexture("Images/SpriteSheet1.png", renderer);
			duck2.Initialize();
			duck3.CreateTexture("Images/SpriteSheet1.png", renderer);
			duck3.Initialize();
			duck4.CreateTexture("Images/SpriteSheet2.png", renderer);
			duck4.InitializeAlt();
			duck5.CreateTexture("Images/SpriteSheet2.png", renderer);
			duck5.InitializeAlt();
			aim.CreateTexture("Images/aim.png", renderer);
			gun.CreateTexture("Images/gun.png", renderer);
			score.CreateFont("Font/calibrib.ttf", 38);
			timeleft.CreateFont("Font/calibrib.ttf", 38);
			yourScore.CreateFont("Font/calibrib.ttf", 50);
			restartMenu.CreateTexture("Images/RestartMenu.png", renderer);

			std::string s;
			s = "Score: " + std::to_string(points);
			score.Text(s, 255, 255, 255, renderer);

			std::string s1;
			s1 = "Time: " + std::to_string(abs(time - 40));
			timeleft.Text(s1, 255, 255, 255, renderer);
		}
		else
		{
		std::cout << "Not created!" << std::endl;
		}
	}
	else
	{
	std::cout << "window not created!" << std::endl;
	}
}

void GameLoop::LowerMusic() {
	Mix_VolumeMusic(2);
}

void GameLoop::Reset() {
	GameState = true;
	points = 0;
	time = 0;

	std::string s;
	s = "Score: " + std::to_string(points);
	score.Text(s, 255, 255, 255, renderer);

	std::string s1;
	s1 = "Time: " + std::to_string(abs(time - 40));
	timeleft.Text(s1, 255, 255, 255, renderer);
}

int GameLoop::Restart() {
	SDL_RenderClear(renderer);
	restartMenu.Render(renderer);
	SDL_RenderPresent(renderer);
	while (true) {
		while (SDL_PollEvent(&evnt)) {
			if (evnt.type == SDL_QUIT)
			{
				return -1;
			}
			if (evnt.type == SDL_MOUSEBUTTONDOWN && evnt.motion.x > 60 && evnt.motion.x < 415 && evnt.motion.y > 133 && evnt.motion.y < 235)
			{
				Mix_PlayChannel(-1, Button, 0);
				while (Mix_Playing(-1))
				{

				}
				return 1;
			}
			if (evnt.motion.x > 60 && evnt.motion.x < 415 && evnt.motion.y > 133 && evnt.motion.y < 235) {
				if (isHover1) {
					Mix_PlayChannel(-1, Hover, 0);
					isHover1 = false;
				}
			}
			else {
				isHover1 = true;
			}
			if (evnt.type == SDL_MOUSEBUTTONDOWN && evnt.motion.x > 60 && evnt.motion.x < 415 && evnt.motion.y > 240 && evnt.motion.y < 351)
			{
				Mix_PlayChannel(-1, Button, 0);
				while (Mix_Playing(-1))
				{

				}
				return -1;
			}
			if (evnt.motion.x > 60 && evnt.motion.x < 415 && evnt.motion.y > 240 && evnt.motion.y < 351) {
				if (isHover2) {
					Mix_PlayChannel(-1, Hover, 0);
					isHover2 = false;
				}
			}
			else {
				isHover2 = true;
			}
		}
	}
}

void GameLoop::MainMenu()
{
	menu.Initialize(renderer);
	while (!menu.getClicked())
	{
		if (menu.EventHandling(event1) == -1)
		{
			GameState = false;
			break;
		}
		SDL_RenderClear(renderer);
		menu.Render(renderer);
		SDL_RenderPresent(renderer);
	}
}

void GameLoop::Event()
{
	while (SDL_PollEvent(&evnt)) {

		if (evnt.type == SDL_QUIT) {
			GameState = false;
		}
		if (evnt.type == SDL_MOUSEBUTTONDOWN) {
			Mix_PlayChannel(-1, GunShot, 0);
			SDL_Rect temp;
			temp.h = 2;
			temp.w = 2;
			temp.x = evnt.motion.x - 1;
			temp.y = evnt.motion.y - 1;
			if (CollisionDetection::CheckCollision(&duck1.getDest(), &temp)) {
				if (duck1.getState()) {
					duck1.Die();
					points++;
					// Scoring Mechanics
					std::string s;
					s = "Score: " + std::to_string(points);
					score.Text(s, 255, 255, 255, renderer);
				}
			}
			if (CollisionDetection::CheckCollision(&duck2.getDest(), &temp)) {
				if (duck2.getState()) {
					duck2.Die();
					points++;
					// Scoring Mechanics
					std::string s;
					s = "Score: " + std::to_string(points);
					score.Text(s, 255, 255, 255, renderer);
				}
			}
			if (CollisionDetection::CheckCollision(&duck3.getDest(), &temp)) {
				if (duck3.getState()) {
					duck3.Die();
					points++;
					// Scoring Mechanics
					std::string s;
					s = "Score: " + std::to_string(points);
					score.Text(s, 255, 255, 255, renderer);
				}
			}
			if (CollisionDetection::CheckCollision(&duck4.getDest(), &temp)) {
				if (duck4.getState()) {
					duck4.Die();
					points++;
					// Scoring Mechanics
					std::string s;
					s = "Score: " + std::to_string(points);
					score.Text(s, 255, 255, 255, renderer);
				}
			}
			if (CollisionDetection::CheckCollision(&duck5.getDest(), &temp)) {
				if (duck5.getState()) {
					duck5.Die();
					points++;
					// Scoring Mechanics
					std::string s;
					s = "Score: " + std::to_string(points);
					score.Text(s, 255, 255, 255, renderer);
				}
			}
		}
		aim.AimUpdate(evnt.motion.x, evnt.motion.y);
		gun.GunUpdate(evnt.motion.x);
	}
}

void GameLoop::Update()
{
	duck1.Update();
	duck2.Update();
	duck3.Update();
	duck4.UpdateAlt();
	duck5.UpdateAlt();


	if (abs(time - 40) == 0) {
		std::string s1;
		s1 = "Time: " + std::to_string(abs(time - 40));
		timeleft.Text(s1, 255, 255, 255, renderer);

		std::string s3;
		s3 = "You Hunted " + std::to_string(points) + " Ducks !";
		yourScore.Text(s3, 255, 255, 255, renderer);
		yourScore.Render(renderer, 280, 330);
		SDL_RenderPresent(renderer);
		SDL_Delay(3000);
		
		yourScore.FreeTexture();
		GameState = false;
	}

	if (counter % 100 == 0) {
		time++;
		std::string s1;
		s1 = "Time: " + std::to_string(abs(time - 40));
		timeleft.Text(s1, 255, 255, 255, renderer);
	}

	counter++;
}

void GameLoop::Render()
{
	SDL_RenderClear(renderer);
	background.Render(renderer);
	duck1.Render(renderer);
	duck2.Render(renderer);
	duck3.Render(renderer);
	duck4.Render(renderer);
	duck5.Render(renderer);
	aim.AimRender(renderer);
	gun.GunRender(renderer);
	score.Render(renderer, 875, 10);
	timeleft.Render(renderer, 10, 10);
	SDL_RenderPresent(renderer);
}

void GameLoop::Clear()
{
	yourScore.CloseFont();
	score.CloseFont();
	timeleft.CloseFont();
	Mix_FreeChunk(Point);
	Mix_FreeChunk(Hit);
	Mix_FreeChunk(GunShot);
	Mix_FreeMusic(Music);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}