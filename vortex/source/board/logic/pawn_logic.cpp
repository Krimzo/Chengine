#include "vortex.h"


void vtx::get_white_pawn_moves(const Board& board, const int x, const int y, std::vector<Board>& out_boards)
{
	const int from_index = get_index(x, y);

	if (in_board(x, y - 1) && !board[get_index(x, y - 1)]) {
		out_boards.push_back(board.after_playing(from_index, get_index(x, y - 1), (y == 1) ? W_QUEEN : W_PAWN));

		if (y == 6 && !board[get_index(x, y - 2)]) {
			out_boards.push_back(board.after_playing(from_index, get_index(x, y - 2), W_PAWN));
		}
	}

	if (in_board(x - 1, y - 1) && board[get_index(x - 1, y - 1)].is_black()) {
		out_boards.push_back(board.after_playing(from_index, get_index(x - 1, y - 1), (y == 1) ? W_QUEEN : W_PAWN));
	}
	if (in_board(x + 1, y - 1) && board[get_index(x + 1, y - 1)].is_black()) {
		out_boards.push_back(board.after_playing(from_index, get_index(x + 1, y - 1), (y == 1) ? W_QUEEN : W_PAWN));
	}
}

void vtx::get_black_pawn_moves(const Board& board, const int x, const int y, std::vector<Board>& out_boards)
{
	const int from_index = get_index(x, y);

	if (in_board(x, y + 1) && !board[get_index(x, y + 1)]) {
		out_boards.push_back(board.after_playing(from_index, get_index(x, y + 1), (y == 6) ? B_QUEEN : B_PAWN));

		if (y == 1 && !board[get_index(x, y + 2)]) {
			out_boards.push_back(board.after_playing(from_index, get_index(x, y + 2), B_PAWN));
		}
	}

	if (in_board(x - 1, y + 1) && board[get_index(x - 1, y + 1)].is_white()) {
		out_boards.push_back(board.after_playing(from_index, get_index(x - 1, y + 1), (y == 6) ? B_QUEEN : B_PAWN));
	}
	if (in_board(x + 1, y + 1) && board[get_index(x + 1, y + 1)].is_white()) {
		out_boards.push_back(board.after_playing(from_index, get_index(x + 1, y + 1), (y == 6) ? B_QUEEN : B_PAWN));
	}
}
