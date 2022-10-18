#include <iostream>
#include <fstream>
#include <string>
#include "BitStream.h"

using namespace std;

int main(int argc, char* argv[]){
    string mode {"r"};

    if (argc < 2){
        cerr << "test_bs [-r (def)] \n";
        cerr << "        [-w] \n";
        cerr << "        text_file bin_file \n";
        return 1;
    }

    for (int n = 0; n < argc ; n++){
        if(string(argv[n]) == "-r"){    // Reading mode
            mode = "r";
            break;
        }
    }

    for (int n = 0; n < argc ; n++){
        if(string(argv[n]) == "-w"){    // Writing mode
            mode = "w";
            break;
        }
    }


    BitStream bs {argv[argc-1], mode};

    if (mode == "r"){
        ofstream ofs {argv[argc-2]};    // reading mode - ler o ficheiro que se colocou primeiro
        int bit;
        
        while ((bit = bs.read_bit()) != EOF){
            ofs << bit << endl;
        }
        ofs.close();
        
    } else {            // writing mode
        ifstream ifs {argv[argc-2]};
        int val;
        while (ifs >> val)
        {
            bs.write_bit(val);
        }
        ifs.close();
    }

    bs.close();

    return 0;
}