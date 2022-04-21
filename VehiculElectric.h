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

    void incarca();
    int getNivelBaterie();
    static double getCostSuplimentarPeMinut();
    VehiculElectric(VehiculElectric &);

    static void setCostSuplimentarPeMinut(double);

};



#endif //VEHICULELECTRIC_H
