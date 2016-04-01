#include "../World.h"


class OverWorld: public World {
    public:
        void tick(float delta) {
            tickInstances(delta);
            tickChunks(delta);
            generate();
        }

        void draw(float delta) {
            drawInstances(delta);
            drawChunks(delta);
        }

        void initialize(float delta) {}
};
