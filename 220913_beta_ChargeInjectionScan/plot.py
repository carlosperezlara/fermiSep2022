import matplotlib.pyplot as pyplot
import numpy
import pandas

#xpoints = np.array([1, 8])
#ypoints = np.array([3, 10])
#plt.plot(xpoints, ypoints)
#plt.show()

df = pandas.read_csv("output.txt")
print( df.head() )

filt_200_0 = ( (df['Vbias']==200) & (df['Switch']==0) )
filt_200_1 = ( (df['Vbias']==200) & (df['Switch']==1) )
filt_0_0 = ( (df['Vbias']==0) & (df['Switch']==0) )
filt_0_1 = ( (df['Vbias']==0) & (df['Switch']==1) )

df_200_0 = df.loc[ filt_200_0 ]
df_200_1 = df.loc[ filt_200_1 ]
df_0_0 = df.loc[ filt_0_0 ]
df_0_1 = df.loc[ filt_0_1 ]

ax1 = df_200_0.plot(kind = 'scatter', x = 'EffCap', y = 'Sigma', label='200V NoBuf', c='y')
df_200_1.plot(kind = 'scatter',       x = 'EffCap', y = 'Sigma', label='200V BUF',  c = 'r', ax=ax1)
df_0_0.plot(kind = 'scatter',         x = 'EffCap', y = 'Sigma', label='0V NoBuf', c = 'g', ax=ax1)
df_0_1.plot(kind = 'scatter',         x = 'EffCap', y = 'Sigma', label='0V BUF', c = 'b', ax=ax1)

ax2 = df_200_0.plot(kind = 'scatter', x = 'EffCap', y = 'Mean', label='200V NoBuf', c='y')
df_200_1.plot(kind = 'scatter',       x = 'EffCap', y = 'Mean', label='200V BUF',  c = 'r', ax=ax2)
df_0_0.plot(kind = 'scatter',         x = 'EffCap', y = 'Mean', label='0V NoBuf', c = 'g', ax=ax2)
df_0_1.plot(kind = 'scatter',         x = 'EffCap', y = 'Mean', label='0V BUF', c = 'b', ax=ax2)

ax3 = df_200_0.plot(kind = 'scatter', x = 'EffCap', y = 'Amplitude', label='200V NoBuf', c='y')
df_200_1.plot(kind = 'scatter',       x = 'EffCap', y = 'Amplitude', label='200V BUF',  c = 'r', ax=ax3)
df_0_0.plot(kind = 'scatter',         x = 'EffCap', y = 'Amplitude', label='0V NoBuf', c = 'g', ax=ax3)
df_0_1.plot(kind = 'scatter',         x = 'EffCap', y = 'Amplitude', label='0V BUF', c = 'b', ax=ax3)

pyplot.show()
