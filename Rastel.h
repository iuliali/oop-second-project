#pragma once
#ifndef RASTEL_H
#define RASTEL_H
#include "BicicletaStandard.h"
#include "BicicletaElectrica.h"
#include <vector>
#include <memory>
class TwoWheelsRentalSystem;
class Rastel {
    static int locuriRastel;
    int locuriLibere;
    std::string locatieRastel;
    std::vector<VehiculDouaRoti*> rastel;
    void generareVehiculeRastel();


public:
    Rastel(std::string locatie);
    ~Rastel();
    std::string getLocatie();
    int getLocuriLibere() const;
    friend std::ostream& operator<<(std::ostream& o,  Rastel rastel);


    void setLocuriLibere(int locuriLibere);

    void scoateBicicleta(int pozitie);

    BicicletaStandard & getBicicleta(int k);



    void afisareBiciclete();



    void adaugaBicicleta(BicicletaStandard *pBicicleta);
};


#endif //RASTEL_H
