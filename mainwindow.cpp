#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    resize(640, 640);
    board_ = new Board();
    ai_ = new AI();
}

MainWindow::~MainWindow() {
    delete board_;
    delete ai_;
}

void MainWindow::paintEvent(QPaintEvent *) {
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
            if (board_->chessboard_[i][j] == 1) {
                brush.setColor(Qt::black);
                p.setBrush(brush);
                p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);
            } else if (board_->chessboard_[i][j] == 2) {
                brush.setColor(Qt::white);
                p.setBrush(brush);
                p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);
            }
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e) {
    int x, y;
    if (e->x() >= 20 && e->x() < 620 && e->y() >= 20 && e->y() < 620) {
        x = (e->x() - 20) / 40;
        y = (e->y() - 20) / 40;
        if (!board_->chessboard_[x][y]) {
            board_->chessboard_[x][y] = 1;
        }
        update();
        if (board_->isWin(x, y)) {
            update();
            setEnabled(false);
            QMessageBox::information(this, "Win", "Win", QMessageBox::Ok);
        }
        ai_->updateBoard(x, y, 1);
        std::pair<int, int> pos = ai_->calculate();
        board_->chessboard_[pos.first][pos.second] = 2;
        ai_->updateBoard(pos.first, pos.second, 2);
        if (board_->isWin(pos.first, pos.second)) {
            update();
            setEnabled(false);
            QMessageBox::information(this, "Lose", "Lose", QMessageBox::Ok);
        }
    }
    update();
}
