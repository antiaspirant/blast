#include <iostream>

#include "test_blast.h"

void BlastTest::SetUp() {

    Bomb b1(0, 0, 0);
    Bomb b2(10, 10, 10);
    v.push_back(b1);
    v.push_back(b2);
    
    blst = new Blast(v);

}

void BlastTest::TearDown() {

    delete blst;
}

TEST_F(BlastTest, shockWave) {
    
    EXPECT_EQ(4, blst->shockWave(0, 1));
    EXPECT_EQ(3, blst->shockWave(0, 2));
    EXPECT_EQ(33, blst->shockWave(1, 4));
    
}

TEST_F(BlastTest, calculateRange) {

    unsigned long int ref = 990*990+990*990+990*990;
    blst->calculateRange();

    EXPECT_EQ(ref, blst->rangeMax);
    
    std::vector<Bomb> v2;
    v2.push_back(Bomb(500, 500, 500));
    Blast *blst2 = new Blast(v2);
    blst2->calculateRange();

    EXPECT_EQ(500*500+500*500+500*500, blst2->rangeMax);
    
    delete blst2;
}

TEST_F(BlastTest, calculateSafeDistance) {
    
    blst->bombList[0].active = 0;
    EXPECT_EQ(990*990+990*990+990*990, blst->calculateSafeDistance());
}

