#ifndef WAVCMP_H
#define WAVCMP_H

#include <iostream>
#include <vector>
#include <sndfile.hh>
#include <math.h>

class WavCmp{
    private:
        double max_err = 0.0, e_x = 0.0, e_r = 0.0;
        std::vector<short> signal;
        std::vector<short> signal_r;

    public:
        void energy_sigals(std::vector<short> x, std::vector<short> r){
            int i = 0;
            while(i != x.size()){
                e_x += abs(x[i]^2);      //calculo das energias de cada sinal
                e_r += abs(r[i]^2);
                if(abs(x[i]-r[i])>max_err){
                    max_err = abs(x[i]-r[i]);
                }
                i++;
            }
        }
        double snr(){
            return 10*log10(e_x/e_r);
        }
        double maxerr(){
            return max_err;
        }

    
};

#endif
