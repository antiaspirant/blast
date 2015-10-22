#ifndef __TEST_BLAST
#define __TEST_BLAST

#include <vector>
#include <limits.h>
#include <gtest/gtest.h>

#include "Blast.h"

class BlastTest : public ::testing::Test {
protected:
    virtual void SetUp();
    virtual void TearDown();
    
    std::vector<Bomb> v;
    Blast *blst;
    
};   

#endif//_TEST_BLAST

