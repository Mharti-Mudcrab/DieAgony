#include "Dieface.h"
#include <stdexcept>
#include <math.h>
#include <iostream>

DieFace::DieFace(int faceNum)
    : mFaceNum{faceNum}, mValue{0}, mRotation{0}
{}

void DieFace::populateFaces(DieFace *up, DieFace *left, DieFace *down, DieFace *right)
{
    mNextFaceUp = up;
    mNextFaceLeft = left;
    mNextFaceDown = down;
    mNextFaceRight = right;
}

void DieFace::setRotation(DieFace *fromFace, direction rollDir)
{
    if (fromFace == mNextFaceUp)
    {
        mRotation = (4 + 0 + 2 - rollDir) % 4;
        return;
    }
    else if (fromFace == mNextFaceLeft)
    {
        mRotation = (4 + 1 + 2 - rollDir) % 4;
        return;
    }
    else if (fromFace == mNextFaceDown)
    {
        mRotation = (4 + 2 + 2 - rollDir) % 4;
        return;
    }
    else if (fromFace == mNextFaceRight)
    {
        mRotation = (4 + 3 + 2 - rollDir) % 4;
        return;
    }
}

DieFace* DieFace::getCorrectRotation(direction dir) const
{
    switch ( (dir + mRotation) % 4 )
    {
    case DIR_UP:
        return mNextFaceUp;
    case DIR_LEFT:
        return mNextFaceLeft;
    case DIR_DOWN:
        return mNextFaceDown;
    case DIR_RIGHT:
        return mNextFaceRight;

    default: // logical error
        throw new std::logic_error("Logical error invalid direction");
    }
}

DieFace* DieFace::nextFaceUp() const
{
    return getCorrectRotation(DIR_UP);
}

DieFace* DieFace::nextFaceLeft() const
{
    return getCorrectRotation(DIR_LEFT);
}

DieFace* DieFace::nextFaceDown() const
{
    return getCorrectRotation(DIR_DOWN);
}

DieFace* DieFace::nextFaceRight() const
{
    return getCorrectRotation(DIR_RIGHT);
}

int DieFace::getValue() const
{
    return mValue;
}

void DieFace::setValue(int value)
{
    mValue = value;
}

int DieFace::getFaceNum() const
{
    return mFaceNum;
}
