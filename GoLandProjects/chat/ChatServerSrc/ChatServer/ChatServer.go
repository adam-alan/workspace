package ChatServer

import (

	"log"
	"net"
	"sync"
)

type ChatServer struct {
	Sessions sync.Map
}
var once sync.Once
var chatServer * ChatServer = nil

func GetInstanceOfChatServer()(* ChatServer){
	once.Do(func() {
		chatServer = new(ChatServer)
	})
	return chatServer
}

func (self * ChatServer)StartService(){
	server, err := net.Listen("tcp","localhost:60000")
	if err != nil {
		log.Fatal(err)
	}
	for {

		conn, err := server.Accept()
		if err != nil {
			log.Println(err)
		}
		session := ChatSession{
			User: OnlineUser{
				ID:       0,
				Name:     "",
				PassWord: "",
			},
			Conn:conn,
			IsLogin: false,
		}
		self.Sessions.Store(conn, session)
		go session.OnRead(conn)
	}
}