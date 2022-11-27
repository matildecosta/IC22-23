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

    if (argc < 5)
    {
        cout << "Usage: ./copy <inFile_Path> <mode(w or r)> <m> <int to encode>" << endl;
        return -1;
    } 
    std::string mode = argv[argc-3];
    int num = stoi(argv[argc-1]);
    int m = stoi(argv[argc-2]);
    Golomb gol(m,argv[argc-4],mode);
    if(mode == "r"){
        gol.decode();
    }
    else{
        gol.encode(num);
        // std::cout  << endl;
        gol.encode(2);
        // std::cout  << endl;
        gol.encode(1);
    }
    gol.close();
    //Golomb gol(4,argv[argc-2],argv[argc-1]);
    //gol.encode(4);
    //gol.decode();

    return 0;
}