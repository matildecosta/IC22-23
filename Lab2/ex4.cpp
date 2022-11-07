#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main (int argc, char** argv)
{

    if (argc != 3)
    {
        cout << "Usage: ./copy <inFile_Path> <outFile _Path>" << endl;
        return -1;
    }

    Mat in = imread(argv[argc-2],IMREAD_COLOR);
    Mat out;


    imwrite(argv[argc-1], out);
    imshow("Display window", out);
    waitKey(0);
    return 0;
}