#pragma once
#include "Board.h"
#include "Location.h"
#include <assert.h>

class Snek
{
private: 
	class Segment
	{
	public:
		void InitHead(const Location& site);
		void InitBody(Color c_input);
		void Follow(const Segment& next);
		void MoveBy(const Location& head_dir);
		void Draw(Board& brd) const;
		const Location& GetLocation()const;
	private:
		Location site;
		Color c;
	};
public: 
	Snek(const Location& site);
	void MoveBy(const Location& head_dir);
	Location GetNextHeadLocation(const Location& head_dir) const;
	void Grow();
	void Draw(Board& brd)const;
	bool IsOverlapping(const Location& target) const;
	bool IsOverlappingExceptEnd(const Location& target) const;
	int GetnSegments();

private:
	static constexpr Color HeadColor = Colors::MakeRGB(104,215,136);
	static constexpr auto MaxSegments = 100;
	Segment segments[MaxSegments];
	int nSegments = 1;
};