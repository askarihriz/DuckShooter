#pragma once
#include "Object.h"
#include<SDL_mixer.h>
#include<iostream>

class Ducks :public Object
{
private:
    int SrcW = 328;
    int DestY = rand() % 300 + 10;
    int DestX = rand() % 100 - 100;
    int altDestY = rand() % 300 + 10;
    int altDestX = rand() % 100 + 1024;
    int counter = 0;
    bool isAlive = true;
    Mix_Chunk* Quack;
public:
    void Initialize();
    void InitializeAlt();
    void Clear();
    void Update();
    void UpdateAlt();
    bool getState();
    void Die();
    void Render(SDL_Renderer* ren);
};

