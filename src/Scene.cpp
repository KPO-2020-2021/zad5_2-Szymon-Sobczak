#include "Scene.hh"

/*!
    \file
        \brief Definicje metod klasy Drone.

    Zawiera definicje metod klasy Drone.
*/

/*!
    Konstruktor z parametrem obiektu typu Scene. 
    Tworzy scene z dwoma dronami w predefiniowanych miejscach. 
    Dolacza pliki zawierajace dane o wierzcholkach globalnych elementow dronow do Gnuplot oraz. 
    Ustala zakres rysowania w Gnuplot i grubosc rysowania linii.

    \param [in] Link - lacze do Gnuplota. 

    \return Scene zawierajaca dwa drony.        
*/

Scene::Scene(PzG::LaczeDoGNUPlota & Link){
    Nbr_of_active_drone = 1;
    double val_ctr1[3]={100,100,3}, val_ctr2[3]={50,50,3};
    Vector3D center_of_drone1(val_ctr1),center_of_drone2(val_ctr2);
    Drone drone_1(center_of_drone1,1), drone_2(center_of_drone2,2); 
    
    Drones.push_back(drone_1);
    Drones.at(0).set_ID(1);

    Drones.push_back(drone_2);
    Drones.at(1).set_ID(2);

    Link.ZmienTrybRys(PzG::TR_3D); /* Ustawienie trybu rysowania w gnuplot na 3D. */
    Link.UstawZakresY(0,200);      /* Uwstawienie zakresu osi OX, OY i OZ w Gnuplot */ 
    Link.UstawZakresX(0,200);
    Link.UstawZakresZ(0,150); 

    PzG::InfoPlikuDoRysowania *File_info_bed = & Link.DodajNazwePliku("../datasets/bed.dat");
    File_info_bed -> ZmienKolor(4);
    File_info_bed -> ZmienSzerokosc(2); 

    Tab_of_properties_d1[0] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_fuselage.dat");
    Tab_of_properties_d1[1] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_rotor0.dat");
    Tab_of_properties_d1[2] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_rotor1.dat");
    Tab_of_properties_d1[3] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_rotor2.dat");
    Tab_of_properties_d1[4] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_rotor3.dat");
    Tab_of_properties_d1[5] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_front_camera.dat");

    Tab_of_properties_d2[0] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_2_fuselage.dat");
    Tab_of_properties_d2[1] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_2_rotor0.dat");
    Tab_of_properties_d2[2] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_2_rotor1.dat");
    Tab_of_properties_d2[3] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_2_rotor2.dat");
    Tab_of_properties_d2[4] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_2_rotor3.dat");
    Tab_of_properties_d2[5] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_2_front_camera.dat");

    for (unsigned int i = 0; i < 6; ++i){
        Tab_of_properties_d1[i] -> ZmienSzerokosc(2);
        Tab_of_properties_d2[i] -> ZmienSzerokosc(2);
    } 
}

/*!
    Metoda pozwala ustawic, ktory z dron na scenie jest dronem aktywnym. 
    Metoda zmienia kolory dronow w zaleznosci od tego, ktory dron zostal wybrany jako aktywny.

    \param [in] active_drone - numer drona do aktywacji.
*/

void Scene::choose_drone(unsigned int active_drone){
    if(active_drone > Drones.size() || active_drone == 0)
      throw std::invalid_argument(":/ Podano bledny numer drona ");
    else    
        Nbr_of_active_drone = active_drone;
        
    if (active_drone==1){
        for (unsigned int i = 0; i < 6; ++i){
            Tab_of_properties_d1[i] -> ZmienKolor(1);
            Tab_of_properties_d2[i] -> ZmienKolor(8);
        }  
    }
    if (active_drone==2){
        for (unsigned int i = 0; i < 6; ++i){
            Tab_of_properties_d1[i] -> ZmienKolor(8);
            Tab_of_properties_d2[i] -> ZmienKolor(1);
        }  
    }
}

/*!
    \return Instancje aktywnego drona z std::vector jako stala. 
*/

Drone const & Scene::get_active_drone(){
    return Drone_list[Nbr_of_active_drone-1];
}

/*!
    \return Instancje aktywnego drona z std::vector dronow. 
*/
Drone & Scene::use_active_drone(){
    return Drone_list.at(Nbr_of_active_drone-1);
}

/* void add_obstacle_plateau(){
    std::shared_ptr<>
}  */

void Scene::add_new_drone(Vector3D & position){
    std::shared_ptr<Drone> tmp_ptr = std::make_shared<Drone>(position, Number_of_drones++);
    Drone_list.push_back(tmp_ptr);
    Objects_list.push_back(tmp_ptr);
}