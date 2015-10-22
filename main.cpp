#include <getopt.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <vector>
#include <string>

#include "main.h"
#include "TauKita.h"
//#include "Bomb.h"
//#include "Blast.h"

using namespace std;

const char *program_name = "blast";

void print_usage() {

    cout << "Usage: " << program_name << " [-hio]" << endl;
    cout << "\t-h\t\thelp message" << endl;
    cout << "\t-i <filename>\tread data from file (default \"in\")" << endl;
    cout << "\t-o <filename>\twrite data to file (default \"out\")" << endl;
}

int main(int argc, char **argv) {

    int option = 0;
    const char *file_input = NULL;
    const char *file_output = NULL;
    const char *short_options = "hi:o:";
    while((option = getopt(argc, argv, short_options)) != -1) {
        switch(option) {
            case 'h':
                print_usage();
                exit(0);
            case 'i':
                file_input = optarg;
                break;
            case 'o':
                file_output = optarg;
                break;
            default:
                print_usage();
                exit(1);
        }
    }
    
    if(!file_input) file_input = "in";
    if(!file_output) file_output = "out";
    
    cout << "Reading from \"" << file_input << "\" file, writing to \"" << file_output << "\" file." << endl;
    
    TauKita *taukita = new TauKita();
    if(!taukita->loadTestFile(file_input)) {
        cout << "Exit" << endl;
        return 1;
    }
    //taukita->showBombs();
    taukita->explode();
    if(!taukita->writeTestFile(file_output)) {
        cout << "Exit" << endl;
        return 1;
    }

    return 0;
}

