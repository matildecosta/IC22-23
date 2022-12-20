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
        cout << "Usage: ./part1 <file> <model>" << endl;
        return -1;
    }
    int k; double alpha;
    cout << "Insert context order: ";
    cin >> k;
    cout << "Insert smoothing parameter:  ";
    cin >> alpha; 
    FCM fcm(k, alpha); //iniciar as variaveis fundamentais
    double min = MAXFLOAT, tmp;
    string language;
    for(size_t j = 2; j < argc; j++){
        std::cout << "Processing " << j-1 << endl;
        fcm.read_model(argv[j]);
        tmp = fcm.get_entropy(argv[1]);
        if(tmp < min){
            min = tmp; 
            language = string(argv[j]).erase(string(argv[j]).length()-5);
            language.erase(0,7);
        }
    }
    cout << "Language: " << language << endl;
    cout << "N. of bits: " << min << endl; 
    return 0;
}
