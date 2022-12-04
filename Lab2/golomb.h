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
        int base, x;
        BitStream bs;
        std::string mode;

    public:
        Golomb(){
        }

        Golomb(int parameter, std::string file, std::string md){
            m = parameter;
            mode = md;
            //bs.set_mode(md);
            bs.nameFile(file,mode);
            base = ceil(log2(m));      // só é importante caso m não seja potência de 2
            x = pow(2,base)-m;
        }

        void set(int parameter, std::string file, std::string md){
            m = parameter;
            mode = md;
            //bs.set_mode(md);
            bs.nameFile(file,mode);
            base = ceil(log2(m));      // só é importante caso m não seja potência de 2
            x = pow(2,base)-m;
        }

        void encode(int n){
            int q = abs(floor(n/m));    // Divisão inteira
            int r = abs(n%m);    // Resto da divisão
            // std::cout << "m = " << m << endl;
            // std::cout << "b = " << base << endl;
            // std::cout << "q = " << q << endl;
            // std::cout << "r = " << r << endl;
            // std::cout << "n =  " << n <<endl;
            // std::cout << "x = " << x << endl;
            int i;
            if(n<0){
                bs.write_bit(1); //se for negativo
            }
            else{
                bs.write_bit(0);  //se for positivo
            }
            for(i=0; i<q; i++){ // códifo unário do quociente
                bs.write_bit(1);
            }
            bs.write_bit(0);
            // std::cout << "i = " << i << endl;
            if(r<(pow(2,base+1)-m)){ //representação normal b bits
                for(int j=i; j<i+base; j++){ // código binário do resto
                    bs.write_bit(((r)>>((base+i-1)-j))& 0x01);
                    //bs.write_bit(0x01);
                }
            }
            else{ // b+1 bits 
                for(int j=i; j<i+base; j++){ // código binário do resto
                    bs.write_bit(((r+x)>>((base+i-1)-j))& 0x01);
                }
            }
        }

        int decode1(){
            //std::cout << "x = " << x << endl;
            int q = 0;
            int r = 0;

            bool flag = false,qzero = false;
            vector<int> inf;
            int i = 0;
            int bit = 0;
            
            while ((bit = bs.read_bit()) != EOF){
                inf.push_back(bit);
                //cout << bit << endl;
                i++;
            }
            // std::cout << "i = " << i << endl;
            if(inf[0] == 1) flag = true;
            if(inf[1] == 0) qzero = true;;
            i =1;
            while((inf[i] != 0) && (qzero != true)){    // leitura do quociente
                 //std::cout << inf[i];
                 q++;
                 i++;
            }
            i++;
            // std::cout << "i = " << i << endl;
            // std::cout << "base = " << base << endl;
            for(int j = i; j<(i+base); j++){ // leitura do resto
                r += inf[j]<<((i+base-1)-j);
            }
            if(r < (pow(2,base+1)-m)){ //b bits de representaçao
                //mantem-se
            }
            else{ // (b+1)bits de representaçao
                r = r - pow(2,base+1)+m;
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
        auto decode(){
            //std::cout << "x = " << x << endl;
            int q = 0;
            int r = 0;

            bool flag = false, isq = true, first = true;
            int bit = 0;
            int j = 0;
            vector<short> values;

            while ((bit = bs.read_bit()) != EOF){
                if(isq){
                    if(first){
                        if(bit == 1) {flag = true;}
                        first = false;
                    }
                    else if(bit != 0){
                        q++;
                    }
                    else{
                        isq = false;
                    }
                }
                else{
                    // std::cout << "base = " << base << endl;
                    if(j < base){
                        r += bit << ((base-1-j));
                        j++;
                    }
                    if(j == base){
                        if(r < (pow(2,base+1)-m)){ //b bits de representaçao
                            //mantem-se
                        }
                        else{ // (b+1)bits de representaçao
                            r = r - pow(2,base+1)+m;
                        }
                        //std::cout << "q = " << q << endl;
                        //std::cout << "r = " << r << endl;
                        if(flag){
                            values.push_back(-(q*m + r));
                            //std::cout << "Inteiro descodificado: " << -(q*m + r) <<endl;
                        }
                        else{
                            values.push_back((q*m + r));
                            //std::cout << "Inteiro descodificado: " << q*m + r <<endl;
                        }
                        isq = true; first = true; flag = false;
                        r = 0; q = 0; j = 0;
                    }
                }
            }
            
            return values;
            //return q*m + r;
        }
        bool IsPowerOfTwo(ulong x)
        {
            return (x & (x - 1)) == 0;
        }

        void close(){
            bs.close();
        }
};

#endif