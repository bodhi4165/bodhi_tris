#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

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


/*
 *
 */
int init_server_mode (int argc, char* argv[]) {
	gui_welcome();

	int socket_desc , client_sock , c , read_size;
	struct sockaddr_in server , client;
	char client_match[10];

	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1) {
		printf("Could not create socket");
	}
	puts("Socket created");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );

	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
		//print the error message
		perror("bind failed. Error");
		return 1;
	}
	//Listen
	listen(socket_desc , 3);

	//Accept and incoming connection
	gui_net_waiting_players()

	c = sizeof(struct sockaddr_in);

	//accept connection from an incoming client
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0) {
		perror("accept failed");
		return 1;
	}

	puts("Connection accepted");

	//Receive a message from client
	while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 ) {
		char* new_message = "ho capio, cambiemo un po";

		//Send the message back to client
		write(client_sock , new_message , strlen(new_message));

		printf("ho inviato: %s\n", new_message);
		printf("e ho ricevuto: %s\n", client_message);

		memset(client_message,0,100);
	}

	if(read_size == 0) {
		puts("Client disconnected");
		fflush(stdout);
	} else if(read_size == -1) {
		perror("recv failed");
	}

	return 0;
}


/*
 *
 */
int init_client_mode (int argc, char* argv[]) {
	gui_welcome();

	int sock;
	struct sockaddr_in server;
	char message[1000] , server_reply[2000];

	//Create socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1) {
		printf("Could not create socket");
	}
	puts("Socket created");

	// TODO -> cercare all'interno della rete
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888 );

	//Connect to remote server
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
		perror("connect failed. Error");
		return 1;
	}

	puts("Connected\n");

	//keep communicating with server
	while(1) {

		message = "";

		printf("Enter message : ");
		scanf("%s" , message);


		if (strcmp(message, "quit") == 0) {

			close(sock);
			break;
		}

		//Send some data
		if( send(sock , message , strlen(message) , 0) < 0){
			puts("Send failed");
			return 1;
		}

		int read_serv = 0;
		//Receive a reply from the server
		if( (read_serv = recv(sock , server_reply , 2000 , 0)) < 0) {
			puts("recv failed");
			break;
		}

		if (read_serv > 0) {
			puts("sleep...");
			sleep(10);
		}
		puts("Server reply :");
		puts(server_reply);
	}

	close(sock);

	return 0;
}


/*
 *
 */
int main(int argc, char* argv[]) {

	if (argc != 3) {
		gui_no_user_input();
		return ERR_NO_USER;
	}

	/* choose input type */
	if (strcmp (argv[2], "server") == 0) {
		return init_server_mode (argc, argv);
	} else if (strcmp (argv[2], "connect") == 0) {
		return init_client_mode(argc, argv);
	} else {
		return ERR_NOT_VALID_INPUT;
	}



	//gui_welcome();

	//play(init(argv[1], argv[2]));

	return 0;
}
