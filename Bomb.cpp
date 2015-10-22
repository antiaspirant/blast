#include "Bomb.h"

Vec3::Vec3() : x(0), y(0), z(0) {

}

Vec3::Vec3(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {

}

Bomb::Bomb(int x_, int y_, int z_) : Vec3(x_, y_, z_), active(1), count(0) {

}

