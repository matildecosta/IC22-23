#ifndef FCM_H
#define FCM_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

class fcm
{
private:
    std::map<pair<string,char>,float> table;
    fstream myFile;
    int k;

public:
    fcm(string name, int model){
        myFile.open(name, ios::in);
        if (!myFile.is_open()){
            cout << "Error opening file" << endl;
            exit(1);
        } else {
            cout << "File opened successfully" << endl;
        }
        k = model;
    }

    void readFile(){
        string k_model;
        char c;
        for (int i = 0; i < k; i++) // Lê os primeiros k chars do ficheiro para começar a comparar
        {
            myFile.get(c);
            k_model += c;
        }
        while (!myFile.eof()){
            myFile.get(c);
            if(c != '\n'){
                if (table.find(make_pair(k_model, c)) == table.end())
                { // Se não existir a key k_model no map
                    table.insert(make_pair(make_pair(k_model,c),1));
                } 
                else 
                {
                    table[make_pair(k_model, c)] += 1;
                }
                // comparar com os ultimos k valores
                // adicionar ao mapa
                k_model.erase(0,1);
                k_model += c;
            }
            //table.insert(make_pair(k_model,make_pair(make_pair(c,1),1.0)));
            
        }
    }

    void getStats(){
        for(map< pair<string,char>, float>::const_iterator it = table.begin();
            it != table.end(); ++it)
        {
            std::cout << it->first.first << " " << it->first.second << " " << it->second << "\n";
        }
        return ;
    }

    void closeFile(){
        myFile.close();
        cout << "File closed successfully" << endl;
    }

};

#endif