#include "MiniCppUnit.hxx"
#include "LibFileSystem.hxx"
#include "SingAlong.hxx"
#include <fstream>

class CompressionTests : public TestFixture<CompressionTests>
{
public:
	TEST_FIXTURE( CompressionTests )
	{
		TEST_CASE( compressionTestByDefault_withOneMaster );
		//TEST_CASE( compressionTest_configuredWithFile );
		//TEST_CASE( configurationTest_withUnsupportedFormat );
		//TEST_CASE( configurationTest_withUnsupportedBitrateMp3 );
	}

	/**
	 * setUp is automatically called before each test case
	 */
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

	
	void compressionTestByDefault_withOneMaster()
	{
		SingAlong business;
		business.createArtist( "An artist", false );

		createMasterFile( "aMasterFile.wav", 120 );
		business.createNewTrack( "An artist", "A track", "aMasterFile.wav" );

		ASSERT_EQUALS(
			"compressed/An artist - A track [128].mp3\n"
			"compressed/An artist - A track [128].ogg\n"
			"compressed/An artist - A track [192].mp3\n"
			"compressed/An artist - A track [192].ogg\n"
			"compressed/An artist - A track [96].mp3\n"
			"compressed/An artist - A track [96].ogg\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}
	// Note: the functionality of reading a configuration file is not
	// a priority of the client at this time.
	// 
	// The following tests are thus optional, but if implemented, they
	// are considered favorably by the client (and your teachers :)
	/*void compressionTest_configuredWithFile()
	{
		std::ofstream configuration( "config/converters.cfg" );
		configuration << "mp3 192" << std::endl;
		configuration << "ogg 192" << std::endl;
		configuration << "ogg 128" << std::endl;
		configuration.close();

		SingAlong business( "config/converters.cfg" );
		business.createArtist( "An artist", false );

		createMasterFile( "aMasterFile.wav", 120 );
		business.createNewTrack( "An artist", "A track", "aMasterFile.wav" );

		ASSERT_EQUALS(
			"compressed/An artist - A track [128].ogg\n"
			"compressed/An artist - A track [192].mp3\n"
			"compressed/An artist - A track [192].ogg\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}
	void configurationTest_withUnsupportedFormat()
	{
		std::ofstream configuration( "config/converters.cfg" );
		configuration << "wma 192" << std::endl;
		configuration.close();

		try
		{
			SingAlong business( "config/converters.cfg" );
			FAIL( "An exception should be caught!" );
		}
		catch( std::exception & e )
		{
			ASSERT_EQUALS( "Unsupported format", e.what() );
		}
	}
	void configurationTest_withUnsupportedBitrateMp3()
	{
		std::ofstream configuration( "config/converters.cfg" );
		configuration << "mp3 666" << std::endl;
		configuration.close();

		try
		{
			SingAlong business( "config/converters.cfg" );
			FAIL( "An exception should be caught!" );
		}
		catch( std::exception & e )
		{
			ASSERT_EQUALS( "Unsupported format", e.what() );
		}
	}
	*/
};

REGISTER_FIXTURE( CompressionTests )


