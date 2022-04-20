#include "VehiculDouaRoti.h"
#include <iostream>

double VehiculDouaRoti::pretPeOra = 7.5;
VehiculDouaRoti::VehiculDouaRoti(int idV, std::string model) {
    this->modelVehicul = model;
    this->idVehicul = idV;
    //this->rastelCurent = nullptr;
    //std::cout<<"Constructor Vehicul 2 roti \n";
}

VehiculDouaRoti::VehiculDouaRoti(int idV) {
    this->idVehicul = idV;
    //this->rastelCurent = nullptr;

    //std::cout<<"Constructor Vehicul 2 roti \n";
}


VehiculDouaRoti::~VehiculDouaRoti() {
    //std::cout<<"Desctructor Vehicul 2 roti \n";

}

int VehiculDouaRoti::getIdVehicul() {
    return this->idVehicul;
}

std::string VehiculDouaRoti::getModelVehicul() {
    return this->modelVehicul;
}

void VehiculDouaRoti::setModelVehicul(std::string model) {
    this->modelVehicul = model;
}

std::ostream& operator<<(std::ostream &o, VehiculDouaRoti& vehicul) {
    o<<vehicul.getModelVehicul()<<" ";
    o<<"- ID:"<<vehicul.getIdVehicul();
    return o;
}

void VehiculDouaRoti::setRastelCurent(Rastel* rastel) {
    //this->rastelCurent = rastel;
}

Rastel* VehiculDouaRoti::getRastelCurent() {
    //return this->rastelCurent;
}

void VehiculDouaRoti::afisare() {
    std::cout<<this->getModelVehicul()<<" ";
    std::cout<<"- ID:"<<this->getIdVehicul();
}

double VehiculDouaRoti::getPretPerOra() {
    return pretPeOra;
}

void VehiculDouaRoti::setID(int id) {
    this->idVehicul= id;
}


