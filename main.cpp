#include <QApplication>

#include "board.h"
#include "boardwidget.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	Board *board = new Board(5, 6);
	board->setSlot(0, 0, Board::Player1);
	board->setSlot(1, 0, Board::Player2);
	BoardWidget bw(*board);
	bw.show();

	return app.exec();
}

