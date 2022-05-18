cmake_minimum_required(VERSION 3.21)
project(twoWheelsRentalSystem)

set(CMAKE_CXX_STANDARD 14)
set(HEADER_FILES  VehiculDouaRoti.h  BicicletaStandard.h  TrotinetaStandard.h VehiculElectric.h BicicletaElectrica.h Rastel.h TwoWheelsRentalSystem.h Meniu.h)


add_executable(twoWheelsRenalSystem
        main.cpp
        VehiculDouaRoti.cpp
        VehiculDouaRoti.h
        BicicletaStandard.cpp
        BicicletaStandard.h
        VehiculElectric.cpp
        VehiculElectric.h
        BicicletaElectrica.cpp
        BicicletaElectrica.h
        Rastel.cpp
        Rastel.h
        Meniu.cpp Meniu.h
        TwoWheelsRentalSystem.cpp
        TwoWheelsRentalSystem.h
        Repository.cpp
        Repository.h
        )



