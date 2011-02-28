#include "board.h"

#include "board.moc"

Board::Board(int rows, int cols)
	: m_rows(rows)
	, m_cols(cols)
{
	m_board = new SlotState*[rows];
	int i;
	for(i = 0;i < rows;i++)
		m_board[i] = new SlotState[cols];
}

Board::~Board(void)
{
	int i;
	for(i = 0;i < m_rows;i++)
		delete m_board[i];
	delete m_board;
}

Board::SlotState Board::slot(int row, int col) const
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

