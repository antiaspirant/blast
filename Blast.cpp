#include <cstring>
#include <iostream>
#include <math.h>

#include "Blast.h"

using namespace std;

Blast::Blast(vector<Bomb> b) {

    bombList = b;
    bombAmount = bombList.size();

    memset(world, 0, sizeof(world));
    worldSize = (W_MAX-W_MIN+1)*(W_MAX-W_MIN+1)*(W_MAX-W_MIN+1);
    
}

Blast::~Blast() {
    
}

unsigned long int Blast::explode() {

    calculateRange();
    dichotomy();
    safeDist = calculateSafeDistance();
    cout << "Max safe distance=" << safeDist << endl;
    
    return safeDist;
}

void Blast::calculateRange() {
    
    rangeMin = 0;
    
    vector<Vec3> v;
    v.push_back(Vec3(W_MIN, W_MIN, W_MIN));
    v.push_back(Vec3(W_MIN, W_MIN, W_MAX));
    v.push_back(Vec3(W_MIN, W_MAX, W_MIN));
    v.push_back(Vec3(W_MIN, W_MAX, W_MAX));
    v.push_back(Vec3(W_MAX, W_MIN, W_MIN));
    v.push_back(Vec3(W_MAX, W_MIN, W_MAX));
    v.push_back(Vec3(W_MAX, W_MAX, W_MIN));
    v.push_back(Vec3(W_MAX, W_MAX, W_MAX));
    
    rangeMax = worldSize;
    for(int i = 0 ; i < bombAmount; i++) {
        unsigned long int d = 0;
        for(int j = 0; j < v.size(); j++) {
            unsigned long int d2 = (bombList[i].x-v[j].x)*(bombList[i].x-v[j].x)+(bombList[i].y-v[j].y)*(bombList[i].y-v[j].y)+(bombList[i].z-v[j].z)*(bombList[i].z-v[j].z);
            
            //cout << d2 << endl;
            if(d2 > d) d = d2;
        }
        if(d < rangeMax) rangeMax = d;
    }
    cout << "rangeMin=" << rangeMin << "\trangeMax=" << rangeMax << endl;
}

void Blast::dichotomy() {

    unsigned long int _safeCells = worldSize;
	while((_safeCells == 0) || (_safeCells > (W_MAX*W_MAX))) {
		unsigned long int _range = (unsigned long int) (rangeMin + rangeMax) / 2;
		_safeCells = worldSize;
		memset(world, 0, sizeof(world));
		
		cout << "New squared range=" << _range << endl;
		for(int i = 0; i < bombAmount; i++) {
		    cout << "Bomb #" << i+1 << endl;
		    if(bombList[i].active) bombList[i].count = shockWave(i, _range);
            _safeCells -= bombList[i].count;
		    cout << "\tactive=" << bombList[i].active << "\t" << "affected cells=" << bombList[i].count << endl;
		    if(_safeCells == 0) break;
		}
		cout << "Safe cells=" << _safeCells << endl;
	    if(_safeCells > 0) {
	        rangeMin = _range;
	        for(int j = 0; j < bombAmount; j++) {
	            if(bombList[j].count == 0) bombList[j].active = 0;
	        }
    	} else {
	        rangeMax = _range;
	    }
	}
}

unsigned long int Blast::shockWave(int i, unsigned long int range) {
    
    unsigned long int _affectedCells = 0;
    
    int rmax = (int) sqrt(range) + 1;
    int xmin = ((bombList[i].x-rmax)>W_MIN)?(bombList[i].x-rmax):W_MIN;
    int xmax = ((bombList[i].x+rmax)<W_MAX)?(bombList[i].x+rmax):W_MAX;
    int ymin = ((bombList[i].y-rmax)>W_MIN)?(bombList[i].y-rmax):W_MIN;
    int ymax = ((bombList[i].y+rmax)<W_MAX)?(bombList[i].y+rmax):W_MAX;
    int zmin = ((bombList[i].z-rmax)>W_MIN)?(bombList[i].z-rmax):W_MIN;
    int zmax = ((bombList[i].z+rmax)<W_MAX)?(bombList[i].z+rmax):W_MAX;
    cout << "\tshockwave range [" << xmin << "; " << xmax << "][" << ymin << "; " << ymax << "][" << zmin << "; " << zmax << "]" << endl;

    for(int k = xmin; k <= xmax; k++) {
        for(int l = ymin; l <= ymax; l++) {
            for(int m = zmin; m <= zmax; m++) {
                if(world[k][l][m] == 1) continue;
                unsigned long int ri = (bombList[i].x-k)*(bombList[i].x-k)+(bombList[i].y-l)*(bombList[i].y-l)+(bombList[i].z-m)*(bombList[i].z-m);
                
                if(ri <= range) {
                    world[k][l][m] = 1;
                    _affectedCells++;
                }
            }
        }
    }
    
    return _affectedCells;
}

unsigned long int Blast::calculateSafeDistance() {
    
    unsigned long int _maxSafe = 0;
    
	for(int k = W_MIN; k <= W_MAX; k++) {
	    for(int l = W_MIN; l <= W_MAX; l++) {
	        for(int m = W_MIN; m <= W_MAX; m++) {
	            unsigned long int safe = worldSize;
	            if(world[k][l][m] == 0) {
	                for(int i = 0; i < bombAmount; i++) {
	                    if(bombList[i].active == 0) continue;
	                    unsigned long int safe2 = (bombList[i].x-k)*(bombList[i].x-k)+(bombList[i].y-l)*(bombList[i].y-l)+(bombList[i].z-m)*(bombList[i].z-m);
	                    
	                    if (safe2 < safe) safe = safe2;
	                }
	            if (safe > _maxSafe) _maxSafe = safe;
	            }
	        }
	    }
	}
	
	return _maxSafe;
}

