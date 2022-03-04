#include <iostream>

#include "game_lib.h"
#include "partita.h"

void print_result ( const std::string winner ) {
    if (winner.length() > 0) {
        std::cout << "Fine! Ha vinto " << winner << std::endl;
    } else {
        std::cout << "Fine! Partita pari" << std::endl;
    }
}
int get_in_mossa () {
    int x;
    std::cout << "> ";
    std::cin >> x;
    return x;
}
int get_in_x (int p) {
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
            return -1;
    }
}

int get_in_y (int p) {
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
            return -1;
    }
}

partita pre_start () {
    std::string p1;
    std::string p2;
    std::cout << "Giocatore 1: ";
    std::cin >> p1;
    std::cout << "Giocatore 2: ";
    std::cin >> p2;

    return partita(p1, p2);
}

void gioca (partita p) {
    int counter = 0;
    int winner = -1;

    while (counter < 9) {
        clear();
        p.print_game();
        int player = counter % 2;
        std::cout << "Turno di " << p.get_player(player) << ": [0-2 per x; 0-2 per y]" << std::endl;

        int m = -1;
        do {
            if (m == 2) {
                std::cout << "Mossa non valida, riprova: " << std::endl;
            }
            int pos = get_in_mossa();
            int x = get_in_x(pos);
            int y = get_in_y(pos);

            m = p.mossa(player, x, y);
        } while (m == 2);

        if (m == -1) {
            counter++;
        } else {
            winner = m;
            break;
        }
    }

    clear();
    p.print_game();
    print_result(p.get_player(winner));
}

int main() {
    std::cout << "Hello, tris!!" << std::endl;

    gioca (pre_start());

    return 0;
}