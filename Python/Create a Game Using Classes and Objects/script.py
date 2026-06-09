import random

# ─────────────────────────────────────────────
#  CORE CLASSES
# ─────────────────────────────────────────────

class Casino:
    """Manages the casino: its name, available games, and registered players."""

    def __init__(self, name):
        if not isinstance(name, str):
            raise TypeError(f"Expected string for name, but got {type(name).__name__}")
        self.name = name
        self.games = []        # list of Game instances
        self.players = []      # list of Player instances

    def add_game(self, game):
        if not isinstance(game, Game):
            raise TypeError("Expected a Game instance.")
        self.games.append(game)
        print(f"  ✓ '{game.name}' added to {self.name}.")

    def register_player(self, player):
        if not isinstance(player, Player):
            raise TypeError("Expected a Player instance.")
        self.players.append(player)
        print(f"  ✓ {player.name} registered with ${player.money:.2f}.")

    def show_games(self):
        if not self.games:
            print("No games available.")
            return
        print(f"\n  Games at {self.name}:")
        for i, g in enumerate(self.games, 1):
            print(f"    {i}. {g.name}")

    def __repr__(self):
        return (f"Casino(name='{self.name}', "
                f"games={len(self.games)}, players={len(self.players)})")


# ─────────────────────────────────────────────

class Game:
    """Base class for all casino games."""

    def __init__(self, name, min_bet=1.0):
        if not isinstance(name, str):
            raise TypeError(f"Expected string for name, but got {type(name).__name__}")
        self.name = name
        self.min_bet = float(min_bet)

    def play(self, player, bet):
        raise NotImplementedError("Subclasses must implement play().")

    def _validate_bet(self, player, bet):
        """Returns True and deducts bet if valid; prints error and returns False otherwise."""
        if bet < self.min_bet:
            print(f"  Minimum bet is ${self.min_bet:.2f}.")
            return False
        if bet > player.money:
            print(f"  Not enough funds! You have ${player.money:.2f}.")
            return False
        player.money -= bet
        return True

    def __repr__(self):
        return f"Game(name='{self.name}', min_bet=${self.min_bet:.2f})"


# ─────────────────────────────────────────────

class Player:
    """Represents a casino patron with a name, wallet, and ban status."""

    def __init__(self, name, money, ban_status=False):
        if not isinstance(name, str):
            raise TypeError(f"Expected string for name, but got {type(name).__name__}")
        if not isinstance(money, (int, float)) or money < 0:
            raise ValueError("money must be a non-negative number.")
        if not isinstance(ban_status, bool):
            raise TypeError(f"Expected bool for ban_status, but got {type(ban_status).__name__}")
        self.name = name
        self.money = float(money)
        self.ban_status = ban_status

    def is_banned(self):
        if self.ban_status:
            print(f"  ⛔  {self.name} is BANNED from this casino.")
            return True
        return False

    def show_balance(self):
        print(f"  💰  {self.name}'s balance: ${self.money:.2f}")

    def deposit(self, amount):
        if amount <= 0:
            print("  Deposit amount must be positive.")
            return
        self.money += float(amount)
        print(f"  Deposited ${amount:.2f}. New balance: ${self.money:.2f}")

    def __repr__(self):
        status = "BANNED" if self.ban_status else "active"
        return f"Player(name='{self.name}', money=${self.money:.2f}, status={status})"


# ─────────────────────────────────────────────
#  GAME SUBCLASSES
# ─────────────────────────────────────────────

