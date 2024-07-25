#include "GameObjectPyramid.h"
#include <iostream>
#include <cmath> // For sin and cos functions

namespace Azul
{
    GameObjectPyramid::GameObjectPyramid(GraphicsObject* poGraphicsObject)
        : GameObject(poGraphicsObject) // Initialize base class
    {}

    void GameObjectPyramid::setRotation(float _radius)
    {
        this->radius = _radius;
    }

    void GameObjectPyramid::setSpeed(float _speed)
    {
        this->speed = _speed;
    }

    void GameObjectPyramid::Update()
    {
        // Example of a time-based transformation
        static float time = 0.0f;
        time += speed; // Increment time (assuming 60 FPS, so roughly 0.016 seconds per frame)

        // Move in a circular path
        poPos->x(radius * cos(time));
        poPos->z(radius * sin(time));


        // Translate to the new position
        Trans TransA(poPos->x(), poPos->y(), poPos->z());
        Scale ScaleA(scale, scale, scale);

        // Combine transformations: Scale, Rotate, and Translate
        *this->poWorld = ScaleA * TransA;

        // PUSH to Graphics object
        this->poGraphicsObject->SetWorld(*this->poWorld);

    }

    void GameObjectPyramid::ChangeTexture(TextureObject* pTex)
    {
        this->poGraphicsObject->ChangeTexture(pTex);
    }


}
