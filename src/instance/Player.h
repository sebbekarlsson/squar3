const Uint8 *state = SDL_GetKeyboardState(NULL);
class Player: public Entity {
    public:

        Player (float x, float y, World * world) : Entity (x, y, world) {
            this->w = 12;
            this->h = 28;
            this->type = "player1";
        }

        void placeBlock(int bx, int by, BlockType * type) {
            int cchunkx = (int)((int)((bx))%((16*16)*100))/(16*16);
            int cchunky = (int)((int)((by))%((16*16)*8))/(16*16);
            Chunk * click_chunk = world->chunks[cchunkx][cchunky];
            click_chunk->blocks[((bx)%(16*16))/16][((by)%(16*16))/16]->setType(type);
        }

        void tick (float delta) {
            updatePhysics(delta);

            int camera_zoom = (int)world->camera->zoom;

            int mx = 0;
            int my = 0;
            SDL_PumpEvents();
            if (SDL_GetMouseState(&mx, &my) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                int bx = ((mx/camera_zoom)+(world->camera->x+(WIDTH * SCALE)/3));
                int by = ((my/camera_zoom)+(world->camera->y+(HEIGHT * SCALE)/3));
                bool can_place = true;
                

                if (bx+(16) >= x+(dx*delta) && bx <= x+w+(dx*delta)) {
                    if (by+(16) >= y+(dy*delta) && by <= y+h+(dy*delta)) {
                        can_place = false;
                    }
                }

                if (can_place) {
                    placeBlock(bx, by, &BLOCK_COBBLE);
                }
            }
            if (SDL_GetMouseState(&mx, &my) & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
                int bx = ((mx/camera_zoom)+(world->camera->x+(WIDTH * SCALE)/3));
                int by = ((my/camera_zoom)+(world->camera->y+(HEIGHT * SCALE)/3));

                placeBlock(bx, by, &BLOCK_AIR);
            }

            if (state[SDL_SCANCODE_LEFT]) {
                dx -= 16.0f;
            }
            if (state[SDL_SCANCODE_RIGHT]) {
                dx += 16.0f;
            }
            if (state[SDL_SCANCODE_UP] && on_ground) {
                addForce(270, ((16+weight)*weight));
            }
            if (state[SDL_SCANCODE_DOWN]) {
                dy += 16.0f;
            }
            if (state[SDL_SCANCODE_R]) {
                world->generate();
                x = 0;
                y = 0;
            }

            updateCollisions(delta); 
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
