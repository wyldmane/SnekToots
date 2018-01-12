#pragma once
#include "Graphics.h"
#include "Location.h"


class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& site, Color c);
	int GetBoardWidth() const;
	int GetBoardHeight() const;
	bool isInsideBoard(const Location& loca) const;
	void DrawBorder();

private:
	static constexpr int cellPadding = 1;
	static constexpr Color bColor = Colors::MakeRGB(164,214,221);
	static constexpr auto dimension = 20;
	static constexpr auto width = 28;
	static constexpr auto height = 21;
	static constexpr auto bWidth = 4;
	static constexpr auto padding = 2;
	static constexpr int x = 100;
	static constexpr int y = 80;
	Graphics& gfx;
};