class user(object):
    def __init__(self, id, name):
        self.id = id
        self.name = name



class message(object):
    def __init__(self, sendUser, recvUser, text):
        self.sendUser = sendUser
        self.recvUser = recvUser
        self.text = text