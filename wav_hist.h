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
		int i = 1;
		std::ofstream outfile ("test.txt");
		std:: cout << counts.size()<< std::endl;
		while(i < samples.size()){
			if(i%2 == 1){
				double mean = (samples[i-1] + samples[i])/2;
				//std::cout << mean << std::endl;
				std::cout << samples[i] << std::endl;


				outfile << mean << std::endl;
				}
				i++;
		}
		outfile.close();
		
		   

	}
	void difference(){} 
};

#endif

