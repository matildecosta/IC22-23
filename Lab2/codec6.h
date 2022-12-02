#ifndef WAVQUANT_H
#define WAVQUANT_H

#include <iostream>
#include <vector>
#include <map>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include "golomb.h"
using namespace cv;
class Codec6{
    private:
        Mat in;
        int ch;
        size_t ind=0;
        double max = 32767,min=-32768; // limitações de uma variável do tipo short
        Golomb  mod0, mod1, mod2, mod3, mod4, mod5;

    public:

        Codec6(int op, Mat img){
            switch(op)
            {
                case 0:
                    mod0.set(50,"mod0.bin","w");
                    break;
                case 1:
                    mod1.set(50,"mod1.bin","w");
                    break;
                case 2:
                    mod2.set(50,"mod2.bin","w");
                    break;
                case 3:
                    mod3.set(50,"mod3.bin","w");
                    break;
                default:
                    break;
            }
            in = img;
            ch = img.channels();
        }

        void set_read(int op){
            switch(op)
            {
                case 0:
                    mod0.set(50,"mod0.bin","r");
                    break;
                case 1:
                    mod1.set(50,"mod1.bin","r");
                    break;
                case 2:
                    mod2.set(50,"mod2.bin","r");
                    break;
                case 3:
                    mod3.set(50,"mod3.bin","r");
                    break;                   
                default:
                    break;
            }
        }    

        void mode0(){
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){
                    for (int i = 0; i < ch; i++){
                        in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i];
                        mod0.encode(in.at<Vec3b>(j,k)[i]);
                    }
                }
            }
            return ;
        }

        void mode1(){
            int x_prev = 0;
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        if(k > 0){
                            x_prev = x1prev(in, k, j, i);
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i] - x_prev;
                            mod1.encode(in.at<Vec3b>(j,k)[i]);
                        }
                        else{
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i];
                            mod1.encode(in.at<Vec3b>(j,k)[i]);
                        }  
                    }
                }
            }
            return ;
        }
        void mode2(){
            int x_prev = 0;
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){  
                    for (int i = 0; i < ch; i++){
                        if(j > 0){
                            x_prev = x2prev(in.at<Vec3b>(j-1,k)[i]);
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i] - x_prev;
                            mod2.encode(in.at<Vec3b>(j,k)[i]);
                        }
                        else{
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i];
                            mod2.encode(in.at<Vec3b>(j,k)[i]);
                        }
                    }
                }
            }
            return ;
        }
        void mode3(){
            int x_prev = 0;
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){  
                    for (int i = 0; i < ch; i++){
                        if(j > 0 && k > 0){
                            x_prev = x3prev(in, k, j, i);
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i] - x_prev;
                            mod3.encode(in.at<Vec3b>(j,k)[i]);
                        }
                        else{
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i];
                            mod3.encode(in.at<Vec3b>(j,k)[i]);
                        }
                    }
                }
            }
            return ;
        }

        void desmod0(){
            Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
            vector<short> values = mod0.decode();
            int count = 0;
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(j,k)[i] = values[count];
                        count++;  
                    }
                }
            } 
            imwrite("mod0.ppm", out);
            imshow("Display window", out);
            waitKey(0);
            return ;
            
        }

        void desmod1(){
            Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
            vector<short> values = mod1.decode();
            int count = 0, x_prev = 0;
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(j,k)[i] = values[count];
                        count++;  
                    }
                }
            } 
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        if(k > 0){
                            x_prev = x1prev(out, k, j, i);
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i] + x_prev;
                        }
                        else{
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i];
                        }
                    }
                }
            }
            imwrite("mod1.ppm", out);
            imshow("Display window", out);
            waitKey(0);
            return ;   
        }

        void desmod2(){
            Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
            vector<short> values = mod2.decode();
            int count = 0, x_prev = 0;
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(j,k)[i] = values[count];
                        count++;  
                    }
                }
            } 
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        if(j > 0){
                            x_prev = x2prev(out.at<Vec3b>(j-1,k)[i]);
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i] + x_prev;
                        }
                        else{
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i];
                        }
                    }
                }
            }
            imwrite("mod2.ppm", out);
            imshow("Display window", out);
            waitKey(0);
            return ;  
        }

        void desmod3(){
            Mat out = Mat::zeros(in.rows, in.cols, CV_8UC3);
            vector<short> values = mod3.decode();
            int count = 0, x_prev = 0;
            int max = 0;
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(j,k)[i] = values[count];
                        count++;  
                    }
                }
            } 
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        if(j > 0 && k > 0){
                            x_prev = x3prev(out, k, j, i);
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i] + x_prev;
                        }
                        else{
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i];
                        }
                        if(max < int(out.at<Vec3b>(j,k)[i])){
                            max = int(out.at<Vec3b>(j,k)[i]);
                        }
                    }
                }
            }
            std::cout << "max: " << max << endl;
            imwrite("mod3.ppm", out);
            imshow("Display window", out);
            waitKey(0);
            return ;  
        }  

        void end(int op){
            switch(op)
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
                default:
                    break;
            }  
        }

        int x1prev(Mat out, int k, int j, int i){
            return int(10*in.at<Vec3b>(j,k-1)[i]);
        }

        int x2prev(auto x){
            return int(x);
        }

        int x3prev(Mat out, int k, int j, int i){
            return int(in.at<Vec3b>(j-1,k-1)[i]);
        }
    
};

#endif