#include "Board.h"
#include<assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	const int off_x = x+borderWidth+borderPadding;
	const int off_y = y + borderWidth + borderPadding;

	gfx.DrawRectDim(loc.x * dimentsion+off_x+cellPadding, loc.y * dimentsion+off_y+cellPadding,dimentsion-cellPadding*2,dimentsion-cellPadding*2,c);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >=0 &&loc.x < width &&
		   loc.y >=0 && loc.y < height;
}

void Board::DrawBorder()
{
	const int top = y;
	const int left = x;
	const int bottom = top + (borderWidth + borderPadding) * 2 + height * dimentsion;
	const int right = left + (borderWidth + borderPadding) * 2 + width * dimentsion;

	//top
	gfx.DrawRect(left, top, right, top + borderWidth, borderColor);
	//left
	gfx.DrawRect(left, top + borderWidth, left + borderWidth, bottom - borderWidth, borderColor);
	//right
	gfx.DrawRect(right - borderWidth, top + borderWidth, right, bottom - borderWidth, borderColor);
	//bottom
	gfx.DrawRect(left, bottom - borderWidth, right, bottom, borderColor);


}


