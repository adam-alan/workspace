//
// Created by zhuxingtian on 19-11-7.
//

#include "GameState.h"
#include <iostream>

GameState::GameState() :evaluator(){
    for (auto & item:boardState){
        item = BoardState::EDGE;
    }
    //printArray(board);
    for (int i = 0;i < 15;i++){
        for (int j = 0;j < 15;j++){
            boardState[17 + j + i * 16] = BoardState::NONE_CHESS;
        }
    }
    //printArray(board);
}


std::vector<std::vector<BoardState>> GameState::getFourDirectionsChess(int x, int y) {
    std::vector<std::vector<BoardState>> result(4,std::vector<BoardState >());
    for(int i = 0;i < 4;i++){
        int begin = 17 + y + x * 16;
        result[i].insert(result[i].end(),boardState[begin]);

        int directionIncrease = directionIncreases[i];
        while (boardState[begin - directionIncrease] != BoardState::EDGE and directionIncrease != 5*directionIncreases[i]) {
            result[i].insert(result[i].begin(),boardState[begin - directionIncrease]);
            directionIncrease += directionIncreases[i];
        }

        directionIncrease = directionIncreases[i];
        while (boardState[begin + directionIncrease] != BoardState::EDGE and directionIncrease != 5*directionIncreases[i]) {
            result[i].insert(result[i].end(),boardState[begin + directionIncrease]);
            directionIncrease += directionIncreases[i];
        }
    }
    return result;
}

std::vector<std::string> GameState::fourDirectionsChessToString(Player &player, int x, int y) {
    auto fourDirections{getFourDirectionsChess(x,y)};
    std::vector<std::string> fourDirectionsString(4);
    for (int i = 0;i < 4;i++){
        for(auto item:fourDirections[i]){
            switch (item){
                case BoardState::NONE_CHESS:
                    fourDirectionsString[i].push_back('0');
                    break;
                case BoardState::WHITE_CHESS:
                    if (player.getBoardState() == BoardState::WHITE_CHESS){
                        fourDirectionsString[i].push_back('1');
                    } else{
                        fourDirectionsString[i].push_back('2');
                    }
                    break;
                case BoardState::BLACK_CHESS:
                    if (player.getBoardState() == BoardState::WHITE_CHESS){
                        fourDirectionsString[i].push_back('1');
                    } else {
                        fourDirectionsString[i].push_back('2');
                    }
                    break;
            }
        }
    }
    return fourDirectionsString;
}
std::vector<std::vector<BoardState>> GameState::getAllRowsChess() {
    std::vector<std::vector<BoardState>> result(15,std::vector<BoardState>());
    for (int i = 0;i < 15;i++){
        for (int j = 0;j < 15;j++){
            result[i][j] = boardState[17 + j + i * 16];
        }
    }
    return result;
}

std::vector<std::vector<BoardState>> GameState::getAllColrolsChess() {
    std::vector<std::vector<BoardState>> result(15,std::vector<BoardState>());
    for (int i = 0;i < 15;i++){
        for (int j = 0;j < 15;j++){
            result[j][i] = boardState[17 + i +  j * 16];
        }
    }
    return result;
}

std::vector<std::vector<BoardState>> GameState::getAllForwardSlashChess() {
    std::vector<std::vector<BoardState>> result(15,std::vector<BoardState>());

    for (int i = 0;i < 15;i++){
        int begin = 17 + i + 16 * i;
        result[i].insert(result[i].end(),boardState[begin]);
        auto directionIncrease = directionIncreases[3];

        while (boardState[begin + directionIncrease ] != BoardState::EDGE) {
            result[i].insert(result[i].end(),boardState[begin + directionIncrease]);
            directionIncrease += directionIncreases[3];
        }
        directionIncrease = directionIncreases[3];
        while (boardState[begin - directionIncrease ] != BoardState::EDGE) {
            result[i].insert(result[i].end(),boardState[begin - directionIncrease]);
            directionIncrease += directionIncreases[3];
        }
    }
}

std::vector<std::vector<BoardState>> GameState::getAllBackSlashChess() {
    std::vector<std::vector<BoardState>> result(15,std::vector<BoardState>());

    for (int i = 0;i < 15;i++){
        int begin = 17 + i + 16 * i;
        result[i].insert(result[i].end(),boardState[begin]);
        auto directionIncrease = directionIncreases[2];

        while (boardState[begin + directionIncrease ] != BoardState::EDGE) {
            result[i].insert(result[i].end(),boardState[begin + directionIncrease]);
            directionIncrease += directionIncreases[2];
        }
        directionIncrease = directionIncreases[2];
        while (boardState[begin - directionIncrease ] != BoardState::EDGE) {
            result[i].insert(result[i].end(),boardState[begin - directionIncrease]);
            directionIncrease += directionIncreases[2];
        }
    }
}


void GameState::printArray(const std::vector<BoardState> boardState){
    for (int i = 0 ; i < boardState.size();i++){
        /*
        if (i % 16 == 0 and i != 272) {
            std::cout << std::endl;
        }*/
        switch (boardState[i]){
            case BoardState::NONE_CHESS:
                std::cout << 0 << " ";
                break;
            case BoardState::EDGE:
                std::cout << 1 << " ";
                break;
        }

    }
    std::cout << std::endl;
}

