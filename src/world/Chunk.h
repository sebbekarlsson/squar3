class Chunk {
    public:
        float x;
        float y;
       // Block* blocks[15][15];
        bool initialized;

        Chunk(float x, float y) {
            this->x = x;
            this->y = y;
            this->initialized = false;
            
            //for (unsigned int xx = 0; xx < sizeof(this->blocks); xx++) {
            //    for(unsigned int yy = 0; yy < sizeof(this->blocks[xx]); yy++) {
            //        this->blocks[xx][yy] = new Block(xx*16, yy*16);
            //    }
           // }
        }

        void tick(float delta) {}
        void draw(float delta) {
            //cout << x << endl;
        }
        void initialize(float delta) {}
};
