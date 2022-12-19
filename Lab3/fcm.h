#ifndef FCM_H
#define FCM_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <math.h>
#include <string>
#include <numeric>

#define ALPHABETH_SIZE 127
using namespace std;

class fcm
{
private:
    map<string,map<char, int>> table;
    map<string, float> prob;
    fstream myFile;
    int k;
    double alpha;

public:
    fcm(string name, int model, double alph)
    {
        myFile.open(name, ios::in);
        if (!myFile.is_open()){
            cout << "Error opening file" << endl;
            exit(1);
        } else {
            cout << "File opened successfully" << endl;
        }
        k = model;
        alpha = alph;
    }

    void readAlphabet(){
        char c;
        int count = 0;
        map<char, int> m;
        while(!myFile.eof()){
            myFile.get(c);
            if(c != '\n'){
                if(m.find(c) == m.end()){
                    m.insert(make_pair(c,1));
                    count++;
                }
                
            }
        }
        std::cout << count;
    }
    void readFile()
    {
        string k_model;
        char c;
        for (int i = 0; i < k; i++) // Lê os primeiros k chars do ficheiro para começar a comparar
        {
            myFile.get(c);
            if(c == '\n'){  // garantir que não estamos no final da linha
                i--;
            }
            else
            {
                k_model += c;
            }

        }
        map<string,map<char, int>>::iterator itr;
        map<char, int>::iterator ptr;
        while (!myFile.eof()){
            myFile.get(c);

            if(c != '\n'){
                if ((itr=table.find(k_model)) == table.end())
                { // Se não existir a key k_model no map
                    table.insert(make_pair(k_model,map<char, int>()));
                    table[k_model].insert(make_pair(c,1));
                } 
                else if ((ptr=table[k_model].find(c)) == table[k_model].end())
                {
                    table[k_model].insert(make_pair(c,1));
                }
                else{
                    ptr->second ++;
                }
                // atualizar a janela de visualização
                k_model.erase(0,1);     // Apaga o primeiro char da string
                k_model += c;           // Adiciona o novo char ao fim da string
            }            
        }
    }

    void getStats()
    {
        map<string,map<char, int>>::iterator itr;
        map<char, int>::iterator ptr;
        for(itr = table.begin(); itr != table.end(); itr++){
            for(ptr = itr->second.begin(); ptr != itr->second.end(); ptr++){
                 
            }
        }
        return ;
    }

    void getEntropy()
    {
        vector<int> sum_context;
        vector<double> H_context;
        int total;
        map<char, int> sum;
        double Prob_context = 0.0, H_model = 0.0; 
        map<string,map<char, int>>::iterator itr;
        map<char, int>::iterator ptr;
        size_t i = 0;
        double prob;
        for(itr = table.begin(); itr != table.end(); itr++){
            sum_context.push_back(accumulate(std::begin(itr->second), end(itr->second), 0, [] (int value, const std::map<char, int>::value_type& p){ return value + p.second; }));
            //sum_context.push_back(accumulate(itr->second.begin(),itr->second.end(),0,addss));
            H_context.push_back(0);
            for(ptr = itr->second.begin(); ptr != itr->second.end(); ptr++){
                
                prob = (ptr->second + alpha)/(sum_context[i] + (alpha * ALPHABETH_SIZE)); //p_i
                H_context[i] += (-prob)*log2(prob);
            }
            total += sum_context[i];
            i++;
        }

        for(size_t j = 0; j <= i; j++){
            Prob_context = sum_context[j] / double(total); 
            H_model += Prob_context * H_context[j];
        } 
        std::cout << "Entropy: " << H_model << endl;
        return ;
    }


    void closeFile(){
        myFile.close();
        cout << "File closed successfully" << endl;
    }
};

#endif