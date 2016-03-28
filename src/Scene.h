#pragma once


class Scene {
    public:
        std::list<Instance*> instances;
        std::list<Instance*>::iterator instanceIterator;
        Camera *camera;
        bool initialized;
        

        Scene () {
            this->initialized = false;
            this->camera = new Camera(0.0f, 0.0f);
        }


        /**
         * This function is used to draw all instances in this scene.
        */
        void drawInstances(float delta) {
            Instance *instance;
            for (instanceIterator = instances.begin() ; instanceIterator != instances.end(); instanceIterator++) {
                instance = &**instanceIterator;
                instance->draw(delta);
            }
        }


        /**
         * This function is used to tick all instances in this scene.
        */
        void tickInstances(float delta) {
            Instance *instance;
            for (instanceIterator = instances.begin() ; instanceIterator != instances.end(); instanceIterator++) {
                instance = &**instanceIterator;
                instance->tick(delta);
            }
        }


        virtual void initialize(float delta) = 0;
        virtual void tick(float delta) = 0;
        virtual void draw(float delta) = 0;
};
