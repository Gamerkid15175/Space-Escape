#include <iostream>
#include <string>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

using namespace std;

void help() {
//     - look       → describe your current surroundings
//     - go [dir]   → move north, south, east, or west
//     - inspect    → check an object more closely
//     - take [item]→ pick up an object
//     - use [item] → use an item in your inventory
//     - inv        → view items you are carrying
//     - quit       → exit game
}

void game_PlaySound(string sound) {
    if (sound == "notify")
    {PlaySound(TEXT("sounds\\notify.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }

}

void Startup(bool game_firstStartup) {
    if (game_firstStartup) {
        cout << "[INITIALIZING TERMINAL CONNECTION...]" << endl;
        Sleep(2000);
        cout << "[CONNECTION ESTABLISHED]" << endl;
        Sleep(6000);
        cout << "[STATION: ASTRA-7 ORBITAL RESEARCH FACILITY]" << endl;
        Sleep(1000);
        cout << "[ALERT: LIFE SUPPORT FAILURE DETECTED]" << endl;
        game_PlaySound("notify");
        Sleep(1000);
        cout << "[ALERT: POWER SYSTEMS AT 12% CAPACITY]" << endl;
        game_PlaySound("notify");
        Sleep(1000);
        cout << "[ALERT: ESCAPE SHUTTLE OFFLINE]" << endl << endl;
        game_PlaySound("notify");
        Sleep(1000);

        for (int i = 0 ; i < 4 ; i++) {
            Sleep(1000);
            cout << ".";
        }

        cout << endl << endl << endl;
        cout << "You wake to the sound of distant alarms and flickering emergency lights." << endl;
        cout << "The air tastes metallic. Gravity is unstable—tools float, then clatter to the floor." << endl << endl;

        cout << "A voice crackles through the intercom, distorted and fragmented:" << endl << endl;

        cout << "\"—crew of Astra-7... catastrophic failure in primary reactor..." << endl;
        cout << "all personnel must evacuate immediately...\"" << endl << endl;

        cout << "The message loops once, then dies in static." << endl << endl;

        cout << "You are alone in your sleeping quarters." << endl;
        cout << "The door to the hallway hums faintly, half-powered." << endl << endl;

        cout << "> A terminal panel nearby flickers with a prompt:" << endl;
        cout << "**Type \"help\" for a list of available commands.**" << endl;
;
        string choice;
        cin >> choice;

        if (choice == "help") {
            system("cls");
            help();
        }
    }
    // cout << "" << endl;
// You wake to the sound of distant alarms and flickering emergency lights.
// The air tastes metallic. Gravity is unstable—tools float, then clatter to the floor.
//
// A voice crackles through the intercom, distorted and fragmented:
//
//    "—crew of Astra-7... catastrophic failure in primary reactor...
//     all personnel must evacuate immediately..."
//
// The message loops once, then dies in static.
//
// You are alone in your sleeping quarters.
// The door to the hallway hums faintly, half-powered.
//
// > A terminal panel nearby flickers with a prompt:
//   **Type "help" for a list of available commands.**


}

int main() {
    bool game_over = false, game_active = false, firstStartup = true;

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

        switch (choice) {
            case 1:
                game_active = true;
                break;
            case 2:
                return 0;
                break;
        }
    } while (!game_active);

    game_location = "Living Quarters";
    Startup(firstStartup);

    return 0;
}