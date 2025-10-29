#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void debugmode(string state, string mode, string location) {
    cout << "State: " << state  << endl;
    cout << "Mode: " << mode  << endl;
    cout << "Location: " << location << endl;
    cout << endl;
}

void main_menu() {
    system("cls");

    cout << setw(24) << setfill('*') << " Main Menu ";
}

int main() {
    bool game_over = false;
    bool game_active = true;
    string game_mode = "menu", game_state = "main_menu", game_location = "main menu";

    //notes on what to implement
    // function that when game start it opens saved info
    //function that displays gui secretly, rooms as functions




    main_menu();

    return 0;
}

void GameOver() {}
void GameStart() {}
