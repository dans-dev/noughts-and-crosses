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

// Main function to run the game.
int main() {

    setlocale(LC_CTYPE, ""); // Adds unicode character support by setting locale.
    initscr();
    noecho();
    start_color();

    draw_grid(0,0);
    int input = getch();
    endwin();

}