//
// Created by zhuxingtian on 19-11-8.
//

#ifndef GOBANG_COMPUTERPLAYER_H
#define GOBANG_COMPUTERPLAYER_H

#include <functional>
#include "Player.h"

class ComputerPlayer: public Player{
public:
    explicit ComputerPlayer(BoardState state);
    int getNextPosition() override ;
     ~ComputerPlayer() override ;
};


#endif //GOBANG_COMPUTERPLAYER_H
