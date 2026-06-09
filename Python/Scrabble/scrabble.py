# Scrabble

letters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
points = [1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 4, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10]

letter_to_points = {key:value for key, value in zip(letters, points)}

letter_to_points[" "] = 0

def score_word(word):
    word = word.upper()
    point_total = 0
    for letter in word:
        point_total += letter_to_points.get(letter, 0)
    return point_total

player_to_words = {}
player_to_points = {}

def player_word(player, word):
    if player not in player_to_words:
        player_to_words[player] = []
    player_to_words[player] += [word]
    print(f"{player} played the word: {word.upper()}")

def update_point_totals():
    print("Updating point tally...")
    for player, words in player_to_words.items():
        player_points = 0
        for word in words:
            player_points += score_word(word)
        player_to_points[player] = player_points
        print(f"{player} has {player_points} points.")
    

print("""
=================
 S C R A B B L E 
=================""")
print("\n--- Round 1 ---")
player_word("player1", "Blue")
player_word("wordNerd", "EARTH")
player_word("Lexi Con", "erASer")
player_word("Prof Reader", "zaP")
update_point_totals()
print("\n--- Round 2 ---")
player_word("player1", "tenNIS")
player_word("wordNerd", "eyes")
player_word("Lexi Con", "BellY")
player_word("Prof Reader", "coma")
update_point_totals()
print("\n--- Round 3 ---")
player_word("player1", "ExIt")
player_word("wordNerd", "machine")
player_word("Lexi Con", "husKY")
player_word("Prof Reader", "PERIOD")

print("\n=== Final Scores! ===")
update_point_totals()


