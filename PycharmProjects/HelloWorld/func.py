import numpy
import matplotlib.pyplot

t = numpy.linspace(0, 2*numpy.pi, 1000)
x = numpy.cos(t) * numpy.cos(t) * numpy.cos(t)
y = numpy.sin(t) * numpy.sin(t) * numpy.sin(t)

matplotlib.pyplot.plot(x, y)
matplotlib.pyplot.show()
