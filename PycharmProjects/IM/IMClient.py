import socket
import BaseInfor

clientSocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)



zhangsan = BaseInfor.user(1, "zhangsan")
lisi = BaseInfor.user(2, "lisi")
userName = input()

clientSocket.connect(("", 10000))

while True:
    recvUserName = input()
    data = input()
    msg = BaseInfor.message(userName, recvUserName, data)
    clientSocket.send(str(msg).encode())

    recvData = clientSocket.recv(4096)
    print(recvData.decode())
