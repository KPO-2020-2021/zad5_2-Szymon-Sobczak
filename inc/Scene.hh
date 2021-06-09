#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

#include "Drone.hh"
#include "lacze_do_gnuplota.hh"

/*!
    \file
        \brief  Definicja klasy Scene.

    Prototypy funkcji i metod klasy Scene.
*/

/*!
  \brief Klasa modelujaca w programie pojecie Sceny.   

    Klasa posiada:
        - Prywatne pole "Drones" bedace typu std::vector, reprezentuje zbior dronow znajdujacych sie na scenie.
        - Prywatne pole "tab_of_properties_d1" bedace zbiorem wskaznikow na PzG::InfoPlikuDoRysowania, reprezentuje ono zbior ustawien rysowania drona 1. w Gnuplot.
        - Prywatne pole "tab_of_properties_d2" bedace zbiorem wskaznikow na PzG::InfoPlikuDoRysowania, reprezentuje ono zbior ustawien rysowania drona 2. w Gnuplot.
        - Prywatne pole "nbr_of_active_drone" typu unsigned int  okreslajace, ktory z dronow jest obecnie aktywny. 
        - Prywatne pole "Link" okreslajce lacze do gnuplota.
        - publiczny konstruktor z parametrem, ktory okresla lacze do gnuplota.
 
    Utworzona klasa zawiera publiczne metody pozwalajace na:
        - Zmiane aktywnego drona.
        - Pobranie informacji o aktywnym dronie.
        - Modyfikacje danych aktywnego drona./ 
*/

class Scene{
    private:
        /*! \brief Pole typu std::vector reprezentujace zbior dronow na scenie */
        std::vector <Drone> Drones;

        /*! \brief Pole typu PzG::InfoPlikuDoRysowania reprezentujace zbior ustawien rysowania drona nr 1 w Gnuplot */
        PzG::InfoPlikuDoRysowania *Tab_of_properties_d1[6];

        /*! \brief Pole typu PzG::InfoPlikuDoRysowania reprezentujace zbior ustawien rysowania drona nr 2 w Gnuplot */
        PzG::InfoPlikuDoRysowania *Tab_of_properties_d2[6];

        /*! \brief Pole typu PzG::LaczeDoGNUPlota lacze do Gnuplot */
        PzG::LaczeDoGNUPlota Link;

        /*! \brief Pole typu unsigned int, opisujace numer obecnie aktywnego drona */
        unsigned int Nbr_of_active_drone;

    public:
        /*! \brief Konstrukotr klasy z parametrem */
        Scene(PzG::LaczeDoGNUPlota & Link);

        /*! \brief Metoda sluzaca zmianie numeru aktywnego drona */
        void choose_drone(unsigned int active_drone);

        /*! \brief Metoda sluzaca pobraniu informacji o aktywnym dronie */
        Drone const & get_active_drone();
        
        /*! \brief Metoda sluzaca probranu aktywnego drona aby dokonywac w nim zmian */
        Drone & use_active_drone();
};