class Blackjack(Game):
    """
    Simplified Blackjack:
      • Player and dealer each draw 2 cards (one dealer card is hidden).
      • Player may Hit or Stand.
      • Dealer hits until reaching 17+.
      • Blackjack (21 on first two cards) pays 1.5x.
    """

    SUITS = ["S", "H", "D", "C"]
    RANKS = ["2","3","4","5","6","7","8","9","10","J","Q","K","A"]

    def __init__(self):
        super().__init__("Blackjack", min_bet=5.0)

    def _new_deck(self):
        deck = [(r, s) for s in self.SUITS for r in self.RANKS]
        random.shuffle(deck)
        return deck

    def _card_value(self, rank):
        if rank in ("J", "Q", "K"):
            return 10
        if rank == "A":
            return 11
        return int(rank)

    def _hand_value(self, hand):
        total = sum(self._card_value(r) for r, _ in hand)
        aces  = sum(1 for r, _ in hand if r == "A")
        while total > 21 and aces:
            total -= 10
            aces  -= 1
        return total

    def _fmt_hand(self, hand, hide_second=False):
        if hide_second:
            return f"{hand[0][0]}{hand[0][1]}  [hidden]"
        return "  ".join(f"{r}{s}" for r, s in hand)

    def play(self, player, bet):
        if player.is_banned():
            return
        if not self._validate_bet(player, bet):
            return

        deck         = self._new_deck()
        player_hand  = [deck.pop(), deck.pop()]
        dealer_hand  = [deck.pop(), deck.pop()]

        print(f"\n  -- {self.name} --")
        print(f"  Dealer: {self._fmt_hand(dealer_hand, hide_second=True)}")
        print(f"  You:    {self._fmt_hand(player_hand)}  (total: {self._hand_value(player_hand)})")

        if self._hand_value(player_hand) == 21:
            print("  Blackjack! You win 1.5x!")
            player.money += bet * 2.5
            player.show_balance()
            return

        while True:
            action = input("  Hit or Stand? (h/s): ").strip().lower()
            if action == "h":
                player_hand.append(deck.pop())
                total = self._hand_value(player_hand)
                print(f"  You:    {self._fmt_hand(player_hand)}  (total: {total})")
                if total > 21:
                    print("  Bust! You lose.")
                    player.show_balance()
                    return
                if total == 21:
                    break
            elif action == "s":
                break
            else:
                print("  Please enter 'h' to hit or 's' to stand.")

        print(f"\n  Dealer reveals: {self._fmt_hand(dealer_hand)}  (total: {self._hand_value(dealer_hand)})")
        while self._hand_value(dealer_hand) < 17:
            dealer_hand.append(deck.pop())
            print(f"  Dealer hits:    {self._fmt_hand(dealer_hand)}  (total: {self._hand_value(dealer_hand)})")

        p_total = self._hand_value(player_hand)
        d_total = self._hand_value(dealer_hand)

        if d_total > 21:
            print("  Dealer busts -- you win!")
            player.money += bet * 2
        elif p_total > d_total:
            print(f"  {p_total} beats {d_total} -- you win!")
            player.money += bet * 2
        elif p_total == d_total:
            print("  Push -- your bet is returned.")
            player.money += bet
        else:
            print(f"  {d_total} beats {p_total} -- you lose.")

        player.show_balance()


# ─────────────────────────────────────────────

class SlotMachine(Game):
    """
    3-reel slot machine.
      Match 3 -> 5x payout
      Match 2 -> 1.5x payout
      No match -> lose bet
    """

    SYMBOLS = ["Cherry", "Lemon", "Orange", "Star", "Diamond", "Seven"]
    WEIGHTS  = [30,       25,      20,       15,     7,         3     ]

    def __init__(self):
        super().__init__("Slot Machine", min_bet=1.0)

    def _spin(self):
        return random.choices(self.SYMBOLS, weights=self.WEIGHTS, k=3)

    def play(self, player, bet):
        if player.is_banned():
            return
        if not self._validate_bet(player, bet):
            return

        reels = self._spin()
        display = " | ".join(f"{s:8}" for s in reels)
        print(f"\n  -- {self.name} --")
        print(f"  [ {display} ]")

        matches = max(reels.count(s) for s in set(reels))

        if matches == 3:
            print("  JACKPOT! 3 of a kind -- 5x payout!")
            player.money += bet * 5
        elif matches == 2:
            print("  2 of a kind -- 1.5x payout!")
            player.money += bet * 1.5
        else:
            print("  No match -- better luck next time.")

        player.show_balance()


