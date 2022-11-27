#ifndef WAVQUANT_H
#define WAVQUANT_H

#include <iostream>
#include <vector>
#include <map>
#include <sndfile.hh>
#include <math.h>
#include "golomb.h"

class Codec4{
    private:
        std::vector<std::map<short, size_t>> counts;
        std::vector<short> all_samples;
        size_t ind0=0, ind1=0, ind2=0, ind3=0;
        double max = 32767,min=-32768; // limitações de uma variável do tipo short
        Golomb  mod0, mod1, mod2, mod3;

    public:
        Codec4(const SndfileHandle& sfh) {
		counts.resize(sfh.channels());
	    }

        Codec4(){
            mod0.set(1000,"mod0.bin","w");
            mod1.set(1000,"mod1.bin","w");
            mod2.set(1000,"mod2.bin","w");
            mod3.set(1000,"mod3.bin","w");
        }

        void set_read(){
            mod0.set(1000,"mod0.bin","r");
            mod1.set(1000,"mod1.bin","r");
            mod2.set(1000,"mod2.bin","r");
            mod3.set(1000,"mod3.bin","r");
        }

        void readdata(std::vector<short> samples){
            size_t i = 0;
            while(i<samples.size()){
                all_samples.push_back(samples[i]);
                i++;
            }

        }        

        void mode0(){
            //std::vector<short> test;
            int tmp;
            while(ind0 < all_samples.size()){
                tmp = all_samples[ind0];
                mod0.encode(tmp);
                //test.push_back(tmp);
                ind0++;
            }
            printf("end0\n");
            return ;
        }

        void mode1(){
            //std::vector<short> test;
            int tmp;
            // std::cout << all_samples.size() << endl;
            // while(1);
            while(ind1 < all_samples.size()){
                if(ind1 > 0){
                    tmp = all_samples[ind1]-all_samples[ind1-1];
                    mod1.encode(tmp);
                    //test.push_back(tmp);
                }
                else{
                    tmp = all_samples[ind1];
                    mod1.encode(tmp);
                    //test.push_back(tmp);
                }
                ind1++;
            }
            printf("end1\n");
            return ;
        }
        void mode2(){
            //std::vector<short> test;
            int tmp;
            while(ind2 < all_samples.size()){
                if(ind2 > 1){
                    tmp = all_samples[ind2]-(2*all_samples[ind2-1]-all_samples[ind2-2]);
                    mod2.encode(tmp);
                    //test.push_back(tmp);
                }
                else if(ind2 == 0){
                    tmp = all_samples[ind2];
                    mod2.encode(tmp);
                    //test.push_back(tmp);
                }
                else if(ind2 == 1){
                    tmp = all_samples[ind2] - 2*all_samples[ind2-1];
                    mod2.encode(tmp);
                    //test.push_back(tmp);
                }
                ind2++;
            }
            printf("end2\n");
            return ;
        }
        void mode3(){
            //std::vector<short> test;
            int tmp;
            while(ind3 < all_samples.size()){
                if(ind3 > 2){
                    tmp = all_samples[ind3]-(3*all_samples[ind3-1]-3*all_samples[ind3-2]+all_samples[ind3-3]);
                    mod3.encode(tmp);
                    //test.push_back(all_samples[ind3]-(3*all_samples[ind3-1]-3*all_samples[ind3-2]+all_samples[ind3-3]));
                }
                else if(ind3 == 0){
                    tmp = all_samples[ind3];
                    mod3.encode(tmp);
                    //test.push_back(tmp);
                }
                else if(ind3 == 1){
                    tmp = all_samples[ind3] - 3*all_samples[ind3-1];
                    mod3.encode(tmp);
                    //test.push_back(tmp);
                }
                else if(ind3 == 2){
                    tmp = all_samples[ind3] - (3*all_samples[ind3-1] - 3*all_samples[ind3-2]);
                    mod3.encode(tmp);
                    //test.push_back(tmp);
                }
                ind3++; 
            }
            printf("end3\n");
            return ;
        }

        void desmod0(){
            SndfileHandle mod0 { "mod0.wav", SFM_WRITE, sfhIn.format(),
	        sfhIn.channels(), sfhIn.samplerate() };

            
        }

        void end(){
            mod0.close();
            mod1.close();
            mod2.close();
            mod3.close();
        }
    
};

#endif