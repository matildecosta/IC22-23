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
    vector<unordered_map<string,unordered_map<char, int>>> models;  // Vector de mapas
    int k;                                                          // Ordem do modelo
    unordered_map<int, string> languages;                           // Mapa para guardar todas as linguagens dos modelos
    double alpha;                                                   // Smoothing parameter
    int count_mods, diff_lang;                                      // Contagem dos diferentes modos e variavel para verificar mudança de linguagem entre frases
    fstream Fileseg;                                                // Ficheiro para análise
    pair<int,int> beg_point, end_point;                             // Variáveis para verificar o começo e final de cada frase

public:
    FCM(){}
    FCM(int k_value, double alpha_value){   // Construtor 
        k = k_value;
        alpha = alpha_value;
        count_mods = 0; diff_lang = -1;
        beg_point = {0,0};
        end_point = {0,0};
    }

    void openFile(string anali_text){// abertura do ficheiro para análise
        Fileseg.open(anali_text, ios::in);
    }

    void closeFile(){// fecho do ficheiro de análise
        Fileseg.close();
    }

    void readmodels(string mod){// leitura de diferentes modelos 
        fstream myFile;
        myFile.open(mod, ios::in);
        mod.erase(mod.length()-5);
        mod.erase(0,7);
        languages.insert(make_pair(count_mods,mod));                                    // Guarda a linguagem 
        string k_model;                                                                 // String que guarda um número de caracteres dependo da ordem do modelo
        char c;                                                                         
        unordered_map<string,unordered_map<char, int>> prov_table;                      // Variavel que guarda os valores de modelo de forma provisória
        for (int i = 0; i < k; i++)                                                     // Lê os primeiros k chars do ficheiro para começar a comparar
        {
            myFile.get(c);
            if(c == '\n'){                                                              // Garantir que não estamos no final da linha
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
                if ((itr=prov_table.find(k_model)) == prov_table.end())                     // Verificar se o contexto já está presente no mapa
                { 
                    prov_table.insert(make_pair(k_model,unordered_map<char, int>()));       // Insere um novo par
                    prov_table[k_model].insert(make_pair(c,1));
                } 
                else if ((ptr=prov_table[k_model].find(c)) == prov_table[k_model].end())    // Verifica se o caracter já existe dentro de um contexto
                {
                    prov_table[k_model].insert(make_pair(c,1));
                }
                else{
                    ptr->second ++;                                                         // Aumenta a contagem de ocorrências da combinação atual
                }
                // atualizar a janela de visualização
                k_model.erase(0,1);                                                         // Apaga o primeiro char da string
                k_model += c;                                                               // Adiciona o novo char ao fim da string
            }            
        }
        models.push_back(prov_table);                                                       // Adiciona este modelo à variável da classe
        count_mods++;                                                                       // Incrementa a contagem dos modelos 
        myFile.close();                                                                     // O ficheiro do modelo é fechado
    }

    void readAlphabet(string model){    //conta o número de caracteres diferentes no modelo
        ifstream myFile(model, ios::in);
        char c;
        int count = 0;                                                                      // Contagem dos diferentes caracteres
        unordered_map<char, int> m;                                                         // Mapa que  guarda todos os caracteres e número  de ocorrências
        while(!myFile.eof()){                                                               // Ficheiro lido char a char
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
    void read_model(string model_text)  // Leitura de um modelo
    {
        table.clear();                                                                      // É feito o reset do modelo, porque já podia ter sido usado um anteriormente
        fstream myFile;
        myFile.open(model_text, ios::in);                                                   // Abertura do ficheiro do modelo
        string k_model;                                                                     // String que guarda um número de caracteres dependo da ordem do modelo
        char c;
        for (int i = 0; i < k; i++)                                                         // Lê os primeiros k chars do ficheiro para começar a comparar
        {
            myFile.get(c);
            if(c == '\n'){                                                                  // Garantir que não estamos no final da linha
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
                if ((itr=table.find(k_model)) == table.end())                               // Verificar se o contexto já está presente no mapa
                { 
                    table.insert(make_pair(k_model,unordered_map<char, int>()));            // Insere um novo par
                    table[k_model].insert(make_pair(c,1));
                } 
                else if ((ptr=table[k_model].find(c)) == table[k_model].end())              // Verifica se o caracter já existe dentro de um contexto
                {
                    table[k_model].insert(make_pair(c,1));
                }
                else{
                    ptr->second ++;                                                         // Aumenta a contagem de ocorrências da combinação atual
                }
                // atualizar a janela de visualização
                k_model.erase(0,1);                                                         // Apaga o primeiro char da string
                k_model += c;                                                               // Adiciona o novo char ao fim da string
            }            
        }
        myFile.close(); // Fecho do ficheiro do modelo
    }

    void getEntropy_model()  // Retorna a entropia do modelo
    {
        vector<int> sum_context;                                                            // Número de chars em cada contexto
        vector<double> H_context;                                                           // Entropia de cada contexto
        int total;                                                                          // Soma do total dos sum_context
        unordered_map<char, int> sum;
        double Prob_context = 0.0, H_model = 0.0;                                           // Prob_context -> probabilidade do contexto aparecer;
                                                                                            // H_model -> Entropia do modelo
        unordered_map<string, unordered_map<char, int>>::iterator itr;
        unordered_map<char, int>::iterator ptr;
        size_t i = 0;
        double prob;                                                                        // Guarda a probabilidade de ocorrer aquela "sequência" específica tendo em conta determinado modelo;
        for(itr = table.begin(); itr != table.end(); itr++){                                // Vai percorrer todos os contextos
            sum_context.push_back(accumulate(std::begin(itr->second), end(itr->second), 0, [] (int value, const std::unordered_map<char, int>::value_type& p){ return value + p.second; })); // Soma de todas as ocorrências de diferentes caracteres dentro do contexto
            H_context.push_back(0);                                                         // Inicializa a entropia deste contexto com 0
            for(ptr = itr->second.begin(); ptr != itr->second.end(); ptr++){                // Dentro de cada contexto percorre todos os caracteres possíveis

                prob = (ptr->second + alpha)/(sum_context[i] + (alpha * ALPHABETH_SIZE));   // Probabilidade desta "combinação"
                H_context[i] += (-prob)*log2(prob);                                         // Entropia desta "combinação"
            }
            total += sum_context[i];   
            i++;
        }

        for(size_t j = 0; j <= i; j++){ // Vai percorrer todos os contextos calculando a entropia total por fim
            Prob_context = sum_context[j] / double(total); 
            H_model += Prob_context * H_context[j];
        } 
        std::cout << "Entropy: " << H_model << endl;
        return ;
    }

    double get_entropy(string anali_text){
        fstream File;
        File.open(anali_text, ios::in);                                                     // Abertura do ficheiro a ser analisado
        string k_model;                                                                     // String que guarda um número de caracteres dependo da ordem do modelo
        char c;                                                                             // Variável para leitura do ficheiro char a char
        for(int i = 0; i < k; i++)
        {
            File.get(c);
            if(c == '\n'){                                                                  // Garantir que não estamos no final da linha
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
        int occur_c, sum_context;                                                           // occur_c -> número de ocorrências de um caracter específico dentro de um certo contexto; 
                                                                                            // sum_context -> total de caracteres dentro de um contexto
        double prob, total_bits = 0.0;                                                      // prob -> guarda a probabilidade de ocorrer aquela "sequência" específica tendo em conta determinado modelo;
                                                                                            // total_bits -> total de bits que seriam necessários para representar este texto com determinado modelo
        while(!File.eof()){
            File.get(c);
            occur_c = 0; sum_context = 0;                                                   // Reset nas variáveis
            if(c != '\n'){
                if((itr = table.find(k_model)) != table.end()){                             // Verificar se o contexto está presente no modelo
                    m = table[k_model];
                    if((ptr = m.begin()) != m.end()){                                       // Verifica se o caracter existe dentro do contexto
                        occur_c = ptr->second;                                              // Número de ocorrências desse caracter
                    }
                    else{
                        occur_c = 0;                                                        // Caso não pertence ao contexto
                    }
                    sum_context = (accumulate(m.begin(), m.end(), 0,[](const int prev_sum, const std::pair<char, int> &entry){return prev_sum + entry.second;})); // Total de caracteres no contexto
                }
                else{                                                                       // Caso o contexto não exista no modelo
                    occur_c = 0;
                    sum_context = 0;
                }
                prob = (occur_c + alpha)/(sum_context + (alpha * ALPHABETH_SIZE));
                total_bits += -log2(prob);                                                  // Total de bits dado pela soma do número de bits necessários para cada "combinação"
            }
            k_model.erase(0,1);                                                             // Apaga o primeiro char da string
            k_model += c;                                                                   // Adiciona o novo char ao fim da string
        }
        File.close();                                                                       // Fecho do ficheiro para análise
        return total_bits;
        
    }

        bool get_entropy_line2line(){  // É realizada a verificação da linguagem linha a linha até ao final do ficheiro
        // O ficheiro é aberto previamente para esta finção poder ser chamada diversas vezes
        string k_model;                                                                     // String que guarda um número de caracteres dependo da ordem do modelo
        char c;                                                                             // Variável para leitura do ficheiro char a char
        bool next_one = false;                                                              // Variável para controlar a presença de caracteres que ocupem 2 bytes
        for(int i = 0; i < k; i++)
        {
            if(Fileseg.eof()){return 0;}                                                    // Se o ficheiro terminar o programa termina
            Fileseg.get(c);                                                                 // Leitura de um char
            if(next_one){
                next_one = false;
            }else{
                if(((c & 0x80) == 0x80)){                                                   // Verificar se é um caracter que ocupa 2 bytes ou 1 byte como é normal
                    end_point.second--;                                                     // Se for um caracter que ocupe 2 bytes vai ser lido em duas chamadas à função ".get()" daí ser preciso fazer o acerto no andamento na linha
                    next_one=true;
                }    
            }
            if(c == '\n'){                                                                  // Garantir que não estamos no final da linha
                end_point.first++;                                                          // Incremento da posição na linha em y
                end_point.second=0;                                                         // Reset da posição na linha em x
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
        unordered_map<string, unordered_map<char, int>>::iterator itr;
        unordered_map<char, int>::iterator ptr;
        unordered_map<char, int> m;
        int occur_c, sum_context;
        double prob, min;
        vector<double> total_bits;
        total_bits.resize(count_mods,0);
        while(!Fileseg.eof())
        {
            Fileseg.get(c);
            if(next_one){
                next_one = false;
            }else{
                if(((c & 0x80) == 0x80)){
                    end_point.second--;
                    next_one=true;
                }    
            }
            end_point.second++;                                                             // Incremento da posição na linha em x  
            if(c != '.'){                                                                   // Final de uma frase
            
                for(int cm = 0; cm < count_mods; cm++){                                     // Correr todos os modelos
                    occur_c = 0; sum_context = 0;
                    if(c != '\n'){
                        if((itr = models[cm].find(k_model)) != models[cm].end()){           // Se o contexto pertencer ao modelo
                            m = models[cm][k_model];
                            if((ptr = m.begin()) != m.end()){                               // Se o caracter pertencer ao contexto
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
                    }
                    else{
                        if(cm == 0){ // Mudança de linha
                            end_point.first++;
                            end_point.second = 0;
                        }
                    }
                }
                k_model.erase(0,1);                                                         // Apaga o primeiro char da string
                k_model += c;                                                               // Adiciona o novo char ao fim da string
            }
            else{  //Quando acabar uma frase
                min = total_bits[0];
                int tmp = 0;
                for(int cm = 1; cm < count_mods; cm++){
                    if(min > total_bits[cm]){                                               // Verificar qual modelo exigia um número de bits menor para representar o nosso texto
                        tmp = cm;
                        min = total_bits[cm];
                    }
                }
                if(diff_lang != tmp){ // Se a linguagem atual da linha for diferente à anterior
                    printf("O segmento que começa em (%d,%d) está em ", beg_point.first, beg_point.second);
                    cout << languages[tmp] << endl;
                    diff_lang = tmp;
                    beg_point.first = end_point.first; beg_point.second = end_point.second;
                }
                return 1; // Ainda tem mais para ser lido, pelo menos assim parece
            }
        }
        return 0;  
        }
};

#endif