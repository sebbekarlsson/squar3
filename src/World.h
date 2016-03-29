#include "Scene.h"
#include "instance/Block.h"
#include "world/Chunk.h"


using namespace std;
class World: public Scene {
    public:
        Chunk** chunks[1][1];


        World () : Scene () {
            /* Does not work... Will take a look at it tomorrow...
             *
             * Some sort of memory problem:
             * "Invalid write of size 8"
            */
            for (int xx = 0; xx < sizeof(this->chunks)-1; xx++) {
                for(int yy = 0; yy < sizeof(this->chunks[xx])-1; yy++) {
                    this->chunks[xx][yy] = new Chunk(0.1f , 0.1f);
                }
            }
        }


        /**
         * This function is used to draw all chunks.in this scene.
         */
        void drawChunks(float delta) {
            //for (int xx = 0; xx < sizeof(this->chunks); xx++) {
            //    for(int yy = 0; yy < sizeof(this->chunks[xx]); yy++) {
            //        this->chunks[xx][yy]->draw(delta);
            //    }
            //}
        }


        /**
         * This function is used to tick all chunks.in this scene.
         */
        void tickChunks(float delta) {
            //for (int xx = 0; xx < sizeof(this->chunks); xx++) {
            //    for(int yy = 0; yy < sizeof(this->chunks[xx]); yy++) {
            //        this->chunks[xx][yy]->draw(delta);
            //    }
            // }
        }
};
