#ifndef BOARD_WIDGET_H
#define BOARD_WIDGET_H

#include <QWidget>
#include <QPaintEvent>

class Board;

class BoardWidget
	: public QWidget
{

	public:
		BoardWidget(Board &b, QWidget *parent = 0);

	protected:
		void paintEvent(QPaintEvent *event);

	private:
		Board *m_board;

};

#endif

