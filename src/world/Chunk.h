#include <algorithm>

using namespace std;
class Chunk {
    public:
        int x;
        int y;
        int w;
        int h;
        Block* blocks[16][16];
        WorldMap * map;

        bool initialized;

        Chunk(int x, int y, WorldMap * map) {
            this->w = 16*16;
            this->h = 16*16;
            this->x = x;
            this->y = y;
            this->map = map;
            this->initialized = false;
            
            for (int xx = 0; xx < sizeof(blocks)/sizeof(*blocks); xx++) {
                for(int yy = 0; yy < sizeof(blocks[xx])/sizeof(*blocks[xx]); yy++) {
                    int s = map->blocks.size();
                    Block * block = map->blocks[min(((x/16)+xx), s-1)][min(((y/16)+yy), s-1)];
                    BlockType * type = block->type;

                    blocks[xx][yy] = new Block(x+(xx*16), y+(yy*16), &*type);
                }
            }
        }

        void drawBlocks(float delta) {
            for (int xx = 0; xx < sizeof(blocks)/sizeof(*blocks); xx++) {
                for(int yy = 0; yy < sizeof(blocks[xx])/sizeof(*blocks[xx]); yy++) {
                    blocks[xx][yy]->draw(delta);
                }
            }
        }


        void tickBlocks(float delta) {
            for (int xx = 0; xx < sizeof(blocks)/sizeof(*blocks); xx++) {
                for(int yy = 0; yy < sizeof(blocks[xx])/sizeof(*blocks[xx]); yy++) {
                    blocks[xx][yy]->tick(delta);
                }
            }
        }

        void tick(float delta) {
            tickBlocks(delta);
        }
        void draw(float delta) {
            drawBlocks(delta);
            glDisable(GL_TEXTURE_2D);
            glColor3f(0.0f, 1.0f, 0.0f);
            glPushMatrix();
            glTranslatef(x, y, -1.0f);
            
            glBegin(GL_LINE_LOOP);
            
            glVertex2f(0.0f, 0.0f);
            glVertex2f(this->w, 0.0f);
            glVertex2f(this->w, this->h);
            glVertex2f(0.0f, this->h);

            glEnd();

            glPopMatrix();
            glEnable(GL_TEXTURE_2D);
        }
        void initialize(float delta) {}
};
