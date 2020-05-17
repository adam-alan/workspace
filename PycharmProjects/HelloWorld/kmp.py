def make_next(string):
    i, k, m = 0, -1, len(string)
    next = [-1] * m
    while i < m - 1:
        if k == -1 or string[i] == string[k]:
            i, k = i + 1, k + 1
            if string[i] != string[k]:
                next[i] = k
            else:
                next[i] = next[k]
        else:
            k = next[k]

    return next

string = "CHINCHILLA"
next = make_next(string)
print(next)
for i in range(0, len(string)):
    print(str(i) + "\t" + string[0:i] + "\t" + str(next[i]) + "\t" + string[0:next[i]])
