// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include"XO_Classes.hpp"
using namespace std;
void GameManager::run() {
    Board x_o;
    int x, y;
    cout << "Welcome to the game of X and O" << endl;
    cout << "to player with computer enter 1, to play with another player enter 2: ";
    int n_players=1;
    cin >> n_players;
    if(n_players==1){
        Player *player1 = new Player('X');
        Player *player2 ;
        comuterPlayer *player_2 = new comuterPlayer('O');
        player2 = player_2;
        x_o.display_board();
        while (x_o.get_n_moves() < 9) {
            player1->get_move(x, y);
            if (x_o.update_board(x, y, player1->get_symbol())) {
                x_o.display_board();
                if (x_o.is_winner()) {
                    cout << player1->to_string() << " is the winner" << endl;
                    break;
                }
            }
            else {
                cout << "Invalid move. Try again" << endl;
                continue;
            }
            player2->get_move(x, y);
            if (x_o.update_board(x, y, player2->get_symbol())) {
                x_o.display_board();
                if (x_o.is_winner()) {
                    cout << player2->to_string() << " is the winner" << endl;
                    break;
                }
            }
            else {
              while (! x_o.update_board(x, y, player2->get_symbol())) {
                player2->get_move(x, y);
              }
            }
        }
        delete player1;
        delete player2;
    }
    else if(n_players==2){
        Player players[2] = {Player (1, 'x'), Player (2, 'o')};
        x_o.display_board();
        while (true) {
            for (int i:{0,1}) {
                players[i].get_move(x, y);
                while (!x_o.update_board (x, y, players[i].get_symbol())){
                    players[i].get_move(x, y);
                }
                x_o.display_board();
                if (x_o.is_winner()){
                    cout  << players[i].to_string() << " wins\n";
                    return;
                }
                if (x_o.is_draw()){
                    cout << "Draw!\n";
                    return;
                }
            }
        }
    }
    else{
        cout << "Invalid input" << endl;
    }
}

