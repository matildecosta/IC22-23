#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class BitStream {
    private:
        std::vector<bool> bit_buffer;
        std::fstream myFileTxt;
        std::fstream myFileBin;
        

    public:

        BitStream(string filenametxt, string filenamebin ){
            myFileTxt.open(filenametxt);
            myFileBin.open(filenamebin);
        }

        void get_bit(){ // 1 bit Txt -> Bin
            if bit_buffer.empty(){  // Leitura de 1 byte
                for(int i = 0;i<8;i++){
                    static string str;
                    getline(myFile, str);
                    bit_buffer.insert(7-i, str-0x30);}
            }
            
                        
        }


        void close (){
            if !bit_buffer.empty(){
                myFile << bit_buffer;}
            
            myFile.close();
        }

        std::istream &operator>>(std::istream &is, BitStream bs){
            is >> bs.bit_buffer;
        }

        std::ostream &operator<<(std::ostream &os, BitStream bs){
            os << (bs.bit_buffer).front();
            (bs.bit_buffer).erase(cbegin());
        }


}

#endif