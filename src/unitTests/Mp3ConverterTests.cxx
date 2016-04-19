#include "MiniCppUnit.hxx"
#include "LibFileSystem.hxx"
#include "Mp3Converter.hxx"
#include <fstream>

class Mp3ConverterTests : public TestFixture<Mp3ConverterTests>
{
public:
	TEST_FIXTURE( Mp3ConverterTests )
	{
		TEST_CASE( testConvert_generateFile );
		
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
		Mp3Converter converter;
		createMasterFile("Master.wav",50);
		converter.conver("masters/Master.wav","compressed/Prefix");

		ASSERT_EQUALS(
			"compressed/Prefix [128].mp3\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}

};
REGISTER_FIXTURE( Mp3ConverterTests )
