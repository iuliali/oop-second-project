#include "VehiculElectric.h"
#include <iostream>

double VehiculElectric:: costSuplimentarPeMinut = 0.25;

VehiculElectric::VehiculElectric(int idV, std::string model, int nivelB) : VehiculDouaRoti(idV,model) {
    this->nivelBaterie = nivelB;
    //std::cout<<"Constructor Vehicul Electric\n";

}

VehiculElectric::VehiculElectric(int idV) : VehiculDouaRoti(idV) {
    this->setNivelBaterie(95);
    //std::cout<<"Constructor Vehicul Electric cu un param\n";

}

void VehiculElectric::reincarcaBaterie() {
    this->setNivelBaterie(100);
}

int VehiculElectric::getNivelBaterie() {
    return this->nivelBaterie;
}

void VehiculElectric::setNivelBaterie(int nivel) {
    this->nivelBaterie = nivel;
}

double VehiculElectric::getCostSuplimentarPeMinut() {
    return costSuplimentarPeMinut;
}

VehiculElectric::VehiculElectric (VehiculElectric &eVehicul) : VehiculDouaRoti(eVehicul.getIdVehicul(), eVehicul.getModelVehicul()) {
    this->nivelBaterie = eVehicul.getNivelBaterie();
}

