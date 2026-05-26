weight = 5
cost = 0.0
cost_drone = 0.0;

# Ground Shipping
if (weight <= 2):
  cost = (1.50 * weight) + 20.00
elif (weight <= 6):
  cost = (3.00 * weight) + 20.00
elif (weight <= 10):
  cost =  (4.00 * weight) + 20.00
else:
  cost = (4.75 * weight) + 20.00

cost_premium = 125.00

print("Cost: ")
print(cost)
print("Premium Cost: ")
print(cost_premium)

# Drone Shipping
if (weight <= 2):
  cost_drone = (4.50 * weight)
elif (weight <= 6):
  cost_drone = (9.00 * weight)
elif (weight <= 10):
  cost_drone = (12.00 * weight)
else:
  cost_drone = (14.75 * weight)

print("Drone Cost: ")
print(cost_drone)