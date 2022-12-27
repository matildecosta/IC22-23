#ifndef FCM_H
#define FCM_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <math.h>
#include <string>
#include <numeric>
#include <ctype.h>
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
    int count_mods, diff_lang;
    fstream Fileseg;
    pair<int,int> beg_point, end_point;

public:
    FCM(){}
    FCM(int k_value, double alpha_value){
        k = k_value;
        alpha = alpha_value;
        count_mods = 0; diff_lang = -1;
        beg_point = {0,0};
        end_point = {0,0};
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

    void readAlphabet(string model){   //conta o número de caracteres diferentes no modelo
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

    void getStats() //usado para imprimir o modelo
    {
        unordered_map<string,unordered_map<char, int>>::iterator itr;
        unordered_map<char, int>::iterator ptr;
        for(itr = table.begin(); itr != table.end(); itr++){
            for(ptr = itr->second.begin(); ptr != itr->second.end(); ptr++){
                 
            }
        }
        return ;
    }


    void getEntropy_model()
    {
        vector<int> sum_context;
        vector<double> H_context;
        int total;
        unordered_map<char, int> sum;
        double Prob_context = 0.0, H_model = 0.0; 
        unordered_map<string, unordered_map<char, int>>::iterator itr;
        unordered_map<char, int>::iterator ptr;
        size_t i = 0;
        double prob;
        for(itr = table.begin(); itr != table.end(); itr++){
            sum_context.push_back(accumulate(std::begin(itr->second), end(itr->second), 0, [] (int value, const std::unordered_map<char, int>::value_type& p){ return value + p.second; }));
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
        bool next_one = false;
        for(int i = 0; i < k; i++)
        {
            if(Fileseg.eof()){return 0;}
            Fileseg.get(c);
            if(next_one){
                next_one = false;
            }else{
                if(((c & 0x80) == 0x80)){
                    end_point.second--;
                    next_one=true;
                }    
            }
            if(c == '\n'){  // garantir que não estamos no final da linha
                end_point.first++;
                end_point.second=0;
                if(i == 0){
                    beg_point.first++;
                    beg_point.second = 0;
                }
                i--;
            }
            else
            {
                end_point.second++;
                k_model += c;
            }
        }
        // printf("(%d,%d)\n", end_point.first, end_point.second);
        unordered_map<string, unordered_map<char, int>>::iterator itr;
        unordered_map<char, int>::iterator ptr;
        unordered_map<char, int> m;
        int occur_c, sum_context, total;
        double prob, min;
        vector<double> total_bits, H;
        pair<int,int> tmp_indc;
        
        total_bits.resize(count_mods,0); H.resize(count_mods,0);
        while(!Fileseg.eof())
        {
            total_bits.resize(count_mods,0); H.resize(count_mods,0); 
            Fileseg.get(c);
            if(next_one){
                next_one = false;
            }else{
                if(((c & 0x80) == 0x80)){
                    end_point.second--;
                    next_one=true;
                }    
            }
            end_point.second++;
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
                    else{
                        if(cm == 0){
                            end_point.first++;
                            end_point.second = 0;
                        }
                    }
                }
                //printf("(%d,%d)\n", end_point.first, end_point.second);
                k_model.erase(0,1);     // Apaga o primeiro char da string
                k_model += c;           // Adiciona o novo char ao fim da string
            }
            else{  //Quando acabar uma frase
                min = total_bits[0];
                int tmp = 0;
                for(int cm = 1; cm < count_mods; cm++){
                    if(min > total_bits[cm]){
                        tmp = cm;
                        min = total_bits[cm];
                    }
                }
                if(diff_lang != tmp){
                    printf("O segmento que começa em (%d,%d) está em ", beg_point.first, beg_point.second);
                    cout << languages[tmp] << endl;
                    //std::cout << "O segmento está em " << languages[tmp] << endl;
                    diff_lang = tmp;
                    beg_point.first = end_point.first; beg_point.second = end_point.second;
                }
                return 1;
            }
        }
        return 0;  
        }
};

#endif