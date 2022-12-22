#ifndef FCM_H
#define FCM_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <math.h>
#include <string>
#include <numeric>
#include <utility>

#define ALPHABETH_SIZE 127
using namespace std;

class FCM
{
private:
    unordered_map<string,unordered_map<char, int>> table;
    vector<unordered_map<string,unordered_map<char, int>>> models; //vector de mapas
    int k;
    unordered_map<int, string> languages;
    double alpha;
    int count_mods;
    fstream Fileseg;

public:
    FCM(){}
    FCM(int k_value, double alpha_value){
        k = k_value;
        alpha = alpha_value;
        count_mods = 0;
    }

    void openFile(string anali_text){
        Fileseg.open(anali_text, ios::in);
        // for(int j=0; j < count_mods; j++){
        //     std::cout << languages[j] << endl;
        // }
    }

    void closeFile(){
        Fileseg.close();
        //cout << "File closed successfully" << endl;
    }

    void readmodels(string mod){
        fstream myFile;
        myFile.open(mod, ios::in);
        mod.erase(mod.length()-5);
        mod.erase(0,7);
        languages.insert(make_pair(count_mods,mod));
        string k_model;
        char c;
        unordered_map<string,unordered_map<char, int>> prov_table;
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
                if ((itr=prov_table.find(k_model)) == prov_table.end())
                { // Se não existir a key k_model no map
                    prov_table.insert(make_pair(k_model,unordered_map<char, int>()));
                    prov_table[k_model].insert(make_pair(c,1));
                } 
                else if ((ptr=prov_table[k_model].find(c)) == prov_table[k_model].end())
                {
                    prov_table[k_model].insert(make_pair(c,1));
                }
                else{
                    ptr->second ++;
                }
                // atualizar a janela de visualização
                k_model.erase(0,1);     // Apaga o primeiro char da string
                k_model += c;           // Adiciona o novo char ao fim da string
            }            
        }
        models.push_back(prov_table);
        count_mods++;
        myFile.close();
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

        bool get_entropy_line2line(){
        //O ficheiro é aberto previamente para esta finção poder ser chamada diversas vezes
        string k_model; 
        char c;
        for(int i = 0; i < k; i++)
        {
            Fileseg.get(c);
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
        double prob, min;
        vector<double> total_bits, H;
        pair<int,int> tmp_indc;
        total_bits.resize(count_mods,0); H.resize(count_mods,0);
        while(!Fileseg.eof()){
            total_bits.resize(count_mods,0); H.resize(count_mods,0); 
            Fileseg.get(c);
            if(c != '.'){ //final de uma frase
            //correr todos os modelos
                for(int cm = 0; cm < count_mods; cm++){
                    occur_c = 0; sum_context = 0;
                    if(c != '\n'){
                        if((itr = models[cm].find(k_model)) != models[cm].end()){ //se pertencer ao modelo
                            m = models[cm][k_model];
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
                        total_bits[cm] += -log2(prob);
                        H[cm] +=  (-prob)*log2(prob);
                        total += sum_context;
                    }
                }
                k_model.erase(0,1);     // Apaga o primeiro char da string
                k_model += c;           // Adiciona o novo char ao fim da string
            }
            else{
                min = total_bits[0];
                int tmp = 0;
                for(int cm = 1; cm < count_mods; cm++){
                    if(min > total_bits[cm]){
                        tmp = cm;
                        min = total_bits[cm];
                    }
                }
                std::cout << "O segmento está em " << languages[tmp] << endl;
                return 1;

                //std::cout << "Nr. bits: " << total_bits <<  endl;   
                //return 1;  //final de uma frase
            }
        }
        return 0;  
        }
};

#endif