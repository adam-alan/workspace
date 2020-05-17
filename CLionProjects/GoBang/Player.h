//
// Created by zhuxingtian on 19-11-8.
//

#ifndef GOBANG_PLAYER_H
#define GOBANG_PLAYER_H

#include "GameState.h"
enum class BoardState;

class Player {
private:
    BoardState boardState;
public:
    Player(BoardState state);
    virtual int getNextPosition() = 0;
    BoardState getBoardState() const {
        return this->boardState;
    }
    virtual ~Player();
};


#endif //GOBANG_PLAYER_H
