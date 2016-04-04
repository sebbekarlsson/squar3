#include "../World.h"

const Uint8 *state = SDL_GetKeyboardState(NULL);
class OverWorld: public World {
    public:
        void tick(float delta) {
            tickInstances(delta);
            tickChunks(delta);
            camera->tick(delta);
            if (state[SDL_SCANCODE_LEFT]) {
                camera->x -= 16.0f;
            }
            if (state[SDL_SCANCODE_RIGHT]) {
                camera->x += 16.0f;
            }
            if (state[SDL_SCANCODE_UP]) {
                camera->y -= 16.0f;
            }
            if (state[SDL_SCANCODE_DOWN]) {
                camera->y += 16.0f;
            }
        }



        void draw(float delta) {
            drawInstances(delta);
            drawChunks(delta);
        }

        void initialize(float delta) {}
};
