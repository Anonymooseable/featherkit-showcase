#include "antapplication.h"

AntApplication::AntApplication()
    :   input(messageBus),
        window(new fea::util::SDL2WindowBackend()),
        renderer(messageBus)
{
    messageBus.addSubscriber<QuitMessage>(*this);
    window.create(fea::VideoMode(800, 600, 32), "ants");
    renderer.setup();
}

AntApplication::~AntApplication()
{
    messageBus.removeSubscriber<QuitMessage>(*this);
}

void AntApplication::loop()
{
    input.inputLoop();
    renderer.render();
    window.swapBuffers();
}

void AntApplication::setup(const std::vector<std::string>& args)
{
    (void)args;
}

void AntApplication::destroy()
{
    window.close();              
}

void AntApplication::handleMessage(const QuitMessage& mess)
{
    (void)mess;
    quit();
}
