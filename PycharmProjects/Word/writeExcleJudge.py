import xlwt


txt = open('/home/zhuxingtian/judgedResult.txt', 'r')
wb = xlwt.Workbook()
sheet = wb.add_sheet("xxxx")
list = []

def getLineNum(line):
    line = str(line)
    index = line.find('.')
    return line[0:index]

for line in txt.readlines():
    lIndex = line.find('(')
    rIndex = line.find(')')
    result = line[lIndex:rIndex+1]
    line = line.replace(result, '')
    line = line.strip()
    line = line.strip('\n')
    line = line + '\t' + result
    list.append(line)



for i in range(0, 229):
    listLine = list[i]
    lineNum = getLineNum(listLine)
    lineNum += '.'
    listLine = listLine.replace(lineNum, '')
    listLine = listLine.strip()
    listLine = listLine.split('\t')
    for j in range(0, 2):
        print(listLine[0] + '\t' + listLine[1])
        sheet.write(i, j, listLine[j])

wb.save("/home/zhuxingtian/test2.xls")
