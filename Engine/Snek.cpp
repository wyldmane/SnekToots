#include "Snek.h"

void Snek::Segment::InitHead(const Location& in_site)
{
	site = in_site;
	c = Snek::HeadColor;
}

void Snek::Segment::InitBody(Color c_input)
{
	c = c_input;
}
void Snek::Segment::Follow(const Segment& next)
{
	site = next.site;
}

void Snek::Segment::MoveBy(const Location& head_dir)
{
	assert(abs(head_dir.x) + abs(head_dir.y) == 1);
	site.Add(head_dir);
}

void Snek::Segment::Draw(Board & brd) const
{
	brd.DrawCell(site, c);
}

const Location& Snek::Segment::GetLocation() const
{
	return site;
}

Snek::Snek(const Location& site)
{
	constexpr int nBodyColors = 4;
	constexpr Color bodyColors[nBodyColors] = 
	{
	{ 38,71,6 },
	{ 39,93,18 },
	{ 43,111,12 },
	{ 39,93,18 }
	};
	for (int i = 0; i < MaxSegments; i++) 
	{
		segments[i].InitBody(bodyColors[i % nBodyColors]);
	}
	segments[0].InitHead(site);
}

void Snek::MoveBy(const Location& head_dir)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(head_dir);
}

Location Snek::GetNextHeadLocation(const Location & head_dir) const
{
	Location loca(segments[0].GetLocation( ));
	loca.Add(head_dir);
	return loca;
}

void Snek::Grow()
{
	if (nSegments < MaxSegments)
	{
		segments[nSegments];
		++nSegments;
	}
}

void Snek::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

bool Snek::IsOverlapping(const Location & target) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
	}

bool Snek::IsOverlappingExceptEnd(const Location & target) const
{
	for (int i = 0; i < nSegments-1; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
	}

int Snek::GetnSegments()
{
	return nSegments;
}
