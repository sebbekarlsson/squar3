#include "types/BlockType.h"
#include "Scene.h"
#include "instance/Block.h"
#include "world/Chunk.h"


using namespace std;
class World: public Scene {
    public:
        Chunk* chunks[4][4];


        World () : Scene () {
            /* Does not work... Will take a look at it tomorrow...
             *
             * Some sort of memory problem:
             * "Invalid write of size 8"
            */
            for (int xx = 0; xx < sizeof(chunks)/(sizeof(*chunks)); xx++) {
                for(int yy = 0; yy < sizeof(chunks[xx])/sizeof(*chunks[xx]); yy++) {
                    chunks[xx][yy] = new Chunk(xx*16*16 , yy*16*16);
                }
            }
        }


        /**
         * This function is used to draw all chunks.in this scene.
         */
        void drawChunks(float delta) {
            for (int xx = 0; xx < sizeof(chunks)/(sizeof(*chunks)); xx++) {
                for(int yy = 0; yy < sizeof(chunks[xx])/sizeof(*chunks[xx]); yy++) {
                    chunks[xx][yy]->draw(delta);
                }
            }
        }


        /**
         * This function is used to tick all chunks.in this scene.
         */
        void tickChunks(float delta) {
            for (int xx = 0; xx < sizeof(chunks)/(sizeof(*chunks)); xx++) {
                for(int yy = 0; yy < sizeof(chunks[xx])/sizeof(*chunks[xx]); yy++) {
                    chunks[xx][yy]->tick(delta);
                }
            }
        }
};
