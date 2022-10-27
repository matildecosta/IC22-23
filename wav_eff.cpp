#include <iostream>
#include <vector>
#include <sndfile.hh>
#include "wav_eff.h"

using namespace std;

constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

int main(int argc, char *argv[]) {

	bool verbose { false };

	if(argc < 2) {
		cerr << "Usage: wav_cp [ -v (verbose) ]\n";
		cerr << "              wavFileIn wavFileOut\n";
		return 1;
	}

	for(int n = 1 ; n < argc ; n++)
		if(string(argv[n]) == "-v") {
			verbose = true;
			break;
		}

	SndfileHandle sfhIn { argv[argc-2] };
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
	size_t nFrames;	//formato size_t frequentemente usado para ciclos iteradores 
	vector<short> samples(FRAMES_BUFFER_SIZE * sfhIn.channels());
	WAVEffec effect;
	effect.set_alpha(stod(argv[argc-1]));
	vector<short> effects;
    SndfileHandle sfhecho { "echo.wav", SFM_WRITE, sfhIn.format(),
	  sfhIn.channels(), sfhIn.samplerate() };
	SndfileHandle sfhmultiecho { "multi_echo.wav", SFM_WRITE, sfhIn.format(),
	  sfhIn.channels(), sfhIn.samplerate() };
	SndfileHandle sfhampmod { "amp_mod.wav", SFM_WRITE, sfhIn.format(),
	  sfhIn.channels(), sfhIn.samplerate() };
	while((nFrames = sfhIn.readf(samples.data(), FRAMES_BUFFER_SIZE))) {     //
		samples.resize(nFrames * sfhIn.channels());	
        effect.readdata(samples);
		sfhecho.writef(effect.echo().data(),nFrames);
		sfhmultiecho.writef(effect.multi_echo().data(),nFrames);
		sfhampmod.writef(effect.mod_ampli().data(),nFrames);
	} 
    //effect.printinfo(); -- usei só para testar
    //sfhOut.writef(effect.echo(atof(samples),nFrames);    
	return 0;
}
