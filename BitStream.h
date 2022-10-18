#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class BitStream {
    private:
        char bit_buffer;
        std::fstream myFile;    // ficheiro binario
        char mode;
        size_t counter;
        

    public:

        BitStream(string filename, char m){
            myFile(filename);
            mode = m;
            counter = 0;
        }

        int read_bit(){ // se buffer está empty: bin -> buffer e devolve sempre a 1ª posição do buffer
            if (counter == 0){        // buffer empty -> ler bin
                bit_buffer = getc(myFile);
                counter = 8;
            }
            int first = (bit_buffer & 0x10) >> 7;  //  devolver o bit mais à esquerda
            bit_buffer = bit_buffer << 1;   // deslocar todos os bits para a esquerda
            counter --; // diminui o valor do counter
            return first;
        }

        void write_bit(int b){  // val parâmetros -> buffer e se buffer está full: buffer -> bin;   b é sempre z ou 1
            but_buffer = (bit_buffer | (b << (7 - counter)));
            counter ++;

            if(counter == 8){      // buffer full --> escrever no bin
                myfile.write(bit_buffer);   // escreve no ficheiro
                bit_buffer = bit_buffer & 0x00;  // limpar o buffer
                counter = 0;    // zero elementos no buffer
            }
        }

        void close (){
        
        }

/*         std::istream &operator>>(std::istream &is, BitStream bs){
            is >> bs.bit_buffer;
        }

        std::ostream &operator<<(std::ostream &os, BitStream bs){
            os << (bs.bit_buffer).front();
        } */


}

#endif