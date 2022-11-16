#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "XO_Classes.hpp"
using namespace std;
comuterPlayer::comuterPlayer(char symbol) : Player(symbol) {
    name = "Computer";
}
void comuterPlayer::get_move(int& x, int& y) {
    cout <<"\nComputer is thinking...\n";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 2);
    x = dis(gen);
    y = dis(gen);
}
string comuterPlayer::to_string() {
    return "Player: " + name;
}