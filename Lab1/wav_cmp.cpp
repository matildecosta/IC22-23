#include <iostream>
#include <vector>
#include <sndfile.hh>
#include "wav_cmp.h"

using namespace std;

constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

int main(int argc, char *argv[]) {

	bool verbose { false };

	if(argc < 3) {
		cerr << "Usage: wav_cp [ -v (verbose) ]\n";
		cerr << "              wavFileIn wavFileOut\n";
		return 1;
	}

	for(int n = 1 ; n < argc ; n++)
		if(string(argv[n]) == "-v") {
			verbose = true;
			break;
		}

	SndfileHandle sfhOrig { argv[argc-2] };
	if(sfhOrig.error()) {
		cerr << "Error: invalid input file\n";
		return 1;
    }

	if((sfhOrig.format() & SF_FORMAT_TYPEMASK) != SF_FORMAT_WAV) {
		cerr << "Error: file is not in WAV format\n";
		return 1;
	}

	if((sfhOrig.format() & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16) {
		cerr << "Error: file is not in PCM_16 format\n";
		return 1;
	}

	if(verbose) {
		cout << "Input file has:\n";
		cout << '\t' << sfhOrig.frames() << " frames\n";
		cout << '\t' << sfhOrig.samplerate() << " samples per second\n";
		cout << '\t' << sfhOrig.channels() << " channels\n";
	}
//////////////////////////////////////////////////////////////////////////
    SndfileHandle sfhOut { argv[argc-1]};
	size_t nFrames, nFrames1;	//formato size_t frequentemente usado para ciclos iteradores 
	vector<short> samples(FRAMES_BUFFER_SIZE * sfhOrig.channels());
    vector<short> samples1(FRAMES_BUFFER_SIZE * sfhOut.channels());
	WavCmp cmp;
	while((nFrames = sfhOrig.readf(samples.data(), FRAMES_BUFFER_SIZE))) {     //
        nFrames1 = sfhOut.readf(samples1.data(), FRAMES_BUFFER_SIZE);
        if(nFrames!=nFrames1){
            cout << "Ficheiros de audio escolhidos incompativeis\n";
            return 0;
        }
        samples1.resize(nFrames1 * sfhOut.channels());
		samples.resize(nFrames * sfhOrig.channels());
        cmp.energy_sigals(samples,samples1);
	}
    cout << "SNR: "<<cmp.snr() << '\n';
    cout << "Maximum per sample absolute error: " << cmp.maxerr() << '\n'; 
	return 0;
}
