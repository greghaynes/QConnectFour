#include "board.h"

#include "board.moc"

Board::Board(int rows, int cols)
	: m_rows(rows)
	, m_cols(cols)
{
	m_board = new SlotState[rows][cols];
}

Board::~Board(void)
{
	delete m_board;
}

SlotState Board::slot(int row, int col) const
{
	return m_board[row][col];
}

int Board::setSlot(int row, int col, SlotState val)
{
	if(row >= m_rows || col >= m_cols)
		return false;
	m_board[row][col] = val;
	return true;
}

