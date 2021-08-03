#include "Ducks.h"
#include<iostream>

void Ducks::Initialize() {
	setSrc(360, 120, 35, 115);
	Quack = Mix_LoadWAV("Sound/duck.wav");
	Mix_VolumeChunk(Quack, 34);
}

void Ducks::InitializeAlt() {
	setSrc(95, 120, 35, 115);
	Quack = Mix_LoadWAV("Sound/duck.wav");
	Mix_VolumeChunk(Quack, 34);
}

void Ducks::Clear() {
	Mix_FreeChunk(Quack);
}

void Ducks::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

void Ducks::Update()
{
	if (isAlive) {
		if (counter % 10 == 0) {
			if (SrcW > 440)
				SrcW = 328;
			SrcW += 38;
		}
		if (SDL_GetTicks() % 100 == 0) {
			Mix_PlayChannel(-1, Quack, 0);
		}
		setSrc(SrcW, 120, 35, 38);
		setDest(DestX+=3, DestY, 35, 38);
		counter++;
	}
	else {
		setSrc(485, 120, 35, 38);
		setDest(DestX, DestY+=3, 35, 38);
	}
	if (DestY > 550 || DestX > 1040) {
		isAlive = true;
		DestY = rand() % 300 + 10;
		DestX = -20;
	}
}

void Ducks::UpdateAlt()
{
	if (isAlive) {
		if (counter % 10 == 0) {
			if (SrcW > 171)
				SrcW = 60;
			SrcW += 38;
		}
		setSrc(SrcW, 120, 35, 38);
		setDest(DestX -= 3, DestY, 35, 38);
		counter++;
	}
	else {
		setSrc(60, 120, 35, 38);
		setDest(DestX, DestY+=3, 35, 38);
	}
	if (DestY > 550 || DestX < -10) {
		isAlive = true;
		DestY = rand() % 300 + 10;
		DestX = 1040;
	}
}

bool Ducks::getState() {
	return isAlive;
}

void Ducks::Die() {
	isAlive = false;
}
