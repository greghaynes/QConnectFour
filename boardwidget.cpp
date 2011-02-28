#include "boardwidget.h"

#include <QPainter>

#include <QDebug>

BoardWidget::BoardWidget(Board &b, QWidget *parent)
	: QWidget(parent)
	, m_board(&b)
	, m_player(Board::Player1)
{
	b.setParent(this);
}

void BoardWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setBackgroundMode(Qt::OpaqueMode);

	painter.fillRect(0, 0, width(), height(), Qt::white);

	// Draw grid
	int colWidth = width() / m_board->cols();
	int rowHeight = height() / m_board->rows();
	int i, j;
	for(i = 0;i<m_board->cols();i++)
		painter.drawLine(colWidth * i, 0, colWidth * i, height());
	for(i = 0;i<m_board->rows();i++)
		painter.drawLine(0, rowHeight*i, width(), rowHeight*i);

	// Draw pieces
	for(i = 1;i<=m_board->rows();i++)
	{
		for(j = 0;j<m_board->cols();j++)
		{
			switch(m_board->slot(i-1, j))
			{
			case Board::Player1:
				painter.setBrush(QBrush(Qt::red));
				break;
			case Board::Player2:
				painter.setBrush(QBrush(Qt::black));
				break;
			default:
				painter.setBrush(QBrush(Qt::white));
			}

			painter.drawEllipse(j*colWidth, height()-(i*rowHeight), colWidth, rowHeight);
		}
	}
}

void BoardWidget::mouseReleaseEvent(QMouseEvent *event)
{
	int colWidth = width() / m_board->cols();
	int col = event->x() / colWidth;
	int i;

	for(i = 0;i<m_board->rows();i++)
	{
		if(m_board->slot(i, col) == Board::Empty)
		{
			qDebug() << "Placing at " << i << col;
			if(!m_board->setSlot(i, col, m_player))
				qDebug() << "Invalid Placement";
			break;
		}
	}

	update();
	checkForWin(i, col);
	switchPlayer();
}

void BoardWidget::checkForWin(int move_row, int move_col)
{
	int offset, i;
	qDebug() << "Checking for win" << move_row << move_col;
	
	for(offset = 0;offset<4;offset++)
	{
		//check vertical
		for(i = 0;i<4;i++)
		{
			if(m_board->slot(move_row+offset-i, move_col) != m_player)
				break;
			else if(i == 3)
			{
				win();
				return;
			}
		}

		//check pos diag
		for(i = 0;i<4;i++)
		{
			if(m_board->slot(move_row+offset-i, move_col+offset-i) != m_player)
				break;
			else if(i == 3)
			{
				win();
				return;
			}
		}

		//check neg diag
		for(i = 0;i<4;i++)
		{
			if(m_board->slot(move_row+offset-i, move_col+offset+i) != m_player)
				break;
			else if(i == 3)
			{
				win();
				return;
			}
		}

		//check horiz
		for(i = 0;i<4;i++)
		{
			if(m_board->slot(move_row, move_col+offset-i) != m_player)
				break;
			else if(i == 3)
			{
				win();
				return;
			}
		}
	}
}

void BoardWidget::switchPlayer(void)
{
	if(m_player == Board::Player1)
		m_player = Board::Player2;
	else
		m_player = Board::Player1;
}

void BoardWidget::win(void)
{
	qDebug() << "Win!";
}

