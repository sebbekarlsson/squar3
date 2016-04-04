#include "types/BlockType.h"
#include "Scene.h"
#include "instance/Block.h"
#include "world/WorldMap.h"
#include "world/Chunk.h"


using namespace std;
class World: public Scene {
    public:
        Chunk* chunks[100][8];
        WorldMap * map;

        World () : Scene () {
            this->map = new WorldMap(100*16, 8*16);
            for (int xx = 0; xx < sizeof(chunks)/(sizeof(*chunks)); xx++) {
                for (int yy = 0; yy < sizeof(chunks[xx])/sizeof(*chunks[xx]); yy++) {
                    delete chunks[xx][yy];
                    chunks[xx][yy] = new Chunk((xx*(16*16)) , (yy*(16*16)), this->map);
                }
            }
            generate();
        }


        void generate() {
            this->map->generate();
            for (int xx = 0; xx < sizeof(chunks)/(sizeof(*chunks)); xx++) {
                for (int yy = 0; yy < sizeof(chunks[xx])/sizeof(*chunks[xx]); yy++) {
                    chunks[xx][yy]->generate();
                }
            }
        }

        /**
         * This function is used to draw all chunks.in this scene.
         */
        void drawChunks(float delta) {
            for (int xx = 0; xx < sizeof(chunks)/(sizeof(*chunks)); xx++) {
                for (int yy = 0; yy < sizeof(chunks[xx])/sizeof(*chunks[xx]); yy++) {
                    if (!(
                                chunks[xx][yy]->x >= camera->x+(12*12) &&
                                chunks[xx][yy]->x+chunks[xx][yy]->w <= camera->x+((WIDTH*SCALE)-(12*12)) &&
                                chunks[xx][yy]->y >= camera->y+(12*12) &&
                                chunks[xx][yy]->y+chunks[xx][yy]->h <= camera->y+((HEIGHT*SCALE)-12*12) 
                         )
                       ) { continue; }
                    chunks[xx][yy]->draw(delta);

                }
            }
        }


        /**
         * This function is used to tick all chunks.in this scene.
         */
        void tickChunks(float delta) {
            for (int xx = 0; xx < sizeof(chunks)/(sizeof(*chunks)); xx++) {
                for (int yy = 0; yy < sizeof(chunks[xx])/sizeof(*chunks[xx]); yy++) {
                    if (!(
                                chunks[xx][yy]->x >= camera->x+(12*12) &&
                                chunks[xx][yy]->x+chunks[xx][yy]->w <= camera->x+((WIDTH*SCALE)-(12*12)) &&
                                chunks[xx][yy]->y >= camera->y+(12*12) &&
                                chunks[xx][yy]->y+chunks[xx][yy]->h <= camera->y+((HEIGHT*SCALE)-12*12) 
                         )
                       ) { continue; }
                    chunks[xx][yy]->tick(delta);
                }
            }
        }
};
