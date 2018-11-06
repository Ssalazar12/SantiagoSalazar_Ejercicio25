import numpy as np
import matplotlib.pyplot as plt

gauss_dat = np.loadtxt('sample.dat')

mean_est=np.mean(gauss_dat)
std_est=np.std(gauss_dat)

x=np.linspace(min(gauss_dat),max(gauss_dat),len(gauss_dat))
y=1/(std_est*np.sqrt(2*np.pi))*np.exp(-0.5*((x-mean_est)/std_est**2)**2)

plt.hist(gauss_dat, bins=60,density=True)
plt.title('Num ='+str(len(gauss_dat))+' stdev='+str(std_est) + ' mu='+str(mean_est))
plt.plot(x,y)

plt.savefig('sample.pdf')