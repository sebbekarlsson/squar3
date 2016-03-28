class Camera: public Instance {
    public:
        Camera (float x, float y) : Instance(x, y) {}

        void tick(float delta) {}
        void draw(float delta) {}
};
