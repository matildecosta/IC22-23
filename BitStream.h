#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class BitStream {
    private:
        char bit_buffer;
        std::fstream myFile;    // ficheiro .bin
        std::string mode;       // w ou r
        size_t counter;         // número de bits no buffer

    public:

        BitStream(std::string filename, std::string m){
            mode = m;
            if (mode == "r"){
                myFile.open(filename, std::ios::in | std::ios::binary);
            }
            else if (mode == "w"){
                myFile.open(filename, std::ios::out | std::ios::binary);
            }
            if (!myFile.is_open()){
                std::cerr << "Error opening file " << filename << std::endl;
                exit(1);
            }
            counter = 0;
            bit_buffer = 0;
            std::cout << "Bin file opened" << std::endl;
        }

        int read_bit(){ // se buffer está empty: bin -> buffer e devolve sempre a 1ª posição do buffer
            if (mode != "r"){
                std::cerr << "Error: read_bit() called in write mode" << std::endl;
                return EOF;
            }
            if (myFile.eof()){
                std::cout << "end of file" << std::endl;
                return EOF;
            } else {
                if (counter == 0){
                    myFile.read(&bit_buffer, 1);
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
            if (counter != 0){
                bit_buffer <<= 1;
            }
            bit_buffer |= bit;
            counter++;
            if (counter == 8){
                myFile.write(&bit_buffer, 1);
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