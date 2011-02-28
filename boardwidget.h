#ifndef BOARD_WIDGET_H
#define BOARD_WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>

#include "board.h"

class Ai;

class BoardWidget
	: public QWidget
{

	public:
		BoardWidget(Board &b, QWidget *parent = 0);
		~BoardWidget();

	protected:
		void paintEvent(QPaintEvent *event);
		void mouseReleaseEvent(QMouseEvent *event);

	private:
		void switchPlayer(void);
		bool checkForWin(int move_row, int move_col);
		void win(void);
		void reset(void);

		Board *m_board;
		Ai *m_ai;
		Board::SlotState m_player;

};

#endif

