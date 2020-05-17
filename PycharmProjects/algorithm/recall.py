result = []


def backtrack(chooses: list, track: list):
    if (len(chooses) == len(track)):
        result.append(track.copy())
        return
    for item in chooses:
        if track.count(item) == 0:
            track.append(item)
            backtrack(chooses, track)
            track.pop()


backtrack([8, 2, 3], [])
print(result)
