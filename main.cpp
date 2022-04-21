#include <iostream>
#include "BicicletaStandard.h"
#include "TwoWheelsRentalSystem.h"
#include "Meniu.h"
int main() {

    BicicletaStandard* pbike = new BicicletaStandard(0);
    Meniu::getInstance()->initializareSistem(new TwoWheelsRentalSystem(pbike));
    Meniu::getInstance() -> afisareMeniu();


    return 0;
}
