from cs50 import get_float


def calculate_quarters(cents):
    """ Returns the number of quarters coins in change"""
    q = 0
    while cents >= 0.25:
        cents = round(cents - 0.25, 2)
        q += 1
    return q


def calculate_dimes(cents):
    """ Returns the number of dime coins in change"""
    d = 0
    while cents >= 0.1:
        cents = round(cents - 0.1, 2)
        d += 1
    return d


def calculate_nickles(cents):
    """ Returns the number of nickle coins in change"""
    n = 0
    while cents >= 0.05:
        cents = round(cents - 0.05, 2)
        n += 1
    return n


def calculate_pennies(cents):
    """ Returns the number of penny coins in change"""
    p = 0
    while cents >= 0.01:
        cents = round(cents - 0.01, 2)
        p += 1
    return p


change = -1
# Prompt user for change owed
while change < 0:
    change = get_float("Change owed: ")

# Calculate quarters
quarters = calculate_quarters(change)
change = round(change - (quarters * 0.25), 2)

# Calculate dimes
dimes = calculate_dimes(change)
change = round(change - (dimes * 0.1), 2)

# Calculate nickels
nickles = calculate_nickles(change)
change = round(change - (nickles * 0.05), 2)

# Calculate pennies
pennies = calculate_pennies(change)
change = round(change - (pennies * 0.01), 2)

# Sum amount of coins
coins = quarters + dimes + nickles + pennies
print(coins)
