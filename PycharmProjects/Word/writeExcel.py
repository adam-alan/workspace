import xlwt


def getLineNum(line):
    line = str(line)
    index = line.find('.')
    return line[0:index]

result = open("/home/zhuxingtian/result.txt", "r")
wb = xlwt.Workbook()
sheet = wb.add_sheet("xxxx")
list = []

for line in result.readlines():
    lineNum = getLineNum(line)
    line = line.replace(lineNum + '.', '')
    list.append(line)

firstLine = ['题目', '答案解析', '正确答案', '选项A', '选项B', '选项C', '选项D', '选项E', '选项F']
for iter in range(0, 9):
    sheet.write(0, iter, firstLine[iter])


for i in range(1, 430):
    lineStr = list[i].split('\t', 6)
    lineStr[1] = '\t' + lineStr[1]
    for j in range(0, 6):
        sheet.write(i, j, lineStr[j])

wb.save("/home/zhuxingtian/test1.xls")