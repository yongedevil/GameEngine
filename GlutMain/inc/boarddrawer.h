#ifndef _BOARDDRAWER_H
#define _BOARDDRAWER_H

#include "board.h"

namespace GAME3011_Assignment1
{

	class BoardDrawer
	{
	private:

	public:
		BoardDrawer();
		~BoardDrawer();

		void DrawBoard(Board const* board);
	};
}

#endif