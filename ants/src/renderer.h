#pragma once
#include "messages.h"
#include "interpolator.h"
#include "imageloader.h"
#include "physics.h"
#include <featherkit/render2d.h>

class Renderer
    :   public fea::MessageReceiver<CameraPositionMessage>,
        public fea::MessageReceiver<AntPositionMessage>,
        public fea::MessageReceiver<AntPointsMessage>
{
    public:
        Renderer(fea::MessageBus& bus);
        ~Renderer();
        void setup();
        void render();

        //messages//
        virtual void handleMessage(const CameraPositionMessage& mess) override;
        virtual void handleMessage(const AntPositionMessage& mess) override;
        virtual void handleMessage(const AntPointsMessage& mess) override;

    private:
        fea::MessageBus& messageBus;
        glm::vec2 cameraPosition;
        Interpolator cameraInterpolator;
        fea::Renderer2D renderer;
        Physics physics;

        ImageLoader loader;
        std::unordered_map<std::string, fea::Texture> textures;
        void createTexture(const std::string& name, const std::string& path, int width, int height, bool smooth = false, bool interactive = false);

        fea::Quad antQuad;
        fea::Quad dirtQuad;
        fea::Quad dirtBgQuad;

        fea::Quad pointF;
        fea::Quad pointB;

        glm::vec2 posF;
        glm::vec2 posB;
};
