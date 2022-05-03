#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tris.h"
#include "cgui.h"


/*
 *
 */
int get_input_move() {
	int move = EMPTY;
	scanf("%d", &move);

	return move;
}


/*
 *
 */
int get_input_x (int p) {
	switch (p) {
		case 1:
	    case 2:
	    case 3:
	    	return 0;
	    case 4:
		case 5:
		case 6:
			return 1;
		case 7:
		case 8:
		case 9:
			return 2;
		default:
			return EMPTY;
	}
}


/*
 *
 */
int get_input_y (int p) {
	switch (p) {
		case 1:
		case 4:
		case 7:
			return 0;
		case 2:
		case 5:
		case 8:
			return 1;
		case 3:
		case 6:
		case 9:
			return 2;
		default:
			return EMPTY;
	}
}


/*
 *
 */
void play (tris match) {
	int counter = 0;
	int winner = EMPTY;

	while ( counter < 9 ) {
		gui_clear_screen();
		gui_print_game(match);

		int player = counter % 2;

		gui_print_shift (match, player);

		int m = -1;

		do {
			if (m == ERR_NOT_VALID_MOVE) {
				gui_err_not_valid_move();
			}

			int pos = get_input_move();

			int x = get_input_x(pos);
			int y = get_input_y(pos);

			m = move(&match, player, x, y);
		} while (m == ERR_NOT_VALID_MOVE);

		if (m == NO_WINNER) {
			counter++;
		} else {
			winner = m;
			break;
		}
	}

	gui_clear_screen();
	gui_print_game(match);
	gui_print_result(match, winner);
}


int main(int argc, char* argv[]) {
	if (argc != 3) {
		gui_no_user_input();
		return ERR_NO_USER;
	}

	gui_welcome();

	play(init(argv[1], argv[2]));

	return 0;
}
