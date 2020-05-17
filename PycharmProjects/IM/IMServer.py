import socket
import select
import BaseInfor

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
serverSocket.bind(("", 10000))
serverSocket.listen(100)

poll = select.poll()
connections = {}
handlers = {}


def handleInput(socket, data):
    socket.send(data)


def handleRequest(fileno, event):
    if event & select.POLLIN:
        clientSocket = connections[fileno]
        data = clientSocket.recv(4096)
        if data:
            handleInput(clientSocket, data)
        else:
            poll.unregister(fileno)
            clientSocket.close()
            del connections[fileno]
            del handlers[fileno]


def handleAccept(filene, event):
    (clientSocket, clientAddress) = serverSocket.accept()
    print("got connection from" + str(clientAddress))

    poll.register(clientSocket.fileno(), select.POLLIN)
    connections[clientSocket.fileno()] = clientSocket
    handlers[clientSocket.fileno()] = handleRequest


poll.register(serverSocket.fileno(), select.POLLIN)
handlers[serverSocket.fileno()] = handleAccept


while True:
    events = poll.poll(1000)
    for fileno, event in events:
        handler = handlers[fileno]
        handler(fileno, event)
