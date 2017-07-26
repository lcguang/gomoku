#ifndef BOARD_H
#define BOARD_H

#include <QFrame>
#include <vector>

class Board : public QFrame {
    Q_OBJECT

public:
    Board();
    ~Board();

    virtual void paintEvent(QPaintEvent *);

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
