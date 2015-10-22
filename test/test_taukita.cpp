#include <iostream>
#include <vector>

#include "test_taukita.h"

TEST_F(TauKitaTest, explode) {
    
    Bomb b1 = Bomb(100, 100, 100);
    Bomb b2 = Bomb(200, 200, 200);
    Bomb b3 = Bomb(300, 300, 300);
    
    TauKita *taukita = new TauKita();
    taukita->T = 3;

    std::vector<Bomb> v1;
    v1.push_back(b1);

    std::vector<Bomb> v2;
    v2.push_back(b2);
    
    std::vector<Bomb> v3;
    v3.push_back(b1);
    v3.push_back(b2);
    v3.push_back(b3);
    
    taukita->bombVec.push_back(v1);
    taukita->bombVec.push_back(v2);
    taukita->bombVec.push_back(v3);
    
    taukita->explode();
    
    EXPECT_EQ(900*900+900*900+900*900, taukita->sqrdRad[0]);
    EXPECT_EQ(800*800+800*800+800*800, taukita->sqrdRad[1]);
    EXPECT_EQ(700*700+700*700+700*700, taukita->sqrdRad[2]);
    
    delete taukita;
    
}

