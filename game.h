#include <stdio.h>

#ifndef SRC_PARTITA_H_
#define SRC_PARTITA_H_

#define ERR_NOT_VALID_INPUT -4
#define ERR_NO_USER			-3
#define ERR_NOT_VALID_MOVE	-2
#define EMPTY				-1

#define VALID_MOVE			10
#define NO_WINNER			11

#define PLAYER_1	0
#define PLAYER_2	1


/**
 *
 */
typedef struct tris {
	int game_[3][3];
	int shift_number_;
	char players_[2][100];
} tris;


/**
 *
 */
tris init(char* user_1, char* user_2);


/**
 *
 */
void set_username (tris match, char* user1, char* user2);


/**
 *
 */
int move (tris* match, int player, int i, int j);


/**
 *
 */
int check_move (const tris* match, int i, int j);


/**
 *
 */
int check_winner (const tris* match, int player, int i, int j);


/**
 *
 */
int check_vertical (const tris* match, int player, int i, int j);


/**
 *
 */
int check_horizontal (const tris* match, int player, int i, int j);


/**
 *
 */
int check_diagonals (const tris* match, int player, int i, int j);

#endif /* SRC_PARTITA_H_ */


