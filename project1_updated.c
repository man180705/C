#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 3

/* A clearer, safer 3x3 sliding-puzzle (8-puzzle) implementation.
   - Board is a 3x3 char array; the empty cell is ' '.
   - Reads 9 input characters (digits or space) for the initial board.
   - Uses local variables and bounds checks to avoid UB.
*/

void print_board(char b[N][N]) {
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			printf(" %c ", b[r][c]);
			if (c < N-1) printf("|");
		}
		printf("\n");
		if (r < N-1) printf("---|---|---\n");
	}
}

void read_board(char b[N][N]) {
	int filled = 0;
	int ch;
	printf("Enter 9 characters (digits 1-8 and a space for the empty).\n");
	while (filled < 9 && (ch = getchar()) != EOF) {
		if (ch == '\r') continue; /* ignore CR on Windows */
		if (ch == '\n') continue;
		/* accept space as the empty tile */
		b[filled/3][filled%3] = (char)ch;
		filled++;
	}
	while (filled < 9) { b[filled/3][filled%3] = ' '; filled++; }
}

bool is_solved(char b[N][N]) {
	char expect = '1';
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (r == N-1 && c == N-1) {
				if (b[r][c] != ' ') return false;
			} else {
				if (b[r][c] != expect) return false;
				expect++;
			}
		}
	}
	return true;
}

/* Move the empty tile in direction dir (w/a/s/d). Returns true if moved. */
bool move_empty(char b[N][N], char dir) {
	int er=-1, ec=-1;
	for (int r=0; r<N; ++r) for (int c=0; c<N; ++c) if (b[r][c] == ' ') { er = r; ec = c; }
	if (er == -1) return false; /* no empty found */

	int tr = er, tc = ec;
	dir = (char) tolower((unsigned char)dir);
	if (dir == 'w') tr = er - 1;
	else if (dir == 's') tr = er + 1;
	else if (dir == 'a') tc = ec - 1;
	else if (dir == 'd') tc = ec + 1;
	else return false;

	if (tr < 0 || tr >= N || tc < 0 || tc >= N) return false;
	char tmp = b[tr][tc];
	b[tr][tc] = b[er][ec];
	b[er][ec] = tmp;
	return true;
}

int main(void) {
	char board[N][N];
	read_board(board);
	int moves = 0;

	while (1) {
		print_board(board);
		if (is_solved(board)) {
			printf("You solved the puzzle in %d moves!\n", moves);
			break;
		}
		printf("Enter move (W=up, S=down, A=left, D=right): ");
		int c = getchar();
		while (c == '\n' || c == '\r') c = getchar();
		if (c == EOF) break;
		/* consume rest of line */
		while (getchar() != '\n' && !feof(stdin)) {}

		if (!move_empty(board, (char)c)) {
			printf("Invalid move or move out of bounds. Try again.\n");
			continue;
		}
		moves++;
	}
	return 0;
}