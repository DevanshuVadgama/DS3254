import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import pandas as pd
def func(x, a, b, c):
    return a * x**2 + b * x + c
data = pd.read_csv('output.txt', delim_whitespace=True, header=None, names=["x", "y"])
x = data['x']
y = data['y']
params, covariance = curve_fit(func, x, y)
a, b, c = params
print(f"Fitted parameters: a={a}, b={b}, c={c}")
plt.scatter(x, y, label='Data', color='red')  
plt.plot(x, func(x, *params), label='Fitted curve', color='blue')  
plt.xlabel('Size of Array')
plt.ylabel('Time')
plt.title('Data Fitting to y = ax^2 + bx + c')
plt.legend()
plt.grid(True)
plt.show()
print(a,b,c)