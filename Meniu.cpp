#include <iostream>
#include "Meniu.h"
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
    while(true)
    {
        if (sistem->areBicicletaImprumutata()) {
            std::cout << "Ai o BICICLETA IMPRUMUTATA!";
            sistem->afiseazaBicicletaCurenta();
            std::cout << "\n";
        }
        std::cout
                << "Bine ai venit! Inchiriaza-ti bicileta prin 2Wheels Rental System!\nAcum disponibil in tot Bucurestiul!\n";
        std::cout << "1.Inchiriere biciclete.\n";
        std::cout << "2.Returnare bicicleta.\n";
        std::cout << "3.Vezi tarife biciclete.\n";
        std::cout << "4.Exit.\n";
        int rasp;
        std::cin >> rasp;
        switch (rasp) {
            case 1 : {
                try {
                    this->inchiriere();//inchiriere
                    break;
                }
                catch (int err) {
                    if (err == 0) {
                        std::cout << "Puteti imprumuta o singura bicicleta. Returnati intai bicicleta!\n";
                    }
                    break;
                }
                catch (std::bad_cast &err2) {
                    std::cout << "Alegeti un nr valid de bicicleta!\n";
                    break;
                }
            }
            case 2: {
                if (sistem->areBicicletaImprumutata()){
                    this->returnare();
                    break;
                }

                else {
                    std::cout << "Nu ai nicio bicicleta imprumutata! Imprumuta una mai intai\n";
                    break;
                }

            }
            case 3: {
                tarifeBiciclete();
                break;
            }
            case 4: {
                exit(0);
                break;
            }
            case 5: {
                this->meniuSecret();
                break;
            }
            default: {
                std::cout << "Invalid!\n";
                break;
            }

        }

    }
}

void Meniu::inchiriere() {
    if(sistem->areBicicletaImprumutata()) {
        throw 0;
    }
    sistem->afisareLocatii();
    int rasp;
    std::cin >>rasp;
    sistem->afisareRastel(rasp-1);
    std::cout<<"Alegeti bicicleta dorita\n";
    int rasp2;
    std::cin >>rasp2;
    if(sistem->getRastel(rasp-1)->getBicicleta(rasp2-1) == nullptr) {
        throw std::bad_cast();
    }

    sistem->getRastel(rasp-1)->getBicicleta(rasp2-1)->afisare();
    std::cout<<"\n";
    sistem->imprumutaBicicleta(sistem->getRastel(rasp-1),rasp2-1);
    std::cout<<"Biciclete ramase in rastelul :";
    sistem->getRastel(rasp-1)->afisareBiciclete();

}

void Meniu::returnare() {
    sistem->afisareLocuriLibere();
    int rasp;
    std::cout<<"Alege nr locatiei unde vrei sa returnezi bicicleta:\n";
    std::cin >>rasp;
    sistem->returneazaBicicleta(rasp-1);



}

void Meniu::meniuSecret() {
    while(true) {
        std::cout << "1.Introduceti biciclete intr-un anumit rastel.\n";
        std::cout << "2.Incarcati bicicletele electrice dintr-un anumit rastel.\n";
        std::cout << "3.Modifica tarifele pentru inchiriere biciclete\n";
        std::cout << "4.Inapoi la meniu\n";
        int rasp;
        std::cin >> rasp;
        switch (rasp) {
            case 1: {
                sistem->afisareLocatii();
                std::cout << "Alege locatia\n";
                int rasp2;
                std::cin >> rasp2;
                try {
                    this->adaugareBiciclete(rasp2 - 1);
                }
                catch (int err) {
                    if(err == -1) {
                        std::cout << "Nu poti adauga atatea biciclete !\n";
                    }
                }
                break;
            }
            case 2: {
                sistem->afisareLocatii();
                std::cout << "Alege locatia pentru a incarca bicicletele electrice\n";
                int rasp2;
                std::cin >> rasp2;
                sistem->incarcaBicicleteRastel(rasp2-1);
                break;
            }
            case 3:{
                this->modificaTarife();
                break;
            }
            case 4: {
                this->afisareMeniu();
                break;
            }
            default: {
                std::cout << "Comanda Invalida\n";
                break;
            }

        }
    }

}

void Meniu::tarifeBiciclete() {
    std::cout<< "Preturi Biciclete Standard : "<<VehiculDouaRoti::getPretPerOra()<<"\n";
    std::cout<< "Preturi Biciclete Electrice : "<<VehiculDouaRoti::getPretPerOra()<<" lei pe ora + ";
    std::cout << VehiculElectric::getCostSuplimentarPeMinut()<<"lei pe minut"<<"\n";


}

void Meniu::adaugareBiciclete(int i) {
    std::cout<<"Poti adauga "<<sistem->getRastel(i)->getLocuriLibere()<<" biciclete in acest rastel\n";
    std::cout << "Cate biciclete vrei sa adaugi? ";
    int nr;
    std::cin >> nr;
    if(nr > sistem->getRastel(i)->getLocuriLibere() || nr < 1){
        throw -1;
    }
    else {
        while(nr){
            std::cout<<"Standard/ Electrica . Alege S/E\n";
            char rasp;
            std::cin >> rasp;
            if(rasp == 'S'){
                BicicletaStandard* bike = new BicicletaStandard(-1);
                //std::cout << *bike;
                std::cin >> *bike;
                sistem->getRastel(i)->adaugaBicicleta(bike);


            } else {
                BicicletaElectrica* bike = new BicicletaElectrica(-1);
                //std::cout << *bike;
                std::cin >> *bike;
                sistem->getRastel(i)->adaugaBicicleta(bike);

            }

            nr--;
        }
        std::cout << "Am adaugat cu succes biciclte in rastelul din ";
        sistem->getRastel(i)->afisareBiciclete();
        std::cout << "\n";
    }

}

void Meniu::modificaTarife() {
    std::cout << "1.Modifica pret pe ora pentru inchiriere biciclete\n";
    std::cout << "2.Modifica cost suplimentar pe minut pentru inchiriere bicicletelor electrice\n";
    int rasp;
    std::cin >> rasp;
    if(rasp == 1) {
        double pret;
        std::cout << "Introdu un nou pret per ora pentru inchiriere biciclete: ";
        std::cin >> pret;
        if(pret < 0) {
            std::cout << "Nu poti seta acest pret";
        }
        else {
            VehiculDouaRoti::setPretPerOra(pret);

        }
        this->tarifeBiciclete();
    }
    else if (rasp == 2){
        double pret;
        std::cout << "Introdu un nou pret per minut pentru inchiriere biciclete electrice: ";
        std::cin >> pret;
        if(pret < 0) {
            std::cout << "Nu poti seta acest pret";
        }
        else {
            VehiculElectric::setCostSuplimentarPeMinut(pret);

        }
        this->tarifeBiciclete();
    }
    else {
        std::cout <<"Alege 1 sau 2 !\n ";
        this-> modificaTarife();
    }



}










