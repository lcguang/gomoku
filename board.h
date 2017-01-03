#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();
    ~Board();

    int isWin(int, int);
    std::vector<std::vector<int>> chessboard_;
    int player_;

private:
    int f1(int, int);
    int f2(int, int);
    int f3(int, int);
    int f4(int, int);
};

#endif // BOARD_H
