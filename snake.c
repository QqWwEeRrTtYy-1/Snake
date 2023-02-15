#include <ncurses.h>
#include <stdio.h>

int main(int argc, char *argv[], char *env[]) {
	int x = 0, y = 0, ch;
	if (NULL == initscr()) {
		fprintf(stdout, "initscr() failed\n");
		return EXIT_FAILURE;
	}

	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	do {
		mvaddch(x, y, '');

		switch (ch) {
			case KEY_UP:
				y = (y + LINES - 1) % LINES;
				break;
		}
		mvaddch(y, x, '*');
		refresh();
	} while ('q' != (ch = getch()));

	endwin();
	return EXIT_SUCCESS;
}