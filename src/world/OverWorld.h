#include "../World.h"

class OverWorld: public World {
    public:
        void tick(float delta) {
            tickInstances(delta);
            tickChunks(delta);
            camera->tick(delta);
        }

        void tickInstances(float delta) {
            Instance *instance;
            for (instanceIterator = instances.begin() ; instanceIterator != instances.end(); instanceIterator++) {
                instance = &**instanceIterator;
                instance->tick(delta);
                if (instance->type == "player1") {
                    camera->x = instance->x - (WIDTH * SCALE) /2;
                    camera->y = instance->y - (HEIGHT * SCALE) /2;
                }
            }
        }

        void draw(float delta) {
            drawInstances(delta);
            drawChunks(delta);
        }

        void initialize(float delta) {
            instances.insert(instances.begin(), new Player(0.0f, 0.0f));
        }
};
