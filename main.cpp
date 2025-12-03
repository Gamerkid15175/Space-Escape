#include <iostream>
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib>

#pragma comment(lib, "winmm.lib")

using namespace std;

void mainmenu();
void help();
void game_PlaySound(string sound);
void Startup(bool game_firstStartup);
void RoomFunction(string action, string currentroom);
void LivingQuarters(string action);
void Hallway(string action);

string currentRoom;

int main() {
    bool game_over = false, game_active = false, firstStartup = true;

    string game_mode = "menu", game_state = "main_menu", game_location = "main menu";


    //notes on what to implement
    //function that when game start it opens saved info
    //rooms as functions


    // To-Do
    // 11-2-25 Add global bools for each room, first time in room? if so play first entrance sequence, if no then play standard sequence.
    // Thinking about changing story to my trauma team story.

    mainmenu();


    game_location = "Living Quarters";
    Startup(firstStartup);
    game_active = true;
    //Game Loop
    while(game_active) {
        cout << currentRoom << endl;

        string choice;
        getline(cin, choice);

        //do what when typed
        if (choice == "help") { //when typed help , print commands
            help();
        }
        else if (choice == "inspect") {
            cout << "Inspecting Item Function" << endl;
        }
        else if (choice == "take item") {
            cout << "take Item Funtion" << endl;
        }
        else if (choice == "use") {
            cout << "Use Item Function" << endl;
        }
        else if (choice == "inv") {
            cout << "show Inventory Function" << endl;
        }
        else if (choice == "quit") {
            game_active = false;
        }
        else {
            RoomFunction(choice, currentRoom); //get current room and do action from commands list
        }
    }

    return 0;
}


void mainmenu() {
    bool game_active;
    game_PlaySound("menu");
    do {
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
                currentRoom = "LivingQuarters";
                break;
            case 2:
                exit(0);
                break;
            case 3:
                help();
                break;
        }
    } while (!game_active);
}

void help() {
    cout << "\33[31m- look       \33[0m\>describe your current surroundings" << endl;
    cout << "\33[31m- go [dir]   \33[0m\>go north, south, east, or west" << endl;
    cout << "\33[31m- inspect    \33[0m\>check an object more closely" << endl;
    cout << "\33[31m- take [item]\33[0m\>pick up an object" << endl;
    cout << "\33[31m- use [item] \33[0m\>use an item in your inventory" << endl;
    cout << "\33[31m- inv        \33[0m\>view items you are carrying" << endl;
    cout << "\33[31m- help       \33[0m\>print commands" << endl;
    cout << "\33[31m- quit       \33[0m\>exit game" << endl;
    cin.get();

}

