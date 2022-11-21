#ifndef WAVQUANT_H
#define WAVQUANT_H

#include <iostream>
#include <vector>
#include <map>
#include <sndfile.hh>
#include <math.h>

class Codec4{
    private:
        std::vector<std::map<short, size_t>> counts;
        std::vector<short> all_samples;
        size_t ind0=0, ind1=0, ind2=0, ind3=0;
        double max = 32767,min=-32768; // limitações de uma variável do tipo short

    public:
        Codec4(const SndfileHandle& sfh) {
		counts.resize(sfh.channels());
	    }

        Codec4(){
        }

        void readdata(std::vector<short> samples){
            size_t i = 0;
            while(i<samples.size()){
                all_samples.push_back(samples[i]);
                i++;
            }

        }        

        auto mode0(){
            std::vector<short> test;
            int tmp;
            while(ind0 < all_samples.size()){
                tmp = all_samples[ind0];
                tmp = //valor codificado por golomb
                test.push_back(tmp);
                ind0++;
            }
            return test;
        }

        auto mode1(){
            std::vector<short> test;
            int tmp;
            while(ind1 < all_samples.size()){
                if(ind1 > 0){
                    tmp = all_samples[ind1]-all_samples[ind1-1];
                    tmp = //valor codificado por golomb
                    test.push_back(tmp);
                }
                else{
                    tmp = all_samples[ind1];
                    tmp = //valor codificado por golomb
                    test.push_back(tmp);
                }
                ind1++;
            }
            return test;
        }
        auto mode2(){
            std::vector<short> test;
            int tmp;
            while(ind2 < all_samples.size()){
                if(ind2 > 1){
                    tmp = all_samples[ind2]-(2*all_samples[ind2-1]-all_samples[ind2-2]);
                    tmp = //valor codificado por golomb
                    test.push_back(tmp);
                }
                else if(ind2 == 0){
                    tmp = all_samples[ind2];
                    tmp = //valor codificado por golomb
                    test.push_back(tmp);
                }
                else if(ind2 == 1){
                    tmp = all_samples[ind2] - 2*all_samples[ind2-1];
                    tmp = //valor codificado por golomb
                    test.push_back(tmp);
                }
                ind2++;
            }
            return test;
        }
        auto mode3(){
            std::vector<short> test;
            int tmp;
            while(ind3 < all_samples.size()){
                if(ind3 > 2){
                    tmp = all_samples[ind3]-(3*all_samples[ind3-1]-3*all_samples[ind3-2]+all_samples[ind3-3]);
                    tmp = //valor codificado por golomb
                    test.push_back(all_samples[ind3]-(3*all_samples[ind3-1]-3*all_samples[ind3-2]+all_samples[ind3-3]));
                }
                else if(ind3 == 0){
                    tmp = all_samples[ind3];
                    tmp = //valor codificado por golomb
                    test.push_back(tmp);
                }
                else if(ind3 == 1){
                    tmp = all_samples[ind3] - 3*all_samples[ind3-1];
                    tmp = //valor codificado por golomb
                    test.push_back(tmp);
                }
                else if(ind3 == 2){
                    tmp = all_samples[ind3] - (3*all_samples[ind3-1] - 3*all_samples[ind3-2]);
                    tmp = //valor codificado por golomb
                    test.push_back(tmp);
                }
                ind3++;
            }
            return test;
        }
    
};

#endif