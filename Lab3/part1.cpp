#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "fcm.h"

using namespace std;

int main (int argc, char** argv)
{
    if (argc != 4)
    {
        cout << "Usage: ./part1 <inFile_Path> <k> <alpha>" << endl;
        return -1;
    }

    string text = argv[argc-1];
    fcm myFCM(text, atoi(argv[argc-2]));
    myFCM.readFile();
    myFCM.closeFile();
    myFCM.getStats();
    


    return 0;
}
