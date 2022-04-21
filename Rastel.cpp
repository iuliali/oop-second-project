#include "Rastel.h"
#include <iostream>
#include <experimental/random>
#include <typeinfo>
#include <string.h>



int Rastel::locuriRastel = 9;


Rastel::Rastel(std::string locatie) {
    //std::cout <<"Constructor Rastel" << locatie<<"\n";
    this->locatieRastel = locatie;
    this->locuriLibere = locuriRastel;
    this->generareVehiculeRastel();
}

 void Rastel::generareVehiculeRastel() {
    for(int i = 0; i < locuriRastel; i++) {
        std::experimental::reseed();
        //std::cout<<i+1<<". ";
        if (std::experimental::randint(1,100) % 3 == 1) {
            std::experimental::reseed();
            int random = std::experimental::randint(1, 999);
            VehiculDouaRoti* p = new BicicletaElectrica(random);
            this->rastel.push_back(p);

            //std::cout << *dynamic_cast<VehiculDouaRoti*>(p);
            this->locuriLibere -= 1;
        }
        else if (std::experimental::randint(1,100) % 3 == 0) {
            std::experimental::reseed();
            int random = std::experimental::randint(1, 999);
            VehiculDouaRoti* p = new BicicletaStandard(random);
            this->rastel.push_back(p);

            //std::cout << *dynamic_cast<VehiculDouaRoti*>(p);
            this->locuriLibere -= 1;
        }
        else {
            this->rastel.push_back(nullptr);
        }
        //std::cout<<"\n";


    }
}

Rastel::~Rastel() {
    std::vector<VehiculDouaRoti*>::iterator ptr;
    for(ptr = rastel.begin(); ptr < rastel.end(); ptr++) {
        delete *ptr;
    }
    rastel.clear();
    //std::cout<<"Destructor rastel \n";
}

int Rastel::getLocuriLibere() const {
    return this->locuriLibere;
}


std::ostream& operator<<(std::ostream &o, Rastel rastel) {
    o << rastel.getLocatie()<<"\n";
    for(int i= 0; i < rastel.rastel.size(); i++) {
        if(rastel.rastel[i] != nullptr){
            std::cout<<i+1<<". ";
            (*rastel.rastel[i]).afisare();
            std::cout << "\n";
            }

    }


    return o;
}

std::string Rastel::getLocatie() {
    return this->locatieRastel;
}

void Rastel::setLocuriLibere(int locuri){
    this->locuriLibere = locuri;
}

void Rastel::scoateBicicleta(int pozitie) {
    //std::cout<< pozitie<<"\n";
    this->rastel[pozitie] = nullptr;
}

void Rastel::adaugaBicicleta(VehiculDouaRoti* pBicicleta) {
    //std::cout << "TB SA ADAUG ASTA";
    //pBicicleta->afisare();
    //std::cout <<"\n";
    //std::cout<<rastel.size();
    for (int i = 0; i < this->rastel.size(); i++) {
        //std::cout << typeid(rastel[i]).name();
        if (rastel[i] == nullptr) {
            rastel[i] = pBicicleta;
            //std::cout << "AM ADAUGAT BICICLETA ASTA : ";
            //pBicicleta->afisare();
            std::cout <<"\n";
            this->locuriLibere --;
            break;
        }

    }
}
VehiculDouaRoti* Rastel::getBicicleta(int k) {
    return this->rastel[k]; ///upcast
}

void Rastel::afisareBiciclete() {
        std::cout << this->getLocatie()<<"\n";
        for(int i= 0; i < this->rastel.size(); i++) {
            if(rastel[i] != nullptr) {
                std::cout<<i+1<<". ";
                (*rastel[i]).afisare();
                std::cout << "\n";
            }
        }


}

void Rastel::incarcaBiciclete() {
    for(int p =0 ; p < this->rastel.size(); p++) {
        if (rastel[p] != nullptr) {
            (*rastel[p]).incarca();
        }
    }
    std::cout << "RASTEL INCARCAT - ";
    this->afisareBiciclete();
    std::cout << "\n";
    }

    ///copy constructor
Rastel::Rastel(Rastel& rastel0) {
    this->locuriLibere = Rastel::locuriRastel;
    this->locatieRastel = rastel0.getLocatie();
    std::vector<VehiculDouaRoti*>::iterator it;
    for (it = rastel0.rastel.begin(); it!= rastel0.rastel.end(); it++) {
        if(*it != nullptr) {
            if (dynamic_cast<BicicletaElectrica *>(*it) != nullptr) {
                VehiculDouaRoti *newB = new BicicletaElectrica(*dynamic_cast<BicicletaElectrica *>(*it));
                this->rastel.push_back(newB);
            } else if (dynamic_cast<BicicletaStandard *>(*it) != nullptr) {
                VehiculDouaRoti *newB = new BicicletaStandard(*dynamic_cast<BicicletaStandard *>(*it));
                this->rastel.push_back(newB);
            }

        }
        else{
            this->rastel.push_back(nullptr);
        }
    }
    this->locuriLibere = rastel0.getLocuriLibere();
}






