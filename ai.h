#ifndef AI_H
#define AI_H

class Board;

class Ai
{

	public:
		Ai(Board &b);

		void move(void);

	private:
		enum Quality
		{
			Win,
			Loss,
			Tie,
			Invalid,
		};

		Quality move(int row, int col);
		Quality invert(Quality q) const;
		void playCol(int i);

		Board *m_board;

};

#endif

