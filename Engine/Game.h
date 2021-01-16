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
#include "FrameTimer.h"
#include <random>
#include <chrono>

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

    void DrawCircle(int x_pos, int y_pos, int radius);

private:
	MainWindow& wnd;
	Graphics gfx;

	/********************************/
	/*  User Variables              */
	/********************************/

    static const int amount = 9;
    float targetXVectorTable[amount] = { 1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f };
    float targetYVectorTable[amount] = { 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f };
    float targetSpeedTable[amount] = { 1.5f, 1.0f, 2.0f, 1.5f, 1.0f, 2.0f, 1.5f, 1.0f, 2.0f };
    int targetSizeTable[amount] = { 13, 15, 17, 13, 15, 17, 13, 15, 17 };
    bool collisionDetected = false;

    FrameTimer ft;
    std::random_device rd;
    std::mt19937 rng;
    std::uniform_int_distribution<int> xPosDistribution;
    std::uniform_int_distribution<int> yPosDistribution;

    Crosshair crosshair;
    Target targets[amount];

    bool levelIsComplete = false;
};