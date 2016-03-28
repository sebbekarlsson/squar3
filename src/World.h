#include "Scene.h"
#include "world/Chunk.h"


class World: public Scene {
    public:
        std::list<Chunk*> chunks;
        std::list<Chunk*>::iterator chunkIterator;


        /**
         * This function is used to draw all chunks.in this scene.
        */
        void drawChunks(float delta) {
            Chunk *chunk;
            for (chunkIterator = chunks.begin() ; chunkIterator != chunks.end(); chunkIterator++) {
                chunk = &**chunkIterator;
                chunk->draw(delta);
            }
        }


        /**
         * This function is used to tick all chunks.in this scene.
        */
        void tickChunks(float delta) {
            Chunk *chunk;
            for (chunkIterator = chunks.begin() ; chunkIterator != chunks.end(); chunkIterator++) {
                chunk = &**chunkIterator;
                chunk->tick(delta);
            }
        }
};
