#include "MiniCppUnit.hxx"
#include "LibFileSystem.hxx"
#include "OggConverter.hxx"
#include "Converter.hxx"
#include <fstream>

class OggConverterTests : public TestFixture<OggConverterTests>
{
public:
	TEST_FIXTURE( OggConverterTests )
	{
		TEST_CASE( testConvert_generateFile );
		TEST_CASE( testConvert_generateContent );
		TEST_CASE( testConvert_withDifferentBitrate );
		TEST_CASE( testConvert_withInexistentMaster ) ;
		//TEST_CASE( testConvert_polymorphicCall );
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
	
	void testConvert_generateFile(){
		OggConverter converter;
		createMasterFile("Master.wav",50);
		converter.convert("masters/Master.wav","compressed/Prefix");

		ASSERT_EQUALS(
			"compressed/Prefix [128].ogg\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}
	
	void testConvert_generateContent(){
		OggConverter converter;
		createMasterFile("Master.wav",50);
		converter.convert("masters/Master.wav","compressed/Prefix");

		ASSERT_EQUALS(
			"OGG extracted from 'masters/Master.wav' at 128 bps and length 50s.\n",
			LibFileSystem::fileContent( "compressed/Prefix [128].ogg" )
		);
		
	}
	
	void testConvert_withDifferentBitrate(){
		OggConverter converter;
		createMasterFile("Master.wav",50);
		converter.bitRate(96);
		converter.convert("masters/Master.wav","compressed/Prefix");
		ASSERT_EQUALS(
			"OGG extracted from 'masters/Master.wav' at 96 bps and length 50s.\n",
			LibFileSystem::fileContent( "compressed/Prefix [96].ogg" )
		);
	}
	
	void testConvert_withInexistentMaster(){
		OggConverter converter;
		try{
			converter.convert("masters/Vacio.wav","compressed/Prefix");
		}catch(std::exception & e ){
			ASSERT_EQUALS(
			"The master file does not exist",
			e.what()
		);
		}
	}
	/*void testConvert_polymorphicCall(){
		Converter* converter = new OggConverter();
		createMasterFile("Master.wav",50);
		converter->convert("masters/Master.wav","compressed/Prefix");

		ASSERT_EQUALS(
			".ogg extracted from 'masters/Master.wav' at 128 bps and length 50s.\n",
			LibFileSystem::fileContent( "compressed/Prefix [128].ogg" )
		);
		delete converter ;
	}
	*/
};
REGISTER_FIXTURE( OggConverterTests )
