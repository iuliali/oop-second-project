#ifndef MENIU_H
#define MENIU_H
#include <memory>
#include "TwoWheelsRentalSystem.h"
#include "BankX.h"

class Meniu {
    static Meniu* instance;
    TwoWheelsRentalSystem* sistem;
    Meniu();

public:
    Meniu(Meniu &altMeniu) = delete;
    void operator = (const Meniu&) = delete;
    static Meniu* getInstance();
    void initializareSistem(TwoWheelsRentalSystem* sistem);
    //void bunVenit();
    void afisareMeniu();
//    void afiseazaVehicule(const std::string& raspuns);
//    void alegeBicicleta(Rastel& pRastel);
//
//    void returneazaBicicleta(BicicletaStandard &pbicicletaDeReturnat);
    void inchiriere();

    void returnare();

    void meniuSecret();

    static void tarifeBiciclete();

    void adaugareBiciclete(int i);
};


#endif //MENIU_H
