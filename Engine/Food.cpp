#include "Food.h"

Food::Food(std::mt19937& rng, const Board& brd, const Snek& snek)
{
	Respawn(rng, brd, snek);
}

void Food::Respawn(std::mt19937& rng, const Board& brd, const Snek& snek)
{
	std::uniform_int_distribution<int> yDist(0, brd.GetBoardHeight() - 1);
	std::uniform_int_distribution<int> xDist(0, brd.GetBoardWidth() - 1);

	Location newLoca;
	do
	{
		newLoca.y = yDist(rng);
		newLoca.x = xDist(rng);
	} 
	while (snek.IsOverlapping(newLoca));
	site = newLoca;
}

void Food::Draw(Board& brd)
{
	brd.DrawCell(site, FoodColor);
}

const Location& Food::getLocation() const
{
	return site;
}
