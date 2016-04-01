class Block : public Instance {
    public:
        EasyImage * image;
        BlockType * type;

        Block (float x, float y, BlockType * type) : Instance(x, y) {
            this->h = 16;
            this->w = 16;
            setType(type);
        }

        ~Block () {
            delete image;
            delete type;
            cout << "block del" << endl;
        }

        void setType(BlockType * type) {
            this->type = &*type;

            if (type->texture_path != "") {
                SDLImageLoader IMGLoader = SDLImageLoader();
                this->image = IMGLoader.load(type->texture_path);
            }
        }

        void tick(float delta) {
        }

        void draw(float delta) {
            if (type->texture_path != "") {
                glEnable(GL_TEXTURE_2D);
                glColor3f(1.0f, 1.0f, 1.0f);

                glPushMatrix();

                glTranslatef(this->x, this->y, 0.0f);
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
                glDisable(GL_TEXTURE_2D);
            }
        }
};
