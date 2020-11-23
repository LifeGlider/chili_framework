/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Target.h"
#include "Crosshair.h"
#include <random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();

	/********************************/
	/*  User Functions              */
	/********************************/

    int Game::SetPixelPosition(int pixel_pos, int pixel_speed, int screen_border);

    void Game::DrawTarget(int size, int x_pos, int y_pos);

    void Game::DrawCrosshair(int mesh[32][2], int pixelCount, int x_pos, int y_pos, int ScreenWidth, int ScreenHeight, int speed, int red_color, int green_color, int blue_color);

private:
	MainWindow& wnd;
	Graphics gfx;

	/********************************/
	/*  User Variables              */
	/********************************/

    static const int amount = 9;
    int targetXVectorTable[amount] = { 1, -1, -1, 1, -1, -1, 1, -1, -1 };
    int targetYVectorTable[amount] = { 1, 1, -1, 1, 1, -1, 1, 1, -1 };
    int targetSizeTable[amount] = { 13, 15, 17, 13, 15, 17, 13, 15, 17 };
    int targetSpeedTable[amount] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    bool collisionDetected = false;

    std::random_device rd;
    std::mt19937 rng;
    std::uniform_int_distribution<int> xPosDistribution;
    std::uniform_int_distribution<int> yPosDistribution;

    Crosshair crosshair;
    Target targets[amount];

    bool levelIsComplete = false;
};