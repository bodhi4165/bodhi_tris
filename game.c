#include "game.h"

#include <stdio.h>
#include <string.h>

/*
 *
 */
tris init (char* user_1, char* user_2) {
	tris match;
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			match.game_[i][j] = -1;
		}
	}
	match.shift_number_ = 0;

	strcpy(match.players_[0], user_1);
	strcpy(match.players_[1], user_2);

	return match;
}

/*
 *
 */
void set_username ( tris match, char* user_1, char* user_2 ) {
	strcpy(match.players_[PLAYER_1], user_1);
	strcpy(match.players_[PLAYER_2], user_2);
}

/*
 *
 */
int move ( tris* match, int player, int i,int j) {
	if (check_move(match, i, j) != VALID_MOVE) {
		return ERR_NOT_VALID_MOVE;
	}

	match->game_[i][j] = player;
	match->shift_number_++;

	return check_winner(match, player, i, j);
}


/*
 *
 */
int check_move ( const tris* match, int i, int j) {
	if (i < 0 || i > 2) {
		return ERR_NOT_VALID_MOVE;
	} else if ( j < 0 || j > 2 ) {
		return ERR_NOT_VALID_MOVE;
	} else if (match->game_[i][j] != EMPTY) {
		return ERR_NOT_VALID_MOVE;
	} else {
		return VALID_MOVE;
	}
}


/*
 *
 */
int check_winner (const tris* match, int player, int i, int j) {
	int cnt_oriz = check_horizontal (match, player, i, j);
    int cnt_vert = check_vertical (match, player, i, j);
    int cnt_diag = check_diagonals (match, player, i, j);

    if (cnt_oriz == 3 || cnt_vert == 3 || cnt_diag == 3) {
        return player;
    } else {
        return NO_WINNER;
    }
}


/*
 *
 */
int check_vertical (const tris* match, int player, int i, int j) {
	int tot_players = 0;

	for (int h = 0; h < 3; h++) {
		if (i == h) {
			tot_players++;
		} else {
			if (match->game_[h][j] == player) {
				tot_players++;
			}
		}
	}

	return tot_players;
}


/*
 *
 */
int check_horizontal (const tris* match, int player, int i, int j) {
	int tot_players = 0;

	for (int h = 0; h < 3; h++) {
		if (h == j) {
			tot_players++;
		} else {
			if (match->game_[i][h] == player) {
				tot_players++;
			}
		}
	}

	return tot_players;
}


/*
 *
 */
int check_diagonals (const tris* match, int player, int i, int j) {
	int tot_diag_1 = 0;
	int tot_diag_2 = 0;

	if (i == j) {
		for (int h = 0; h < 3; h++) {
			if (h == i || h == j) {
				tot_diag_1++;
			} else {
				if (match->game_[h][h] == player) {
					tot_diag_1++;
				}
			}
		}
	}

	if ( (i == 0 && j == 2) || (i == 2 && j == 0) || (i == 1 && j == 1)) {
		int c_i = 0;
		int c_j = 2;

		for (int h = 0; h < 3; h++) {
			if(match->game_[c_i++][c_j--] == player) {
				tot_diag_2++;
			}

		}
	}

	if (tot_diag_1 == 3) {
		return tot_diag_1;
	} else if (tot_diag_2 == 3) {
		return tot_diag_2;
	} else {
		return tot_diag_1;
	}
}
