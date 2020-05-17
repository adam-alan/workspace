import socket
import time
import os
'''
申请客户端socket
'''
clientSocket = socket.socket()
'''
设置服务器地址与端口
'''
host = socket.gethostname()
port = socket.htons(10000)
'''
向服务器发起连接
'''
clientSocket.connect((host, port))
'''
得到初始时间
'''
initTime = int(time.clock_gettime(time.CLOCK_PROCESS_CPUTIME_ID))
print(initTime)

isSend = False
while True:
    nowTime = int(time.clock_gettime(time.CLOCK_PROCESS_CPUTIME_ID))
    canSend = (nowTime - initTime) % 3 == 0 and nowTime != initTime

    if canSend and isSend:
        isPrint = True
    else:
        isPrint = False

    if canSend and not isSend:
        isPrint = True
        print(nowTime)
        clientSocket.send("i am active".encode())
        msg = clientSocket.recv(1024).decode()
        print(msg)
        if msg != "OK":
            print("Good Bye")
            break

clientSocket.close()
