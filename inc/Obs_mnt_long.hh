#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Cuboid.hh"
#include "Scene_object.hh"


class Mnt_long: public Cuboid, public Scene_object{
    private:
        void save_to_file(Vector3D const &  position);
    public:

        Mnt_long(Vector3D const & position, Vector3D const & scale, unsigned int ID);

        void transform_shape();
        
        std::string const & get_name_of_file() override final;

        Vector3D const & get_position() override final;
};