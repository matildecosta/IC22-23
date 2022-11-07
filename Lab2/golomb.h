#ifndef GOLOMB_H
#define GOLOMB_H

#include <iostream>
#include <math.h>
#include "BitStream.h"

using namespace std;

class Golomb{
    private:

        int m;
        int base;
        BitStream bs;
        std::string mode;

    public:
        Golomb();

        Golomb(int parameter, std::string file, std::string md){
            m = parameter;
            mode = md;
            bs.nameFile(file);
            base = (int)ceil(log2(m));
        }

        void encode(int n){
            int q = n/m;    // Divisão inteira
            int r = n%m;    // Resto da divisão

            for(int i=0; i<q; i++){ // códifo unário do quociente
                bs.write_bit(1);
            }
            bs.write_bit(0);
            
            for(int i=base-1; i>=0; i--){ // código binário do resto
                bs.write_bit((r>>i)& 0x01);
            }
        }

        int decode(){
            int q = 0;
            int r = 0;
            int bit = 0;

            while(bit != 0){    // leitura do quociente
                bit = bs.read_bit();
                q++;
            }
            q--;    // porque ele ainda dá o incremento ao ler o zero do stop

            for(int i=base-1; i>=0; i--){ // leitura do resto
                bit = bs.read_bit();
                r += bit<<i;
            }

            return q*m + r;
        }
};

#endif