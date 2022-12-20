#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "fcm.h"

using namespace std;

int main (int argc, char** argv)
{
    if (argc != 5)
    {
        cout << "Usage: ./part1 <model_file> <test> <k> <alpha>" << endl;
        return -1;
    }
    FCM fcm(atoi(argv[argc-2]), atof(argv[argc-1]));
    fcm.read_model(argc[argv-4]);
    fcm.get_entropy(argv[argc-3]);


    return 0;
}
