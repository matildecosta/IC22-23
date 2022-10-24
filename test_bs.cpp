#include <iostream>
#include <fstream>
#include <string>
#include "BitStream.h"

using namespace std;

int main(int argc, char* argv[]){
    string mode = "r";
    string namebin (argv[argc-2]);
    string nametxt (argv[argc-3]);

    if (argc < 2){
        cerr << "test_bs [-r] \n";
        cerr << "        [-w] \n";
        cerr << "        text_file bin_file \n";
        return 1;
    }

    if(string(argv[argc-1]) == "-r"){    // Reading mode
        mode = "r";
    }else if(string(argv[argc-1]) == "-w"){    // Writing mode
        mode = "w";
    }else{
        cerr << "test_bs [-r (def)] \n";
        cerr << "        [-w] \n";
        cerr << "        text_file bin_file \n";
        return 1;
    }

    BitStream bs (namebin, mode);

    if (mode == "r"){
        ofstream ofs (nametxt);    // reading mode - bin -> txt
        int bit;
        
        while ((bit = bs.read_bit()) != EOF){
            ofs << bit << endl;
            cout << bit << endl;
        }
        ofs.close();
    } else {            // writing mode - txt -> bin
        ifstream ifs (nametxt);
        int val;
        while (ifs >> val)
        {
            bs.write_bit(val);
            cout << val << endl;
        }
        ifs.close();
    }

    bs.close();

    return 0; 
}