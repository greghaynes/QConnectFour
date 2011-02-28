#include "mainwindow.h"
#include "board.h"
#include "boardwidget.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	m_board = new Board(5, 6);
	m_boardWidget = new BoardWidget(*m_board);

	setCentralWidget(m_boardWidget);
}

