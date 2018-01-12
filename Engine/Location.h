#pragma once

class Location
{
public:
	void Add(const Location& pos) 
	{
		x += pos.x;
		y += pos.y;
	}
	bool operator==(const Location& rightSide) const
	{
		return x == rightSide.x && y == rightSide.y;
	}
	int x;
	int y;
};