#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "golomb.h"

using namespace std;
using namespace cv;

int main (int argc, char** argv)
{

    if (argc < 3 )
    {
        cout << "Usage: ./copy <inFile_Path> <mode(w or r)> <inteiro a descodificar>" << endl;
        return -1;
    } 
    std::string mode = argv[argc-2];
    int num = stoi(argv[argc-1]);
    Golomb gol(4,argv[argc-3],mode);
    if(mode == "r"){
        gol.decode();
    }
    else{
        gol.encode(num);
    }
    //Golomb gol(4,argv[argc-2],argv[argc-1]);
    //gol.encode(4);
    //gol.decode();

    return 0;
}