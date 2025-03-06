import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import pandas as pd
def func(x, a, b):
    return a*x*np.log(x)+b
data = pd.read_csv('output.txt', delim_whitespace=True, header=None, names=["x", "y"])
x = data['x']
y = data['y']
params, covariance = curve_fit(func, x, y)
a, b = params
print(f"Fitted parameters: a={a},b={b}")

plt.scatter(x, y, label='Data', color='pink')  
plt.plot(x, func(x, *params), label='Fitted curve', color='white')  
plt.xlabel('Size of Array')
plt.ylabel('Time')
plt.title('Data Fitting to y = axlog(x)+b')
plt.legend()
plt.grid(True)
plt.show()
print(a,b)