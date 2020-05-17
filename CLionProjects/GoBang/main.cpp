//
// Created by zhuxingtian on 19-11-7.
//

#include <iostream>
#include <vector>
#include "ACSymbolTable.h"
#include "GameState.h"
#include "ComputerPlayer.h"


int main(){
    /*ACSymbolTable<uint32_t> table;
    for(auto item:paternsAndScore){
        table.put(item.first,item.second);
    }
    table.buildFailurePointer();

    for (auto item:table.match("0001100000")){
        std::cout << item << std::endl;
    }*/
    GameState gameState;
    ComputerPlayer computerPlayer(BoardState::WHITE_CHESS);
    /*
    for(auto item:gameState.getFourDirectionsChess(0,7)){
        gameState.printArray(item);
    }*/

    for (auto item:gameState.fourDirectionsChessToString(computerPlayer,0,7)){
        std::cout << item << std::endl;
    }
    return 0;
}