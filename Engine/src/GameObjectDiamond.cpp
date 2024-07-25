#include "GameObjectDiamond.h"
#include <iostream>
#include <cmath> // For sin and cos functions

namespace Azul
{
    GameObjectDiamond::GameObjectDiamond(GraphicsObject* poGraphicsObject)
        : GameObject(poGraphicsObject) // Initialize base class
    {}


    void GameObjectDiamond::Update()
    {
        static float angle = 0.0f;
        angle += 0.01f;

        // Translate the cube in a spiral path
        float radius = 2.0f + 0.5f * Trig::sin(0.5f * angle); // Vary the radius over time
        Trans TransC(poPos->x(), poPos->y(), poPos->z());
        Scale ScaleA(scale, scale, scale);
        Trans TransA(radius * Trig::cos(angle), radius * Trig::sin(angle), -4.0f);

        // Adding some bobbing motion in the z-axis
        Trans TransB(0.0f, 0.0f, Trig::sin(3.0f * angle) * 0.5f);

        // Complex rotation around the Y and Z axes
        Rot RotY(Rot1::Y, 0.8f * angle);
        Rot RotZ(Rot1::Z, 0.5f * angle);

        // Combine the transformations
        *this->poWorld = TransC * ScaleA * RotY * RotZ * TransB * TransA;

        // PUSH to Graphics object
        this->poGraphicsObject->SetWorld(*this->poWorld);

    }


}
