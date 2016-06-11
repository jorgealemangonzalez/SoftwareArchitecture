#include "MiniCppUnit.hxx"
#include "LibFileSystem.hxx"
#include "MailStub.hxx"
#include "SingAlong.hxx"
#include <fstream>

class SendStrategyTests : public TestFixture<SendStrategyTests>
{
public:
	TEST_FIXTURE( SendStrategyTests )
	{
		TEST_CASE( testAssociateStyleWithTrack_notifyUsersInDifferentWays );
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
		MailStub::theInstance().removeSent();
		SmsStub::theInstance().removeSent();
		WhatsappStub::theInstance().removeSent();
	}

	void createMasterFile( const std::string & name, int duration )
	{
		std::string completeName( "masters/" );
		completeName += name;
		std::ofstream os( completeName.c_str() );
		os << duration << std::endl;
	}
	
	void testAssociateStyleWithTrack_notifyUsersInDifferentWays()
	{
		SingAlong business;
		business.createArtist( "An artist", false );
		business.createNewStyle( "A style" );

		business.createNewUser( "Internet user", "internet@mail.org" );
		business.createNewUser( "Cellphone user", "cellphone@mail.org" );
		business.createNewUser( "Whatsapp user", "whatsapp@mail.org" );
		business.userPrefersSms( "Cellphone user", "12345678955" );
		business.userPrefersWhatsapp( "Whatsapp user", "987654321" );

		business.subscribeUserToStyle( "Internet user", "A style" );
		business.subscribeUserToStyle( "Cellphone user", "A style" );
		business.subscribeUserToStyle( "Whatsapp user", "A style" );

		createMasterFile( "aMasterFile.wav", 30 );
		business.createNewTrack( "An artist", "A track", "aMasterFile.wav" );
		business.associateStyleWithTrack( "A style", "An artist", "A track" );

		ASSERT_EQUALS(
			"To: Internet user <internet@mail.org>\n"
			"Subject: new track A track by An artist\n"
			"\n", 
			MailStub::theInstance().sentMails()
		);
		ASSERT_EQUALS(
			"SMS to 12345678955: [SingAlong] new track A track by An artist\n",
			SmsStub::theInstance().sentMessages()
		);
		ASSERT_EQUALS(
			"Whatsapp to 987654321: [SingAlong] new track A track by An artist\n",
			WhatsappStub::theInstance().sentMessages()
		);
	}
};

REGISTER_FIXTURE( SendStrategyTests )


