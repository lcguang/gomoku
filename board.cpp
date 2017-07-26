#include <QPainter>
#include "board.h"

Board::Board() {
    resize(640, 640);
    chessboard_.resize(15, std::vector<int>(15, 0));
    player_ = 1;
}

Board::~Board() {

}

void Board::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    int i, j;
    for (i = 0; i < 16; i++) {
        p.drawLine(20, 20 + i * 40, 620, 20 + i * 40);
        p.drawLine(20 + i * 40, 20, 20 + i * 40, 620);
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            if (chessboard_[i][j] == 1) {
                brush.setColor(Qt::black);
                p.setBrush(brush);
                p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);
            } else if (chessboard_[i][j] == 2) {
                brush.setColor(Qt::white);
                p.setBrush(brush);
                p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);
            }
        }
    }
}

int Board::isWin(int x, int y) {
     return f1(x, y) || f2(x, y) || f3(x, y) || f4(x ,y);
}

int Board::f1(int x, int y) {
    int i;
    for (i = 0; i < 5; i++) {
        if(y - i >= 0 &&
           y + 4 - i <= 0xF &&
           chessboard_[x][y - i] == chessboard_[x][y + 1 - i] &&
           chessboard_[x][y - i] == chessboard_[x][y + 2 - i] &&
           chessboard_[x][y - i] == chessboard_[x][y + 3 - i] &&
           chessboard_[x][y - i] == chessboard_[x][y + 4 - i]) return 1;
    }
    return 0;
}

int Board::f2(int x, int y) {
    int i;
    for (i = 0; i < 5; i++) {
        if(x - i >= 0 &&
           x + 4 - i <= 0xF &&
           chessboard_[x - i][y] == chessboard_[x + 1 - i][y] &&
           chessboard_[x - i][y] == chessboard_[x + 2 - i][y] &&
           chessboard_[x - i][y] == chessboard_[x + 3 - i][y] &&
           chessboard_[x - i][y] == chessboard_[x + 4 - i][y]) return 1;
    }
    return 0;
}

int Board::f3(int x, int y) {
    int i;
    for (i = 0; i < 5; i++) {
        if(x - i >= 0 &&
           y - i >= 0 &&
           x + 4 - i <= 0xF &&
           y + 4 - i <= 0xF &&
           chessboard_[x - i][y - i] == chessboard_[x + 1 - i][y + 1 - i] &&
           chessboard_[x - i][y - i] == chessboard_[x + 2 - i][y + 2 - i] &&
           chessboard_[x - i][y - i] == chessboard_[x + 3 - i][y + 3 - i] &&
           chessboard_[x - i][y - i] == chessboard_[x + 4 - i][y + 4 - i]) return 1;
    }
    return 0;
}

int Board::f4(int x, int y) {
    int i;
    for (i = 0; i < 5; i++) {
        if(x + i <= 0xF &&
           y - i >= 0 &&
           x - 4 + i >= 0 &&
           y + 4 - i <= 0xF &&
           chessboard_[x + i][y - i] == chessboard_[x - 1 + i][y + 1 - i] &&
           chessboard_[x + i][y - i] == chessboard_[x - 2 + i][y + 2 - i] &&
           chessboard_[x + i][y - i] == chessboard_[x - 3 + i][y + 3 - i] &&
           chessboard_[x + i][y - i] == chessboard_[x - 4 + i][y + 4 - i]) return 1;
    }
    return 0;
}
