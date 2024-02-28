#ifndef DIEFACE_H
#define DIEFACE_H

enum direction
{
    DIR_UP = 0,
    DIR_LEFT = 1,
    DIR_DOWN = 2,
    DIR_RIGHT = 3
};

class DieFace
{
public:
    DieFace(int faceNum);

    void populateFaces(DieFace* up, DieFace* left, DieFace* right, DieFace* down);
    void setRotation(DieFace* fromFace, direction rollDir);

    DieFace* nextFaceUp() const;
    DieFace* nextFaceLeft() const;
    DieFace* nextFaceDown() const;
    DieFace* nextFaceRight() const;

    int getValue() const;
    void setValue(int value);

    int getFaceNum() const;

private:
    DieFace* getCorrectRotation(direction dir) const;

    int mFaceNum;
    int mValue;
    int mRotation;
    DieFace* mNextFaceUp;
    DieFace* mNextFaceLeft;
    DieFace* mNextFaceDown;
    DieFace* mNextFaceRight;
};

#endif // DIEFACE_H
