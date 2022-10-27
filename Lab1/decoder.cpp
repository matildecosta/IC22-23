#include <iostream>
#include <fstream>
#include <string>
#include "BitStream.h"

using namespace std;

// decoder - binary to text - mode = r

int main(int argc, char* argv[]){
    string mode = "r";
    string namebin (argv[argc-1]);
    string nametxt (argv[argc-2]);
    int num = 0;


    BitStream bs (namebin, mode);   // cria o objeto para enviar dados para o binário

    if (mode != "r"){
        cerr << "Invalid mode" << endl;
        return -1;
    } else {            // reading mode -r
        ofstream ofs (nametxt);
        char op;
        cout << "Do you want to decode all the .bin file? (y/n)";
        cin >> op;
        if (op == 'y'){
            int bit;
            while ((bit = bs.read_bit()) != EOF){
                ofs << bit << endl;
                cout << bit << endl;
        }
            cout << "Done!" << endl;
        }
        else if(op == 'n'){
            cout << "How many bits do you want to read?";
            cin >> num;
            int arr[num];
            bs.readN_bits(num, arr);    // preenche o array
            for (int i = 0; i < num; i++){  // escreve no txt
                ofs << arr[i] << endl;
                cout << arr[i] << endl;
            }
            cout << "Done!" << endl;
        }
        ofs.close();
    }
    bs.close();

    return 0; 
}