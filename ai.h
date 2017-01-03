#ifndef AI_H
#define AI_H

#include "board.h"
#include <map>
#include <set>

class AI {
public:
    AI();
    ~AI();
    void updateBoard(int, int, int);
    std::pair<int, int> calculate();

private:
    void initWinMatrix();

    Board* board_;
    std::vector<std::vector<std::vector<bool>>> win_matrix_;
    std::vector<std::vector<long long>> player_score_;
    std::vector<std::vector<long long>> ai_score_;
    std::vector<int> player_win_;
    std::vector<int> ai_win_;
    std::map<std::pair<int, int>, std::set<int>> pos_win_map_;
    int win_count_;
};

#endif // AI_H
