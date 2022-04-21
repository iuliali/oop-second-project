
#include "BicicletaElectrica.h"
#include <iostream>
BicicletaElectrica::BicicletaElectrica(int idV,std::string model, int nivelB) : VehiculDouaRoti(idV,model),BicicletaStandard(idV,model), VehiculElectric(idV, model, nivelB) {
    //std::cout<<"Constructor BiciElectrica\n";
}

BicicletaElectrica::BicicletaElectrica(int idV):VehiculDouaRoti(idV), VehiculElectric(idV),BicicletaStandard(idV) {
    //std::cout<<"Constructor BiciElectrica\n";

}



void BicicletaElectrica::afisare() {
    std::cout <<"Bicicleta Electrica "<< this->getModelVehicul() << " - ID:" << this->getIdVehicul()<<" Nivel Baterie: ";
    std::cout<<this->getNivelBaterie()<<"%";
}

BicicletaElectrica::BicicletaElectrica(BicicletaElectrica &bike) : VehiculDouaRoti(bike.getIdVehicul(),bike.getModelVehicul()),
                                                                   BicicletaStandard(bike),
                                                                   VehiculElectric(bike) {

}

void BicicletaElectrica::incarca() {
    VehiculElectric::incarca();
}

BicicletaElectrica& BicicletaElectrica::operator=(BicicletaElectrica bike) {
    this->BicicletaStandard::operator=(bike);
    this->setNivelBaterie(bike.getNivelBaterie());
}

//std::istream &operator>>(std::istream &i, BicicletaElectrica &bike) {

//    std::cout<<"Introduceti modelul de bicicleta electrica: ";
//    std::string model;
//    i>>model;
//    bike.setModelVehicul(model);
//    std::cout<<"Introduceti ID: ";
//    int id;
//    i>>id;
//    bike.setID(id);
//
//    i.get();
//    return i;
//}


