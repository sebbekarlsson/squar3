class Chunk {
    public:
        bool initialized;

        Chunk() {
            this->initialized = false;
        }

        void tick(float delta) {}
        void draw(float delta) {}
        void initialize(float delta) {}
};
