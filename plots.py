import numpy as np
import matplotlib.pyplot as plt

mapa= np.loadtxt("map_data.txt")
datos=np.loadtxt("datos.txt")

fig,ax =plt.subplots()
circle=Circle((datos[0],datos[1]),datos[2],alpha=.3,color='r')
ax.add_artist(circle)
ax.add_artist(plt.imshow(mapa,cmap='winter'))
plt.savefig('mapa.pdf')
plt.close()
