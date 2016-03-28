#pragma once
#include <iostream>
#include <typeinfo>
#include <string>
#include <iostream>


using namespace std;
class Instance {
    public:
        float x, y;
        float dx, dy;
        float w, h;
        float friction;
        string type;

        Instance (float x, float y) {
            this->x = x;
            this->y = y;
            this->w = 0;
            this->h = 0;
            this->dx = 0;
            this->dy = 0;
            this->friction = 0.01f;
            this->type = "instance";
        }

        virtual void tick(float delta) = 0;
        virtual void draw(float delta) = 0;

        void addForce (float direction, float force) {
            float radians = direction * M_PI / 180.0; 
            dx += (float) (cos(radians) * force);
            dy += (float) (sin(radians) * force);
        }
};
