#ifndef BOARD_H
#define BOARD_H

#include <QObject>

class Board
	: public QObject
{
	Q_OBJECT

	public:
		enum SlotState
		{
			Player1,
			Player2,
			Empty
		};

		Board(int rows, int cols, QObject *parent = 0);
		~Board(void);

		SlotState slot(int row, int col) const;
		/** Returns true on success, false on error **/
		int setSlot(int row, int col, SlotState val);

		int rows(void) const;
		int cols(void) const;
		void reset(void);

	Q_SIGNALS:
		void boardChanged(void);

	private:
		int m_rows;
		int m_cols;
		SlotState **m_board;
};

#endif

