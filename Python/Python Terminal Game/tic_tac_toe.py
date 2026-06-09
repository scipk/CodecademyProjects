#!/usr/bin/env python3
"""
Tic Tac Toe - terminal game for 2 players or 1 player vs AI.
"""

import random
import sys


# ── ANSI colors (disabled automatically on Windows if not supported) ──────────
RESET  = "\033[0m"
BOLD   = "\033[1m"
RED    = "\033[91m"
BLUE   = "\033[94m"
CYAN   = "\033[96m"
YELLOW = "\033[93m"
GREEN  = "\033[92m"
DIM    = "\033[2m"


def colored(text: str, color: str) -> str:
    return f"{color}{text}{RESET}"


# ── Board ─────────────────────────────────────────────────────────────────────

def make_board() -> list[str]:
    return [str(i) for i in range(1, 10)]   # '1' … '9'


def display_board(board: list[str]) -> None:
    def fmt(cell: str) -> str:
        if cell == "X":
            return colored(f" {cell} ", RED + BOLD)
        if cell == "O":
            return colored(f" {cell} ", BLUE + BOLD)
        return colored(f" {cell} ", DIM)

    sep = colored("───┼───┼───", CYAN)
    print()
    for row in range(3):
        r = row * 3
        print("  " + "│".join(fmt(board[r + c]) for c in range(3)))
        if row < 2:
            print("  " + sep)
    print()


# ── Win / draw detection ──────────────────────────────────────────────────────

WINNING_LINES = [
    (0, 1, 2), (3, 4, 5), (6, 7, 8),   # rows
    (0, 3, 6), (1, 4, 7), (2, 5, 8),   # cols
    (0, 4, 8), (2, 4, 6),              # diagonals
]


def check_winner(board: list[str], marker: str) -> bool:
    return any(all(board[i] == marker for i in line) for line in WINNING_LINES)


def is_draw(board: list[str]) -> bool:
    return all(cell in ("X", "O") for cell in board)


def available_moves(board: list[str]) -> list[int]:
    return [i for i, cell in enumerate(board) if cell not in ("X", "O")]


# ── AI (minimax) ──────────────────────────────────────────────────────────────

def minimax(board: list[str], is_maximizing: bool) -> int:
    if check_winner(board, "O"):
        return 1
    if check_winner(board, "X"):
        return -1
    if is_draw(board):
        return 0

    moves = available_moves(board)
    if is_maximizing:
        best = -2
        for idx in moves:
            board[idx] = "O"
            score = minimax(board, False)
            board[idx] = str(idx + 1)
            best = max(best, score)
        return best
    else:
        best = 2
        for idx in moves:
            board[idx] = "X"
            score = minimax(board, True)
            board[idx] = str(idx + 1)
            best = min(best, score)
        return best


def ai_move(board: list[str]) -> int:
    moves = available_moves(board)
    best_score, best_idx = -2, moves[0]
    random.shuffle(moves)          # tiebreak randomly for variety
    for idx in moves:
        board[idx] = "O"
        score = minimax(board, False)
        board[idx] = str(idx + 1)
        if score > best_score:
            best_score, best_idx = score, idx
    return best_idx


# ── Input helpers ─────────────────────────────────────────────────────────────

def prompt(msg: str) -> str:
    try:
        return input(msg).strip()
    except (EOFError, KeyboardInterrupt):
        print("\n\nThanks for playing!")
        sys.exit(0)


def get_player_move(board: list[str], marker: str, name: str) -> int:
    while True:
        raw = prompt(f"  {colored(name, RED if marker == 'X' else BLUE)} ({marker}), enter a square [1-9]: ")
        if raw.isdigit() and 1 <= int(raw) <= 9:
            idx = int(raw) - 1
            if board[idx] not in ("X", "O"):
                return idx
            print(colored("  That square is taken - try again.", YELLOW))
        else:
            print(colored("  Please enter a number from 1 to 9.", YELLOW))


# ── Game loop ─────────────────────────────────────────────────────────────────

def play_game(vs_ai: bool, player1: str, player2: str) -> str | None:
    board = make_board()
    markers = {player1: "X", player2: "O"}
    turn_order = [player1, player2]

    print(colored("\n  Board positions:", DIM))
    display_board(make_board())
    print(colored("  Let's play!\n", GREEN + BOLD))

    for turn in range(9):
        current = turn_order[turn % 2]
        marker  = markers[current]

        display_board(board)

        if vs_ai and current == player2:
            print(colored(f"  {player2} (O) is thinking…", BLUE))
            idx = ai_move(board)
        else:
            idx = get_player_move(board, marker, current)

        board[idx] = marker

        if check_winner(board, marker):
            display_board(board)
            return current

        if is_draw(board):
            display_board(board)
            return None

    return None


# ── Main ──────────────────────────────────────────────────────────────────────

def main() -> None:
    print(colored("\n╔══════════════════════════╗", CYAN))
    print(colored("║      TIC  TAC  TOE       ║", CYAN + BOLD))
    print(colored("╚══════════════════════════╝", CYAN))

    while True:
        # Mode selection
        print()
        mode = prompt("  Play against [1] another player  or  [2] the AI?  → ").strip()
        if mode not in ("1", "2"):
            print(colored("  Please enter 1 or 2.", YELLOW))
            continue

        vs_ai = (mode == "2")
        player1 = prompt("  Player 1 name (X): ") or "Player 1"
        player2 = prompt("  Player 2 name (O): ") if not vs_ai else "Computer"
        if not player2:
            player2 = "Player 2"

        # Best-of / play again loop
        scores: dict[str, int] = {player1: 0, player2: 0, "draws": 0}
        game_num = 1

        while True:
            print(colored(f"\n  ── Game {game_num} ──", CYAN + BOLD))
            winner = play_game(vs_ai, player1, player2)

            if winner:
                color = RED if winner == player1 else BLUE
                print(colored(f"  🎉  {winner} wins!", color + BOLD))
                scores[winner] += 1
            else:
                print(colored("  It's a draw!", YELLOW + BOLD))
                scores["draws"] += 1

            # Scoreboard
            print(f"\n  {colored('Scores', BOLD)}  "
                  f"{colored(player1, RED)}: {scores[player1]}  │  "
                  f"{colored(player2, BLUE)}: {scores[player2]}  │  "
                  f"Draws: {scores['draws']}")

            again = prompt("\n  Play again? [y/n]: ").lower()
            if again != "y":
                break
            game_num += 1

        new_game = prompt("\n  Start a new session? [y/n]: ").lower()
        if new_game != "y":
            print(colored("\n  Thanks for playing - goodbye!\n", GREEN + BOLD))
            break


if __name__ == "__main__":
    main()