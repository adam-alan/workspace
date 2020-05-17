package protocol
const (
	GeneralUserMessageType uint8 = 100
	GeneralGroupUserMessageType uint8 = 101
	LoginMessageType uint8 = 102
)

type GeneralUserMessage struct {
	SenderID uint64	"json:senderID"
	ReceiverID uint64	"json:receicverID"
	Content string	"json:content"
	Ack bool	"json:ack"
	Seq bool	"json:seq"
}

type GroupUserMessage struct {
	SenderID uint64 "json:senderID"
	ReceiverID uint64 "json:receicverID"
	Content string "json:content"
	Seq bool "json:seq"
	Ack bool "json:ack"
}

type LoginMessage struct {
	ID uint64
	Name string
	PassWord string
}
