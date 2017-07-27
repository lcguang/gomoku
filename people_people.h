#ifndef PEOPLE_PEOPLE_H
#define PEOPLE_PEOPLE_H

#include "board.h"
#include "logger.h"

class PeoplePeople : public Board {
public:
    PeoplePeople();
    ~PeoplePeople();
    void mouseReleaseEvent(QMouseEvent *);

private:
	Logger* logger_;
};

#endif // PEOPLE_PEOPLE_H
