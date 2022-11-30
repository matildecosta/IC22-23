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
        cout << "Usage: ./copy" << endl;
        return -1;
    }

    int op = 0;
    int op2 = 0;
    Mat in = imread(argv[argc-1],IMREAD_COLOR);

    if (!in.data){
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    cout << "What process do you want to do?" << endl;
    cout << "      0. mod0" << endl;
    cout << "      1. mod1" << endl;
    cout << "      2. mod2" << endl;
    cout << "      3. mod3" << endl;
    cout << "      4. mod4" << endl;
    cout << "      5. mod5" << endl;
    cin >> op;
    Codec6 codec(op,in);
    switch (op)
    {
        case 0: // Negative
            codec.mode0();  
            codec.end();
            codec.set_read(0);
            codec.desmod0();            
            break;

        case 1: // Mirror horizontally 
            codec.mode1();
            codec.end();
            codec.set_read(1);
            codec.desmod1();
            break;

        case 2: // Mirror vertically 
            codec.mode2();
            codec.end();
            codec.set_read(2);
            codec.desmod2();
            break;
        
        case 3: // Mirror vertically 
            codec.mode3();
            codec.end();
            codec.set_read(3);
            codec.desmod3();
            break;

        case 4: // Mirror vertically 
            codec.mode4();
            codec.end();
            codec.set_read(4);
            codec.desmod4();
            break;

        case 5: // Mirror vertically 
            codec.mode5();
            codec.end();
            codec.set_read(5);
            codec.desmod5();
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