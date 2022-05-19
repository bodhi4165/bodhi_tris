#ifndef SRC_CGUI_H_
#define SRC_CGUI_H_

/**
 *
 */
void gui_print_game (const tris match);


/**
 *
 */
void gui_clear_screen();


/**
 *
 */
void gui_print_result (tris match, int winner);


/**
 *
 */
char gui_decode_player_cell (int m);


/**
 *
 */
void gui_print_shift (const tris match, int player);

/**
 *
 */
void gui_err_not_valid_move ();


/**
 *
 */
void gui_no_user_input();


/**
 *
 */
void gui_welcome();


/**
 *
 */
void gui_net_waiting_players();

#endif /* SRC_CGUI_H_ */
