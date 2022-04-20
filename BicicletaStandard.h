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
    ~BicicletaStandard();

    void afisare();
    friend std::istream& operator>>(std::istream& i, BicicletaStandard& bike);

    void setID(int i);


};


#endif //BICICLETASTANDARD_H
