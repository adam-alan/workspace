package protocol


type GeneralUser  struct {
	ID uint64
	Name string
	PassWord string
}

type OnlineUser struct {
	ID uint64
	Name string
	PassWord string
}


type GroupUser struct {
	ID uint64
	Name string
}

type Friend struct {
	FriendId uint64
	MarkName string
	TeamName string
}

