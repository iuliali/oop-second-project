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


TwoWheelsRentalSystem::TwoWheelsRentalSystem(BicicletaStandard* bicicletaInchiriata)
        : bicicletaInchiriata( bicicletaInchiriata) {
    //std::cout<<TwoWheelsRentalSystem::listaLocatii.size()<<" locatii:\n";

    for(int i = 0; i < TwoWheelsRentalSystem::listaLocatii.size(); i++) {
        //std::cout<<i+1<<" ";
        Rastel* pRastelNou(new Rastel(TwoWheelsRentalSystem::listaLocatii[i]));
        bdRastele.push_back(pRastelNou);
        //std::cout << *pRastelNou;

    }
    bicicletaImprumutata = false;

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
    this->bicicletaInchiriata = &prastel.getBicicleta(i);
    std::cout << *this->bicicletaInchiriata;
    prastel.scoateBicicleta(i);
    bicicletaImprumutata = true;
    //prastel.afisareBiciclete();
    //this->bicicletaInchiriata.afisare();
    return  *this->bicicletaInchiriata;
}

void TwoWheelsRentalSystem::afisareLocuriLibere() {
    for (int i = 0 ; i < bdRastele.size(); i ++) {
        std::cout << i+1<< ". In Rastelul din "<<bdRastele[i]->getLocatie()<<" sunt "<< bdRastele[i]->getLocuriLibere()<<" locuri libere\n";
    }
}

void TwoWheelsRentalSystem::returneazaBicicleta(int i) {
    if(this->bdRastele[i]->getLocuriLibere() == 0){
        std::cout<<"Nu sunt locuri libere\n";
    } else {
        std::cout << "\n";
        this->bdRastele[i]->afisareBiciclete();
        std::cout << "\n";
        this->bdRastele[i]->setLocuriLibere(this->bdRastele[i]->getLocuriLibere() - 1);
        this->bdRastele[i]->adaugaBicicleta(this->bicicletaInchiriata);
        std::cout << "\n";
        this->bdRastele[i]->afisareBiciclete();
        std::cout << "\n";
        //this->afisareRastel(i);
        std::cout << "Ai returnat cu succes bicicleta ";
        bicicletaInchiriata->afisare();
        std::cout << " in rastelul din " << bdRastele[i]->getLocatie() << "\n";
        this->bicicletaInchiriata = new BicicletaStandard(0);
        bicicletaImprumutata = false;
    }

}

bool TwoWheelsRentalSystem::areBicicletaImprumutata() {
    return bicicletaImprumutata;
}

void TwoWheelsRentalSystem::afiseazaBicicletaCurenta() {
    std::cout << "\n";
    std::cout << *bicicletaInchiriata;
    std::cout << "\n";
}











