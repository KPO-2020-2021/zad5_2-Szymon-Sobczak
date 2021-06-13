#include "Obs_plateau.hh"

 Plateau::Plateau(Vector3D const & position, Vector3D const & scale, unsigned int ID) : Cuboid (), Scene_object(ID, "plaskowyz") {
    this-> update_scale (scale);
    save_to_file(position);
}


void Plateau::save_to_file(Vector3D const & position){
    
    Transform_to_global_coords(position);

    std::ofstream  FileStrm;
    Vector3D P1,P2;

    std::string name_of_file = this->Get_Name_of_file_global() + "No_" + std::to_string(get_obj_ID()) + "_plateau.dat";
    
    update_Name_of_file_global(name_of_file);

    FileStrm.open(name_of_file);
    if (!FileStrm.is_open()){
      throw std::runtime_error(":(  Operacja otwarcia pliku do zapisu nie powiodla sie.");
    }
    
    P1 = ((*this)[0] + (*this)[7])/2;
    P2 = ((*this)[2] + (*this)[5])/2;

    FileStrm << P1 << std::endl
             << (*this)[6] << std::endl
             << (*this)[4] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;

    FileStrm << P1 << std::endl
             << (*this)[7] << std::endl
             << (*this)[5] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm << P1 << std::endl
             << (*this)[1] << std::endl
             << (*this)[3] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm << P1 << std::endl
             << (*this)[0] << std::endl
             << (*this)[2] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm << P1 << std::endl
             << (*this)[6] << std::endl
             << (*this)[4] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm.close();
}

std::string const & Plateau::get_name_of_file(){
  return Get_Name_of_file_global();
}

Vector3D const & Plateau::get_position(){
  return get_center();
}