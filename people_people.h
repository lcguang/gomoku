#ifndef PEOPLE_PEOPLE_H
#define PEOPLE_PEOPLE_H

#include "board.h"

class PeoplePeople : public Board {
public:
    PeoplePeople();
    ~PeoplePeople();
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // PEOPLE_PEOPLE_H
