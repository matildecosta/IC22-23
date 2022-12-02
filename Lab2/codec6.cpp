#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "codec6.h"

using namespace std;
using namespace cv;

int main (int argc, char** argv)
{

    if (argc != 2)
    {
        cerr << "Usage: ./ex6 <inFile_Path.ppm>" << endl;
        return -1;
    }

    int op = 0;
    Mat in = imread(argv[argc-1],IMREAD_COLOR);
    
    if (!in.data){
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    cout << "What process do you want to do?" << endl;
    cout << "      0. mod0      2. mod2     4. mod4     6. mod6" << endl;
    cout << "      1. mod1      3. mod3     5. mod5     7. mod7" << endl;
    cout << "R: ";
    cin >> op;
    Codec6 codec(op,in);
    switch (op)
    {
        case 0:
            codec.mode0();
            codec.end(0);
            codec.set_read(0);
            codec.desmod0();
            codec.end(0);
            break;

        case 1:
            codec.mode1();
            codec.end(1);
            codec.set_read(1);
            codec.desmod1();
            codec.end(1);
            break;

        case 2:
            codec.mode2();
            codec.end(2);
            codec.set_read(2);
            codec.desmod2();
            codec.end(2);
            break;
        
        case 3:
            codec.mode3();
            codec.end(3);
            codec.set_read(3);
            codec.desmod3();
            codec.end(3);
            break;

        case 4:
            codec.mode4();
            codec.end(4);
            codec.set_read(4);
            codec.desmod4();
            codec.end(4);
            break;

        case 5:
            codec.mode5();
            codec.end(5);
            codec.set_read(5);
            codec.desmod5();
            codec.end(5);
            break;
        
        case 6:
            codec.mode6();
            codec.end(6);
            codec.set_read(6);
            codec.desmod6();
            codec.end(6);
            break;

        case 7:
            codec.mode7();
            codec.end(7);
            codec.set_read(7);
            codec.desmod7();
            codec.end(7);
            break;

        default:
            cout << "Not an option!" << endl;
            break;
    }

    // imwrite(argv[argc-1], out);
    // imshow("Display window", out);
    // waitKey(0);
    return 0;
}