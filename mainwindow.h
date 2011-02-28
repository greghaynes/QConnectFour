#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Board;
class BoardWidget;

class MainWindow
	: public QMainWindow
{

	public:
		MainWindow(QWidget *parent = 0);

	private:
		Board *m_board;
		BoardWidget *m_boardWidget;

};

#endif

