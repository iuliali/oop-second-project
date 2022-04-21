#ifndef BICICLETASTANDARD_H
#define BICICLETASTANDARD_H
#include <vector>
#include <string>
#include "VehiculDouaRoti.h"


class BicicletaStandard: public virtual VehiculDouaRoti {

    static std::vector <std::string >listaModele;
public:
    BicicletaStandard(int idV,std::string model);
    BicicletaStandard(int idV);
    void generareModel();

    void afisare();
    friend std::istream& operator>>(std::istream& i, BicicletaStandard& bike);
    void incarca();
    void setID(int i);

    BicicletaStandard( BicicletaStandard &bike);

};


#endif //BICICLETASTANDARD_H
