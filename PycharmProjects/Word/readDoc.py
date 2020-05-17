txt1 = open("/home/zhuxingtian/haha.txt", "r")
txt2 = open("/home/zhuxingtian/result.txt", "w")

para = []


for line in txt1.readlines():
    lineStr = line
    index1 = lineStr.find('(')
    index2 = lineStr.find(')')
    tmpStr = lineStr[index1:index2+1]
    lineStr.find(tmpStr)

    #print(tmpStr+'k')
    if (len(tmpStr) != 5):
        print(lineStr)

    else:
        lineStr = lineStr.replace(tmpStr, "()", 1)

    for iter in tmpStr:
        if iter.isalpha():
            resultStr = iter
    indexA = lineStr.find('(A)')
    indexB = lineStr.find('(B)')
    indexC = lineStr.find('(C)')
    indexD = lineStr.find('(D)')
    resultA = lineStr[indexA+3:indexB-1]
    resultB = lineStr[indexB+3:indexC-1]
    resultC = lineStr[indexC+3:indexD-1]
    resultD = lineStr[indexD+3:len(lineStr)]
    index1 = lineStr.find('。')
    newLine = lineStr[0:index1+1] + '\t' + resultStr + '\t' + resultA + '\t' + resultB + '\t' + resultC + '\t' + resultD
    txt2.write(newLine)
    #print(newLine)
    #print(lineStr + '\t\t' + result + '\t\t' + str(index))