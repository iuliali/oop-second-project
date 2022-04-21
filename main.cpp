#include <iostream>
#include "BicicletaStandard.h"
#include "TwoWheelsRentalSystem.h"
#include "Meniu.h"
int main() {

    BicicletaStandard* pbike = new BicicletaStandard(0);
    Meniu::getInstance()->initializareSistem(new TwoWheelsRentalSystem(pbike));
    Meniu::getInstance() -> afisareMeniu();
///pentru ilustrare operator= si copy constructor - decomenteaza ce urmeaza
//    BicicletaElectrica bike(3817,"CARPAT", 89);
//    std::cout <<"Bike ";
//    bike.afisare();
//    std::cout <<"\n";
//    BicicletaElectrica bike2(bike);
//    std::cout <<"Bike 2 ";
//    bike2.afisare();//identic bike
//    std::cout <<"\n";
//    BicicletaElectrica bike3 (99);
//    std::cout <<"Bike 3 ";
//    bike3.afisare();
//    std::cout <<"\n";
//    bike2 = bike3;
//    std::cout <<"Bike 2 ";//identic bike3
//    bike2.afisare();
//    std::cout <<"\n";
//    Rastel rastel("Bucuresti Centru Vechi");
//    rastel.afisareBiciclete();
//    Rastel rastel2(rastel);
//    rastel2.afisareBiciclete();



    return 0;
}
