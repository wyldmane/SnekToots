#pragma once
#include "Snek.h"
#include "Board.h"
#include <random>

class Spider
{
public:
	Spider(std::mt19937& rng, const Board& brd, const Snek& snek);
	void Respawn(std::mt19937& rng, const Board& brd, const Snek& snek);
	void Draw(Board& brd, const Location& site);
	const Location& getLocation() const;
	bool isInStrikeZone (const Location& loca) const;
private:
	static constexpr Color SpiderColor = Colors::MakeRGB(20, 52, 91);
	Location pos;
};