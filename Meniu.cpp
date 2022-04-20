#include <iostream>
#include "Meniu.h"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
#include <cstdlib>
#include "BicicletaStandard.h"

Meniu* Meniu::instance = nullptr;

Meniu* Meniu::getInstance() {
    if(instance == nullptr) {
        instance = new Meniu();
    }
    return instance;
}

Meniu::Meniu() {
    //std::cout<<"Meniu creat\n";
}

void Meniu::initializareSistem(TwoWheelsRentalSystem* sist) {
    this->sistem = sist;



}


void Meniu::afisareMeniu(){


    std::cout << "Bine ai venit! Inchiriaza-ti bicileta prin 2Wheels Rental System! Acum disponibil in tot Bucurestiul!\n";
    std::cout<< "1.Inchiriere biciclete.\n";
    std::cout << "2.Returnare bicicleta.\n";
    std::cout << "3.Vezi tarife biciclete.\n";
    std::cout << "4.Exit.\n";
    int rasp;
    std::cin >> rasp;
    switch (rasp) {
        case 1 : {
            try {
                this->inchiriere();//inchiriere
            }
            catch (int err) {
                std::cout << "Puteti imprumuta o singura bicicleta. Returnati intai bicicleta!";
                this->afisareMeniu();
            }
            break;
        }
        case 2: {this->returnare();break;}
        case 3: {tarifeBiciclete();
            this->afisareMeniu();
            break;}
        case 4: {exit(0);break;}
        case 5: {this->meniuSecret();break;}
        default: {
            std::cout << "Invalid!\n";
            this->afisareMeniu();

        }

    }


}

void Meniu::inchiriere() {
    if(!sistem->areBicicletaImprumutata()) {
        throw 0;
    }
    sistem->afisareLocatii();
    int rasp;
    std::cin >>rasp;
    sistem->afisareRastel(rasp-1);
    std::cout<<"Alegeti bicicleta dorita\n";
    int rasp2;
    std::cin >>rasp2;
    sistem->getRastel(rasp-1).getBicicleta(rasp2-1).afisare();
    std::cout<<"\n";
    sistem->imprumutaBicicleta(sistem->getRastel(rasp-1),rasp2-1);
    std::cout<<"Biciclete ramase in rastelul :";
    sistem->getRastel(rasp-1).afisareBiciclete();
    this->afisareMeniu();

}

void Meniu::returnare() {
    sistem->afisareLocuriLibere();
    int rasp;
    std::cout<<"Alege nr locatiei unde vrei sa returnezi bicicleta:\n";
    std::cin >>rasp;
    sistem->returneazaBicicleta(rasp-1);
    this->afisareMeniu();



}

void Meniu::meniuSecret() {
    std::cout << "1.Introduceti biciclete intr-un anumit rastel.\n";
    std::cout << "2.Incarcati bicicletele electrice dintr-un anumit rastel.\n";
    std::cout << "3.Inapoi la meniu\n";
    int rasp;
    std::cin >> rasp;
    switch (rasp){
        case 1: {
            sistem->afisareLocatii();
            std::cout << "Alege locatia\n";
            int rasp2;
            std::cin >> rasp2;
            this->adaugareBiciclete(rasp2-1);
            break;
        }
        case 2: {
            sistem->afisareLocatii();
            std::cout << "Alege locatia pentru a incarca bicicletele electrice\n";
            int rasp2;
            std::cin >> rasp2;
            //sistem->incarcaBicicleteRastel(rasp2-1);
            break;
        }
        case 3:     {this->afisareMeniu();

            break;
        }
        default: {
            std::cout<< "Comanda Invalida\n";
            this->meniuSecret();
            break;
        }

    }


}

void Meniu::tarifeBiciclete() {
    std::cout<< "Preturi Biciclete Standard : "<<VehiculDouaRoti::getPretPerOra()<<"\n";
    std::cout<< "Preturi Biciclete Electrice : "<<VehiculDouaRoti::getPretPerOra()<<" lei pe ora + ";
    std::cout << VehiculElectric::getCostSuplimentarPeMinut()<<"lei pe minut"<<"\n";


}

void Meniu::adaugareBiciclete(int i) {
    std::cout<<"Poti adauga "<<sistem->getRastel(i).getLocuriLibere()<<" biciclete in acest rastel\n";
    std::cout << "Cate biciclete vrei sa adaugi? ";
    int nr;
    std::cin >> nr;
    if(nr > sistem->getRastel(i).getLocuriLibere()){
        throw -1;
    }
    else {
        while(nr){
            std::cout<<"Standard/ Electrica . Alege S/E\n";
            char rasp;
            if(rasp == 'S'){
                BicicletaStandard* bike = new BicicletaStandard(-1);
                std::cin >> *bike;
                sistem->getRastel(i).adaugaBicicleta(*bike);


            } else {
                BicicletaElectrica * bike;
                std::cin >> *dynamic_cast<BicicletaStandard*>(bike);
                sistem->getRastel(i).adaugaBicicleta(*bike);

            }
            nr--;
        }
    }

}








