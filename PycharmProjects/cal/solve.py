
'''
x = [0, 0, 0]

while True:
    x[0] = (x[1]**2 + 4 * x[2] + 7) / 12
    x[1] = (-x[0]**2 + x[2] + 11)/10
    x[2] = (-x[1]**3 + 8)/10
    print(x)

'''
import sympy

x1 = sympy.Symbol('x1')
x2 = sympy.Symbol('x2')
x3 = sympy.Symbol('x3')
res = sympy.solve([12*x1-x2**2-4*x3-7, x1**2+10*x2-x3-11, x2**3+10*x3-8], [x1, x2, x3])
print(res)


