import sympy
x1 = sympy.Symbol('x1')
x2 = sympy.Symbol('x2')
x3 = sympy.Symbol('x3')
x4 = sympy.Symbol('x4')

f1 = x1 + 0.333*x2 + 1.5*x3 - 0.333*x4 - 3
f2 = -2.01*x1 + 1.45*x2 + 0.5*x3 + 2.95*x4 - 5.4
f3 = 4.32*x1 - 1.95*x2 + 0*x3 + 2.08*x4 - 0.13
f4 = 5.11*x1 - 4*x2 + 3.33*x3 - 1.11*x4 - 3.77

print(sympy.solve((f1, f2, f3, f4), x1, x2, x3, x4))
# print(sympy.solve((x**2+x*y+1, y**2 + x*y + 2), x, y))