# ─────────────────────────────────────────────

class Roulette(Game):
    """
    European Roulette (single zero, 0-36).
    Bet types: number (36x), red/black (2x), even/odd (2x).
    """

    RED_NUMBERS = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36}

    def __init__(self):
        super().__init__("Roulette", min_bet=2.0)

    def play(self, player, bet):
        if player.is_banned():
            return
        if not self._validate_bet(player, bet):
            return

        print(f"\n  -- {self.name} --")
        print("  Bet types:  [n] Specific number (0-36)  |  [r] Red  |  [b] Black  |  [e] Even  |  [o] Odd")
        choice = input("  Your bet type: ").strip().lower()

        if choice == "n":
            try:
                number = int(input("  Which number (0-36)? ").strip())
                if not 0 <= number <= 36:
                    raise ValueError
            except ValueError:
                print("  Invalid number. Bet returned.")
                player.money += bet
                return
            bet_label = f"number {number}"
        elif choice in ("r", "b", "e", "o"):
            bet_label = {"r":"red","b":"black","e":"even","o":"odd"}[choice]
        else:
            print("  Invalid choice. Bet returned.")
            player.money += bet
            return

        result = random.randint(0, 36)
        color  = "red" if result in self.RED_NUMBERS else ("green" if result == 0 else "black")
        print(f"\n  The wheel spins... ball lands on {result} ({color})!")

        won = False
        multiplier = 0
        if choice == "n" and result == number:
            won = True; multiplier = 36
        elif choice == "r" and color == "red":
            won = True; multiplier = 2
        elif choice == "b" and color == "black":
            won = True; multiplier = 2
        elif choice == "e" and result != 0 and result % 2 == 0:
            won = True; multiplier = 2
        elif choice == "o" and result % 2 == 1:
            won = True; multiplier = 2

        if won:
            print(f"  You win! {multiplier}x payout on '{bet_label}'.")
            player.money += bet * multiplier
        else:
            print(f"  You lose. Better luck next spin.")

        player.show_balance()


# ─────────────────────────────────────────────
#  MAIN LOOP
# ─────────────────────────────────────────────

def main():
    print("=" * 50)
    print("       Welcome to the Python Casino!")
    print("=" * 50)

    casino = Casino("The Royal Flush")
    casino.add_game(Blackjack())
    casino.add_game(SlotMachine())
    casino.add_game(Roulette())

    name = input("\nEnter your name: ").strip() or "Player"
    while True:
        try:
            funds = float(input("Starting funds ($): ").strip())
            if funds <= 0:
                raise ValueError
            break
        except ValueError:
            print("  Please enter a positive number.")

    player = Player(name, funds)
    casino.register_player(player)

    while True:
        print("\n" + "-" * 40)
        player.show_balance()
        if player.money <= 0:
            print("  You're out of money! Game over.")
            break

        casino.show_games()
        print(f"    {len(casino.games) + 1}. Deposit more funds")
        print(f"    {len(casino.games) + 2}. Quit")

        try:
            pick = int(input("\n  Choose an option: ").strip())
        except ValueError:
            print("  Please enter a number.")
            continue

        if pick == len(casino.games) + 2:
            print(f"\n  Thanks for playing, {player.name}! You leave with ${player.money:.2f}.")
            break
        elif pick == len(casino.games) + 1:
            try:
                amount = float(input("  Deposit amount: $").strip())
                player.deposit(amount)
            except ValueError:
                print("  Invalid amount.")
        elif 1 <= pick <= len(casino.games):
            game = casino.games[pick - 1]
            try:
                bet = float(input(f"  Bet amount (min ${game.min_bet:.2f}): $").strip())
            except ValueError:
                print("  Invalid bet.")
                continue
            game.play(player, bet)
        else:
            print("  Invalid option.")

    print("\nFinal state:", player)
    print("=" * 50)


if __name__ == "__main__":
    main()