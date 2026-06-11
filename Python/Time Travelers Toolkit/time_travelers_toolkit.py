# Add your Code below
import datetime as dt
import decimal as Decimal
from random import randint, choice
import custom_module

date_today = dt.date.today()
time_now = dt.datetime.now().time()

print(f"It is {date_today} today, at {time_now}.")

target_year = randint(1900, 2100)

base_cost = Decimal.Decimal(50)
current_year = date_today.year

year_difference = abs(target_year - current_year)
cost_multiplier = 1 + (year_difference / 1000)

final_cost = base_cost * Decimal.Decimal(cost_multiplier)

final_cost_formatted = f"{float(final_cost):.2f}"

destinations = ["Ancient Rome", "Medieval England", "Ancient Egypt", "Future Mars", "Victorian Era", "Prehistoric Times"]
selected_destination = choice(destinations)

custom_module.generate_time_travel_message(target_year, selected_destination, final_cost_formatted)

print("\nCongratulations on completing the Time Travelers Toolkit project!")

