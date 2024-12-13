#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <camera.h>
#include <gameObject.h>

class Scene{
    private:
        std::vector<GameObject*> objects;
        Camera *camera;
    public:
        Scene() {
            objects = std::vector<GameObject*>();
        };

        void add(GameObject *obj){
            objects.push_back(obj);
        }

        void update() {
            for (int i = 0; i < objects.size(); i++) {
                objects[i]->update();
            }
        }

        void setCamera(Camera *camera) {
            this->camera = camera;
        }

        Camera *getCamera() {
            return camera;
        }
};

#endif