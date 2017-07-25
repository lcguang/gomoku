#include "ai.h"

AI::AI() {
    board_ = new Board();
    win_matrix_.resize(15, std::vector<std::vector<bool>>(15, std::vector<bool>(572, false)));
    player_score_.resize(15, std::vector<long long>(15, 0));
    ai_score_.resize(15, std::vector<long long>(15, 0));
    win_count_ = 0;
    //player_color_ = 1;
    initWinMatrix();
    player_win_.resize(win_count_, 0);
    ai_win_.resize(win_count_, 0);
}

AI::~AI() {
    delete board_;
}

void AI::updateBoard(int x, int y, int val) {
    board_->chessboard_[x][y] = val;
    std::pair<int, int> pos = std::make_pair(x, y);
    auto it = pos_win_map_[pos].begin();
    while (it != pos_win_map_[pos].end()) {
        if (val == 1) player_win_[*it]++;
        else ai_win_[*it]++;
        it++;
    }
}

void AI::initWinMatrix() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 11; j++) {
            for (int k = 0; k < 5; k++) {
                win_matrix_[i][j + k][win_count_] = true;
                std::pair<int, int> pos = std::make_pair(i, j + k);
                pos_win_map_[pos].insert(win_count_);
            }
            win_count_++;
        }
    }
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 15; j++) {
            for (int k = 0; k < 5; k++) {
                win_matrix_[i + k][j][win_count_] = true;
                std::pair<int, int> pos = std::make_pair(i + k, j);
                pos_win_map_[pos].insert(win_count_);
            }
            win_count_++;
        }
    }
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            for (int k = 0; k < 5; k++) {
                win_matrix_[i + k][j + k][win_count_] = true;
                std::pair<int, int> pos = std::make_pair(i + k, j + k);
                pos_win_map_[pos].insert(win_count_);
            }
            win_count_++;
        }
    }
    for (int i = 0; i < 11; i++) {
        for (int j = 14; j > 3; j--) {
            for (int k = 0; k < 5; k++) {
                win_matrix_[i + k][j - k][win_count_] = true;
                std::pair<int, int> pos = std::make_pair(i + k, j - k);
                pos_win_map_[pos].insert(win_count_);
            }
            win_count_++;
        }
    }
}

std::pair<int, int> AI::calculate() {
    int max = 0;
    int x = 0, y = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (0 == board_->chessboard_[i][j]) {
                for (int k = 0; k < win_count_; k++) {
                    if (win_matrix_[i][j][k]) {
                        if (1 == player_win_[k]) {
                            player_score_[i][j] += 200;     // oringinal: 200
                        } else if (2 == player_win_[k]) {
                            player_score_[i][j] += 400;     // oringinal: 400
                        } else if (3 == player_win_[k]) {
                            player_score_[i][j] += 2000;    // oringinal: 2000
                        } else if (4 == player_win_[k]) {
                            player_score_[i][j] += 10000;   // oringinal: 10000
                        }
                        if (1 == ai_win_[k]) {
                            ai_score_[i][j] += 320;         // oringinal: 320
                        } else if (2 == ai_win_[k]) {
                            ai_score_[i][j] += 420;         // oringinal: 420
                        } else if (3 == ai_win_[k]) {
                            ai_score_[i][j] += 4200;        // oringinal: 4200
                        } else if (4 == ai_win_[k]) {
                            ai_score_[i][j] += 20000;       // oringinal: 20000
                        }
                    }
                }
                if (player_score_[i][j] > max) {
                    max = player_score_[i][j];
                    x = i;
                    y = j;
                } else if (player_score_[i][j] == max) {
                    if (ai_score_[i][j] > ai_score_[x][y]) {
                        x = i;
                        y = j;
                    }
                }
                if (ai_score_[i][j] > max) {
                    max = ai_score_[i][j];
                    x = i;
                    y = j;
                } else if (ai_score_[i][j] == max) {
                    if (player_score_[i][j] > player_score_[x][y]) {
                        x = i;
                        y = j;
                    }
                }
            }
        }
    }
    std::pair<int, int> pos = std::make_pair(x, y);
    return pos;
}
