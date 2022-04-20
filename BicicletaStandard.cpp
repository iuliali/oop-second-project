#include "BicicletaStandard.h"
#include <iostream>

#include <experimental/random>

std::vector <std::string > BicicletaStandard::listaModele = {"DHS Citadinne",
                                                             "Velors 2",
                                                             "Elops 520",
                                                             "Goetze Touring",
                                                             "Romet Orion",
                                                             "Pegas Clasic",
                                                             "Corelli Fit",
                                                             "Goetze Eco",
                                                             "Colinelli 264",
                                                             "Davi Lila",
                                                             "Pegas Magistral"};


BicicletaStandard::BicicletaStandard(int idV, std::string model): VehiculDouaRoti(idV, model) {
    std::cout<< "Constructor BiciSTD \n";
}

BicicletaStandard::BicicletaStandard(int idV): VehiculDouaRoti(idV) {
    this->generareModel();
    //std::cout<< "Constructor BiciSTD \n";
}

void BicicletaStandard::generareModel() {
    std::experimental::reseed();
    int lLen = listaModele.size();
    std::string random = listaModele[std::experimental::randint(0,lLen-1)];
    this->setModelVehicul(random);
}

BicicletaStandard::~BicicletaStandard() {
    //std::cout<<"Destructor BiciStd "<<this->getModelVehicul()<<"\n";
}

void BicicletaStandard::afisare() {
    std::cout <<"Bicicleta Standard "<< this->getModelVehicul() <<" - ID:"<< this->getIdVehicul();
}

void BicicletaStandard::setID(int i) {
    VehiculDouaRoti::setID(i);
}


std::istream &operator>>(std::istream &i, BicicletaStandard &bike) {
    std::cout<<"Introduceti modelul: ";
    std::string model;
    i>>model;
    bike.setModelVehicul(model);
    std::cout<<"Introduceti ID: ";
    int id;
    i>>id;
    bike.setID(id);

    i.get();
    return i;
}





