import math
import numpy
'''
import sympy
x = sympy.Symbol('x')
e = sympy.Integral(sympy.sqrt(4 - sympy.sin(x) * sympy.sin(x)), (x, 0, sympy.pi/6))
print(e.evalf())
'''


def f(x):
    # return math.sqrt(4 - math.sin(x) * math.sin(x))
    return math.pow(x, 1.5)


def romberg(t: numpy.matrix, a: float, b: float):
    # T = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    h = b - a
    n = 1
    t[0][0] = (h / 2) * (f(a) + f(b))
    # print(T[0])
    # while math.fabs(T[k][0] - T[k-1][0]) > 1e-6:
    for k in range(0, 8):
        the_sum = 0
        for i in range(0, n):
            the_sum += f(a + (2 * i + 1) * ((b - a)/(2*n)))
        t[k+1][0] = 0.5*t[k][0] + (h / 2) * the_sum
        # print(theSum * h/2, T[k - 1])
        print(t[k][0])
        n *= 2
        h /= 2


T = numpy.mat(numpy.zeros((10, 10)))
# T.tolist()
print(T)
print(T[0][0])
a = 0
# b = math.pi
b = 1

romberg(T, a, b)
