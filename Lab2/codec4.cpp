#include <iostream>
#include <vector>
#include <sndfile.hh>
#include "codec4.h"

using namespace std;

constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

int main(int argc, char *argv[]) {

	bool verbose { false };

	if(argc < 2) {
		cerr << "Usage: ./ex4 <inFile_Path.wav>\n";
		return 1;
	}

	SndfileHandle sfhIn { argv[argc-1] };
	if(sfhIn.error()) {
		cerr << "Error: invalid input file\n";
		return 1;
    }

	if((sfhIn.format() & SF_FORMAT_TYPEMASK) != SF_FORMAT_WAV) {
		cerr << "Error: file is not in WAV format\n";
		return 1;
	}

	if((sfhIn.format() & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16) {
		cerr << "Error: file is not in PCM_16 format\n";
		return 1;
	}

	if(verbose) {
		cout << "Input file has:\n";
		cout << '\t' << sfhIn.frames() << " frames\n";
		cout << '\t' << sfhIn.samplerate() << " samples per second\n";
		cout << '\t' << sfhIn.channels() << " channels\n";
	}
//////////////////////////////////////////////////////////////////////////
	int op = 0; 
	vector<short> values;
	SndfileHandle mod0 ;
	SndfileHandle mod1 ;
	SndfileHandle mod2 ;
	SndfileHandle mod3 ;
	int quant;
	cout << "What mod do you want to do?" << endl;
    cout << "      0. mod0		2. mod2" << endl;
    cout << "      1. mod1		3. mod3" << endl;
	cout << "R: ";
    cin >> op;
	size_t nFrames;
	vector<short> samples(FRAMES_BUFFER_SIZE * sfhIn.channels());
	Codec4  codec(op);
	switch (op)
	{
		case 0:
			mod0 = { "mod0.wav", SFM_WRITE, sfhIn.format(),	sfhIn.channels(), sfhIn.samplerate() };
			std::cout << "Number of quantization bits (0 if no quantization is needed): ";
			cin >> quant;
			while((nFrames = sfhIn.readf(samples.data(), FRAMES_BUFFER_SIZE))) {    
				samples.resize(nFrames * sfhIn.channels());	
				codec.readdata(samples);
				codec.mode0(quant);  
			}
			codec.end(0);
			//codec.mean();
			codec.set_read(0);
			values = codec.desmod0();
			mod0.writef(values.data(),values.size()/2); 
			codec.end(0);
			break;

		case 1:
			mod1 = { "mod1.wav", SFM_WRITE, sfhIn.format(),	sfhIn.channels(), sfhIn.samplerate() };
			std::cout << "Number of quantization bits (0 if no quantization is needed): ";
			cin >> quant;
			while((nFrames = sfhIn.readf(samples.data(), FRAMES_BUFFER_SIZE))) {    
				samples.resize(nFrames * sfhIn.channels());	
				codec.readdata(samples);
				codec.mode1(quant);  
			}
			codec.end(1);
			codec.set_read(1);
			values = codec.desmod1();
			mod1.writef(values.data(),values.size()/2); 
			codec.end(1);
			break;

		case 2:
			mod2 = { "mod2.wav", SFM_WRITE, sfhIn.format(),	sfhIn.channels(), sfhIn.samplerate() };
			std::cout << "Number of quantization bits (0 if no quantization is needed): ";
			cin >> quant;
			while((nFrames = sfhIn.readf(samples.data(), FRAMES_BUFFER_SIZE))) {    
				samples.resize(nFrames * sfhIn.channels());	
				codec.readdata(samples);
				codec.mode2(quant);  
			}
			codec.end(2);
			codec.set_read(2);
			values = codec.desmod2();
			mod2.writef(values.data(),values.size()/2); 
			codec.end(2);
			break;
		case 3:
			mod3 = { "mod3.wav", SFM_WRITE, sfhIn.format(),	sfhIn.channels(), sfhIn.samplerate() };
			std::cout << "Number of quantization bits (0 if no quantization is needed): ";
			cin >> quant;
			while((nFrames = sfhIn.readf(samples.data(), FRAMES_BUFFER_SIZE))) {    
				samples.resize(nFrames * sfhIn.channels());	
				codec.readdata(samples);
				codec.mode3(quant);  
			}
			codec.end(3);
			codec.set_read(3);
			values = codec.desmod3();
			mod3.writef(values.data(),values.size()/2); 
			codec.end(3);
			break;

		default:
        	std::cout << "Not an option!" << endl;
        	break;
	}

	return 0;
}