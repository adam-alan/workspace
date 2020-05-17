import docx

file = docx.Document('/home/zhuxingtian/judge.docx')

txt = open('/home/zhuxingtian/judgedResult.txt','w')

for para in file.paragraphs:
    print(para.text)
    txt.writelines(para.text + '\n')

