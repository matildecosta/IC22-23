#include <iostream>
#include <vector>
#include <sndfile.hh>
#include "codec4.h"

using namespace std;

constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

int main(int argc, char *argv[]) {

	bool verbose { false };

	if(argc < 3) {
		cerr << "Usage: wav_quant [ -v (verbose) ]\n";
		cerr << "              wavFileIn wavFileOut bits\n";
		return 1;
	}

	for(int n = 1 ; n < argc ; n++)
		if(string(argv[n]) == "-v") {
			verbose = true;
			break;
		}

	SndfileHandle sfhIn { argv[argc-3] };
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

	size_t nFrames;
	vector<short> samples(FRAMES_BUFFER_SIZE * sfhIn.channels());

	SndfileHandle mod0 { "mod0.wav", SFM_WRITE, sfhIn.format(),
	sfhIn.channels(), sfhIn.samplerate() };
	SndfileHandle mod1 { "mod1.wav", SFM_WRITE, sfhIn.format(),
	sfhIn.channels(), sfhIn.samplerate() };
	SndfileHandle mod2 { "mod2.wav", SFM_WRITE, sfhIn.format(),
	sfhIn.channels(), sfhIn.samplerate() };
	SndfileHandle mod3 { "mod3.wav", SFM_WRITE, sfhIn.format(),
	sfhIn.channels(), sfhIn.samplerate() };

	Codec4  codec;
    SndfileHandle sfhOut { argv[argc-2], SFM_WRITE, sfhIn.format(),
	  sfhIn.channels(), sfhIn.samplerate() };
	while((nFrames = sfhIn.readf(samples.data(), FRAMES_BUFFER_SIZE))) {    
		samples.resize(nFrames * sfhIn.channels());	
        codec.readdata(samples);
        mod0.writef(codec.mode0().data(),nFrames);   
		mod1.writef(codec.mode1().data(),nFrames);  
		mod2.writef(codec.mode2().data(),nFrames);  
		mod3.writef(codec.mode3().data(),nFrames);   
		
	}
	return 0;
}