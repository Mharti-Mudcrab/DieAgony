#ifndef DIE_H
#define DIE_H

#include "Dieface.h"

class Die
{
public:
    Die();

    int rollUp();
    int rollLeft();
    int rollDown();
    int rollRight();

    int peakValue(direction dir) const;

    int getCurrentFace() const;

    int getCurrentValue() const;
    void setCurrentValue(int val);


private:
    DieFace* mFaces[6];
    int mIdx;
};

#endif // DIE_H
