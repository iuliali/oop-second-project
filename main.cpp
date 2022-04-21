#include <iostream>
#include "BicicletaElectrica.h"
#include "BicicletaStandard.h"
#include "VehiculDouaRoti.h"
#include "Rastel.h"
#include "TwoWheelsRentalSystem.h"
#include "Meniu.h"
int main() {
//    CardPremium card1("Iulia Talpalariu");
//    std::cout<< card1.getNumeDetinator();
//    std::cout<<card1.getNrCard()<<std::endl;
//    std::cout<<card1.getCVV()<<" ";
//    std::cout<<card1.getDataExpirare().first<<" "<<card1.getDataExpirare().second;
//    BankX::getInstance();
//    std::cout<< BankX::getInstance();

//    BicicletaElectrica bike1(34572,"CubeX5");
//    std::cout<<bike1.getModelVehicul()<<"\n";
//    std::cout<<bike1.getNivelBaterie()<<"\n";
//
//
//    BicicletaElectrica ebike(468);
//    std::cout<<ebike.getModelVehicul()<<"\n";
//    std::cout<<ebike.getIdVehicul()<<"\n";
//    std::cout<<ebike.getNivelBaterie()<<"\n";

    BicicletaStandard* pbike = new BicicletaStandard(0);
    Meniu::getInstance()->initializareSistem(new TwoWheelsRentalSystem(pbike));
    Meniu::getInstance() -> afisareMeniu();







    return 0;
}
