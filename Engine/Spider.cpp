#include "Spider.h"

Spider::Spider(std::mt19937 & rng, const Board & brd, const Snek & snek)
{
	Respawn(rng, brd, snek);
}

void Spider::Respawn(std::mt19937 & rng, const Board & brd, const Snek & snek)
{
	std::uniform_int_distribution<int> yDist(2, brd.GetBoardHeight() - 3);
	std::uniform_int_distribution<int> xDist(2, brd.GetBoardWidth() - 3);

	Location newLoca;
	do
	{
		newLoca.y = yDist(rng);
		newLoca.x = xDist(rng);
	}
	while (snek.IsOverlapping(newLoca));
	pos = newLoca;
}
void Spider::Draw(Board& brd, const Location& site)
{
	if (isInStrikeZone)
	{
		brd.DrawCell(site, SpiderColor);
	}
	else
	{
		brd.DrawCell(pos, SpiderColor);
	}
}
const Location & Spider::getLocation() const
{
	return pos;
}


bool Spider::isInStrikeZone(const Location& site) const
{
	return site.x >= pos.x -1 && site.x <= pos.x + 1 &&
		site.y >= pos.y - 1 && site.y <= pos.y + 1;
}
