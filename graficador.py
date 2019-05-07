from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import

import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import numpy as np

fig = plt.figure(figsize= (13,5))
ax = fig.add_subplot(1,2,1, projection='3d')

# Make data.
X = np.array(range(601))*6/600
Y = np.array(range(101))/100
X, Y = np.meshgrid(X, Y)
Z = np.loadtxt('datos.txt').T

# Plot the surface.
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm,
                       linewidth=0, antialiased=False)

# Customize the z axis.
plt.ylabel('Posicion [metros]')
plt.xlabel('Tiempo [segundos]')

# Add a color bar which maps values to colors.
fig.colorbar(surf, shrink=0.5, aspect=5, ticks=[-0.75,-0.50,-0.25,0.00,0.25,0.50,0.75])
plt.show()

ax1 = fig.add_subplot(1,2,2)
Y = np.array(range(101))/101
plt.plot(Y,Z[:,0],label = 'tiempo inicial')
plt.plot(Y,Z[:,-1],label = 'tiempo final')
plt.xlabel('Posicion [metros]')
plt.ylabel('Desplazamiento [metros]')
plt.legend()

plt.savefig("Resultado.png")