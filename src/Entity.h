#pragma once
#include "Instance.h"
#include <iostream>


using namespace std;
class Entity: public Instance {
    public:
        float dx, dy;
        float weight;
        bool on_ground;
        World * world;

        Entity (float x, float y, World * world) : Instance(x, y) {
            this->dx = 0;
            this->dy = 0;
            this->type = "entity";
            this->weight = 6.2f;
            this->on_ground = false;
            this->world = world;
        }

        void updateCollisions(float delta) {
            int chunkx = (int)((int)(x+(dx*delta))%((16*16)*100))/(16*16);
            int chunky = (int)((int)(y+(dy*delta))%((16*16)*8))/(16*16);
            Chunk * current_chunk = world->chunks[chunkx][chunky];

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

                                if (!(y+h+(dy*delta) < block->y+1.0f)) {
                                    dx -= dx;
                                } else {
                                    y = block->y-h;
                                }
                            }
                        }
                    }
                }
            } 
        }

        void updatePhysics (float delta) {
            if(dx > 0){
                if(dx - friction < 0){
                    dx = 0;
                }else{
                    dx -= friction;
                }
            }
            if(dx < 0){
                if(dx + friction > 0){
                    dx = 0;
                }else{
                    dx += friction;
                }
            }

            if(dy > 0){
                if(dy - friction < 0){
                    dy = 0;
                }else{
                    dy -= friction;
                }
            }
            if(dy < 0){
                if(dy + friction > 0){
                    dy = 0;
                }else{
                    dy += friction;
                }
            }
            
            x += dx * delta;
            y += dy * delta;

            dy += weight;
        }
        
        void addForce (float direction, float force) {
            float radians = direction * M_PI / 180.0; 
            dx += (float) (cos(radians) * force);
            dy += (float) (sin(radians) * force);
        }
};
