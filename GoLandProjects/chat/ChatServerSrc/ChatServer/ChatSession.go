package ChatServer

import (
	"chat/Protocol"
	"encoding/json"
	"fmt"
	"log"
	"net"
)


type ChatSession struct {
	User protocol.OnlineUser
	Conn net.Conn
	IsLogin bool
}


func (self * ChatSession)onGeneralUserChatResponce(message [] byte){
	var generalUserMessage protocol.GeneralUserMessage
	err := json.Unmarshal(message,&generalUserMessage)
	if err != nil {
		log.Println(err)
	}

	chatServer := GetInstanceOfChatServer();
	messagePacket := protocol.MessagePacket{
		MessageType: protocol.GeneralUserMessageType,
		Message:     message,
	}
	fmt.Printf("%s\n",message)
	chatServer.Sessions.Range(func(key, value interface{}) bool {
		session := value.(ChatSession)
		fmt.Println(session.User.ID,session.User.Name,session.User.PassWord)
		return true
	})
	chatServer.Sessions.Range(func(key, value interface{}) bool {
		session := value.(ChatSession)
		if session.User.ID == generalUserMessage.ReceiverID {
			protocol.WriteMessagePacket(session.Conn,messagePacket)
			fmt.Println("send success")
		}
		return true
	})


}

func (self * ChatSession)onLoginResponce(message [] byte){
	var loginMessage protocol.LoginMessage
	err := json.Unmarshal(message,&loginMessage)
	if err != nil {
		log.Println(err)
	}
	session := ChatSession{
		User:    protocol.OnlineUser{
			ID:       loginMessage.ID,
			Name:     loginMessage.Name,
			PassWord: loginMessage.PassWord,
		},
		Conn:    self.Conn,
		IsLogin: true,
	}
	chatServer := GetInstanceOfChatServer()
	chatServer.Sessions.Store(self.Conn,session)
	if self.IsLogin {
		return
	}
	messagePacket := protocol.MessagePacket{
		MessageType: protocol.LoginMessageType,
		Message:     message,
	}
	fmt.Println(loginMessage)
	protocol.WriteMessagePacket(self.Conn,messagePacket)
}

func (self * ChatSession)OnRead(conn net.Conn){
	for {
		messagePacket := protocol.ReadMessagePacket(conn);
		if messagePacket == nil {
			continue
		}
		self.messageDispatcher(*messagePacket)
	}
}

func (self * ChatSession)messageDispatcher(messagePacket protocol.MessagePacket){
	switch messagePacket.MessageType {
	case protocol.LoginMessageType:
		self.onLoginResponce(messagePacket.Message)
	case protocol.GeneralUserMessageType:
		self.onGeneralUserChatResponce(messagePacket.Message)
	}
}
