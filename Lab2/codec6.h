#ifndef WAVQUANT_H
#define WAVQUANT_H

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <math.h>
#include "golomb.h"
using namespace cv;
class Codec6
{
private:
    Mat in;
    int ch;
    size_t ind = 0;
    Golomb mod0, mod1, mod2, mod3, mod4, mod5, mod6, mod7;

public:
    Codec6(int op, Mat img)
    {
        switch (op)
        {
        case 0:
            mod0.set(50, "mod0.bin", "w");
            break;
        case 1:
            mod1.set(50, "mod1.bin", "w");
            break;
        case 2:
            mod2.set(50, "mod2.bin", "w");
            break;
        case 3:
            mod3.set(50, "mod3.bin", "w");
            break;
        case 4:
            mod4.set(50, "mod4.bin", "w");
            break;
        case 5:
            mod5.set(50, "mod5.bin", "w");
            break;
        case 6:
            mod6.set(50, "mod6.bin", "w");
            break;
        case 7:
            mod7.set(50, "mod7.bin", "w");
            break;
        default:
            break;
        }
        in = img;
        ch = img.channels();
    }

    void set_read(int op)
    {
        switch (op)
        {
        case 0:
            mod0.set(50, "mod0.bin", "r");
            break;
        case 1:
            mod1.set(50, "mod1.bin", "r");
            break;
        case 2:
            mod2.set(50, "mod2.bin", "r");
            break;
        case 3:
            mod3.set(50, "mod3.bin", "r");
            break;
        case 4:
            mod4.set(50, "mod4.bin", "r");
            break;
        case 5:
            mod5.set(50, "mod5.bin", "r");
            break;
        case 6:
            mod6.set(50, "mod6.bin", "r");
            break;
        case 7:
            mod7.set(50, "mod7.bin", "r");
            break;
        default:
            break;
        }
    }

