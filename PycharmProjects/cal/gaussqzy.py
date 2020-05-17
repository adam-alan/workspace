a = [[0.001, 2, 3], [-1, 3.712, 4.623], [-2, 1.072, 5.643]]
b = [1, 2, 3]
m = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
x = [0, 0, 0]

for k in range(0, 2):
    for i in range(k + 1, 3):
        for j in range(0, 3):
            m[i][j] = a[i][k] / a[k][k]
    for i in range(k+1, 3):
        b[i] -= m[i][k]*b[k]
        for j in range(0, 3):
            a[i][j] -= m[i][j] * a[k][j]

# x[2] = b[2]/a[2][2]
# x[1] = (b[1] - a[1][2]*x[2])/a[1][1]
# x[0] = (b[0] - a[0][2]*x[2] - a[0][1] * x[1])/a[0][0]

print('m = ', m)
print('a = ', a)
print('b = ', b)

for i in [2, 1, 0]:
    for j in range(i, 3):
        if j == i:
            continue
        b[i] -= a[i][j] * x[j]
    x[i] = b[i]/a[i][i]

print('x = ', x)
