package protocol

import (
	"bytes"
	"encoding/binary"
	"io"
	"log"
	"net"
)

type MessagePacket struct {
	MessageType uint8
	Message [] byte
}

func ReadMessagePacket(conn net.Conn) (* MessagePacket){
	packetHead := make([]byte,4)
	readNum,err := io.ReadFull(conn,packetHead)
	if err != nil {
		if readNum == 0 {
			return nil
		}
		log.Printf("%s %s\n","ReadMessage:",err)
	}
	size := binary.BigEndian.Uint32(packetHead)
	log.Println(size)
	packet := make([]byte,size)
	_,err = io.ReadFull(conn,packet)
	if err != nil {
		log.Printf("%s %s\n","ReadMessage:",err)
	}
	var messagePacket MessagePacket
	messagePacket.Message = packet[1:]
	messagePacket.MessageType = packet[0]
	return &messagePacket
}


func WriteMessagePacket(conn net.Conn, messagePacket MessagePacket)(uint32) {
	length := uint32(len(messagePacket.Message)) + 1
	buf := bytes.NewBuffer(make([]byte,0))
	binary.Write(buf,binary.BigEndian,length)
	binary.Write(buf,binary.BigEndian,messagePacket.MessageType)

	packet := buf.Bytes()
	for _,value := range messagePacket.Message {
		packet = append(packet,value)
	}
	conn.Write(packet)
	return uint32(length)
}
