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
    
    std::cout << & Link << std::endl;

    Link_to_gnuplot = Link;

    std::cout << & Link_to_gnuplot << std::endl;

    Nbr_of_active_drone = 1;

    double val_ctr1[3]={100,100,3}, val_ctr2[3]={50,50,3};
    Vector3D center_of_drone1(val_ctr1),center_of_drone2(val_ctr2);

    add_new_drone(center_of_drone1);
    
    add_new_drone(center_of_drone2);

    double val_ctr_pla0[3]={150,50,10}, val_scale[3]={60,60,20};
    Vector3D center_of_plateau0(val_ctr1),scale_of_plateau0(val_ctr2);

    add_obstacle_plateau(val_ctr_pla0,val_scale, Link);
    /* 
    double trans_test[3] = {100,100,20}, scale_test[3] = {20,20,40};
    Vector3D translation(trans_tes), scale(scale_test);

    add_obstacle_plateau(trans_test,scale_test);
    */

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
    Link.Rysuj();
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

void Scene::add_obstacle_plateau(Vector3D const & position, Vector3D const & scale, PzG::LaczeDoGNUPlota & Link){
    std::shared_ptr<Plateau> tmp_ptr = std::make_shared<Plateau>(position, scale, Number_of_obstacles++);

    PzG::InfoPlikuDoRysowania *Temp_property = & Link.DodajNazwePliku(tmp_ptr->Get_Name_of_file_global().c_str());
    Temp_property-> ZmienSzerokosc(2);

    Obstacle_list.push_back(tmp_ptr);
    Objects_list.push_back(tmp_ptr);

    Link.Rysuj();
}  

void Scene::add_new_drone(Vector3D const & position){
    std::shared_ptr<Drone> tmp_ptr = std::make_shared<Drone>(position, Number_of_drones++);
    Drone_list.push_back(tmp_ptr);
    Objects_list.push_back(tmp_ptr);
}

void Scene::list_obstacles(){
    for(std::shared_ptr<Scene_object> Obstacle : Obstacle_list) {
      std::cout << "ID: " <<  Obstacle->get_obj_ID() << " "  << std::fixed << std::setprecision(2) << "(" << Obstacle->get_position()[0] << " " << Obstacle->get_position()[1] <<") - "<< Obstacle->get_type() << std::endl; 
    }
}


void Scene::delete_obstacle(int obstacle_ID, PzG::LaczeDoGNUPlota & Link){

    auto check_obstacle = [obstacle_ID](std::shared_ptr<Scene_object> Ptr) -> bool{ 
        return (Ptr->get_obj_ID() == obstacle_ID && Ptr->get_type() != "dron" ); 
    };

    std::list<std::shared_ptr<Scene_object>>::iterator obs_iterator = 
    std::find_if(Obstacle_list.begin(),Obstacle_list.end(), check_obstacle);

    if (obs_iterator == Obstacle_list.end()) {
        throw std::invalid_argument(":/ Podano bledny numer ID przeszkody ");
        return;
    }

    std::list<std::shared_ptr<Scene_object>>::iterator obj_iterator = 
    std::find(Objects_list.begin(),Objects_list.end(), (*obs_iterator));
    
    if (obj_iterator == Objects_list.end()){
        throw std::invalid_argument(":/ Podano bledny numer drona ");
        return;
    }

    Link.UsunNazwePliku((*obs_iterator)->get_name_of_file().c_str());
    
    Obstacle_list.erase(obs_iterator);
    Objects_list.erase(obj_iterator);
}