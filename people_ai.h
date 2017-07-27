#ifndef PEOPLE_AI_H
#define PEOPLE_AI_H

#include <map>
#include <set>
#include "board.h"
#include "logger.h"

class PeopleAi : public Board {
public:
    PeopleAi();
    ~PeopleAi();
    void mouseReleaseEvent(QMouseEvent *);

    void aiUpdateBoard(int, int, int);
    std::pair<int, int> aiCalculate();

private:
    void initWinMatrix();

private:
    std::vector<std::vector<std::vector<bool>>> win_matrix_;
    std::vector<std::vector<long long>> player_score_;
    std::vector<std::vector<long long>> ai_score_;
    std::vector<int> player_win_;
    std::vector<int> ai_win_;
    std::map<std::pair<int, int>, std::set<int>> pos_win_map_;
    int win_count_;

    Logger* logger_;
};

#endif // PEOPLE_AI_H
