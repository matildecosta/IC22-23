#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main (int argc, char** argv)
{
    // if (argc != 3)
    // {
    //     cout << "Usage: ./copy <inFile_Path> <outFile _Path>" << endl;
    //     return -1;
    // }
    map<string,int> data;
    std::fstream newfile;
    int n = 2;                              //número de caracteres considerados
    std::map<string,int>::iterator itr;
    newfile.open("grandatextotuga.utf8", ios::in);
    if(newfile.is_open()){
        std::string tp;
        while(getline(newfile, tp)){
            for(size_t i = 0; i < tp.size()-2; i++)
            {
                string s;
                s.push_back(char(tp[i]));
                s.push_back(char(tp[i+1]));
                s.push_back(char(tp[i+2]));
                if((itr=data.find(s)) == data.end()){
                    data.insert({s, 1});
                }
                else{
                    itr->second += 1;
                }
                
            }
        }
        newfile.close();
        ofstream MyFile("filename.utf8");
        for(map<string, int>::const_iterator it = data.begin(); it != data.end(); ++it)
        {
            std::cout << it->first << " " << it->second << "\n";
            MyFile << it->first << " " << it->second << "\n";
        }
        MyFile.close();
    } 

    return 0;
}
