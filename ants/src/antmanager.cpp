#include "antmanager.h"
#include <stdlib.h>

AntManager::AntManager(fea::MessageBus& bus)
    :   messageBus(bus)
{
    nextAntId = 0;

    spawnPositionA = glm::vec2(20.0f, 900.0f);
    spawnPositionB = glm::vec2(1575.0f, 690.0f);

    messageBus.addSubscriber<AntOutsideBoundariesMessage>(*this);
}

AntManager::~AntManager()
{
    messageBus.removeSubscriber<AntOutsideBoundariesMessage>(*this);
}

void AntManager::update()
{
    spawn();
}

void AntManager::createAnt(bool type, bool goingRight, glm::vec2 position, float velocity)
{
    ants.emplace(nextAntId, Ant(type));
    messageBus.send(AntCreationMessage(nextAntId, type, goingRight, position, velocity));
    nextAntId++;
}

void AntManager::handleMessage(const AntOutsideBoundariesMessage& mess)
{
    int index;
    std::tie(index) = mess.mData;
    ants.erase(index);
    messageBus.send(AntDeletionMessage(index));
}

void AntManager::spawn()
{
    if(rand() % 100 < 2)
    {
        createAnt((rand() % 2), true, spawnPositionA, ((float)(rand() % 25 + 10))/10.0f);
    }

    if(rand() % 100 < 2)
    {
        createAnt((rand() % 2), false, spawnPositionB, ((float)(rand() % 25 + 10))/10.0f);
    }
}
