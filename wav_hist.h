#ifndef WAVHIST_H
#define WAVHIST_H

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <sndfile.hh>

class WAVHist {
  private:
	std::vector<std::map<short, size_t>> counts;
	std::map<double,int> results_diff;
	std::map<double,int> results_sum;

  public:
	WAVHist(const SndfileHandle& sfh) {
		counts.resize(sfh.channels());
	}

	void update(const std::vector<short>& samples) {
		size_t n { };
		for(auto s : samples)
			counts[n++ % counts.size()][s]++;
	}

	void dump(const size_t channel) const {
		for(auto [value, counter] : counts[channel])
			std::cout << value << '\t' << counter << '\n';
	}

	void average(const std::vector<short>& samples){
		int i = 1,count;
		double mean;
		std::vector<double> mean_values;
		std::ofstream outfile ("test_sum.txt");
		//std:: cout << counts.size()<< std::endl;
		while(i < samples.size()){
			if(i%2 == 1){
				mean = (samples[i-1] + samples[i])/2;
				mean_values.push_back(mean);
				//std::cout << mean << std::endl;
				//std::cout << samples[i] << std::endl;
				outfile << mean << std::endl;
				}
				i++;
		}
		outfile.close();

		//contagem das repetições das médias
		for(int i=0; i<mean_values.size(); i++){
			count = 0;
			for(int j=0; j<mean_values.size(); j++){
				if((mean_values[i] == mean_values[j]) && i!=j){
					count++;
					if (results_sum.find(mean_values[i]) == results_sum.end()) {
						results_sum.insert({mean_values[i],count});
					}
					else{
						results_sum[mean_values[i]] += count;
					}
					mean_values.erase(mean_values.begin()+j);
					j--;	//correção de remover um elemento	
					
				}

			}
			
			mean_values[i] += count;	
		}
	}

	void difference(const std::vector<short>& samples){
		int i = 1;
		std::vector<double> mean_values;
		std::ofstream outfile ("test_diff.txt");
		//std:: cout << counts.size()<< std::endl;
		while(i < samples.size()){
			if(i%2 == 1){
				double mean = (samples[i-1] - samples[i])/2;
				mean_values.push_back(mean);
				//std::cout << mean << std::endl;
				//std::cout << samples[i] << std::endl;
				outfile << mean << std::endl;
				}
				i++;
		}
		outfile.close();
		
		//contagem das repetições das médias
		int count;
		for(int i=0; i<mean_values.size(); i++){
			count = 0;
			for(int j=0; j<mean_values.size(); j++){
				if((mean_values[i] == mean_values[j]) && i!=j){
					count++;
					if (results_diff.find(mean_values[i]) == results_diff.end()) {
						results_diff.insert({mean_values[i],count});
					}
					else{
						results_diff[mean_values[i]] += count;
					}
					mean_values.erase(mean_values.begin()+j);
					j--;	//correção de remover um elemento	
					
				}

			}
			
			mean_values[i] += count;	
		}
	} 

	void show_result(){
		std::ofstream outfile1 ("hist_sum.txt");
		for (auto itr = results_sum.begin(); itr != results_sum.end(); ++itr) {
        	outfile1 << itr->first << '\t';
			outfile1 << itr->second << '\n';
			// for(int i =0;i<itr->second;i++){
			// 	outfile1 << "*";
			// }
			// outfile1 << '\n';
    	}
		outfile1.close();

		std::ofstream outfile2 ("hist_diff.txt");
		for (auto itr = results_diff.begin(); itr != results_diff.end(); ++itr) {
        	outfile2 << itr->first << '\t';
			outfile2 << itr->second << '\n';
    	}
		outfile2.close();

	}
};

#endif