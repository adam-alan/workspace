//
// Created by zhuxingtian on 19-11-8.
//

#include "Evaluator.h"


Evaluator::Evaluator() {
    for (const auto & item:paternsAndScore){
        acSymbolTable.put(item.first,item.second);
    }
    acSymbolTable.buildFailurePointer();
}
int Evaluator::evaluateFourDircetions(Player &player, GameState &gameState, int x, int y) {
    std::vector<std::string> fourDirectionsStrings{gameState.fourDirectionsChessToString(player, x, y)};
    int scores{0};
    for (const auto & item:fourDirectionsStrings){
        for(const auto & item1:acSymbolTable.match(item)){
            scores += *acSymbolTable.get(item1);
        }
    }
    return scores;
}
int Evaluator::evaluateBoardState() {
    return 0;
}