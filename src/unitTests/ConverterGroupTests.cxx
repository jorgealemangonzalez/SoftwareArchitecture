#include "MiniCppUnit.hxx"
#include "ConverterGroup.hxx"
#include "LibFileSystem.hxx"
#include <fstream>
#include "OggConverter.hxx"
#include "Converter.hxx"
//#include "Mp3Converter.hxx"


class ConverterGroupTests : public TestFixture<ConverterGroupTests>
{
public: 
	TEST_FIXTURE(ConverterGroupTests)
	{
		TEST_CASE(testConvert_withMp3Converter);
		TEST_CASE(testConvert_withoutConverter);
		TEST_CASE(testConvert_withOggConverter);
	}

	void setUp()
	{
		LibFileSystem::createNetDirectory( "masters" );
		LibFileSystem::createNetDirectory( "compressed" );
		LibFileSystem::createNetDirectory( "config" );
	}

	/**
	 * tearDown is automatically called after each test case
	 */
	void tearDown()
	{
		LibFileSystem::cleanupDirectory( "masters" );
		LibFileSystem::cleanupDirectory( "compressed" );
		LibFileSystem::cleanupDirectory( "config" );
	}

	void createMasterFile( const std::string & name, int duration )
	{
		std::string completeName( "masters/" );
		completeName += name;
		std::ofstream os( completeName.c_str() );
		os << duration << std::endl;
	}

	void testConvert_withMp3Converter(){
		ConverterGroup converter ;
		createMasterFile("Master.wav",50);
		converter.addConverter("mp3" , 128);
		converter.convert("masters/Master.wav","compressed/Prefix","mp3",128);
		ASSERT_EQUALS(
			"MP3 extracted from 'masters/Master.wav' at 128 bps and length 50s.\n",
			LibFileSystem::fileContent( "compressed/Prefix [128].mp3" )
		);

	}
	void testConvert_withoutConverter(){
		ConverterGroup converter ;
		createMasterFile("Master.wav",50);
		try{
			converter.convert("masters/Master.wav","compressed/Prefix","mp3",128);
		}catch(std::exception & e){
			ASSERT_EQUALS(
				"No converted added",
				e.what()
			);
		}
	}
	void testConvert_withOggConverter(){
		ConverterGroup converter ;
		createMasterFile("Master.wav",50);
		converter.addConverter("ogg" , 128);
		converter.convert("masters/Master.wav","compressed/Prefix","ogg",128);
		ASSERT_EQUALS(
			"OGG extracted from 'masters/Master.wav' at 128 bps and length 50s.\n",
			LibFileSystem::fileContent( "compressed/Prefix [128].mp3" )
		);

	}

};


REGISTER_FIXTURE( ConverterGroupTests )
