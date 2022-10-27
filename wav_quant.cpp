#include <iostream>
#include <vector>
#include <sndfile.hh>
#include "wav_quant.h"

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

	size_t nFrames;	//formato size_t frequentemente usado para ciclos iteradores 
	vector<short> samples(FRAMES_BUFFER_SIZE * sfhIn.channels());
	WavQuant quant { sfhIn };
    SndfileHandle sfhOut { argv[argc-2], SFM_WRITE, sfhIn.format(),
	  sfhIn.channels(), sfhIn.samplerate() };
	while((nFrames = sfhIn.readf(samples.data(), FRAMES_BUFFER_SIZE))) {     //
		samples.resize(nFrames * sfhIn.channels());	//redimensiona o vector para o número de elementos restantes. Vai ler FRAMES_BUFFER_SIZE de cada vez, 
														//no entanto no final o nº de elementos 
														//restantes pode ser mais pequeno daí precisar de limitar o tamanho do vector, para não haver sobreposição de dados

        //a quantização é feita às partes
        //precisava de saber os valores max e min do sinal para poder fazer por intervalos
        //no entanto eu sei os valoes maximos que uma varivel do tipo  short pode tomar, podendo deste modo reduzir o nº de bits usados
        //O problema é que posso acabar por usar um intervalo de amostras muito maior do que o que realmente é importante degradando demasiado o sinal
        //quant.quantizacao(samples);
        sfhOut.writef(quant.quantizacao(atof(argv[argc-1]),samples),nFrames);    
		
	}
	return 0;
}
