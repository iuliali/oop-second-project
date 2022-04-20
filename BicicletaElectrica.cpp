
#include "BicicletaElectrica.h"
#include <iostream>
BicicletaElectrica::BicicletaElectrica(int idV,std::string model, int nivelB) : VehiculDouaRoti(idV,model),BicicletaStandard(idV,model), VehiculElectric(idV, model, nivelB) {
    //std::cout<<"Constructor BiciElectrica\n";
}

BicicletaElectrica::BicicletaElectrica(int idV):VehiculDouaRoti(idV), VehiculElectric(idV),BicicletaStandard(idV) {
    //std::cout<<"Constructor BiciElectrica\n";

}

BicicletaElectrica::~BicicletaElectrica() {
    //std::cout<<"Destructor Bicielectrica "<<this->getModelVehicul()<<"\n";

}

void BicicletaElectrica::afisare() {
    std::cout <<"Bicicleta Electrica "<< this->getModelVehicul() << " - ID:" << this->getIdVehicul()<<" Nivel Baterie: ";
    std::cout<<this->getNivelBaterie()<<"%";
}


