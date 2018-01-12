#pragma once
#include "Snek.h"
#include "Board.h"
#include <random>

class Food
{
public:
	Food(std::mt19937& rng, const Board& brd, const Snek& snek);
	void Respawn(std::mt19937& rng, const Board& brd, const Snek& snek);
	void Draw(Board& brd);
	const Location& getLocation() const;

private:
	static constexpr Color FoodColor = Colors::MakeRGB(253,224,70);
	Location site;
};