//
// Created by zhuxingtian on 19-11-8.
//

#ifndef GOBANG_EVALUATOR_H
#define GOBANG_EVALUATOR_H


#include "Player.h"
#include "ACSymbolTable.h"
#include "GameState.h"
class GameState;
class Player;



class Evaluator {
public:
    Evaluator();
    int evaluateFourDircetions(Player & player,GameState & gameState,int x,int y);
    int evaluateBoardState();
private:
    const std::vector<std::pair<std::string,uint32_t>> paternsAndScore
    {
        {"11111",50000},
        {"011110",4320},
        {"011100",720},
        {"001110",720},
        {"011010",720},
        {"010110",720},
        {"11110",720},
        {"01111",720},
        {"11011",720},
        {"10111",720},
        {"11101",720},
        {"001100",120},
        {"001010",120},
        {"010100",120},
        {"000100",20},
        {"001000",10},
    };
    ACSymbolTable<uint32_t > acSymbolTable;
};


#endif //GOBANG_EVALUATOR_H
