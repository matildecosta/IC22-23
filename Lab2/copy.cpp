#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main (int argc, char** argv)
{
    Mat image;
    image = imread(argv[argc-2], CV_LOAD_IMAGE_COLOR);

    if (!image.data)
    {
        cout << "Could not open or find the image" << endl;
        return -1;
    }
    
    imwrite(argv[argc-1], image);

    imshow("Display window", image);
    waitKey(0);
    return 0;
}