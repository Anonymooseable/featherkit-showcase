#pragma once
#include "messages.h"
#include "physicsbody.h"
#include <featherkit/render2d.h>

class Physics
{
    public:
        Physics(fea::MessageBus& bus);
        ~Physics();

        void update();
        void setTexture(fea::Texture* texture);

    private:
        fea::MessageBus& messageBus;
        glm::vec2 gravity;
        float thresholdAngle;

        void addVelocity(PhysicsBody& body);
        void addFalling(PhysicsBody& body);
        void terrainCheck(PhysicsBody& body);
        bool terrainCollisionAt(glm::vec2 pos);

        const fea::Texture* dirtTexture;
        PhysicsBody ant;
};
