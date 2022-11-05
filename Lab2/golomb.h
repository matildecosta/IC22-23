#ifndef GOLOMB_H
#define GOLOMB_H

#include <iostream>
#include <math.h>

using namespace std;

class Golomb{
    private:

        int m;

    public:
        Golomb();

        Golomb(int parameter){
            m = parameter;  
        }

        int encode(int n){
            int q = n/m;
            int r = n%m;
            int b = ceil(log2(m));
            int k = pow(2,b) - m;
            int a = r < k ? r : r + k;
            int c = a + (q*b);
            return c;
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