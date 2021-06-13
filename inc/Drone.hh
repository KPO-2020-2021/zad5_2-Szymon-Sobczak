#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <unistd.h>
#include "matrix3x3.hh"
#include "vector3D.hh"
#include "Cuboid.hh"
#include "Scene_object.hh"
#include "Hexagonal_prism.hh"
#include "lacze_do_gnuplota.hh"

/*!
    \file
        \brief  Definicja klasy Drone.

    Prototypy funkcji i metod klasy Drone.
*/

/*!
    \brief Klasa modelujaca w programie pojecie drona.
    Dron jest reprezentowany przez prostopadloscian- kadlub, cztery graniastoslupy prawidlowe szesciokatne- rotory oraz dodatkowy element reprezentujacy kamere przednia.

    Klasa posiada:
        - prywatne pole "drone_location" bedace wektorem, opisuje ono wektorowo pozycje globalnego srodka drona.
        - prywatne pole "rotors" bedace tablica czteroelementowa obiektow Hexagonal_prism, reprezentuje ono zbior rotorow drona.
        - prywatne pole "fuselage" bedace typu Cuboid, reprezentuje ono kadlub drona.
        - prywatne pole "front_camera" bedace typu Hexagonal_prism, reprezentuje ono dodatkowa bryle wyrozniajaca front drona.
        - prywatne pole "Orientation_angle" opisujace obrot drona w osi Z. 
        - prywatne pole "Drone_ID" opisujace numer identyfikacyjny drona. 
        - publiczny konstruktor z parametrm, ktory okresla pozycje poczatkowa drona.
    
    Klasa posiada prywatne metody pozwalajace na:
        - Obliczenie i zapisanie danych o wierzcholkach globalnych kadluba do pliku.
        - Obliczenie i zapisanie danych o wierzcholkach globalnych pojedynczego rotora do pliku.
        - Obliczenie i zapisanie danych o wierzcholkach globalnych dodatkowego obiektu wyroznijacego front drona do pliku.

    Klasa posiada publiczne metody pozwalajace na:
        - Ustawienie numeru ID drona.
        - Pobranie informacji o polozeniu srodka drona- wektora3D.
        - Zaplanowanie sciezki pojedynczego przelotu oraz zwiadu i zapisanie jej do pliku.
        - Poruszanie sie dronem w ukladzie globalnym, sceny w gore, dol, boki oraz obrot.
        - Aktualizacje kata obrotu drona w osi Z. 
        - Zapis polaczonej bryly drona do pliku.                                                     
*/

class Drone: public Scene_object{
    private:
        /*! \brief Wektor3D reprezentujacy srodek graniastoslupa prawidlowego szesciokatnego w przestrzeni globalnej. */
        Vector3D drone_location;
        
        /*! \brief Pole typu Cuboid reprezentujace kadlub drona. */
        Cuboid fuselage;

        /*! \brief Tablica Hexagonal_prism reprezentuja zbior rotorow drona. */
        Hexagonal_prism rotors[4];
    
        /*! \brief Pole typu Hexagonal_prism reprezentujace kamere przednia drona, dodatkowy element wyrozniajacy przod. */
        Hexagonal_prism front_camera; 

        /*! \brief Wartosc double reprezentujaca kat obrotu drona w osi Z. */
        double Orientation_angle;
        
        /*! \brief Wartosc unsigned int reprezentujaca ID drona. */
        unsigned int Drone_ID;
        
        /*! \brief Metoda realizujaca obliczanie i zapisywanie danych o wierzcholkach globalnych kadluba do pliku. */
        void Calculate_and_save_to_file_fuselage();
        
        /*! \brief Metoda realizujaca obliczanie i zapisywanie danych o wierzcholkach globalnych wybranego rotora do pliku .*/
        void Calculate_and_save_to_file_rotor(unsigned int index, Vector3D const & Trasnlation);
        
        /*! \brief Metoda realizujaca obliczanie i zapisywanie danych o wierzcholkach globalnych kamery przedniej do pliku. */
        void Calculate_and_save_to_file_front_camera(Vector3D const & Trasnlation);

    public:
        /*! \brief Konstrukotr klasy z parametrem. */
        Drone(Vector3D const & location, unsigned int ID);

        /*! \brief Metoda pozawalajaca nadac ID dronowi. */
        void set_ID(unsigned int const & new_ID);

        /*! \brief Metoda pozwlajaca pobrac informacje o polozeniu srodka kadluba drona. */
        Vector3D const get_drone_location() const;        

        /*! \brief Metoda pozwalajaca zaktualizowac kat obrotu drona o wybrany kat. */
        void update_angle(double const & additional_angle);

        /*! \brief Metoda pozwaljaca pobrac aktualny kat obrotu drona */
        double get_angle() const;
        
        /*! \brief Metoda wyznaczajaca, zapisujaca oraz rysujaca sciezke pojedynczego przelotu. */
        void plan_path(double const & angle, double const & distance, PzG::LaczeDoGNUPlota & Link);

        /*! \brief Metoda wyznaczajaca, zapisujaca oraz rysujaca sciezke zwiadu. */
        void plan_reacon(PzG::LaczeDoGNUPlota & Link);

        /*! \brief Metoda realizujaca przelot drona w pionie. */
        void go_verical(double const & altitude, PzG::LaczeDoGNUPlota & Link);

        /*! \brief Metoda realizujaca obrot drona w osi Z. */
        void rotate_drone(double const & user_angle, PzG::LaczeDoGNUPlota & Link);

        /*! \brief Metoda realizujaca przelot drona w poziomie. */
        void go_horizontal(double const & distance, double const & user_angle, PzG::LaczeDoGNUPlota & Link);

        /*! \brief Metoda realizujaca zapis calego drona do pliku. */
        void Calculate_and_save_to_file_drone();


        std::string const & get_name_of_file() override final;

        Vector3D const & get_position() override final;
};  