#include <vector>


using namespace std;
class WorldMap {
    public:
        int size;
        std::vector< std::vector<Block*> > blocks;

        WorldMap (int size) {
            this->size = size;

            blocks.resize(size);
            for (int xx = 0; xx < size; xx++) {
                for(int yy = 0; yy < size; yy++) {
                    blocks[xx].push_back(new Block(xx*16, yy*16, &BLOCK_AIR));
                }
            }
        }

        void generate () {
            srand(time(NULL));

            int genx = 0;
            int geny = (size/2)-16;

            while (genx < size) {
                BlockType * type = &BLOCK_COBBLE;
                blocks[genx][geny] = new Block(0.0f, 0.0f, type); 
                
                for (int yy = 0; yy < size-geny; yy+=1) {
                    type = &BLOCK_DIRT;
                    
                    if (yy == 0) {
                        type = &BLOCK_GRASS;
                    } else if (yy > 4) {
                        type = &BLOCK_STONE;
                    }

                    blocks[genx][geny+yy] = new Block(0.0f, 0.0f, type);
                }
                
                int minus = rand()%(1-(-1) + 1) + -1;
                int ym = (rand()%(3-0 + 1) + 0) * minus;
                genx += 1;
                geny += ym;

                
            }
        } 
};
