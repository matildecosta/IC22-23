#ifndef GOLOMB_H
#define GOLOMB_H

#include <iostream>
#include <math.h>
#include <vector>
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
            //bs.set_mode(md);
            bs.nameFile(file,md);
            base = (int)ceil(log2(m));      // só é importante caso m não seja potência de 2
        }

        void encode(int n){
            int q = abs(floor(n/m));    // Divisão inteira
            int r = abs(n%m);    // Resto da divisão
            std::cout << "base = " << base << endl;
            std::cout << "q = " << q << endl;
            std::cout << "r = " << r << endl;
            std::cout << "n: " << n <<endl;
            int i;
            if(n<0){
                bs.write_bit(0);
            }
            for(i=0; i<q; i++){ // códifo unário do quociente
                bs.write_bit(1);
            }
            bs.write_bit(0);
            for(int j=i+1; j<=i+base; j++){ // código binário do resto
                bs.write_bit((r>>(base+i-j))& 0x01);
                //bs.write_bit(0x01);
            }
            bs.close();
        }

        int decode(){
            int q = 0;
            int r = 0;
            bool flag = false;
            vector<int> inf;
            size_t i = 0;
            int bit = 0;
            while ((bit = bs.read_bit()) != EOF){
                inf.push_back(bit);
                //cout << bit << endl;
                i++;
            }
            //std::cout << "i = " << i;
            //std::cout << inf[0];
            if(inf[0] == 0)  //numero negativo
            {
                i=1;
                flag = true;
            }
            else{i=0;}
            while(inf[i] != 0){    // leitura do quociente
                 //std::cout << inf[i];
                 q++;
                 i++;
            }
            i++;
            for(int j = i; j<(i+base); j++){ // leitura do resto
                r += inf[j]<<((i+base-1)-j);
                //std::cout << inf[i];
            }
            std::cout << "q = " << q << endl;
            std::cout << "r = " << r << endl;
            if(flag){
                std::cout << "Inteiro descodificado: " << -(q*m + r) <<endl;
            }
            else{
                std::cout << "Inteiro descodificado: " << q*m + r <<endl;
            }
            return 0;
            //return q*m + r;
        }
};

#endif