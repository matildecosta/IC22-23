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
        std::string mode;
        size_t counter;      

    public:
        BitStream(std::string filename, std::string m){
            myFile.open(filename);
            mode = m;
            counter = 0;
            std::cout << "File opened" << std::endl;
        }

        int read_bit(){ // se buffer está empty: bin -> buffer e devolve sempre a 1ª posição do buffer
            if (mode != "r"){
                std::cerr << "Error: read_bit() called in write mode" << std::endl;
                return EOF;
            }
            if (myFile.eof()){
                return EOF;
                std::cout << "end of file" << std::endl;
            } else {
                if (counter == 0){
                    char c;
                    myFile.read(&c, 8);
                    bit_buffer = c-0x30;
                    counter = 8;
                }   
                    std::cout << "buffer filled" << std::endl;
                }
                int bit = (bit_buffer & 0x01);
                bit_buffer = bit_buffer >> 1;
                counter--;
                return bit;
        }

        void write_bit(int bit){ // se buffer está full: buffer -> bin e escreve no buffer
            if (mode != "w"){
                std::cerr << "Error: write_bit() called in read mode" << std::endl;
                return;
            }
            bit_buffer <<= 1;
            bit_buffer |= bit;
            counter++;
            if (counter == 8){
                char c = bit_buffer + 0x30;
                myFile.write(&c, 8);
                bit_buffer = 0;
                counter = 0;
                std::cout << "buffer emptied" << std::endl;
            }
        }

        void close(){
            if (mode == "w"){
                if (counter != 0){
                    myFile.write(&bit_buffer, 1);
                }
            }
            myFile.close();
            std::cout << "File closed" << std::endl;
        }
};

#endif