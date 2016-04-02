class Block : public Instance {
    public:
        BlockType * type;

        Block (float x, float y, BlockType * type) : Instance(x, y) {
            this->h = 16;
            this->w = 16;
            setType(type);

            cout << "block create" << endl;
        }

        ~Block () {
            delete type;
            cout << "block del" << endl;
        }

        void setType(BlockType * type) {
            this->type = &*type;
        }

        void tick(float delta) {
        }

        void draw(float delta) {
            if (type->image != NULL) {
                glEnable(GL_TEXTURE_2D);
                glColor3f(1.0f, 1.0f, 1.0f);

                glPushMatrix();

                glTranslatef(this->x, this->y, 0.0f);
                this->type->image->bind();
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
