#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include "TauKita.h"

//using namespace std;

TauKita::TauKita() {

}

bool TauKita::loadTestFile(const char* in) {

    //cout << "TauKita::loadTestFile()" << endl;

    ifstream is;
    is.open(in);
    if(!is) {
        cerr << "Can't read file " << in << endl;
        return false;
    }
    
    const int buf_size = 100;
    char buf[buf_size];
    char delim[] = " ";
    
    if(!is.getline(buf, buf_size)) {
        cerr << "Wrong file format" << endl;
        return false;
    }
    T = atoi(buf);
    for(int sT = 0; sT < T; sT++) {
        vector<Bomb> b;
        
        is.getline(buf, buf_size);
        int N = atoi(buf);
        for(int sN = 0; sN < N; sN++) {
            vector<int> v;
            
            is.getline(buf, buf_size);
            char *token = strtok(buf, delim);
            while (token != NULL) {
                v.push_back(atoi(token));
                token = strtok(NULL, delim);
            }
            
            b.push_back(Bomb(v[0], v[1], v[2]));
        }
        bombVec.push_back(b);
    }
    is.close();
    
    return true;
}

bool TauKita::writeTestFile(const char* out) {

    //cout << "TauKita::writeTestFile()" << endl;
    
    ofstream os;
    os.open(out, ios::trunc);
    if(!os) {
        cerr << "Can't open file " << out << endl;
        return false;
    }
    
    for(int i = 0; i < sqrdRad.size(); i++) {
        os << sqrdRad[i] << endl;
    }
    
    os.close();
    
    return true;
}

void TauKita::explode() {
    
    for(int i = 0; i < T; i++) {
        cout << "---Test #" << i+1 << " of " << T << " / Bombs: " << bombVec[i].size() << " ---" << endl;
        
        Blast *blst = new Blast(bombVec[i]);
        sqrdRad.push_back(blst->explode());
        delete blst;
    }
}

void TauKita::showBombs() {

    //cout << "TauKita::showBombs()" << endl;

    vector< vector<Bomb> >::iterator itv;
    vector<Bomb>::iterator itb;
    for(itv = bombVec.begin(); itv != bombVec.end(); ++itv) {
        cout << "---Test---" << endl;
        for(itb = (*itv).begin(); itb != (*itv).end(); ++itb) {
            cout << (*itb).x << "\t" << (*itb).y << "\t" << (*itb).z << endl;
        }
    }
}


