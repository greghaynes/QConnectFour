#include "boardwidget.h"
#include "board.h"

BoardWidget::BoardWidget(Board &b, QWidget *parent)
	: QWidget(parent)
	, m_board(&b)
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

