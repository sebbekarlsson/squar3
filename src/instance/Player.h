const Uint8 *state = SDL_GetKeyboardState(NULL);
class Player: public Entity {
    public:
        Player (float x, float y) : Entity (x, y) {
            this->w = 16;
            this->h = 32;
            this->type = "player1";
        }

        void tick (float delta) {
            if (state[SDL_SCANCODE_LEFT]) {
                dx -= 16.0f;
            }
            if (state[SDL_SCANCODE_RIGHT]) {
                dx += 16.0f;
            }
            if (state[SDL_SCANCODE_UP]) {
                dy -= 16.0f;
            }
            if (state[SDL_SCANCODE_DOWN]) {
                dy += 16.0f;
            }

            /* TODO
             *
             * Hmm... We need to have the World class / object
             * (the current world that this player exists in) in scope.
             *
             * How would we achieve this?
             * this is needed to be able to check for collisions.
             * We currently cannot reach the current world object from here.
             *
             * something like:
             *
             *     getCurrentWorld().getCurrentChunk(this).getBlocks();
             *
             * would have been very nice.
             */

            updatePhysics(delta); 
        }

        void draw (float delta) {
            glDisable(GL_TEXTURE_2D);
            glColor3f(1.0f, 0.0f, 0.0f);
            glPushMatrix();
            glTranslatef(x, y, -1.0f);

            glBegin(GL_LINE_LOOP);

            glVertex2f(0.0f, 0.0f);
            glVertex2f(this->w, 0.0f);
            glVertex2f(this->w, this->h);
            glVertex2f(0.0f, this->h);

            glEnd();

            glPopMatrix();
            glEnable(GL_TEXTURE_2D);
        }
};