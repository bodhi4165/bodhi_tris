//
// Created by bodhi
//
#include "partita.h"
#include <iostream>

partita::partita() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game_[i][j] = -1;
        }
    }
    num_turni_ = 0;
}

partita::partita (std::string player1, std::string player2) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game_[i][j] = -1;
        }
    }
    players_[0] = player1;
    players_[1] = player2;
    num_turni_ = 0;
}
/*
void partita::print_game() {
    std::cout << "-------------" << std::endl;
    std::cout << "| " << encode_player_turn(game_[0][0]) << " | "
                      << encode_player_turn(game_[0][1]) << " | "
                      << encode_player_turn(game_[0][2]) << " |" << std::endl;
    std::cout << "-------------" << std::endl;
    std::cout << "| " << encode_player_turn(game_[1][0]) << " | "
                      << encode_player_turn(game_[1][1]) << " | "
                      << encode_player_turn(game_[1][2]) << " |" <<  std::endl;
    std::cout << "-------------" << std::endl;
    std::cout << "| " << encode_player_turn(game_[2][0]) << " | "
                      << encode_player_turn(game_[2][1]) << " | "
                      << encode_player_turn(game_[2][2]) << " |" <<  std::endl;
    std::cout << "-------------" << std::endl;
}
 */

void partita::print_game() {
    std::cout << "-------------" << "          help: " << "-------------" << std::endl;

    std::cout << "| " << encode_player_turn(game_[0][0]) << " | "
              << encode_player_turn(game_[0][1]) << " | "
              << encode_player_turn(game_[0][2]) << " |" << "                | 1 | 2 | 3 |" << std::endl;
    std::cout << "-------------" << "                " << "-------------" << std::endl;
    std::cout << "| " << encode_player_turn(game_[1][0]) << " | "
              << encode_player_turn(game_[1][1]) << " | "
              << encode_player_turn(game_[1][2]) << " |" << "                | 4 | 5 | 6 |" << std::endl;
    std::cout << "-------------" << "                " << "-------------" << std::endl;
    std::cout << "| " << encode_player_turn(game_[2][0]) << " | "
              << encode_player_turn(game_[2][1]) << " | "
              << encode_player_turn(game_[2][2]) << " |" << "                | 7 | 8 | 9 |" << std::endl;
    std::cout << "-------------" << "                " << "-------------" << std::endl;
}

std::string partita::get_player (int n) {
    return players_[n];
}

char partita::encode_player_turn (int m) {
    switch (m) {
        case 0:
            return 'X';
        case 1:
            return 'O';
        default:
            return ' ';
    }
}

/*
 * return:
 *      -1 - continue
 *       0 - win player 0 (X)
 *       1 - win player 1 (O)
 */
int partita::check_vittoria (int player, int i, int j) {
    // contatori vittoria
    int cnt_oriz = 0;
    int cnt_vert = 0;
    int cnt_diag_1 = 0;
    int cnt_diag_2 = 0;

    int c_i = 0;
    int c_j = 2;
    for ( int h = 0; h < 3; h++ ) {
        if ((i == 0 && j == 2) || (i == 2 && j == 0) || (i == 1 && j == 1)) {
            if (c_i == i && c_j == j) {
                cnt_diag_2++;
                c_i++;
                c_j--;
            } else {
                if (game_[c_i++][c_j--] == player) {
                    cnt_diag_2++;
                }
            }
        }
        else {
            //check orizzontali
            if (h == i && game_[i][h] == player) {
                cnt_oriz++;
            } else {
                if (game_[i][h] == player) {
                    cnt_oriz++;
                }
            }

            // check verticali
            if (h == j && game_[j][h] == player) {
                cnt_vert++;
            } else {
                if (game_[j][h] == player) {
                    cnt_vert++;
                }
            }

            // check diag 1
            if (i == j) {
                if (h == i) {
                    cnt_diag_1++;
                } else {
                    if (game_[h][h] == player) {
                        cnt_diag_1++;
                    }
                }
            }
        }
    }

    if (cnt_oriz == 3 || cnt_vert == 3 || cnt_diag_1 == 3 || cnt_diag_2 == 3) {
        return player;
    } else {
        return -1;
    }
}

/*
 *  return:
 *      0 - ok
 *      -1 - mossa non consentita
 */
int partita::check_mossa (int i, int j) {
    if (i < 0 || i > 2) {
        return 2;
    } else if (j < 0 || j > 2) {
        return 2;
    } else if (game_[i][j] != -1) {
        return 2;
    } else {
        return 0;
    }
}

/*
*    return:
*      -1 - continue
*       0 - win player 1
*       1 - win player 2
*       2 - errore - mossa non consentita
*/
int partita::mossa (int player, int i, int j) {
    if (check_mossa(i, j) != 0) {
        return 2;
    }

    game_[i][j] = player;
    num_turni_++;

    return check_vittoria(player, i, j);
}