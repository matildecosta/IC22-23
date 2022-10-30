#ifndef WAVEffec_H
#define WAVEffec_H


#include <fstream>
#include <iostream>
#include <vector>
#include <sndfile.hh>
#include <math.h>
#include <stdlib.h> 

class WAVEffec {
  private:
    std::vector<short> all_samples;
    size_t ind = 0, ind_mult = 0, ind_amp = 0, ind_muldel=0;
    double alpha = 0.5;
    size_t delay = 88200;   //atraso de 1 segundo
    int freq = 2;           //Hz
    int freqam = 44100;     //Hz

  public:
    void set_alpha(double x){
      alpha = x;
    }
    double get_alpha(){
      return alpha;
    }
	  void readdata(std::vector<short> samples){
        size_t i = 0;
        while(i<samples.size()){
            all_samples.push_back(samples[i]);
            i++;
        }

    }
    void printinfo(){
        size_t i = 0;
        while(i<all_samples.size()){
            std::cout << all_samples[i] << '\n';
            i++;
        }
    }

    auto echo(){
      std::vector<short> test;
      while(ind<all_samples.size()){
        if(ind>=delay){
          test.push_back((all_samples[ind]+alpha*all_samples[ind-delay])/(1+alpha));
        }
        else{
          test.push_back(all_samples[ind]);
        }
        ind++;
      }
      return test;    
    }
    auto multi_echo(){
      std::vector<short> test;
      while(ind_mult<all_samples.size()){
        if(ind_mult>=delay){ 
          if(ind_mult>=(delay*2)){
            test.push_back((all_samples[ind_mult]+alpha*all_samples[ind_mult-delay]+alpha*all_samples[ind_mult-(delay*2)])/(2+alpha));  
          }           
          else{
            test.push_back((all_samples[ind_mult]+alpha*all_samples[ind_mult-delay])/(1+alpha));
          }
        }
        else{
          test.push_back(all_samples[ind]);
        }
        ind_mult++;
      }
      return test;    
    }
    auto mod_ampli(){
      std::vector<short> test;
       while(ind_amp<all_samples.size()){
          test.push_back((all_samples[ind_amp]*cos(2*M_PI*(double(freq)/freqam)*ind_amp)));
          ind_amp++;
        }
      return test;
    }
    auto var_delays(){
      std::vector<short> test;
      int random;
      if(ind_muldel>0)
          random = rand()%ind_muldel;
      else{
          random = 0;
      } 
        
      while(ind_muldel<all_samples.size()){  
                  
          test.push_back((all_samples[ind_muldel]+alpha*all_samples[ind_muldel-random])/(1+alpha));
          ind_muldel++;
      }
      return test;          
    }
};

#endif

