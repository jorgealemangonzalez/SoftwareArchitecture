#ifndef FraunhofferTools_hxx
#define FraunhofferTools_hxx

#include <fstream>

enum frk_Rate{ bps96, bps128, bps192, bps240 };

/**
 * Simulates the compresion of a wav file into a mp3 file.
 * In fact it simply writes a string describing the process.
 *  - returns -1 if file doesn't exist or it is incorrect
 *  - returns 0 si conversion is ok
 **/
inline int frk_MP3_compression( const char* inWavFile, const char* outFile, frk_Rate rate )
{
	std::ifstream wav;
	wav.open( inWavFile );
	if ( !wav.is_open() ) return -1;
	int duration;
	wav >> duration;

	std::ofstream mp3( outFile );
	mp3 << "MP3 extracted from '" << inWavFile << "' at ";
	switch ( rate )
	{
		case bps96 : mp3 <<  96; break;
		case bps128: mp3 << 128; break;
		case bps192: mp3 << 192; break;
		case bps240: mp3 << 240; break;
	}
	mp3 << " bps and length " << duration << "s." << std::endl;
	return 0;
}

#endif

