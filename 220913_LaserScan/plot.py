import matplotlib.pyplot as pyplot
import numpy
import pandas

#xpoints = np.array([1, 8])
#ypoints = np.array([3, 10])
#plt.plot(xpoints, ypoints)
#plt.show()

df = pandas.read_csv("output.txt")
print( df.head() )

filt_0 = (df['Buffered']==0)
filt_1 = (df['Buffered']==1)

df_0 = df.loc[ filt_0 ]
df_1 = df.loc[ filt_1 ]

ax1 = df_0.plot(kind = 'scatter', x = 'Amplitude', y = 'Sigma', label='nonBUFF', c='y')
df_1.plot(kind = 'scatter',       x = 'Amplitude', y = 'Sigma', label='BUFFERED',  c = 'r', ax=ax1)

ax2 = df_0.plot(kind = 'scatter', x = 'Amplitude', y = 'Mean', label='nonBUFF', c='y')
df_1.plot(kind = 'scatter',       x = 'Amplitude', y = 'Mean', label='BUFFERED',  c = 'r', ax=ax2)

ax3 = df_0.plot(kind = 'scatter', x = 'LasTune', y = 'Amplitude', label='nonBUFF', c='y')
df_1.plot(kind = 'scatter',       x = 'LasTune', y = 'Amplitude', label='BUFFERED',  c = 'r', ax=ax3)

pyplot.show()
