#include "board.h"

#include "board.moc"

Board::Board(int rows, int cols, QObject *parent)
	: QObject(parent)
	, m_rows(rows)
	, m_cols(cols)
{
	m_board = new SlotState*[rows];
	int i, j;
	for(i = 0;i < rows;i++)
	{
		m_board[i] = new SlotState[cols];
		for(j = 0;j < cols;j++)
			m_board[i][j] = Empty;
	}
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
	if(row < 0 || row >= m_rows || col < 0 || col >= m_cols)
		return Empty;
	return m_board[row][col];
}

int Board::setSlot(int row, int col, SlotState val)
{
	if(row < 0 || row >= m_rows || col < 0 || col >= m_cols)
		return false;
	m_board[row][col] = val;
	return true;
}

int Board::rows(void) const
{
	return m_rows;
}

int Board::cols(void) const
{
	return m_cols;
}

void Board::reset(void)
{
	int i, j;
	for(i = 0;i < m_rows;i++)
	{
		for(j = 0;j < m_cols;j++)
			m_board[i][j] = Empty;
	}
}

