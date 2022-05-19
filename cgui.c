#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"
#include "cgui.h"

/*
 *
 */
void gui_print_game (const tris match) {
    printf("-------------          help: -------------\n");

    printf("| %c | %c | %c |", gui_decode_player_cell(match.game_[0][0]), gui_decode_player_cell(match.game_[0][1]), gui_decode_player_cell(match.game_[0][2]));
    printf("                | 1 | 2 | 3 |\n");

    printf("-------------");
    printf("                -------------\n");

    printf("| %c | %c | %c |", gui_decode_player_cell(match.game_[1][0]), gui_decode_player_cell(match.game_[1][1]), gui_decode_player_cell(match.game_[1][2]));
    printf("                | 4 | 5 | 6 |\n");

    printf("-------------");
    printf("                -------------\n");

    printf("| %c | %c | %c |", gui_decode_player_cell(match.game_[2][0]), gui_decode_player_cell(match.game_[2][1]), gui_decode_player_cell(match.game_[2][2]));
    printf("                | 7 | 8 | 9 |\n");
    printf("-------------");
    printf("                -------------\n");
}


/*
 *
 */
void gui_clear_screen() {
    printf("\x1B[2J\x1B[H");
}


/*
 *
 */
void gui_print_result (tris match, int winner) {
	const char* s_winner = match.players_[winner];

	if (strlen (s_winner) > 0) {
		printf("End! %s it's the winner!\n", s_winner);
	} else {
		printf("End! The game ended in a draw\n");
	}
}


/*
 *
 */
char gui_decode_player_cell (int m) {
	switch (m) {
		case PLAYER_1:
			return 'X';
		case PLAYER_2:
			return 'O';
		default:
			return ' ';
	}
}


/*
 *
 */
void gui_print_shift (const tris match, int player) {
	printf("It's turn of %s: [0-2 per x; 0-2 per y] ", match.players_[player]);
}


/*
 *
 */
void gui_err_not_valid_move () {
	printf("Not valid move. Retry\n");
}


/*
 *
 */
void gui_no_user_input() {
	printf("No user input. retry with \"./tris user1 user2\"\n");
}


/*
 *
 */
void gui_welcome() {
	printf("Hello! play tris!\n");
}


/*
 *
 */
void gui_net_waiting_players() {
	printf("waiting for other players...");
}
