#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "fcm.h"

using namespace std;

int main (int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./part1 <inFile_Path>" << endl;
        return -1;
    }

    fcm myFCM(argv[1]);

    


    return 0;
}
