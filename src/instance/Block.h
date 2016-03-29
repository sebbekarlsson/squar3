class Block : public Instance {
    public:
        EasyImage *image;
        
        Block (float x, float y) : Instance(x, y) {
            SDLImageLoader loader;
            this->image = loader.load("res/dot.png");
        }

        void tick(float delta) {}
        void draw(float delta) {}
};
