#include <QMessageBox>
#include <QMouseEvent>
#include "people_people.h"

PeoplePeople::PeoplePeople() {
    logger_ = new Logger("people_people_log.txt");
}

PeoplePeople::~PeoplePeople() {
    delete logger_;
}

void PeoplePeople::mouseReleaseEvent(QMouseEvent *e) {
    int x, y;
    if (e->x() >= 20 && e->x() < 620 && e->y() >= 20 && e->y() < 620) {
        x = (e->x() - 20) / 40;
        y = (e->y() - 20) / 40;
        logger_->writeLog(x, y);
        if (!chessboard_[x][y]) {
            chessboard_[x][y] = player_;
            player_ = 3 - player_;
        }
        update();
        if (isWin(x, y)) {
            update();
            setEnabled(false);
            QString player_win(player_ == 1 ? "White Win" : "Black Win");
            QMessageBox::information(this, "Win", player_win, QMessageBox::Ok);
            return;
        }
    }
    update();
}
