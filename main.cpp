#include <iostream>

using namespace std;
int main() {
    bool game_over = false;
    bool game_active = true;

    cout << R"(____ ___  ____ ____ ____    ____ _  _ ____ ____ ____ ____ _  _ ____ _   _
[__  |__] |__| |    |___    |___ |\/| |___ |__/ | __ |___ |\ | |     \_/
___] |    |  | |___ |___    |___ |  | |___ |  \ |__] |___ | \| |___   |  )" << endl;

    int counter = 0;
    while(game_active) {
        cout << "Main Menu" << endl << endl << endl;
        counter++;

        if(counter == 2000) {break;}
    }

    return 0;
}
