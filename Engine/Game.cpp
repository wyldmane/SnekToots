/****************************************************************************************** 
 *	Chili siteX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili siteX Framework.									  *
 *																						  *
 *	The Chili siteX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili siteX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili siteX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snake({ 2,2 }),
	prey(rng, brd, snake),
	spidey(rng, brd, snake),
	spidey2(rng, brd, snake),
	spidey3(rng, brd, snake),
	spidey4(rng, brd, snake)
{
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
	if (gameIsStarted) {
		if (!gameIsOver)
		{
			if (wnd.kbd.KeyIsPressed(0x57))
			{
				head_dir = { 0, -1 };
			}
			else if (wnd.kbd.KeyIsPressed(0x41))
			{
				head_dir = { -1, 0 };
			}
			else if (wnd.kbd.KeyIsPressed(0x44))
			{
				head_dir = { 1, 0 };
			}
			else if (wnd.kbd.KeyIsPressed(0x53))
			{
				head_dir = { 0, 1 };
			}

			++MoveTimer;

			if (MoveTimer >= MoveDelay)
			{
				MoveTimer = 0;
				const Location next = snake.GetNextHeadLocation(head_dir);
				if (!brd.isInsideBoard(next) || snake.IsOverlappingExceptEnd(next) || spidey.isInStrikeZone(next) || 
					spidey2.isInStrikeZone(next) || spidey3.isInStrikeZone(next))
				{
					gameIsOver = true;
				}
				else
				{
					const bool eating = next == prey.getLocation();
					if (eating)
					{
						snake.Grow();
					}
					if (snake.GetnSegments() >= 10) 
					{
						addSpider = true;
					}
					if (snake.GetnSegments() >= 25)
					{
						addMoreSpiders = true;
					}
					const bool spiderBite = next == spidey.getLocation();
					if (spiderBite)
					{
						gameIsOver = true;
					}
					snake.MoveBy(head_dir);
					if (eating)
					{
						prey.Respawn(rng, brd, snake);
					}
				}
			}
		}
	}
	else {
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			gameIsStarted = true;
		}

	}
}

void Game::ComposeFrame()
{
	if (!gameIsStarted)
	{
		SpriteCodex::DrawTitleAlt(60, 80, gfx);
	}
	else {
		snake.Draw(brd);
		prey.Draw(brd);
		spidey.Draw(brd,head_dir);

		if (addSpider)
		{
			spidey2.Draw(brd, head_dir);
		}

		if (addMoreSpiders)
		{
			spidey3.Draw(brd, head_dir);
			spidey4.Draw(brd, head_dir);
		}

		if (gameIsOver)
		{
			SpriteCodex::DrawGameOverAlt(60, 80, gfx);
		}
		
		brd.DrawBorder();
		//there's a snake in my boot!
	}
}
