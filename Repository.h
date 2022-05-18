#ifndef TWOWHEELSRENTALSYSTEM_REPOSITORY_H
#define TWOWHEELSRENTALSYSTEM_REPOSITORY_H

#include <vector>
#include <iostream>

template <class Entity>

class Repository {
public:
    void adauga(Entity* entity) {
        mEntities.push_back(entity);
    }
    void sterge(int i){
        typename std::vector<Entity*>::iterator it;
        this->mEntities[i] = nullptr;

        }
    Entity* getEntity(int i) {
        return this->mEntities[i];
    }

protected:
    std::vector<Entity*> mEntities;
};


#endif //TWOWHEELSRENTALSYSTEM_REPOSITORY_H
