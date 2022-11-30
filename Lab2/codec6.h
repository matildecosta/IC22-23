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
        size_t count = 0;

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
                case 4:
                    mod4.set(50,"mod4.bin","w");
                    break;
                case 5:
                    mod5.set(50,"mod5.bin","w");
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
                case 4:
                    mod4.set(50,"mod4.bin","r");
                    break;
                case 5:
                    mod5.set(50,"mod5.bin","r");
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
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        if(k > 0){
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i] - 0.001*in.at<Vec3b>(j,k-1)[i];
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
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){  
                    for (int i = 0; i < ch; i++){
                        if(j > 1){
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i] - 0.001*in.at<Vec3b>(j-1,k)[i];
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
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        if(j > 1 && k>1){
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i] - 0.001*in.at<Vec3b>(j-1,k-1)[i];
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

        void mode4(){
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){  
                    for (int i = 0; i < ch; i++){
                        if(j > 1 && k>1){
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i] - (0.001*in.at<Vec3b>(j,k-1)[i] + 0.001*in.at<Vec3b>(j-1,k)[i] - 0.001*in.at<Vec3b>(j-1,k-1)[i]);
                            mod4.encode(in.at<Vec3b>(j,k)[i]);
                        }
                        else{
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i];
                            mod4.encode(in.at<Vec3b>(j,k)[i]);
                        }
                    }
                }
            }
            return ;
        }

        void mode5(){
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){  
                    for (int i = 0; i < ch; i++){
                        if(j > 1 && k>1){
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i] - (0.001*in.at<Vec3b>(j,k-1)[i] + (0.001*in.at<Vec3b>(j-1,k)[i] - 0.001*in.at<Vec3b>(j-1,k-1)[i])/2);
                            mod5.encode(in.at<Vec3b>(j,k)[i]);
                        }
                        else{
                            in.at<Vec3b>(j,k)[i] = in.at<Vec3b>(j,k)[i];
                            mod5.encode(in.at<Vec3b>(j,k)[i]);
                        }
                    }
                }
            }
            return ;            
        }

        void desmod0(){
            Mat out = Mat::zeros(in.cols, in.rows, CV_8UC3);
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
            Mat out = Mat::zeros(in.cols, in.rows, CV_8UC3);
            vector<short> values = mod1.decode();
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
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        if(k > 0){
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i] + 0.001*out.at<Vec3b>(j,k-1)[i];
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
            Mat out = Mat::zeros(in.cols, in.rows, CV_8UC3);
            vector<short> values = mod2.decode();
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
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){ 
                    for (int i = 0; i < ch; i++){
                        if(j > 1){
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i] + 0.001*out.at<Vec3b>(j-1,k)[i];
                        }
                        else{
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i];
                        }
                    }
                }
            }
            std::cout << count << endl;
            imwrite("mod2.ppm", out);
            imshow("Display window", out);
            waitKey(0);
            return ;  
        }

        void desmod3(){
            Mat out = Mat::zeros(in.cols, in.rows, CV_8UC3);
            vector<short> values = mod3.decode();
            int count = 0;
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){  //a partir de k=1, pk para k=0 o valor segue inalterado.
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(j,k)[i] = values[count];
                        count++;  
                    }
                }
            } 
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){  //a partir de k=1, pk para k=0 o valor segue inalterado.
                    for (int i = 0; i < ch; i++){
                        if(j > 1 && k>1){
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i] + 0.001*out.at<Vec3b>(j-1,k-1)[i];
                        }
                        else{
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i];
                        }
                    }
                }
            }
            imwrite("mod3.ppm", out);
            imshow("Display window", out);
            waitKey(0);
            return ;  
        }   

        void desmod4(){
            Mat out = Mat::zeros(in.cols, in.rows, CV_8UC3);
            vector<short> values = mod4.decode();
            int count = 0;
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){  //a partir de k=1, pk para k=0 o valor segue inalterado.
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(j,k)[i] = values[count];
                        count++;  
                    }
                }
            } 
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){  //a partir de k=1, pk para k=0 o valor segue inalterado.
                    for (int i = 0; i < ch; i++){
                        if(j > 1 && k>1){
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i] + (0.001*out.at<Vec3b>(j,k-1)[i] + 0.001*out.at<Vec3b>(j-1,k)[i] - 0.001*out.at<Vec3b>(j-1,k-1)[i]);
                        }
                        else{
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i];
                        }
                    }
                }
            }
            imwrite("mod4.ppm", out);
            imshow("Display window", out);
            waitKey(0);
            return ;  
        }    

        void desmod5(){
            Mat out = Mat::zeros(in.cols, in.rows, CV_8UC3);
            vector<short> values = mod5.decode();
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){  //a partir de k=1, pk para k=0 o valor segue inalterado.
                    for (int i = 0; i < ch; i++){
                        out.at<Vec3b>(j,k)[i] = values[count];
                        count++;  
                    }
                }
            } 
            for (int j = 0; j < in.rows; j++)
            {
                for (int k = 0; k < in.cols; k++){  //a partir de k=1, pk para k=0 o valor segue inalterado.
                    for (int i = 0; i < ch; i++){
                        if(j > 1 && k>1){
                            in.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i] + (0.001*out.at<Vec3b>(j,k-1)[i] + (0.001*out.at<Vec3b>(j-1,k)[i] - 0.001*out.at<Vec3b>(j-1,k-1)[i])/2);
                        }
                        else{
                            out.at<Vec3b>(j,k)[i] = out.at<Vec3b>(j,k)[i];
                        }
                    }
                }
            }
            imwrite("mod5.ppm", out);
            imshow("Display window", out);
            waitKey(0);
            return ;  
        }                    

        int quantizacao(int bits, int n){
            int niveis = pow(2,bits);                       // numero de intervalos para estes bits
            double int_niveis = abs((max-min)/niveis);      // intervalo entre cada nivel
            int i;
            double dist;
            //std::cout << niveis << "  " << int_niveis << '\n';
            i=0;
            while(i <= niveis){
                dist = n-((i*int_niveis)+min);
                if(dist <= (int_niveis/2) && dist>=0){      //verifica se está a metade do intervalo
                    n = (i*int_niveis)+min;                 //se estiver a metade arredonda sempre para cima 
                    break;
                }
                i++;
            } 
            return n;
        }

        void end(){
            mod0.close();
            mod1.close();
            mod2.close();
            mod3.close();
            mod4.close();
            mod5.close();
        }
    
};

#endif