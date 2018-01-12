#include "Board.h"
#include <assert.h>

Board::Board(Graphics & gfx)
	:
	gfx (gfx)
{}

void Board::DrawCell(const Location& site, Color c) 
{
	assert(site.x >= 0);
	assert(site.x < width);
	assert(site.y >= 0);
	assert(site.y < height);

	const int offsetx = x + bWidth + padding;
	const int offsety = y + bWidth + padding;

	gfx.DrawRectDim(site.x * dimension + offsetx + cellPadding, site.y * dimension + offsety + cellPadding, 
		dimension - cellPadding * 2, dimension - cellPadding * 2, c);
}

int Board::GetBoardWidth() const
{
	return width;
}

int Board::GetBoardHeight() const
{
	return height;
}

bool Board::isInsideBoard(const Location& site) const
{
	return site.x >= 0 && site.x < width &&
		site.y >= 0 && site.y < height;
}

void Board::DrawBorder()
{
	const int top = y;
	const int left = x;
	const int bottom = top + (bWidth + padding) * 2 + height * dimension;
	const int right = left + (bWidth + padding) * 2 + width * dimension;

	//top
	gfx.DrawRect(left, top, right, top + bWidth, bColor);
	//left
	gfx.DrawRect(left + bWidth, top + bWidth, left, bottom - bWidth, bColor);
	//bottom
	gfx.DrawRect(left, bottom - bWidth, right, bottom, bColor);
	//right
	gfx.DrawRect(right - bWidth, top + bWidth, right, bottom - bWidth, bColor);
}
