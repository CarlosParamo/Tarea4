import numpy as np
import matplotlib.pyplot as plt 

a= np.genfromtxt("datos.dat")


plt.plot(a[0,:], len(a))
