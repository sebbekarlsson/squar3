#pragma once
#include "Instance.h"
#include <iostream>


using namespace std;
class Entity: public Instance {
    public:
        float dx, dy;

        Entity (float x, float y) : Instance(x, y) {
            this->dx = 0;
            this->dy = 0;
            this->type = "entity";
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
        }
        
        void addForce (float direction, float force) {
            float radians = direction * M_PI / 180.0; 
            dx += (float) (cos(radians) * force);
            dy += (float) (sin(radians) * force);
        }
};
