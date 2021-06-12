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
    double val_ctr1[3]={100,100,3}, val_ctr2[3]={50,50,3},val_ctr3[3]={30,30,3}, val_ctr4[3]={150,150,3};
    Vector3D center_of_drone1(val_ctr1),center_of_drone2(val_ctr2),center_of_drone3(val_ctr3),center_of_drone4(val_ctr4);
    Drone drone_1(center_of_drone1,1), drone_2(center_of_drone2,2); 
    
    Drones.push_back(drone_1);
    Drones.at(0).set_ID(1);

    Drones.push_back(drone_2);
    Drones.at(1).set_ID(2);

    add_new_drone(center_of_drone3);

    add_new_drone(center_of_drone4);

    double trans_test[3] = {100,100,20}, scale_test[3] = {20,20,40};
    Vector3D translation(trans_test), scale(scale_test);

    add_obstacle_plateau(trans_test,scale_test);


    Tab_of_properties_d1[0] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_0_plateau.dat");

    Link.ZmienTrybRys(PzG::TR_3D); /* Ustawienie trybu rysowania w gnuplot na 3D. */
    Link.UstawZakresY(0,200);      /* Uwstawienie zakresu osi OX, OY i OZ w Gnuplot */ 
    Link.UstawZakresX(0,200);
    Link.UstawZakresZ(0,150); 

    PzG::InfoPlikuDoRysowania *File_info_bed = & Link.DodajNazwePliku("../datasets/bed.dat");
    File_info_bed -> ZmienKolor(4);
    File_info_bed -> ZmienSzerokosc(2); 
    
    Tab_of_properties_d1[0] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_0_fuselage.dat");
    Tab_of_properties_d1[1] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_0_rotor0.dat");
    Tab_of_properties_d1[2] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_0_rotor1.dat");
    Tab_of_properties_d1[3] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_0_rotor2.dat");
    Tab_of_properties_d1[4] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_0_rotor3.dat");
    Tab_of_properties_d1[5] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_0_front_camera.dat");

    Tab_of_properties_d2[0] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_fuselage.dat");
    Tab_of_properties_d2[1] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_rotor0.dat");
    Tab_of_properties_d2[2] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_rotor1.dat");
    Tab_of_properties_d2[3] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_rotor2.dat");
    Tab_of_properties_d2[4] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_rotor3.dat");
    Tab_of_properties_d2[5] = & Link.DodajNazwePliku("../datasets/Glb_crd_No_1_front_camera.dat");

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
    
    
 /*    if(active_drone > Drones.size() || active_drone == 0)
      throw std::invalid_argument(":/ Podano bledny numer drona ");
    else   */  
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

std::shared_ptr <Drone> const Scene::get_active_drone(){
    int Number = Nbr_of_active_drone -1 ;
    
    auto check_nbr = [Number](std::shared_ptr<Drone> Ptr) -> bool{ 
        return (Ptr->get_obj_ID() == Number); 
    };
    
    std::list<std::shared_ptr<Drone>>::iterator Drone_iterator = std::find_if(Drone_list.begin(), Drone_list.end(), check_nbr);
    
    if (Drone_iterator == Drone_list.end()){
        throw std::invalid_argument(":/ Podano bledny numer drona ");
    }

    return *Drone_iterator;
}

/*!
    \return Instancje aktywnego drona z std::vector dronow. 
*/
std::shared_ptr <Drone> Scene::use_active_drone(){
    
    int Number = Nbr_of_active_drone -1 ;
    
    auto check_nbr = [Number](std::shared_ptr<Drone> Ptr) -> bool{ 
        return (Ptr->get_obj_ID() == Number); 
    };
    
    std::list<std::shared_ptr<Drone>>::iterator Drone_iterator = std::find_if(Drone_list.begin(), Drone_list.end(), check_nbr);
    
    if (Drone_iterator == Drone_list.end()){
        throw std::invalid_argument(":/ Podano bledny numer drona ");
    }

    return *Drone_iterator;
}

void Scene::add_obstacle_plateau(Vector3D const & position, Vector3D const & scale){
    std::shared_ptr<Plateau> tmp_ptr = std::make_shared<Plateau>(position, scale, Number_of_obstacles++);
    Obstacle_list.push_back(tmp_ptr);
    Objects_list.push_back(tmp_ptr);
    Link.Rysuj();
}  

void Scene::add_new_drone(Vector3D const & position){
    std::shared_ptr<Drone> tmp_ptr = std::make_shared<Drone>(position, Number_of_drones++);
    Drone_list.push_back(tmp_ptr);
    Objects_list.push_back(tmp_ptr);
    Link.Rysuj();
}