#include <vector>


using namespace std;
class WorldMap {
    public:
        int w;
        int h;
        std::vector< std::vector<Block*> > blocks;
        int biomeIndex;
        int biomeChange;

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

            for (int xx = 0; xx < w; xx++) {
                for(int yy = 0; yy < h; yy++) {
                    blocks[xx][yy]->setType(&BLOCK_AIR);
                }
            }

            int genx = 0;
            int geny = (h/2);

            while (genx < w) {
                biomeChange = rand() % 20 + 0;

                if (biomeChange == 0) {
                    biomeIndex = rand() % 2 + 0;
                }

                BlockType * type = &BLOCK_COBBLE;


                if (biomeIndex == 0) {
                    if (rand() % 3 + 0 == 0) {
                        blocks[genx][max(0, geny-1)]->setType(&BLOCK_MUSHROOM);
                    }
                    if (rand() % 5 + 0 == 0) {
                        int i = 0;
                        for (i = 0; i < 6; i++) {
                            if (geny - i <= 0) { break; }
                            blocks[genx][max(0, geny-i)]->setType(&BLOCK_LOG);
                        }

                        int th = geny-i;

                        if (th < 0) { th = 0; }
                        if (th > h) { th = h; }

                        blocks[genx][min(h, th+1)]->setType(&BLOCK_LEAF);
                        blocks[genx][min(h, th)]->setType(&BLOCK_LEAF);
                        blocks[genx][max(0, th-1)]->setType(&BLOCK_LEAF);
                        blocks[min(w, genx+1)][min(h, th)]->setType(&BLOCK_LEAF);
                        blocks[max(0, genx-1)][min(h, th)]->setType(&BLOCK_LEAF);
                        blocks[min(w, genx+1)][min(h, th+1)]->setType(&BLOCK_LEAF);
                        blocks[max(0, genx-1)][min(h, th+1)]->setType(&BLOCK_LEAF);
                        blocks[min(w, genx+2)][min(h, th+1)]->setType(&BLOCK_LEAF);
                        blocks[max(0, genx-2)][min(h, th+1)]->setType(&BLOCK_LEAF);
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

                    blocks[min(w, genx)][max(0, geny+yy)]->setType(type);
                }

                int minus = rand()%(1-(-1) + 1) + -1;
                int ym = (rand()%(3-0 + 1) + 0) * minus;
                genx += 1;
                geny += ym;

                if (geny < 0) { geny = 0; }
                if (geny > h) { geny = h-1; }
            }
        } 
};
