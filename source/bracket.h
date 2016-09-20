#ifndef BRACKET_H
#define BRACKET_H

class Bracket {
private:
    int count;
    bool inside;
/*
- count is amount of brackets in this spot 
- "inside" means this bracket space is inside 2 brackets,
* so count can't be incremented no more.
*/

public:
    bool isInside();
    void setInside();
    int getCount();
    void incCount();
    void setCount(int);

    Bracket();
};

#endif //CURS_ADA_BRACKET_H