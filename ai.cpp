#include "ai.h"
#include "board.h"

Ai::Ai(Board &b)
	: m_board(&b)
{
}

void Ai::move(void)
{
	Quality *moves = new Quality[m_board->cols()];
	int i, j;

	for(i = 0;i < m_board->cols();i++)
	{
		for(j = 0;j < m_board->rows();j++)
		{
			if(m_board->slot(i, j) == Board::Empty)
				moves[i] = move(i, j);
		}
	}

	for(i = 0;i < m_board->cols();i++)
	{
		if(moves[i] == Win)
		{
			delete moves;
			playCol(i);
			return;
		}
	}
	for(i = 0;i < m_board->cols();i++)
	{
		if(moves[i] == Tie)
		{
			delete moves;
			playCol(i);
			return;
		}
	}
	for(i = 0;i < m_board->cols();i++)
	{
		if(moves[i] == Loss)
		{
			delete moves;
			playCol(i);
			return;
		}
	}

	delete moves;
}

Ai::Quality Ai::move(int row, int col)
{
	Quality *moves = new Quality[m_board->cols()];
	int i, j;

	if(m_board->isWin(row, col))
			return Win;

	for(i = 0;i<m_board->cols();i++)
	{
		for(j=0;j<m_board->rows();j++)
		{
			moves[i] = Invalid;
			if(m_board->slot(i, j) == Board::Empty)
				moves[i] = invert(move(i, j));
		}
	}

	for(i = 0;i<m_board->cols();i++)
	{
		if(moves[i] == Win)
		{
			delete moves;
			return Win;
		}
	}
	for(i = 0;i<m_board->cols();i++)
	{
		if(moves[i] == Tie)
		{
			delete moves;
			return Tie;
		}
	}
	for(i = 0;i<m_board->cols();i++)
	{
		if(moves[i] == Invalid)
		{
			delete moves;
			return Tie;
		}
	}

	delete moves;
	return Loss;
}

Ai::Quality Ai::invert(Quality q) const
{
	if(q == Win)
		return Loss;
	else if(q == Loss)
		return Win;
	return Tie;
}

void Ai::playCol(int i)
{
	int j;
	for(j=0;j<m_board->rows();j++)
	{
		if(m_board->slot(i, j) == Board::Empty)
		{
			m_board->setSlot(i, j, Board::Player2);
			return;
		}
	}
}

