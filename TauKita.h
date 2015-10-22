#ifndef __TAU_KITA_H
#define __TAU_KITA_H

#include <string>
#include <vector>

#include "main.h"
#include "Blast.h"

using namespace std;

class TauKita {
public:
    
    //number of tests
    int T;
    vector< vector<Bomb> > bombVec;
    //resault for each test
    vector<unsigned long int> sqrdRad;
        
    TauKita();
    bool loadTestFile(const char* in);
    bool writeTestFile(const char* out);
    void explode();
    void showBombs();

};

#endif //__TAU_KITA_H

