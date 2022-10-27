#include <iostream>
#include <vector>
#include <sndfile.hh>
#include "wav_hist.h"

using namespace std;

constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

int main(int argc, char *argv[]) {

// ruben - Parte de verificação do ficheiro fornecido pelo utilizador
	if(argc < 3) {
		cerr << "Usage: " << argv[0] << " <input file> <channel>\n";
		return 1;
	}

	SndfileHandle sndFile { argv[argc-2] };
	if(sndFile.error()) {
		cerr << "Error: invalid input file\n";
		return 1;
    }

	if((sndFile.format() & SF_FORMAT_TYPEMASK) != SF_FORMAT_WAV) {
		cerr << "Error: file is not in WAV format\n";
		return 1;
	}

	if((sndFile.format() & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16) {
		cerr << "Error: file is not in PCM_16 format\n";
		return 1;
	}

	int channel { stoi(argv[argc-1]) };
	if(channel >= sndFile.channels()) {
		cerr << "Error: invalid channel requested\n";
		return 1;
	}
//////////////////////////////////////////////////////////////////////////

	size_t nFrames;	//formato size_t frequentemente usado para ciclos iteradores 
	vector<short> samples(FRAMES_BUFFER_SIZE * sndFile.channels());
	WAVHist hist { sndFile };
	while((nFrames = sndFile.readf(samples.data(), FRAMES_BUFFER_SIZE))) {     //
		samples.resize(nFrames * sndFile.channels());	//redimensiona o vector para o número de elementos restantes. Vai ler FRAMES_BUFFER_SIZE de cada vez, 
														//no entanto no final o nº de elementos 
														//restantes pode ser mais pequeno daí precisar de limitar o tamanho do vector, para não haver sobreposição de dados
		hist.update(samples);
		hist.average(samples);
		hist.difference(samples);

		
	}

	//hist.dump(channel);
	hist.show_result();
	return 0;
}
