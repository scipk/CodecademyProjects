# Len's Slice

toppings = ["pepperoni", "pineapple", "cheese", "sausage", "olives", "anchovies", "mushrooms"]
prices = [2, 6, 1, 3, 2, 7, 2]

num_two_dollar_slices = prices.count(2)
print(f"There are {num_two_dollar_slices} $2 slices.")

num_pizzas = len(toppings)
print(f"We sell {num_pizzas} different kinds of pizza!")

pizza_and_prices = [list(pair) for pair in zip(prices, toppings)]

pizza_and_prices.sort()

cheapest_pizza = pizza_and_prices[0]
priciest_pizza = pizza_and_prices[-1]

pizza_and_prices.pop()

pizza_and_prices.insert(4, [2.5, "peppers"])


three_cheapest = pizza_and_prices[:3]
print(f"The three cheapest pizzas are: {three_cheapest}")