# Tugas:
# Write a console program
#   - Asks user to input number of rows
#   - Prints a christmas tree

"""
def segitiga(n):
    for current_row in range(n):
        # Ngeprint n - i - 1 kolom kosong
        for cols in range(n - current_row - 1):
            print(' ', end='')

        # Ngeprint 2 * i + 1 kolom bintang
        for cols in range(2 * current_row + 1):
            print('*', end='')

        # Ngasih enter
        print()

# Prompt user input
number_of_rows = int(input("Enter number of rows: "))

segitiga(number_of_rows)
segitiga(number_of_rows)

for current_row in range(number_of_rows):
    for cols in range(number_of_rows - 2):
        print(' ', end='')
    for cols in range(3):
        print('*', end='')
    print()

a = 1
b = 2.0
c = a + b
print(type(a))
print(type(b))
print(type(c))
"""

splitList = "Halo Farras".split()
print(type(splitList))
splitList.append("Farah")

print(splitList)

print(type(splitList[0]))
