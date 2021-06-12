#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "Geometrical_solid.hh"



class Scene_object{
    private:
        int object_ID;
        
        std::string type_of_obj;
    
    public:
        Scene_object(unsigned int ID, std::string type);
    
        virtual ~Scene_object() {};

        std::string get_type() const;

        int get_obj_ID();
};