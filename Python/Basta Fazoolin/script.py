from datetime import time

def is_time_between(start, end, current):
    return start <= current <= end

class Menu:
    def __init__(self, name, items, start_time, end_time):
        self.name = name
        self.items = items
        self.start_time = start_time
        self.end_time = end_time

    def __repr__(self):
        return f"{self.name} menu available from {self.start_time} to {self.end_time}"
    
    def calculate_bill(self, purchased_items):
        total = 0
        for purchased_item in purchased_items:
            total += self.items.get(purchased_item)
        return total
    
    def get_time(self):
        return [self.start_time, self.end_time]
    
class Franchise:
    def __init__(self, address, menus=[]):
        self.address = address
        self.menus = menus

    def __repr__(self):
        return self.address

    def available_menus(self, time):
        menus_available = []

        for menu in self.menus:
            [start, end] = menu.get_time()
            if is_time_between(start, end, time):
                menus_available.append(menu)

        return menus_available
            
class Business:
    def __init__(self, name, franchises):
        self.name = name
        self.franchises = franchises



brunch_items = {'pancakes': 7.50, 'waffles': 9.00, 'burger': 11.00, 'home fries': 4.50, 'coffee': 1.50, 'espresso': 3.00, 'tea': 1.00, 'mimosa': 10.50, 'orange juice': 3.50}
brunch = Menu("Brunch", brunch_items, time(11, 0), time(16, 0))

early_bird_items = {'salumeria plate': 8.00, 'salad and breadsticks (serves 2, no refills)': 14.00, 'pizza with quattro formaggi': 9.00, 'duck ragu': 17.50, 'mushroom ravioli (vegan)': 13.50, 'coffee': 1.50, 'espresso': 3.00,}
early_bird = Menu("Early-Bird Dinners", early_bird_items, time(15, 0), time(18, 0))

dinner_items = {'crostini with eggplant caponata': 13.00, 'caesar salad': 16.00, 'pizza with quattro formaggi': 11.00, 'duck ragu': 19.50, 'mushroom ravioli (vegan)': 13.50, 'coffee': 2.00, 'espresso': 3.00,}
dinner = Menu("Dinner", dinner_items, time(17, 0), time(23, 0))

kids_items = {'chicken nuggets': 6.50, 'fusilli with wild mushrooms': 12.00, 'apple juice': 3.00}
kids = Menu("Kids", kids_items, time(11, 0), time(21, 0))

flagship_store = Franchise("1232 West End Road", [brunch, early_bird, dinner, kids])
new_installment = Franchise("12 East Mulberry Street", [brunch, early_bird, dinner, kids])

first_business = Business("Basta Fazoolin' with my Heart", [flagship_store, new_installment])

arepas_items = {'arepa pabellon': 7.00, 'pernil arepa': 8.50, 'guayanes arepa': 8.00, 'jamon arepa': 7.50}
arepas_menu = Menu("Take a' Arepa", arepas_items, time(10, 0), time(20, 0))
arepas_place = Franchise("189 Fitzgerald Avenue", [arepas_menu])

new_business = Business("Take a' Arepa", [arepas_place])



