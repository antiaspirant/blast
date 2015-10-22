#ifndef __BLAST_H
#define __BLAST_H

#include <vector>

#include "main.h"
#include "Bomb.h"

class Blast {
public:

    //world points affected or not by shockwave
    bool world[W_MAX+1][W_MAX+1][W_MAX+1];
    //world size
    unsigned long int worldSize;
    
    //all the bombs
    std::vector<Bomb> bombList;
    //amount of bombs
    int bombAmount;
    
    //dichotomy range
    unsigned long int rangeMin;
    unsigned long int rangeMax;
    
    //squared distance
    unsigned long int safeDist;
    
    Blast(std::vector<Bomb> b);
    ~Blast();
    unsigned long int explode();
    void calculateRange();
    void dichotomy();
    unsigned long int shockWave(int i, unsigned long int range);
    unsigned long int calculateSafeDistance();

};

#endif //__BLAST_H

