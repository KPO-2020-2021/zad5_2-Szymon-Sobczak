#include "Scene_object.hh"

Scene_object::Scene_object(unsigned int ID, std::string type){    
    object_ID = ID;
    type_of_obj = type;
}

int Scene_object::get_obj_ID(){
    return object_ID;
}

std::string Scene_object::get_type() const{
    return type_of_obj;
}
