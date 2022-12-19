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
        cout << "Usage: ./ex2 <text_class> <text_analysis> <k> <alpha>" << endl;
        return -1;
    }

    string text = argv[argc-3];
    fcm myFCM(text, atoi(argv[argc-2]), atof(argv[argc-1]));
    myFCM.readFile();
    myFCM.closeFile();
    // myFCM.getStats();
    //myFCM.getProb();


    return 0;
}
