//
//  main.c
//  bodhi-tris
//
//  Created by Matteo Fiori on 19/05/22.
//

#include <stdio.h>
#include <string.h>
#include "tris.h"
#include "cgui.h"


/*
 *
    funzione main:
 
    ./tris nome_giocatore server
        -> avvia server e rimane in attesa di un giocatore su una porta prestabilita
    ./tris nome_giocatore connect
        -> restituisce una lista di server connessi
        -> da digitare in input il nome del server o il numero della lista del server
        -> si connette e inizia il gioco
 
 
 */
int main(int argc, char* argv[]) {

    if (argc != 3) {
        gui_no_user_input();
        return ERR_NO_USER;
    }

    /* choose input type */
    if (strcmp (argv[2], "server") == 0) {
        return init_server_mode (init(argv[1]));   // -> passa a init_server_mode la partita tris
    } else if (strcmp (argv[2], "connect") == 0) {
        // lista di server, quando ti connetti entri con il nome del giocatore
        
        return init_client_mode(argc, argv);
    } else {
        return ERR_NOT_VALID_INPUT;
    }



    //gui_welcome();

    //play(init(argv[1], argv[2]));

    return 0;
}
