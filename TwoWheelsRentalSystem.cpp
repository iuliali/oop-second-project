#include "TwoWheelsRentalSystem.h"
#include "Rastel.h"
#include "CardStandard.h"
#include "CardPremium.h"
#include <cstdlib>
#include <vector>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif


TwoWheelsRentalSystem::TwoWheelsRentalSystem(BicicletaStandard bicicletaInchiriata)
        : bicicletaInchiriata(bicicletaInchiriata) {
    //std::cout<<TwoWheelsRentalSystem::listaLocatii.size()<<" locatii:\n";

    for(int i = 0; i < TwoWheelsRentalSystem::listaLocatii.size(); i++) {
        //std::cout<<i+1<<" ";
        Rastel* pRastelNou(new Rastel(TwoWheelsRentalSystem::listaLocatii[i]));
        bdRastele.push_back(pRastelNou);
        //std::cout << *pRastelNou;

    }
    BicicletaStandard bike(99);
    this->bicicletaInchiriata = bike;
}

std::ostream &operator<<(std::ostream &o,  TwoWheelsRentalSystem sistem) {
    for(int i = 0; i < sistem.bdRastele.size(); i++) {
        std::cout << *sistem.bdRastele[i];
    }
    return o;
}



//std::vector<std::string>& TwoWheelsRentalSystem::getListaLocatii() {
//    return TwoWheelsRentalSystem::listaLocatii;
//}

TwoWheelsRentalSystem::~TwoWheelsRentalSystem() {
    //bdRastele.clear();
    //tb vazut daca se sterge totul;
    //std::cout << "Destructor sistem \n";
}

void TwoWheelsRentalSystem::afisareLocatii() {

    for (int i = 0 ; i <listaLocatii.size(); i ++) {
        std::cout << i+1<< ". "<<listaLocatii[i]<<"\n";
    }
}

Rastel& TwoWheelsRentalSystem::getRastel(int i) {
    return *this->bdRastele[i];
}
void TwoWheelsRentalSystem::afisareRastel(int k) {
    //std::cout << *bdRastele[k-1];
    bdRastele[k]->afisareBiciclete();
}

BicicletaStandard& TwoWheelsRentalSystem::imprumutaBicicleta(Rastel& prastel, int i) {
    prastel.setLocuriLibere(prastel.getLocuriLibere()+1);
    this->bicicletaInchiriata = prastel.getBicicleta(i);
    prastel.scoateBicicleta(i);
    //prastel.afisareBiciclete();
    //this->bicicletaInchiriata.afisare();
    return  this->bicicletaInchiriata;
}

void TwoWheelsRentalSystem::afisareLocuriLibere() {
    for (int i = 0 ; i < bdRastele.size(); i ++) {
        std::cout << i+1<< ". In Rastelul din "<<bdRastele[i]->getLocatie()<<" sunt "<< bdRastele[i]->getLocuriLibere()<<" locuri libere\n";
    }
}

void TwoWheelsRentalSystem::returneazaBicicleta(int i) {
    if(this->bdRastele[i]->getLocuriLibere() == 0){
        //
        std::cout<<"nu sunt locuri libere";
    }
    this->bdRastele[i]->setLocuriLibere(this->bdRastele[i]->getLocuriLibere()-1);
    this->bdRastele[i]->adaugaBicicleta(this->bicicletaInchiriata);
    //this->afisareRastel(i);
    std::cout << "Ai returnat cu succes bicicleta ";
    bicicletaInchiriata.afisare();
    std::cout<<" in rastelul din " << bdRastele[i]->getLocatie() <<"\n" ;

}

bool TwoWheelsRentalSystem::areBicicletaImprumutata() {
    if(bicicletaInchiriata.getIdVehicul() == 0)
        return false;
    return true;
}











