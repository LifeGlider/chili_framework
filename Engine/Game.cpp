/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
    :
    wnd(wnd),
    gfx(wnd),
    rng(rd()),
    xPosDistribution(15, 784),
    yPosDistribution(15, 584),
    crosshair(399, 299, 10, 255, 10)
{
    for (int index = 0; index < amount; ++index)
    {
        targets[index].Init(float(xPosDistribution(rng)), float(yPosDistribution(rng)), targetXVectorTable[index], targetYVectorTable[index], targetSpeedTable[index], targetSizeTable[index], 255, 255, 255);
    }
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    // Update corsshair actual position and update hitbox position
    crosshair.UpdatePosition(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
    crosshair.UpdateHitbox();

    // Execute movement subroutines for all targets and detect collisions with crosshair
    for (int index = 0; index < amount; ++index)
    {
        targets[index].UpdateTargetStatus(crosshair.hitBox, wnd.mouse.LeftIsPressed());
        
        collisionDetected = collisionDetected || targets[index].isColliding(crosshair.hitBox);
    }

    // Change crosshair color if collision is confirmed
    if (collisionDetected)
    {
        crosshair.UpdateColor(255, 10, 10);
        collisionDetected = false;
    }
    else
    {
        crosshair.UpdateColor(10, 255, 10);
    }
}

void Game::ComposeFrame()
{
    for (int index = 0; index < amount; ++index)
    {
        targets[index].Draw(gfx);
    }

    crosshair.Draw(gfx);
}

void Game::DrawCircle(int x_pos, int y_pos, int dimension)
{
    const int radius = dimension / 2;
    const int radius_sqr = radius * radius;

    for (int row = 0; row < dimension; ++row)
    {
        for (int col = 0; col < dimension; ++col)
        {
            int x = col - radius;
            int y = radius - row;
            int sumsqr = x * x + y * y;

            if (sumsqr <= radius_sqr)
            {
                gfx.PutPixel(x_pos + row, y_pos + col, 255, 255, 255);
            }
        }
    }
}
