#include "Background.h"
#include<cstdlib>

void Background::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

void Background::AimRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

void Background::GunRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

void Background::AimUpdate(int X, int Y)
{
	setSrc(0, 0, 600, 600);
	setDest(X-50, Y-50, 100, 100);
}

void Background::GunUpdate(int X)
{
	setSrc(0, 0, 251, 340);
	setDest(X , 768 - 255, 251, 340);
}


void Background::Reset()
{
}