#include "Die.h"

Die::Die()
    : mIdx{5}
{
    mFaces[0] = new DieFace(1);
    mFaces[1] = new DieFace(2);
    mFaces[2] = new DieFace(3);
    mFaces[3] = new DieFace(4);
    mFaces[4] = new DieFace(5);
    mFaces[5] = new DieFace(6);
 //                             up        left       down        right
    mFaces[0]->populateFaces(mFaces[1], mFaces[2], mFaces[4], mFaces[3]);
    mFaces[1]->populateFaces(mFaces[5], mFaces[2], mFaces[0], mFaces[3]);
    mFaces[2]->populateFaces(mFaces[5], mFaces[4], mFaces[0], mFaces[1]);
    mFaces[3]->populateFaces(mFaces[0], mFaces[4], mFaces[5], mFaces[1]);
    mFaces[4]->populateFaces(mFaces[0], mFaces[2], mFaces[5], mFaces[3]);
    mFaces[5]->populateFaces(mFaces[4], mFaces[2], mFaces[1], mFaces[3]);
}

int Die::rollUp()
{
    mFaces[mIdx]->nextFaceUp()->setRotation(mFaces[mIdx], DIR_UP);
    mIdx = mFaces[mIdx]->nextFaceUp()->getFaceNum() -1;
    return mIdx +1;
}

int Die::rollLeft()
{
    mFaces[mIdx]->nextFaceLeft()->setRotation(mFaces[mIdx], DIR_LEFT);
    mIdx = mFaces[mIdx]->nextFaceLeft()->getFaceNum() -1;
    return mIdx +1;
}

int Die::rollDown()
{
    mFaces[mIdx]->nextFaceDown()->setRotation(mFaces[mIdx], DIR_DOWN);
    mIdx = mFaces[mIdx]->nextFaceDown()->getFaceNum() -1;
    return mIdx +1;
}

int Die::rollRight()
{
    mFaces[mIdx]->nextFaceRight()->setRotation(mFaces[mIdx], DIR_RIGHT);
    mIdx = mFaces[mIdx]->nextFaceRight()->getFaceNum() -1;
    return mIdx +1;
}

int Die::peakValue(direction dir) const
{
    switch (dir) {
    case DIR_UP:
        return mFaces[mIdx]->nextFaceUp()->getValue();
        break;
    case DIR_LEFT:
        return mFaces[mIdx]->nextFaceLeft()->getValue();
        break;
    case DIR_DOWN:
        return mFaces[mIdx]->nextFaceDown()->getValue();
        break;
    case DIR_RIGHT:
        return mFaces[mIdx]->nextFaceRight()->getValue();
        break;
    default:
        break;
    }
}

int Die::getCurrentFace() const
{
    return mFaces[mIdx]->getFaceNum();
}

int Die::getCurrentValue() const
{
    return mFaces[mIdx]->getValue();
}

void Die::setCurrentValue(int val)
{
    mFaces[mIdx]->setValue(val);
}
