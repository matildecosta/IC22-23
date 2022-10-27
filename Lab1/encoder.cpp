#include <iostream>
#include <fstream>
#include <string>
#include "BitStream.h"

using namespace std;

// encoder - text to binary - mode = w

int main(int argc, char* argv[]){
    string mode = "w";
    string namebin (argv[argc-1]);
    string nametxt (argv[argc-2]);
    int num = 0;


    BitStream bs (namebin, mode);   // cria o objeto para enviar dados para o binário

    if (mode != "w"){
        cerr << "Invalid mode" << endl;
        return -1;
    } else {            // writing mode - txt -> bin
        ifstream ifs (nametxt);
        char op;
        cout << "Do you want to encode all the .txt file? (y/n)";
        cin >> op;
        if (op == 'y'){
            int val;
            while (ifs >> val){
                bs.write_bit(val);
                cout << val << endl;
            }
            cout << "Done!" << endl;
        }
        else if(op == 'n'){
            cout << "How many bits do you want to write?";
            cin >> num;
            int val;
            int arr[num];
            for (int i = 0; i < num; i++){
                ifs >> val;
                arr[i] = val;
            }
            for (int i = 0; i < num; i++){
                cout << arr[i] << endl;
            }
            bs.writeN_bits(num, arr);
            cout << "Done!" << endl;
        }
        ifs.close();
    }

    bs.close();

    return 0; 
}