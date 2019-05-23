import numpy as np
import matplotlib.pylab as plt


Bx=np.zeros(6)
By=np.zeros(6)
t=np.zeros(6)
Bx[1] = 4
By[1] = 100
Bx[2] = 10
By[2] = 5
Bx[3] = 12
By[3] = 80
Bx[4] = 80
By[4] = 50
Bx[5] = 50
By[5] = 50
Bx[6] = 40
By[6] = 200
t[0] = 0
t[1]  = 73
t[2] = 28
t[3] = 59
t[4] = 52
t[5] = 39
t[6] = 137

#Caminata
yc = np.random.uniform
xc = np.random.uniform(4,80)
yc = np.random.uniform(5,200)
v_ini = np.random.uniform(0.1,0.5)
def distancias(yc,xc): 
    r = []
    for i in range (6):
      
        r_i = np.sqrt(((-By[i]+yc)**2)+((-Bx[i]+xc)**2))
        r = np.append(r,r_i)
    return r[np.argmin(r)]