    void mode0()
    {
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    mod0.encode(in.at<Vec3b>(j, k)[i]);
                }
            }
        }
        return;
    }

    void mode1()
    {
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (k > 0)
                    {
                        x_prev = x1prev(in, k, j, i);
                        in.at<Vec3b>(j, k)[i] = int(in.at<Vec3b>(j, k)[i]) - x_prev;
                        mod1.encode(in.at<Vec3b>(j, k)[i]);
                        
                    }
                    else
                    {
                        mod1.encode(in.at<Vec3b>(j, k)[i]);
                    }
                }
            }
        }
        return;
    }
    void mode2()
    {
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0)
                    {
                        x_prev = x2prev(in, k, j, i);
                        in.at<Vec3b>(j, k)[i] = in.at<Vec3b>(j, k)[i] - x_prev;
                        mod2.encode(in.at<Vec3b>(j, k)[i]);
                    }
                    else
                    {
                        mod2.encode(in.at<Vec3b>(j, k)[i]);
                    }
                }
            }
        }
        return;
    }
    void mode3()
    {
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x3prev(in, k, j, i);
                        in.at<Vec3b>(j, k)[i] = in.at<Vec3b>(j, k)[i] - x_prev;
                        mod3.encode(in.at<Vec3b>(j, k)[i]);
                    }
                    else
                    {
                        mod3.encode(in.at<Vec3b>(j, k)[i]);
                    }
                }
            }
        }
        return;
    }

    void mode4()
    {
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x4prev(in, k, j, i);
                        in.at<Vec3b>(j, k)[i] = in.at<Vec3b>(j, k)[i] - x_prev;
                        mod4.encode(in.at<Vec3b>(j, k)[i]);
                    }
                    else
                    {
                        mod4.encode(in.at<Vec3b>(j, k)[i]);
                    }
                }
            }
        }
        return;
    }

    void mode5()
    {
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x5prev(in, k, j, i);
                        in.at<Vec3b>(j, k)[i] = in.at<Vec3b>(j, k)[i] - x_prev;
                        mod5.encode(in.at<Vec3b>(j, k)[i]);
                    }
                    else
                    {
                        mod5.encode(in.at<Vec3b>(j, k)[i]);
                    }
                }
            }
        }
        return;
    }

    void mode6()
    {
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x6prev(in, k, j, i);
                        in.at<Vec3b>(j, k)[i] = in.at<Vec3b>(j, k)[i] - x_prev;
                        mod6.encode(in.at<Vec3b>(j, k)[i]);
                    }
                    else
                    {
                        mod6.encode(in.at<Vec3b>(j, k)[i]);
                    }
                }
            }
        }
        return;
    }

    void mode7()
    {
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x7prev(in, k, j, i);
                        in.at<Vec3b>(j, k)[i] = in.at<Vec3b>(j, k)[i] - x_prev;
                        mod7.encode(in.at<Vec3b>(j, k)[i]);
                    }
                    else
                    {
                        mod7.encode(in.at<Vec3b>(j, k)[i]);
                    }
                }
            }
        }
        return;
    }

    void desmod0()
    {
        Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
        vector<short> values = mod0.decode();
        int count = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    out.at<Vec3b>(j, k)[i] = values[count];
                    count++;
                }
            }
        }
        imwrite("mod0.ppm", out);
        imshow("Display window", out);
        waitKey(0);
        return;
    }

    void desmod1()
    {
        Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
        Mat outt = Mat::zeros(in.rows, in.cols, CV_8UC3);
        vector<short> values = mod1.decode();
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    out.at<Vec3b>(j, k)[i] = values[x_prev];
                    x_prev++;
                }
            }
        }
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x1prev(out, k, j, i);
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i] + x_prev;
                    }
                    else
                    {
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i];
                    }
                }
            }
        }
        imwrite("mod1.ppm", outt);
        imshow("Display window", outt);
        waitKey(0);
        return;
    }

    void desmod2()
    {
        Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
        Mat outt = Mat::zeros(in.rows, in.cols, CV_8UC3);
        vector<short> values = mod2.decode();
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    out.at<Vec3b>(j, k)[i] = values[x_prev];
                    x_prev++;
                }
            }
        }
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x2prev(out, k, j, i);
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i] + x_prev;
                    }
                    else
                    {
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i];
                    }
                }
            }
        }
        imwrite("mod2.ppm", outt);
        imshow("Display window", outt);
        waitKey(0);
        return;
    }

    void desmod3()
    {
        Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
        Mat outt = Mat::zeros(in.rows, in.cols, CV_8UC3);
        vector<short> values = mod3.decode();
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    out.at<Vec3b>(j, k)[i] = values[x_prev];
                    x_prev++;
                }
            }
        }
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x3prev(out, k, j, i);
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i] + x_prev;
                    }
                    else
                    {
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i];
                    }
                }
            }
        }
        imwrite("mod3.ppm", outt);
        imshow("Display window", outt);
        waitKey(0);
        return;
    }

    void desmod4()
    {
        Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
        Mat outt = Mat::zeros(in.rows, in.cols, CV_8UC3);
        vector<short> values = mod4.decode();
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    out.at<Vec3b>(j, k)[i] = values[x_prev];
                    x_prev++;
                }
            }
        }
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x4prev(out, k, j, i);
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i] + x_prev;
                    }
                    else
                    {
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i];
                    }
                }
            }
        }
        imwrite("mod4.ppm", outt);
        imshow("Display window", outt);
        waitKey(0);
        return;
    }

    void desmod5()
    {
        Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
        Mat outt = Mat::zeros(in.rows, in.cols, CV_8UC3);
        vector<short> values = mod5.decode();
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    out.at<Vec3b>(j, k)[i] = values[x_prev];
                    x_prev++;
                }
            }
        }
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x5prev(out, k, j, i);
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i] + x_prev;
                    }
                    else
                    {
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i];
                    }
                }
            }
        }
        imwrite("mod5.ppm", outt);
        imshow("Display window", outt);
        waitKey(0);
        return;
    }

    void desmod6()
    {
        Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
        Mat outt = Mat::zeros(in.rows, in.cols, CV_8UC3);
        vector<short> values = mod6.decode();
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    out.at<Vec3b>(j, k)[i] = values[x_prev];
                    x_prev++;
                }
            }
        }
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x6prev(out, k, j, i);
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i] + x_prev;
                    }
                    else
                    {
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i];
                    }
                }
            }
        }
        imwrite("mod6.ppm", outt);
        imshow("Display window", outt);
        waitKey(0);
        return;
    }

    void desmod7()
    {
        Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
        Mat outt = Mat::zeros(in.rows, in.cols, CV_8UC3);
        vector<short> values = mod7.decode();
        int x_prev = 0;
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    out.at<Vec3b>(j, k)[i] = values[x_prev];
                    x_prev++;
                }
            }
        }
        for (int j = 0; j < in.rows; j++)
        {
            for (int k = 0; k < in.cols; k++)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (j > 0 && k > 0)
                    {
                        x_prev = x7prev(out, k, j, i);
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i] + x_prev;
                    }
                    else
                    {
                        outt.at<Vec3b>(j, k)[i] = out.at<Vec3b>(j, k)[i];
                    }
                }
            }
        }
        imwrite("mod7.ppm", outt);
        imshow("Display window", outt);
        waitKey(0);
        return;
    }

    void end(int op)
    {
        switch (op)
        {
        case 0:
            mod0.close();
            break;
        case 1:
            mod1.close();
            break;
        case 2:
            mod2.close();
            break;
        case 3:
            mod3.close();
            break;
        case 4:
            mod4.close();
            break;
        case 5:
            mod5.close();
            break;
        case 6:
            mod6.close();
            break;
        case 7:
            mod7.close();
            break;
        default:
            break;
        }
    }

    int x1prev(Mat out, int k, int j, int i)
    {
        return int(10 * out.at<Vec3b>(j, k-1)[i]);
    }

    int x2prev(Mat out, int k, int j, int i)
    {
        return int(out.at<Vec3b>(j-1, k)[i]);
    }

    int x3prev(Mat out, int k, int j, int i)
    {
        return int(out.at<Vec3b>(j-1, k-1)[i]);
    }
    
    int x4prev(Mat out, int k, int j, int i)
    {
        return int(out.at<Vec3b>(j, k-1)[i]) + int(out.at<Vec3b>(j-1, k)[i] - out.at<Vec3b>(j-1, k-1)[i]);
    }

    int x5prev(Mat out, int k, int j, int i)
    {
        return int(out.at<Vec3b>(j, k-1)[i]) + ((out.at<Vec3b>(j-1, k)[i] - out.at<Vec3b>(j-1, k-1)[i])/2);
    }

    int x6prev(Mat out, int k, int j, int i)
    {
        return int(out.at<Vec3b>(j-1, k)[i]) + ((out.at<Vec3b>(j, k-1)[i] - out.at<Vec3b>(j-1, k-1)[i])/2);
    }

    int x7prev(Mat out, int k, int j, int i)
    {
        return (int(out.at<Vec3b>(j, k-1)[i]) + out.at<Vec3b>(j-1, k)[i])/2;
    }
};

#endif