# Sal's Shipping
import sys

print("------------------------------")
print("Welcome to Sal's Shipping!")
print("------------------------------\n")

print("We offer three types of shipping: Ground, Ground Premium, and Drone.")
print("G - Ground Shipping")
print("P - Ground Premium Shipping")
print("D - Drone Shipping")

shipping_type = input("What type of shipping would you like? (G/P/D): ")

weight = float(input("What is the weight of your package?: "))


if shipping_type == "P":
    shipping_type = "Ground Premium Shipping"
    cost = 125
elif shipping_type == "G":
    shipping_type = "Ground Shipping"
    
    if weight <= 2.0:
        cost = 20 + weight * 1.50
    elif weight > 2.0 and weight <= 6.0:
        cost = 20 + weight * 3.00
    elif weight > 6.0 and weight <= 10.0:
        cost = 20 + weight * 4.00
    else:
        cost = 20 + weight * 4.75
elif shipping_type == "D":
    shipping_type = "Drone Shipping"
    if weight <= 2.0:
        cost = weight * 4.50
    elif weight > 2.0 and weight <= 6.0:
        cost = weight * 9.00
    elif weight > 6.0 and weight <= 10.0:
        cost = weight * 12.00
    else:
        cost = weight * 14.25
else:
    sys.exit("Invalid shipping type. Please choose G, P, or D.")

print("------------------------------")

print("Your shipping cost is: $", format(cost, ",.2f"), sep="")
print("Your shipping type is:", shipping_type)

compare_cost = input("\nWould you like to compare the cost of the other shipping options? (Y/N): ")
if compare_cost == "Y":
    print("------------------------------")
    print("Ground Premium Shipping Price is: $125.00")

    if weight <= 2.0:
        cost = 20 + weight * 1.50
    elif weight > 2.0 and weight <= 6.0:
        cost = 20 + weight * 3.00
    elif weight > 6.0 and weight <= 10.0:
        cost = 20 + weight * 4.00
    else:
        cost = 20 + weight * 4.75
    print("Ground Shipping Price is: $", format(cost, ",.2f"), sep="")

    if weight <= 2.0:
        cost = weight * 4.50
    elif weight > 2.0 and weight <= 6.0:
        cost = weight * 9.00
    elif weight > 6.0 and weight <= 10.0:
        cost = weight * 12.00
    else:
        cost = weight * 14.25
    print("Drone Shipping Price is: $", format(cost, ",.2f"), sep="")

print("------------------------------")
print("Thank you for choosing Sal's Shipping!")