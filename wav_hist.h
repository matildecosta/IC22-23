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
		std::ofstream outfile ("test_sum.txt");
		//std:: cout << counts.size()<< std::endl;
		while(i < samples.size()){
			if(i%2 == 1){
				double mean = (samples[i-1] + samples[i])/2;
				//std::cout << mean << std::endl;
				//std::cout << samples[i] << std::endl;
				outfile << mean << std::endl;
				}
				i++;
		}
		outfile.close();
	}

	void difference(const std::vector<short>& samples){
		int i = 1;
		int count = 0;
		std::vector<int> mean_values;
		std::ofstream outfile ("test_diff.txt");
		//std:: cout << counts.size()<< std::endl;
		while(i < samples.size()){
			if(i%2 == 1){
				double mean = (samples[i-1] - samples[i])/2;
				mean_values[count] = mean;
				count++;

				//std::cout << mean << std::endl;
				//std::cout << samples[i] << std::endl;
				outfile << mean << std::endl;
				}
				i++;
		}
		outfile.close();
	} 

	void hist(){
	
		

	/*	int maxEle = *max_element(arr, arr + n);
   for (int i = maxEle; i >= 0; i--) {
      cout.width(2);
      cout << right << i << " | ";
      for (int j = 0; j < n; j++) {
         if (arr[j] >= i)
            cout << " x ";
         else
            cout << " ";
      }
      cout << "\n";
   }
   for (int i = 0; i < n + 3; i++)
   cout << "---";
   cout << "\n";
   cout << " ";
   for (int i = 0; i < n; i++) {
      cout.width(2);
      cout << right << arr[i] << " ";
   }
	} */
};

#endif

