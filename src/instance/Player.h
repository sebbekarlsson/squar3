const Uint8 *state = SDL_GetKeyboardState(NULL);
class Player: public Entity {
    public:
        World * world;
        bool on_ground;

        Player (float x, float y, World * world) : Entity (x, y) {
            this->w = 12;
            this->h = 28;
            this->type = "player1";
            this->world = world;
            this->on_ground = false;
        }

        void tick (float delta) {
            updatePhysics(delta);

            int chunkx = (int)((int)(x+(dx*delta))%((16*16)*100))/(16*16);
            int chunky = (int)((int)(y+(dy*delta))%((16*16)*8))/(16*16);
            Chunk * current_chunk = world->chunks[chunkx][chunky];

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
            
            on_ground = false;

            Chunk * chunks[] = {
                current_chunk,
                world->chunks[max(0, chunkx-1)][chunky],
                world->chunks[chunkx+1][chunky],
                world->chunks[chunkx][chunky+1],
                world->chunks[chunkx][max(0, chunky-1)]

            };

            for (int cc = 0; cc < (sizeof(chunks)/sizeof(*chunks)); cc++) {
                Chunk * chunk = chunks[cc];
                for (int xx = 0; xx < sizeof(chunk->blocks)/(sizeof(*chunk->blocks)); xx++) {
                    for (int yy = 0; yy < sizeof(chunk->blocks[xx])/sizeof(*chunk->blocks[xx]); yy++) {
                        Block * block = chunk->blocks[xx][yy];
                        if (block->type == &BLOCK_AIR) { continue; }

                        int inst_x = block->x;
                        int inst_y = block->y;
                        int inst_w = block->w;
                        int inst_h = block->h;
                        
                        if ((y+h) + (dy * delta) >= inst_y && y+(dy * delta) <= inst_y+inst_h) {
                            if ((x+w)+(dx * delta) >= inst_x && x+(dx * delta) <= inst_x+inst_w) {
                                
                                if (!(x+w-(dx*delta) < block->x || x-(dx*delta) > block->x+block->w)) {
                                    dy -= dy;
                                    on_ground = true;
                                }
                                
                                if (!(y+h+(dy*delta) < block->y+0.1f)) {
                                    dx -= dx;
                                }
                            }
                        }
                    }
                }
            }
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
