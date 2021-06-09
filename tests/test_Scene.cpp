#include "../tests/doctest/doctest.h"
#include "Scene.hh"

TEST_CASE("Test konstrukotra z parametrem klasy Scene wraz z metodami pozwlajacymi na pobieranie stalych danych o dronach ze sceny oraz zmiane aktywnego drona."){
    PzG::LaczeDoGNUPlota Link;
    Scene Example(Link);
  
    CHECK ((Example.get_active_drone().get_drone_location()[0] == 100 &&
            Example.get_active_drone().get_drone_location()[1] == 100 &&
            Example.get_active_drone().get_drone_location()[2] == 3));

    Example.choose_drone(2);

    CHECK ((Example.get_active_drone().get_drone_location()[0] == 50 &&
            Example.get_active_drone().get_drone_location()[1] == 50 &&
            Example.get_active_drone().get_drone_location()[2] == 3));
}

TEST_CASE("Test reakcji metody,sluzacej do zmany aktywnego drona, na podanie blednego nueru indeksu. "){
    PzG::LaczeDoGNUPlota Link;
    Scene Example(Link);
    WARN_THROWS(Example.choose_drone(-15));
}

 TEST_CASE("Test metody pozwalajacej na pobranie drona ze sceny w celu jego modyfikacji- zadaniu kata obrotu. "){
    PzG::LaczeDoGNUPlota Link,Link2;
    Scene Example(Link);
    Vector3D test;

    CHECK ((Example.get_active_drone().get_angle() == 0));

    Example.use_active_drone().update_angle(30);

    CHECK ((Example.get_active_drone().get_angle() == 30));

} 