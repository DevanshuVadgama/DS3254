import numpy as np
with open("random_numbers.txt", "w") as file:
    for i in range(1, 10001):
        random_numbers = np.random.randint(1, 100000, i)
        file.write(" ".join(map(str, random_numbers)) + "\n")

print("Data has been written to 'random_numbers.txt'")

#gives arrays of size 1 to 10000 whose entries are integers from 1 to 100000