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

// Main function to run the game.
int main() {

    setlocale(LC_CTYPE, ""); // Adds unicode character support by setting locale.
    initscr();
    noecho();
    start_color(); // Allows colour to be used in future.

    int items[9] = {1, 2, 0, 0, 1, 2, 2, 0, 1};
    int gridX = 0;
    int gridY = 0;

    int cursorPosition[2] = {0,0};



    draw_grid(gridX, gridY);
    fill_grid(gridX, gridY, items);
    int input = getch();
    endwin();

}
