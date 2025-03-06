import numpy as np
with open("random_numbers.txt", "w") as file:
    for i in range(1, 7000):
        random_numbers = np.random.randint(1, 7000, i)
        file.write(" ".join(map(str, random_numbers)) + "\n")

print("'random_numbers.txt'")
