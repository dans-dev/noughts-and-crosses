#include <ncurses.h>
#include <locale.h>


// Draws the noughts and crosses grid from positions x and y in the terminal.
void draw_grid(int x, int y) {

    for (int i = 0; i < 3; i++) {
        move(y+(i*2), x);
        printw("   ┃   ┃ ");
    }

    for (int i = 0; i < 2; i++) {
        move(y+1+(i*2), x);
        printw("━━━╋━━━╋━━━");
    }

}


// Fills the noughts and crosses grid with the noughts and the crosses.
void fill_grid(int x, int y, int items[9]) {

    int i = 0;
    int j = 0;

    for (int index = 0; index < 9; index++) {

        // Logic to position the items into the grid
        move(y+(2*j), x+1+(4*i)); // the 2*j and 1+(4*i) are derived from drawing the grid and counting characters
        i++;
        if ((index+1) % 3 == 0) j++; // if the index indicates it is the last item of the row, it moves j to the next column
        if (i > 2) i = 0; // if the i indicates it is the last item of the row, then it is set back to the first

        switch (items[index]) {
            case 0:
                printw(" ");
                break;
            case 1:
                printw("X");
                break;
            case 2:
                printw("O");
                break;
        }
    }
}


// Draws the menu to the screen.
void draw_menu(int option) {

    move(1,2);
    printw("__   __           _____");
    move(2,2);
    printw("\\ \\ / /   ___    |  _  |");
    move(3,2);
    printw(" \\ V /   ( _ )   | | | | ");
    move(4,2);
    printw(" /   \\   / _ \\/\\ | | | | ");
    move(5,2);
    printw("/ /^\\ \\ | (_>  < \\ \\_/ / ");
    move(6,2);
    printw("\\/   \\/  \\___/\\/  \\___/  ");
    move(8,4);
    printw("Play a Human");
    move(10,4);
    printw("Play a Bot (Easy)");
    move(12,4);
    printw("Play a Bot (Medium)");
    move(14,4);
    printw("Play a Bot (Hard)");
    move(8+option*2, 2);                   
}


// Makes use of the terminal cursor and draws a block where the cursor is positioned.
void draw_cursor(int cursorX, int cursorY, int gridX, int gridY) {

    move(gridY+(2*cursorY), gridX+1+(4*cursorX));
    printw("█");
}


// Manages user input for the 4 different play modes.
void handle_user(int player, int input, int * cursorX, int * cursorY, int * items) {

    switch(input) {
        case 'w':
        case KEY_UP:

            break;
                    
        case 's':
        case KEY_DOWN:
            break;

        case 'a':
        case KEY_LEFT:
            break;

        case 'd':
        case KEY_RIGHT:
            break;
        
        case ' ':
            break;
    }

}


// Main function to run the game.
int main() {

    setlocale(LC_CTYPE, ""); // Adds unicode character support by setting locale.
    initscr();
    timeout(0);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    start_color(); // Allows colour to be used in future.

    int mode = 0; // (0, main menu) (1, PvP) (2, PvE easy) (3, PvE medium) (4, PvE hard) (5, result screen) (6, end)
    int option = 0;
    int input = 0;
    int player = 1;
    int cursorX = 1;
    int cursorY = 1;
    int items[9] = {0};
    int gridX = 1;
    int gridY = 1;

    while(mode != 6) {
        switch(mode) {
            case 0:
                draw_menu(option);

                switch(input) { // Keyboard logic for main menu

                    case 'w':
                    case KEY_UP:
                        option--;
                        if (option < 0) option = 3;
                        break;
                    
                    case 's':
                    case KEY_DOWN:
                        option++;
                        if (option > 3) option = 0;
                        break;

                    case ' ':
                        mode = option+1;
                        break;
                }

            case 1:
                draw_grid(gridX, gridY);
                fill_grid(gridX, gridY, items);
                break;

        }

        input =  wgetch(stdscr);
        refresh();
        erase();
    }
    
    endwin();

}
