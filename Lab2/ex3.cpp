#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "golomb.h"

using namespace cv;

int main (int argc, char** argv)
{

    if (argc < 4)
    {
        cout << "Usage: ./ex3 <outFile_Path.bin> <mode(w or r)> <m>" << endl;
        return -1;
    }
    std::string mode = argv[argc-2];
    int m = stoi(argv[argc-1]);
    Golomb gol(m,argv[argc-3],mode);
    int num;
    std::vector<short> values;
    if(mode == "r"){
        values = gol.decode();
        for(size_t i=0; i < values.size(); i++){
            std::cout << values[i] << endl;
        }
    }
    else{  //incluir opção de receber mais que um valor 
        std::cout << "How many numbers for coding? ";
        std::cin >> num;
        for(size_t i=0; i < num; i++){
            int tmp;
            std::cout << "Insert number: ";
            std::cin >> tmp;
            values.push_back(tmp);
        }
        size_t j = 0;
        while(j<values.size()){
            gol.encode(values[j]);
            j++;
        }
    }
    gol.close();
    //Golomb gol(4,argv[argc-2],argv[argc-1]);
    //gol.encode(4);
    //gol.decode();

    return 0;
}