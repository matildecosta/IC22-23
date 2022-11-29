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
        size_t ind=0;
        double max = 32767,min=-32768; // limitações de uma variável do tipo short
        Golomb  mod0, mod1, mod2, mod3;
        size_t count = 0;

    public:
        Codec4(const SndfileHandle& sfh) {
		counts.resize(sfh.channels());
	    }

        Codec4(int op){
            switch(op)
            {
                case 0:
                    mod0.set(1000,"mod0.bin","w");
                    break;
                case 1:
                    mod1.set(1000,"mod1.bin","w");
                    break;
                case 2:
                    mod2.set(1000,"mod2.bin","w");
                    break;
                case 3:
                    mod3.set(1000,"mod3.bin","w");
                    break;
                default:
                    break;
            }
            
            
            
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

        void mode0(int quant){
            int tmp;
            while(ind < all_samples.size()){
                all_samples[ind] = all_samples[ind];
                if(quant > 0){
                    all_samples[ind] = quantizacao(quant, all_samples[ind]);
                }
                mod0.encode(all_samples[ind]);
                ind++;
                count++;
            }
            //printf("end0\n");
            return ;
        }

        void mode1(int quant){
            //std::vector<short> test;
            int tmp;
            // std::cout << all_samples.size() << endl;
            // while(1);
            while(ind < all_samples.size()){
                if(ind > 0){
                    all_samples[ind] = all_samples[ind]-all_samples[ind-1];
                    if(quant > 0){
                        all_samples[ind] = quantizacao(quant, all_samples[ind]);
                    }
                    mod1.encode(all_samples[ind]);
                    //test.push_back(tmp);
                }
                else{
                    all_samples[ind] = all_samples[ind];
                    if(quant > 0){
                        all_samples[ind] = quantizacao(quant, all_samples[ind]);
                    }
                    mod1.encode(all_samples[ind]);
                    //test.push_back(tmp);
                }
                ind++;
            }
            //printf("end1\n");
            return ;
        }
        void mode2(int quant){
            //std::vector<short> test;
            int tmp;
            while(ind < all_samples.size()){
                if(ind > 1){
                    all_samples[ind] = all_samples[ind]-(2*all_samples[ind-1]-all_samples[ind-2]);
                    if(quant > 0){
                        all_samples[ind] = quantizacao(quant, all_samples[ind]);
                    }
                    mod2.encode(all_samples[ind]);
                    //test.push_back(tmp);
                }
                else if(ind == 0){
                    all_samples[ind] = all_samples[ind];
                    if(quant > 0){
                        all_samples[ind] = quantizacao(quant, all_samples[ind]);
                    }
                    mod2.encode(all_samples[ind]);
                    //test.push_back(tmp);
                }
                else if(ind == 1){
                    all_samples[ind] = all_samples[ind] - 2*all_samples[ind-1];
                    if(quant > 0){
                        all_samples[ind] = quantizacao(quant, all_samples[ind]);
                    }
                    mod2.encode(all_samples[ind]);
                    //test.push_back(tmp);
                }
                ind++;
            }
            //printf("end2\n");
            return ;
        }
        void mode3(int quant){
            //std::vector<short> test;
            int tmp;
            while(ind < all_samples.size()){
                if(ind > 2){
                    all_samples[ind] = all_samples[ind]-(3*all_samples[ind-1]-3*all_samples[ind-2]+all_samples[ind-3]);
                    if(quant > 0){
                        all_samples[ind] = quantizacao(quant, all_samples[ind]);
                    }
                    mod3.encode(all_samples[ind]);
                    //test.push_back(all_samples[ind]-(3*all_samples[ind-1]-3*all_samples[ind-2]+all_samples[ind-3]));
                }
                else if(ind == 0){
                    all_samples[ind] = all_samples[ind];
                    if(quant > 0){
                        all_samples[ind] = quantizacao(quant, all_samples[ind]);
                    }
                    mod3.encode(all_samples[ind]);
                    //test.push_back(tmp);
                }
                else if(ind == 1){
                    all_samples[ind] = all_samples[ind] - 3*all_samples[ind-1];
                    if(quant > 0){
                        all_samples[ind] = quantizacao(quant, all_samples[ind]);
                    }
                    mod3.encode(all_samples[ind]);
                    //test.push_back(tmp);
                }
                else if(ind == 2){
                    all_samples[ind] = all_samples[ind] - (3*all_samples[ind-1] - 3*all_samples[ind-2]);
                    if(quant > 0){
                        all_samples[ind] = quantizacao(quant, all_samples[ind]);
                    }
                    mod3.encode(all_samples[ind]);
                    //test.push_back(tmp);
                }
                ind++; 
            }
            //printf("end3\n");
            return ;
        }

        vector<short> desmod0(){
        	    vector<short> values = mod0.decode();
                return values;
            
        }

        vector<short> desmod1(){
        	    vector<short> values = mod1.decode();
                vector<short> tmp;
                tmp.resize(values.size());
                tmp[0] = values[0];
                for(size_t j = 1; j < values.size(); j++){
                    tmp[j] = values[j] + values[j-1];
                }
                return tmp;
            
        }

        vector<short> desmod2(){
        	    vector<short> values = mod2.decode();
                vector<short> tmp;
                tmp.resize(values.size());
                for(size_t j = 0; j < values.size(); j++){
                    if(j > 1){
                        tmp[j] = values[j]+(2*values[j-1]-values[j-2]);
                    }
                    else if(j == 0){
                        tmp[j] = values[j];
                    }
                    else if(j == 1){
                        tmp[j] = values[j] + 2*values[j-1];
                    }
                }
                return tmp;
            
        }

         vector<short> desmod3(){
        	    vector<short> values = mod3.decode();
                vector<short> tmp;
                tmp.resize(values.size());
                for(size_t j = 0; j < values.size(); j++){
                     if(j > 2){
                        tmp[j] = values[j]+(3*values[j-1]-3*values[j-2]+values[j-3]);
                    }
                    else if(j == 0){
                        tmp[j] = values[j];
                    }
                    else if(j == 1){
                        tmp[j] = values[j] + 3*values[j-1];
                    }
                    else if(j == 2){
                        tmp[j] = values[j] + (3*values[j-1] - 3*values[j-2]);
                    }
                }
                return tmp;
            
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
        }
    
};

#endif