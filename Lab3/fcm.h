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
    map<string,vector<char,int>,float> table;
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
            if (table.find(k_model) == table.end()){ // Se não existir a key k_model no map
                vector<char,int> v;
                v.push_back(c);
                table.insert(pair<string,vector<char,int>>(k_model,v)); // ??
            } else {
                table[k_model].push_back(c);
            }
            // comparar com os ultimos k valores
            // adicionar ao mapa
            k_model.erase(0,1);
            k_model += c;
    }
    }

    auto getStats(){
        return table;
    }

    void closeFile(){
        myFile.close();
        cout << "File closed successfully" << endl;
    }

};

#endif