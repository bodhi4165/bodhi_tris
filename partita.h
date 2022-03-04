//
// Created by bodhi
//

#ifndef TRIS_PARTITA_H
#define TRIS_PARTITA_H
#include <string>

class partita {
public:
    partita();
    partita (std::string player1,std::string player2);
    int mossa (int player, int i, int j);
    std::string get_player (int n);
    void print_game();
private:
    int game_[3][3];
    int num_turni_;
    std::string players_[2];

    int check_vittoria (int player, int i, int j);
    int check_mossa (int i, int j);
    char encode_player_turn (int m);
};
#endif //TRIS_PARTITA_H
