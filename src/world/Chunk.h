class Chunk {
    public:
        float x;
        float y;
        Block* blocks[16][16];
        bool initialized;

        Chunk(float x, float y) {
            this->x = x;
            this->y = y;
            this->initialized = false;
            
            for (int xx = 0; xx < sizeof(blocks)/sizeof(*blocks); xx++) {
                for(int yy = 0; yy < sizeof(blocks[xx])/sizeof(*blocks[xx]); yy++) {
                    blocks[xx][yy] = new Block(x+(xx*16), y+(yy*16), BLOCK_DIRT);
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

        void tick(float delta) {}
        void draw(float delta) {
            drawBlocks(delta);
        }
        void initialize(float delta) {}
};
