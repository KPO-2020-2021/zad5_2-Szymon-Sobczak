#pragma once 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Cuboid.hh"
#include "Scene_object.hh"


class Plateau: public Cuboid, public Scene_object{
    private:      
        void save_to_file(Vector3D const &  position);

    public:
        Plateau(Vector3D const & position, Vector3D const & scale, unsigned int ID);
};