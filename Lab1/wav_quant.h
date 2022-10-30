#ifndef WAVQUANT_H
#define WAVQUANT_H

#include <iostream>
#include <vector>
#include <map>
#include <sndfile.hh>
#include <math.h>

class WavQuant{
    private:
        std::vector<std::map<short, size_t>> counts;
        double max = 32767,min=-32768; // limitações de uma variável do tipo short

    public:
        WavQuant(const SndfileHandle& sfh) {
		counts.resize(sfh.channels());
	    }
        auto quantizacao(int bits, std::vector<short>& samples){
            int niveis = pow(2,bits);                       // numero de intervalos para estes bits
            double int_niveis = abs((max-min)/niveis);      // intervalo entre cada nivel
            int i;
            double dist;
            std::cout << niveis << "  " << int_niveis << '\n';
            for(size_t j=0;j<samples.size();j++){
                i=0;
                while(i <= niveis){
                    dist = samples[j]-((i*int_niveis)+min);
                    if(dist <= (int_niveis/2) && dist>=0){    //verifica se está a metade do intervalo
                        samples[j] = (i*int_niveis)+min;      //se estiver a metade arredonda sempre para cima 
                        break;
                    }
                    i++;
                    
                } 
            }
            return samples.data();
        }

    
};

#endif
