#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main (int argc, char** argv)
{
    int op = 0;
    int op2 = 0;
    Mat in = imread(argv[argc-2],IMREAD_COLOR);
    Mat out;
    int ch = in.channels();

    if (!in.data){
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    cout << "What process do you want to do?" << endl;
    cout << "      1. Negative" << endl;
    cout << "      2. Mirror horizontally" << endl;
    cout << "      3. Mirror vertically" << endl;
    cout << "      4. Rotate by a multiple of 90º" << endl;
    cout << "      5. Increase the intensity" << endl;
    cout << "      6. Decrease the intensity" << endl;
    cin >> op;

    switch (op)
    {
    case 1: // Negative
        out = Mat::zeros(in.cols, in.rows, CV_8UC3);
            for (int j = 0; j < in.rows; j++){
                for (int k = 0; k < in.cols; k++){
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(j,k)[i] = 255 - in.at<Vec3b>(j,k)[i];
                    }
                }
            }
            cout << "Negative done!" << endl;    
        break;

    case 2: // Mirror horizontally
        out = Mat::zeros(in.cols, in.rows, CV_8UC3);
        for (int j = 0; j < in.rows; j++){
                for (int k = 0; k < in.cols; k++){
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(j,in.cols-k)[i] = 255 - in.at<Vec3b>(j,k)[i];
                    }
                }
            }
            cout << "Mirror horizontally done!" << endl;    
        break;

    case 3: // Mirror vertically
        out = Mat::zeros(in.cols, in.rows, CV_8UC3);
        for (int j = 0; j < in.rows; j++){
                for (int k = 0; k < in.cols; k++){
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(in.rows-j,k)[i] = 255 - in.at<Vec3b>(j,k)[i];
                    }
                }
            }
            cout << "Mirror vertically done!" << endl;    
        break;

    case 4: // Rotate by a multiple of 90 degrees
        cout << "How many times do you want to rotate?" << endl;
        cin >> op2;
        if (op2 == 1){
            out = Mat::zeros(in.rows, in.cols, CV_8UC3);
            for (int j = 0; j < in.rows; j++){
                for (int k = 0; k < in.cols; k++){
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(k,in.rows-j)[i] = 255 - in.at<Vec3b>(j,k)[i];
                    }
                }
            }
            cout << "Rotate 90º done!" << endl;    
        }
        else if (op2 == 2){
            out = Mat::zeros(in.cols, in.rows, CV_8UC3);
            for (int j = 0; j < in.rows; j++){
                for (int k = 0; k < in.cols; k++){
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(in.rows-j,in.cols-k)[i] = 255 - in.at<Vec3b>(j,k)[i];
                    }
                }
            }
            cout << "Rotate 180º done!" << endl;    
        }
        else if (op2 == 3){
            out = Mat::zeros(in.rows, in.cols, CV_8UC3);
            for (int j = 0; j < in.rows; j++){
                for (int k = 0; k < in.cols; k++){
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(in.cols-k,j)[i] = 255 - in.at<Vec3b>(j,k)[i];
                    }
                }
            }
            cout << "Rotate 270º done!" << endl;    
        }
        else{
            cout << "Invalid option!" << endl;
        }
        break;

    case 5: // Increase the intensity
        out = Mat::zeros(in.cols, in.rows, CV_8UC3);
        cout << "How much do you want to increase the intensity? (0-100%)" << endl;
        cin >> op2;

        for (int j = 0; j < in.rows; j++){
            for (int k = 0; k < in.cols; k++){
                for (int i = 0; i < ch; i++){
                    out.at<Vec3b>(j,k)[i] = int((in.at<Vec3b>(j,k)[i])*((double(op2)+100.00)/100.00));
                }
            }
        }
        cout << "Increase intensity done by " << op2 << "%" << endl;       
        break;

    case 6: // Decrease the intensity
        out = Mat::zeros(in.cols, in.rows, CV_8UC3);
        cout << "How much do you want to decrease the intensity? (0-100%)" << endl;
        cin >> op2;

        for (int j = 0; j < in.rows; j++){
            for (int k = 0; k < in.cols; k++){
                for (int i = 0; i < ch; i++){
                    out.at<Vec3b>(j,k)[i] = int((in.at<Vec3b>(j,k)[i])*(1-double(op2)/100.00));
                }
            }
        }
        cout << "Decrease intensity done by " << op2 << "%" << endl; 
        break;
    
    default:
        cout << "Not an option!" << endl;
        break;
    }

    imwrite(argv[argc-1], out);
    imshow("Display window", out);
    waitKey(0);
    return 0;
}