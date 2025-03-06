import numpy as np

# Open the text file in write mode
with open("random_numbers.txt", "w") as file:
    # Loop to generate and save random numbers
    for i in range(1, 7000):
        random_numbers = np.random.randint(1, 7000, i)
        # Convert the numpy array to a string and write it to the file
        file.write(" ".join(map(str, random_numbers)) + "\n")

print("Data has been written to 'random_numbers.txt'")
