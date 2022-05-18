#include "TwoWheelsRentalSystem.h"
#include "Rastel.h"
#include <vector>



TwoWheelsRentalSystem::TwoWheelsRentalSystem(BicicletaStandard* bicicletaInchiriata)
        : bicicletaInchiriata( bicicletaInchiriata) {
    //std::cout<<TwoWheelsRentalSystem::listaLocatii.size()<<" locatii:\n";

    for(int i = 0; i < TwoWheelsRentalSystem::listaLocatii.size(); i++) {
        //std::cout<<i+1<<" ";
        Rastel* pRastelNou(new Rastel(TwoWheelsRentalSystem::listaLocatii[i]));
        this->adauga(pRastelNou);
        //std::cout << *pRastelNou;

    }
    bicicletaImprumutata = false;

}

std::ostream &operator<<(std::ostream &o,  TwoWheelsRentalSystem sistem) {
    for(int i = 0; i < sistem.mEntities.size(); i++) {
        std::cout << *sistem.getEntity(i);
    }
    return o;
}



//std::vector<std::string>& TwoWheelsRentalSystem::getListaLocatii() {
//    return TwoWheelsRentalSystem::listaLocatii;
//}

TwoWheelsRentalSystem::~TwoWheelsRentalSystem() {

    for (int i = 0 ; i < mEntities.size(); i ++) {
        delete mEntities[i];
    }
    mEntities.clear();
    //std::cout << "Destructor sistem \n";
}

void TwoWheelsRentalSystem::afisareLocatii() {

    for (int i = 0 ; i <listaLocatii.size(); i ++) {
        std::cout << i+1<< ". "<<listaLocatii[i]<<"\n";
    }
}

//Rastel* TwoWheelsRentalSystem::getRastel(int i) {
//    return this->mEntities[i];
//}
void TwoWheelsRentalSystem::afisareRastel(int k) {
    //std::cout << *bdRastele[k-1];
    mEntities[k]->afisareBiciclete();
}

void TwoWheelsRentalSystem::imprumutaBicicleta(Rastel* prastel, int i) {
    prastel->setLocuriLibere(prastel->getLocuriLibere()+1);
    this->bicicletaInchiriata = dynamic_cast<BicicletaStandard *>(prastel->getEntity(i));
    //std::cout << *this->bicicletaInchiriata;
    prastel->sterge(i);
    bicicletaImprumutata = true;
    //prastel.afisareBiciclete();
    //this->bicicletaInchiriata.afisare();

}

void TwoWheelsRentalSystem::afisareLocuriLibere() {
    for (int i = 0 ; i < mEntities.size(); i ++) {
        std::cout << i+1<< ". In Rastelul din "<<mEntities[i]->getLocatie()<<" sunt "<< mEntities[i]->getLocuriLibere()<<" locuri libere\n";
    }
}

void TwoWheelsRentalSystem::returneazaBicicleta(int i) {
    if(this->mEntities[i]->getLocuriLibere() == 0){
        std::cout<<"Nu sunt locuri libere\n";
    } else {
        std::cout << "\n";
        this->mEntities[i]->afisareBiciclete();
        std::cout << "\n";
        this->mEntities[i]->adaugaBicicleta(this->bicicletaInchiriata);
        std::cout << "\n";
        this->mEntities[i]->afisareBiciclete();
        std::cout << "\n";
        //this->afisareRastel(i);
        std::cout << "Ai returnat cu succes bicicleta ";
        bicicletaInchiriata->afisare();
        std::cout << " in rastelul din " << mEntities[i]->getLocatie() << "\n";
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

void TwoWheelsRentalSystem::incarcaBicicleteRastel(int i) {
    //std::cout << *bdRastele[i];
    this->getEntity(i)->incarcaBiciclete();

}











