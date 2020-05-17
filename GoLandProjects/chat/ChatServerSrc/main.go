package main

import "chat/ChatServerSrc/ChatServer"

func main()  {
	chatserver := ChatServer.GetInstanceOfChatServer()
	chatserver.StartService()
}


