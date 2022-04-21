#ifndef TWOWHEELSRENTALSYSTEM_H
#define TWOWHEELSRENTALSYSTEM_H
#include <vector>
#include <memory>
#include "VehiculDouaRoti.h"
#include "Rastel.h"
#include <memory>


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
    VehiculDouaRoti* bicicletaInchiriata;
    bool bicicletaImprumutata;
public:
    TwoWheelsRentalSystem(BicicletaStandard* bicicletaInchiriata);
    ~TwoWheelsRentalSystem();

    friend std::ostream& operator<<(std::ostream &o, TwoWheelsRentalSystem sistem);

    void afisareLocatii();

    void afisareRastel(int k);

    void afisareLocuriLibere();

    void returneazaBicicleta(int i);

    Rastel* getRastel(int i);

    bool areBicicletaImprumutata();

    void afiseazaBicicletaCurenta();

    void imprumutaBicicleta(Rastel *prastel, int i);

    void incarcaBicicleteRastel(int i);

};


#endif //TWOWHEELSRENTALSYSTEM_H
