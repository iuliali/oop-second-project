#ifndef TWOWHEELSRENTALSYSTEM_H
#define TWOWHEELSRENTALSYSTEM_H
#include <vector>
#include <memory>
#include "VehiculDouaRoti.h"
#include "Rastel.h"
#include <memory>
#include "Cont.h"


class TwoWheelsRentalSystem {
    std::vector<std::string> listaLocatii= {"Parcul Tineretului",
                                           "Parcul Cismigiu",
                                           "Calea Victoriei1",
                                           "Calea Victoriei2",
                                           "Parcul Bazilescu",
                                           "Parcul Titan",
                                           "Campus Regie",
                                           "Parcul Herastrau",
                                           "Gradina Botanica",
                                           "Parcul Kiseleff"
    };
    std::vector<Rastel*> bdRastele;
    BicicletaStandard bicicletaInchiriata;
public:
    TwoWheelsRentalSystem(BicicletaStandard bicicletaInchiriata);
    ~TwoWheelsRentalSystem();


    //static std::vector<std::string>& getListaLocatii();
    friend std::ostream& operator<<(std::ostream &o, TwoWheelsRentalSystem sistem);
    void afisareLocatii();
    void afisareRastel(int k);
    BicicletaStandard& imprumutaBicicleta(Rastel& prastel, int i);

    void afisareLocuriLibere();

    void returneazaBicicleta(int i);

    Rastel &getRastel(int i);


    bool areBicicletaImprumutata();
};


#endif //TWOWHEELSRENTALSYSTEM_H
