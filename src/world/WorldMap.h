#include <vector>


using namespace std;
class WorldMap {
    public:
        int w;
        int h;
        std::vector< std::vector<Block*> > blocks;
        int biomeIndex;
        int biomeChange;
        int plantChance;

        WorldMap (int w, int h) {
            this->w = w;
            this->h = h;

            blocks.resize(w);
            for (int xx = 0; xx < w; xx++) {
                for(int yy = 0; yy < h; yy++) {
                    blocks[xx].push_back(new Block(xx*16, yy*16, &BLOCK_AIR));
                }
            }
        }

        ~WorldMap () {
            cout << "worldmap del" << endl;
        }

        void generate () {
            srand(time(NULL));

            biomeChange = 0;
            biomeIndex = 0;
            plantChance = 0;

            for (int xx = 0; xx < w; xx++) {
                for(int yy = 0; yy < h; yy++) {
                    blocks[xx][yy]->setType(&BLOCK_AIR);
                }
            }

            int genx = 0;
            int geny = (h/2);

            while (genx < w) {
                biomeChange = rand() % 20 + 0;
                plantChance = rand() % 3 + 0;

                if (biomeChange == 0) {
                    biomeIndex = rand() % 2 + 0;
                }

                BlockType * type = &BLOCK_COBBLE;


                if (biomeIndex == 0) {
                    if (plantChance == 0) {
                        blocks[genx][min(h-1, geny-1)]->setType(&BLOCK_MUSHROOM);
                    }
                }

                for (int yy = 0; yy < h-geny; yy+=1) {
                    type = &BLOCK_DIRT;

                    if (yy == 0) {
                        if (biomeIndex == 0) {
                            type = &BLOCK_GRASS;
                        } else {
                            type = &BLOCK_SAND;
                        }
                    } else if (yy > 4) {
                        type = &BLOCK_STONE;
                    }

                    blocks[genx][geny+yy]->setType(type);
                }

                int minus = rand()%(1-(-1) + 1) + -1;
                int ym = (rand()%(3-0 + 1) + 0) * minus;
                genx += 1;
                geny += ym;
            }
        } 
};
