class Block : public Instance {
    public:
        EasyImage * image;

        Block (float x, float y) : Instance(x, y) {
            this->h = 16;
            this->w = 16;
            SDLImageLoader loader = SDLImageLoader();
            this->image = loader.load("src/res/dirt.png");
        }

        void tick(float delta) {}
        void draw(float delta) {
            glColor3f(1.0f, 1.0f, 1.0f);
            
            glPushMatrix();
            
            glTranslatef(this->x, this->y, 0.0f);
            
            glEnable(GL_TEXTURE_2D);
            this->image->bind();
            glBegin(GL_QUADS);

            glTexCoord2f(0.0f, 0.0f);
            glVertex2f(0.0f, 0.0f);


            glTexCoord2f(0.0f, 1.0f);
            glVertex2f(0.0f, this->h);

            glTexCoord2f(1.0f, 1.0f);
            glVertex2f(this->w, this->h);


            glTexCoord2f(1.0f, 0.0f);
            glVertex2f(this->w, 0.0f);

            glEnd();
            glPopMatrix();
        }
};
