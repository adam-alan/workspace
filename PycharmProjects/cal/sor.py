x = [0, 0, 0, 0]
b = [1, 1, 1, 1]
a = [[-4, 1, 1, 1], [1, -4, 1, 1], [1, 1, -4, 1], [1, 1, 1, -4]]
w = 1.3

# while True:
for k in range(0, 11):
    px = x
    print(px)
    for i in range(0, 4):
        theSum = [0, 0]
        for j in range(0, i):
            theSum[0] += a[i][j]*x[j]
        for j in range(i, 4):
            theSum[1] += a[i][j]*x[j]
        x[i] += w*(b[i] - theSum[0] - theSum[1])/a[i][i]
    print(x)
    array = []
    for i in range(0, 4):
        # array.append(x[i]-px[i])
        print(x[i] == px[i])
    # print(array)
    # print(max(array))
print(x)

