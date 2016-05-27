
#ifndef BRACKET_H
#define BRACKET_H

class Bracket {
private:
    int count;
    bool inside;
public:
    bool isInside();
    void setInside();
    int getCount();
    void incCount();
    void setCount(int);

    Bracket();
};


#endif //CURS_ADA_BRACKET_H
