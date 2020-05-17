//
// Created by zhuxingtian on 19-11-7.
//

#ifndef GOBANG_GAMESTATE_H
#define GOBANG_GAMESTATE_H

#include <vector>
#include <string>
#include "Player.h"
#include "Evaluator.h"

enum class BoardState {
    NONE_CHESS,
    EDGE,
    WHITE_CHESS,
    BLACK_CHESS
};
class Player;
class Evaluator;

class GameState {
public:
    GameState();
    void printArray(const std::vector<BoardState> boardState);
    std::vector<std::string> fourDirectionsChessToString(Player & player,int x,int y);
    std::vector<std::string> allRowsChessToString();

private:
    std::vector<std::vector<BoardState>> getFourDirectionsChess(int x, int y);
    std::vector<std::vector<BoardState>> getAllRowsChess();
    std::vector<std::vector<BoardState>> getAllColrolsChess();
    std::vector<std::vector<BoardState>> getAllForwardSlashChess();
    std::vector<std::vector<BoardState>> getAllBackSlashChess();


    Evaluator evaluator;
    BoardState boardState[273];
    const int directionIncreases[4] = {1,16,17,15}; //Vertical:1;   Transverse:16; /:15;    \:17
};


#endif //GOBANG_GAMESTATE_H
