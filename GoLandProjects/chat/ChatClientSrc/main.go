package main

import (
	"chat/Protocol"
	"encoding/json"
	"fmt"
	"log"
	"net"
)

func main()  {

	client,err := net.Dial("tcp","localhost:60000")

	if err != nil {
		log.Fatal(err)
	}
	defer client.Close()
	go ReadMessage(client)


	var (
		generalUserID uint64
		generalUserName string
		generalUserPassWord string
	)

	fmt.Scan(&generalUserID,&generalUserName,&generalUserPassWord)

	loginMessage := protocol.LoginMessage{
		ID: generalUserID,
		Name: generalUserName,
		PassWord: generalUserPassWord,
	}
	fmt.Println(loginMessage)

	data,err := json.Marshal(loginMessage)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%s\n",data)
	messagePacket := protocol.MessagePacket{
		Message:     data,
		MessageType: protocol.LoginMessageType,
	}
	protocol.WriteMessagePacket(client,messagePacket)


	for {
		var receiver uint64
		fmt.Scan(&receiver)
		generalUserMessage := protocol.GeneralUserMessage{
			SenderID:   generalUserID,
			ReceiverID: receiver,
			Content:    "hello world",
			Ack:        false,
			Seq:        false,
		}

		data,err = json.Marshal(generalUserMessage)
		if err != nil {
			log.Fatal(err)
		}
		fmt.Printf("%s\n",data)
		messagePacket = protocol.MessagePacket{
			Message:     data,
			MessageType: protocol.GeneralUserMessageType,
		}
		protocol.WriteMessagePacket(client,messagePacket)
	}
}


func ReadMessage(conn net.Conn) {
	for {
		messagePacket := protocol.ReadMessagePacket(conn)
		if messagePacket == nil {
			continue
		}
		switch  {
		case messagePacket.MessageType == protocol.GeneralUserMessageType:
			var generalUserMessage protocol.GeneralUserMessage
			err := json.Unmarshal(messagePacket.Message,&generalUserMessage)
			if err != nil {
				log.Fatal(err)
			}
			fmt.Printf("SenderID = %d %s\n",generalUserMessage.SenderID,generalUserMessage.Content)

		case messagePacket.MessageType == protocol.LoginMessageType:
			var onlineuser protocol.OnlineUser
			err := json.Unmarshal(messagePacket.Message,&onlineuser)
			if err != nil {
				log.Fatal(err)
			}
			fmt.Println(onlineuser)
		}
	}
}