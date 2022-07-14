/*
 * tris.h
 *
 *  Created on: 3 mag 2022
 *      Author: bodhi
 */

#ifndef SRC_TRIS_H_
#define SRC_TRIS_H_

#include "game.h"

#define SERVER_MODE server
#define CLIENT_MODE connect
/**
 *
 */
int get_input_move(void);


/**
 *
 */
int get_input_x(int p);


/**
 *
 */
int get_input_y(int p);


/**
 *
 */
void play(tris match);


/***************
 * online game *
 ***************/

/**
 *
 */
int init_server_mode (tris match);


/**
 *
 */
int init_client_mode (int argc, char* argv[]);

#endif /* SRC_TRIS_H_ */
