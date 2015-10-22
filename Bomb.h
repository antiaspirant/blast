#ifndef __BOMB_H
#define __BOMB_H

class Vec3 {
public:
    int x, y, z;

    Vec3();
    Vec3(int x_, int y_, int z_);
    
};

class Bomb: public Vec3 {
public:
    //bomb activeness
    bool active;
    
    //amount of affected points
    unsigned long int count;
    
    Bomb(int x_, int y_, int z_);

};

#endif //__BOMB_H

