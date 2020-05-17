import socket
'''
申请监听socket
'''
listenSocket = socket.socket()
'''
设置主机及其端口
'''
host = socket.gethostname()
port = socket.htons(10000)
'''
bind绑定socket
'''
listenSocket.bind((host,port))
'''
listen监听socket
'''
listenSocket.listen(10);

'''
向已连接的客户端发送信息
'''
while True:
    (connectSocket, addr) = listenSocket.accept();
    print("连接地址", addr)
    msg = connectSocket.recv(1024).decode()
    if msg == 'i am active':
        connectSocket.send('OK'.encode())
    else:
        connectSocket.close()
