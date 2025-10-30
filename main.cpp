#include <iostream>
#include <string>
using namespace std;

int main() {
    bool game_over = false, game_active = false;

    string game_mode = "menu", game_state = "main_menu", game_location = "main menu";

    //notes on what to implement
    // function that when game start it opens saved info
    //function that displays gui secretly, rooms as functions

    do
    {
        system("cls");
        cout << "*********************" << endl;
        cout << "Main Menu" << endl;
        cout << "*********************" << endl;

        cout << "1. Start Game" << endl << endl;
        cout << "2. Exit" << endl << endl;

        int choice;
        cin >> choice;
    } while (!game_active);

    return 0;
}