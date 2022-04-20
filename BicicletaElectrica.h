#ifndef BICICLETAELECTRICA_H
#define BICICLETAELECTRICA_H

#include <string>
#include "BicicletaStandard.h"
#include "VehiculElectric.h"

class BicicletaElectrica: public BicicletaStandard, public VehiculElectric {
public:
    BicicletaElectrica(int idV, std::string model, int nivelB = 100);
    BicicletaElectrica(int idV);
    ~BicicletaElectrica();
    void afisare();

    //int getNivelBaterie();
};


#endif //BICICLETAELECTRICA_H
