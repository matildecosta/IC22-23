#ifndef FCM_H
#define FCM_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <math.h>
#include <string>
#include <numeric>

#define ALPHABETH_SIZE 127
using namespace std;

class FCM
{
private:
    unordered_map<string,unordered_map<char, int>> table;
    int k;
    double alpha;

public:
    FCM(){}
    FCM(int k_value, double alpha_value){
        k = k_value;
        alpha = alpha_value;
    }

    void readAlphabet(string model){
        ifstream myFile(model, ios::in);
        char c;
        int count = 0;
        unordered_map<char, int> m;
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
    void read_model(string model_text)
    {
        table.clear();
        fstream myFile;
        myFile.open(model_text, ios::in);
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
        unordered_map<string,unordered_map<char, int>>::iterator itr;
        unordered_map<char, int>::iterator ptr;
        while (!myFile.eof()){
            myFile.get(c);

            if(c != '\n'){
                if ((itr=table.find(k_model)) == table.end())
                { // Se não existir a key k_model no map
                    table.insert(make_pair(k_model,unordered_map<char, int>()));
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
        myFile.close();
    }

    void getStats()
    {
        unordered_map<string,unordered_map<char, int>>::iterator itr;
        unordered_map<char, int>::iterator ptr;
        for(itr = table.begin(); itr != table.end(); itr++){
            for(ptr = itr->second.begin(); ptr != itr->second.end(); ptr++){
                 
            }
        }
        return ;
    }

    double get_entropy(string anali_text){
        fstream File;
        File.open(anali_text, ios::in);
        string k_model; 
        char c;
        for(int i = 0; i < k; i++)
        {
            File.get(c);
            if(c == '\n'){  // garantir que não estamos no final da linha
                i--;
            }
            else
            {
                k_model += c;
            }
        }
        unordered_map<string, unordered_map<char, int>>::iterator itr;
        unordered_map<char, int>::iterator ptr;
        unordered_map<char, int> m;
        int occur_c, sum_context, total;
        double prob, H = 0.0, total_bits = 0.0;
        while(!File.eof()){
            File.get(c);
            occur_c = 0; sum_context = 0;
            if(c != '\n'){
                if((itr = table.find(k_model)) != table.end()){ //se pertencer ao modelo
                    m = table[k_model];
                    if((ptr = m.begin()) != m.end()){ // se o caracter pertencer ao mapa
                        occur_c = ptr->second;
                    }
                    else{
                        occur_c = 0;
                    }
                    sum_context = (accumulate(m.begin(), m.end(), 0,[](const int prev_sum, const std::pair<char, int> &entry){return prev_sum + entry.second;}));
                }
                else{
                    occur_c = 0;
                    sum_context = 0;
                }
                prob = (occur_c + alpha)/(sum_context + (alpha * ALPHABETH_SIZE));
                total_bits += -log2(prob);
                H +=  (-prob)*log2(prob);
                total += sum_context;
            }
            k_model.erase(0,1);     // Apaga o primeiro char da string
            k_model += c;           // Adiciona o novo char ao fim da string
        }
        //std::cout << "Nr. bits: " << total_bits <<  endl;  
        File.close();    
        return total_bits;
        
    }




    // void closeFile(){
    //     myFile.close();
    //     cout << "File closed successfully" << endl;
    // }
};

#endif