#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "fcm.h"

using namespace std;

int main (int argc, char** argv)
{
    if (argc < 2)
    {
        cout << "Usage: ./locatelang <file> <model>" << endl;
        return -1;
    }
    int k; double alpha;
    cout << "Insert context order: ";
    cin >> k;
    cout << "Insert smoothing parameter:  ";
    cin >> alpha; 
    FCM fcm(k, alpha); //iniciar as variaveis fundamentais

    // Vou fazer a leitura frase a frase e comparar o resultado em bits entre os diferentes modos.
    for(int j = 2; j < argc; j++){
        std::cout << "Processing models" << j-1 << endl;
        fcm.readmodels(argv[j]);
    }
    fcm.openFile(argv[1]);
    while(fcm.get_entropy_line2line());
    fcm.closeFile();
    return 0;
}
