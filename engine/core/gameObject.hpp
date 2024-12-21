#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
    public:
        virtual void init(){}
        virtual void update(){}
        virtual void update(float deltaTime){}
};

#endif