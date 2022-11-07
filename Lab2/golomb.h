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






        int decode(int n){
            int b = ceil(log2(m));
            int k = pow(2,b) - m;
            int q = n/b;
            int r = n%b;
            int a = r < k ? r : r - k;
            int c = a + (q*m);
            return c;
        }

};

#endif