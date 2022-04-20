#ifndef VEHICULELECTRIC_H
#define VEHICULELECTRIC_H

#include <string>
#include "VehiculDouaRoti.h"

class VehiculDouaRoti;

class VehiculElectric: public virtual VehiculDouaRoti {
    static double costSuplimentarPeMinut;
    int nivelBaterie;
public:
    VehiculElectric(int idV, std::string model, int nivelB = 100);
    VehiculElectric(int idV);
    virtual void reincarcaBaterie();
    //
    void setNivelBaterie(int nivel);


    int getNivelBaterie();
    static double getCostSuplimentarPeMinut();
};


#endif //VEHICULELECTRIC_H
