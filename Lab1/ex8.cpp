#include <iostream>
#include <fstream>
#include <string>
#include <sndfile.hh>
#include <fftw3.h>
#include "BitStream.h"
#include "wav_quant.h"

using namespace std;

int main (int argc, char* argv[]){

    // .wav -> blocos após o DCT
    bool verbose { false };
	size_t bs { 1024 };
	double dctFrac { 0.2 };
	vector<short> a;
	int arr[8];

	if(argc < 3) {
		cerr << "Usage: ex8 [ -v (verbose) ]\n";
		cerr << "           wavFileIn  wavFileOut\n";
		return 1;
	}

	for(int n = 1 ; n < argc ; n++)
		if(string(argv[n]) == "-v") {
			verbose = true;
			break;
		}

    // open the .wav file to read
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

    // open the .wav file to write
	SndfileHandle sfhOut { argv[argc-1], SFM_WRITE, sfhIn.format(),
	  sfhIn.channels(), sfhIn.samplerate() };
	if(sfhOut.error()) {
		cerr << "Error: invalid output file\n";
		return 1;
    }

	if(verbose) {
		cout << "Input file has:\n";
		cout << '\t' << sfhIn.frames() << " frames\n";
		cout << '\t' << sfhIn.samplerate() << " samples per second\n";
		cout << '\t' << sfhIn.channels() << " channels\n";
	}

	size_t nChannels { static_cast<size_t>(sfhIn.channels()) };
	size_t nFrames { static_cast<size_t>(sfhIn.frames()) };

	// Read all samples: c1 c2 ... cn c1 c2 ... cn ...
	// Note: A frame is a group c1 c2 ... cn
	vector<short> samples(nChannels * nFrames);
	sfhIn.readf(samples.data(), nFrames);

	size_t nBlocks { static_cast<size_t>(ceil(static_cast<double>(nFrames) / bs)) };

	// Do zero padding, if necessary
	samples.resize(nBlocks * bs * nChannels);

	// Vector for holding all DCT coefficients, channel by channel
	vector<vector<short>> x_dct(nChannels, vector<short>(nBlocks * bs));

	// Vector for holding DCT computations
	vector<double> x(bs);

	// Direct DCT
	fftw_plan plan_d = fftw_plan_r2r_1d(bs, x.data(), x.data(), FFTW_REDFT10, FFTW_ESTIMATE);
	for(size_t n = 0 ; n < nBlocks ; n++)
		for(size_t c = 0 ; c < nChannels ; c++) {
			for(size_t k = 0 ; k < bs ; k++)
				x[k] = samples[(n * bs + k) * nChannels + c];

			fftw_execute(plan_d);
			// Keep only "dctFrac" of the "low frequency" coefficients
			for(size_t k = 0 ; k < bs * dctFrac ; k++)
				x_dct[c][n * bs + k] = x[k] / (bs << 1);

		}

    WavQuant out_dct;
		// quantizar os coeficientes e escreve nos .bin - 1 ficheiro para cada canal
	//Canal 1:
	BitStream b1Out("bit1.bin", "w");
	out_dct.quantizacao(8, x_dct[0]);	// quantiza os coefs do canal 1
	cout << "Quantizacao do canal 1 feita com sucesso!" << endl;
	for (int i = 0; i < x_dct[0].size(); i++) {
		for (int j = 0; j < 8; j++){
			arr[j] = (x_dct[0][i] >> j) & 0x01;
		}
		b1Out.writeN_bits(8, arr);
	}
	b1Out.close();

	
	//Canal 2:
	BitStream b2Out("bit2.bin", "w");
	out_dct.quantizacao(8, x_dct[1]);	// quantiza os coefs do canal 2
	for (int i = 0; i < x_dct[1].size(); i++) {
		for (int j = 0; j < 8; j++){
			arr[j] = (x_dct[1][i] >> j) & 0x01;
		}
		b2Out.writeN_bits(8, arr);
	}
	b2Out.close();

		// Leitura dos ficheiros binários

	// Canal 1:
	BitStream b1In("bit1.bin", "r");
	short num = 0;
	for (int i = 0; i < x_dct[0].size(); i++) {
		b1In.readN_bits(8, arr);
		for (int j = 0; j < 8; j++){
			num += arr[j] << j;
		}
		x_dct[0][i] = num;
	}
	b1In.close();

	// Canal 2:
	BitStream b2In("bit2.bin", "r");
	num = 0;
	for (int i = 0; i < x_dct[1].size(); i++) {
		b2In.readN_bits(8, arr);
		for (int j = 0; j < 8; j++){
			num += arr[j] << j;
		}
		x_dct[1][i] = num;
	}
	b2In.close();


	// Inverse DCT
	fftw_plan plan_i = fftw_plan_r2r_1d(bs, x.data(), x.data(), FFTW_REDFT01, FFTW_ESTIMATE);
	for(size_t n = 0 ; n < nBlocks ; n++)
		for(size_t c = 0 ; c < nChannels ; c++) {
			for(size_t k = 0 ; k < bs ; k++)
				x[k] = x_dct[c][n * bs + k];

			fftw_execute(plan_i);
			for(size_t k = 0 ; k < bs ; k++)
				samples[(n * bs + k) * nChannels + c] = static_cast<short>(round(x[k]));

	}

	sfhOut.writef(samples.data(), sfhIn.frames());
	return 0;

    return 0;
}