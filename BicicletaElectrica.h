#ifndef BICICLETAELECTRICA_H
#define BICICLETAELECTRICA_H

#include <string>
#include "BicicletaStandard.h"
#include "VehiculElectric.h"

class BicicletaElectrica: public BicicletaStandard, public VehiculElectric {
public:
    BicicletaElectrica(int idV, std::string model, int nivelB = 100);
    BicicletaElectrica(int idV);
    BicicletaElectrica(BicicletaElectrica& bike);
    void afisare();
    //friend std::istream &operator>>(std::istream &i, BicicletaElectrica &bike) ;
    void incarca();

        //int getNivelBaterie();
};


#endif //BICICLETAELECTRICA_H
