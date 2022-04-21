#pragma once
#ifndef VEHICULDOUAROTI_H
#define VEHICULDOUAROTI_H

#include <iostream>
#include<memory>
#include <string>

class Rastel;
class VehiculDouaRoti {
    int idVehicul;
    static double pretPeOra;
    std::string modelVehicul;

public:
    VehiculDouaRoti(int idV, std::string model);
    VehiculDouaRoti(int idV);
    virtual ~VehiculDouaRoti();
    virtual int getIdVehicul();
    virtual std::string getModelVehicul();
    virtual void setModelVehicul(std::string model);
    friend std::ostream& operator<<(std::ostream& os,   VehiculDouaRoti& vehicul);
    virtual void afisare();
    static double getPretPerOra();
    void setID(int);
    void virtual incarca() = 0;

    static void setPretPerOra(double pret);
};


#endif //VEHICULDOUAROTI_H