void game_PlaySound(string sound) {
    if (sound == "notify")
    {
        PlaySound(TEXT("sounds\\notify.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    if(sound == "menu")
    {
    PlaySound(TEXT("sounds\\facades.wav"), NULL, SND_ASYNC);
    }

}

void Startup(bool game_firstStartup) {
    //function that check if its your first startup, if so do the initial startup sequence
    if (game_firstStartup) {
        string choice;
        system("CLS");
        cout << "[BOOT SEQUENCE INITIALIZING...]" << endl;
        Sleep(2000);
        cout << "[CRYOPOD STATUS: STABLE]" << endl;
        Sleep(2000);
        cout << "[TEMPERATURE: -142°C]" << endl;
        Sleep(1000);
        cout << "[CREW MEMBER: UNKNOWN - LIFE SIGNS DETECTED]" << endl;
        Sleep(3000);


        cout << endl << endl << endl;
        //dialogue
        cout << "Darkness." << Sleep(2000)<< "Silence. " << endl;
        Sleep(1000);

        cout << "You float in half-conscious thought, your mind flickering between dreams and static." << endl;
        cout << "Something..."; Sleep(1000);
        cout << " is wrong. You can feel the hum of machinery dying around you." << endl << endl;

        cout << "> You are trapped in a cryopod." << endl;
        cout << ">Type \"wake\" to attempt to exit cyrosleep." << endl ;

        do {
            cin >> choice;
        }while (choice != "wake");
        system("CLS");
        cout << "You strain to move, but your body doesn’t respond." << endl;
        cout << "A dull ache spreads through your chest — your heartbeat slow and heavy." << endl << endl;

        cout << "[WARNING: CORE POWER FAILURE]"<< endl;
        cout << "[MANUAL OVERRIDE REQUIRED]" << endl << endl;

        cout << "Your eyelids flutter open briefly." << endl;
        cout << "The cryopod glass is fractured. Ice crystals bloom across your vision." << endl << endl;

        cout << "You try to remember your name, but all you hear is the alarm tone, muffled and distant." << endl << endl;

        cout << "> Try again?" << endl;

        do {
            cin >> choice;
        }while (choice != "wake");
        system("CLS");

        cout << "[OVERRIDE ACCEPTED...]"<< endl;
        cout << "[HEATING ELEMENTS ENGAGED]"<< endl;
        cout << "[DECOMPRESSING CHAMBER...]"<< endl << endl;

        cout << "A hiss of vapor erupts around you. The glass door jerks open violently, releasing a rush of freezing mist."<< endl;
        cout << "You collapse forward, coughing—lungs burning, muscles trembling."<< endl << endl;

        cout << "The floor is cold steel. You drag yourself upright, gasping for air."<< endl << endl;

        cout << "Rows of other cryopods line the room—dark, lifeless."<< endl;
        cout << "Only yours glows faintly."<< endl << endl
        ;
        cout << "A faint terminal light flickers nearby, casting green across the frost."<< endl << endl;

        cout << "> Type \"look\" to examine your surroundings."<< endl;

        //player has too type help fist then after reading the commands type look; then begin play

        cout << "**type \"look\" to start the game." << endl;
        cin>>choice;
    }
}

void RoomFunction(string action,string currentroom) {
    //RoomFunction should control the flow of everyroom
    if (currentroom == "LivingQuarters") {
        LivingQuarters(action);
    }
    if (currentroom == "Hallway") {
        Hallway(action);
    }
}



void LivingQuarters(string action) {
    currentRoom = "LivingQuarters";
    if (action == "look") {
        cout << "You are on the living quarters." << endl;
        cout << "The room is dim and cold. A few items float weightlessly -- a notebook, a cracked visor." << endl;
        cout << "To the north, the automatic door to the main hallway flickers with weak blue light." << endl;
        cout << "A small terminal glows beside your bed." << endl;
        Sleep(4);
    }
    if (action == "go north") {
        currentRoom = "Hallway";
    }
    else {
        cout << "You are on the living quarters." << endl;
        cout << "The room is dim and cold. A few items float weightlessly -- a notebook, a cracked visor." << endl;
        cout << "To the north, the automatic door to the main hallway flickers with weak blue light." << endl;
        cout << "A small terminal glows beside your bed." << endl;
    }
}
void Hallway(string action) {
    currentRoom = "Hallway";
    if (action == "look") {
        cout << "You are on the hallways." << endl;
    }

    // [DOOR OVERRIDE IN PROGRESS...]
    // [ACCESS GRANTED - LIMITED POWER MODE]
    //
    // The door grinds open halfway before stopping. You squeeze through into the main hallway.
    //
    // Cold air rushes past you. The lights flicker in and out, revealing flashes of chaos—
    // floating papers, shattered panels, and streaks of dark fluid along the walls.
    //
    // A faint electrical hum echoes from the east.
    //
    // > To the east: the Power Core Chamber.
    // > To the west: the Command Deck.
    // > Behind you: the Sleeping Quarters.
    //
    // A damaged maintenance drone lies on the floor, sparks dancing across its frame.
    //
    // [TERMINAL NOTE FOUND - LOG 3/7]
    // "Power fluctuations detected in Reactor Node B. Engineering lockdown initiated.
    // Security Chief ordered keycards restricted to authorized personnel only."
    //
    // You notice a **keycard slot** beside the Power Core door—dark and unresponsive.
    //
    // The console blinks weakly with a prompt:
    //   > "Insert Level-1 Access Card to continue."


    //if the player tries to go east without the keycard:
    //
    // [ACCESS DENIED]
    // The Power Core door remains sealed. A faint red light pulses next to the keycard reader.
    // You’ll need to find a Level-1 Access Card.
}
