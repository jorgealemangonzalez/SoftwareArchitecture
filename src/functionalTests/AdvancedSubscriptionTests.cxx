#include "MiniCppUnit.hxx"
#include "LibFileSystem.hxx"
#include "MailStub.hxx"
#include "SingAlong.hxx"
#include <fstream>

class AdvancedSubscriptionTests : public TestFixture<AdvancedSubscriptionTests>
{
public:
	TEST_FIXTURE( AdvancedSubscriptionTests )
	{
		TEST_CASE( testCreateNewTrack_notifyUserSubscribedToArtist );
		TEST_CASE( testCreateNewTrack_notifyTwoUsersSubscribedToArtist );
		TEST_CASE( testListThematicPortals );
		TEST_CASE( testRssByPortal_withoutNotificacion );
		TEST_CASE( testRssByPortal_whenNoPortalExists );
		//TEST_CASE( testRssByPortal_withNotifiedTrack );
		//TEST_CASE( testRssByPortal_subscribedToArtistAndStyle );
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
	}

	void createMasterFile( const std::string & name, int duration )
	{
		std::string completeName( "masters/" );
		completeName += name;
		std::ofstream os( completeName.c_str() );
		os << duration << std::endl;
	}

	
	void testCreateNewTrack_notifyUserSubscribedToArtist()
	{
		SingAlong business;
		business.createArtist( "An artist", false );
		business.createNewUser( "A user", "a@mail.org" );
		business.subscribeUserToArtist( "A user", "An artist" );

		createMasterFile( "aMasterFile.wav", 30 );
		business.createNewTrack( "An artist", "A track", "aMasterFile.wav" );
		ASSERT_EQUALS(
			"To: A user <a@mail.org>\n"
			"Subject: new track A track by An artist\n"
			"\n", 
			MailStub::theInstance().sentMails()
		);
	}
	
	void testCreateNewTrack_notifyTwoUsersSubscribedToArtist()
	{
		SingAlong business;
		business.createArtist( "An artist", false );
		business.createArtist( "Another artist", false );
		business.createNewUser( "A user", "a@mail.org" );
		business.createNewUser( "Another user", "another@mail.org" );

		business.subscribeUserToArtist( "A user", "An artist" );
		business.subscribeUserToArtist( "Another user", "Another artist" );

		createMasterFile( "aMasterFile.wav", 30 );
		business.createNewTrack( "An artist", "A track", "aMasterFile.wav" );

		createMasterFile( "anotherMasterFile.wav", 40 );
		business.createNewTrack( "Another artist", "Another track", "anotherMasterFile.wav" );

		ASSERT_EQUALS(
			"To: A user <a@mail.org>\n"
			"Subject: new track A track by An artist\n"
			"\n"
			"To: Another user <another@mail.org>\n"
			"Subject: new track Another track by Another artist\n"
			"\n", 
			MailStub::theInstance().sentMails()
		);
	}
	
	void testListThematicPortals()
	{
		SingAlong business;
		business.createNewPortal( "Nerds", "If you are a nerd, this portal is for you" );
		business.createNewPortal( "Headbangers", "A portal for heavy metal fans" );
		ASSERT_EQUALS(
			"Nerds\n"
			"\tIf you are a nerd, this portal is for you\n"
			"Headbangers\n"
			"\tA portal for heavy metal fans\n",
			business.listPortals()
		);
	}
	
	void testRssByPortal_withoutNotificacion()
	{
		SingAlong business;
		business.createNewPortal( "Headbangers", "A portal for heavy metal fans" );
		
		ASSERT_EQUALS(
			"<?xml version='1.0' encoding='ISO-8859-15'?>\n"
			"<!DOCTYPE rss PUBLIC '-//Netscape Communications//DTD RSS 0.91//EN'\n"
			"'http://my.netscape.com/publish/formats/rss-0.91.dtd'>\n"
			"<rss version='0.91'>\n"
			"<channel>\n"
			"<title>SingAlong: Headbangers</title>\n"
			"<link>http://www.singalong.com/Headbangers</link>\n"
			"<description>A portal for heavy metal fans</description>\n"
			"</channel>\n"
			"</rss>\n",
			business.rssByPortal( "Headbangers" )
		);
	}
	
	void testRssByPortal_whenNoPortalExists()
	{
		SingAlong business;
		business.createNewPortal( "Headbangers", "A portal for heavy metal fans" );

		try
		{
			business.rssByPortal( "InexistentPortal" );
			FAIL( "An exception should be caught!" );
		}
		catch ( std::exception & e )
		{
			ASSERT_EQUALS( "The portal does not exist", e.what() );
		}
	}
	/*
	void testRssByPortal_withNotifiedTrack()
	{
		SingAlong business;
		business.createNewPortal( "Headbangers", "A portal for heavy metal fans" );

		business.createArtist( "Dark Steel", true );
		business.subscribePortalToArtist( "Headbangers", "Dark Steel" );

		createMasterFile( "lead.wav", 30 );
		business.createNewTrack( "Dark Steel", "Lead", "lead.wav" );

		ASSERT_EQUALS(
			"<?xml version='1.0' encoding='ISO-8859-15'?>\n"
			"<!DOCTYPE rss PUBLIC '-//Netscape Communications//DTD RSS 0.91//EN'\n"
			"'http://my.netscape.com/publish/formats/rss-0.91.dtd'>\n"
			"<rss version='0.91'>\n"
			"<channel>\n"
			"<title>SingAlong: Headbangers</title>\n"
			"<link>http://www.singalong.com/Headbangers</link>\n"
			"<description>A portal for heavy metal fans</description>\n"
			"<item>\n"
			"<title>New track: 'Lead' by 'Dark Steel'</title>\n"
			"<link>http://www.singalong.com/infoTrack?artist='Dark Steel'&title='Lead'</link>\n"
			"</item>\n"
			"</channel>\n"
			"</rss>\n",
			business.rssByPortal( "Headbangers" )
		);
	}	
	void testRssByPortal_subscribedToArtistAndStyle()
	{
		SingAlong business;
		business.createNewPortal( "Headbangers", "A portal for heavy metal fans" );
		
		business.createNewStyle( "Metal" );
		business.createArtist( "Dark Steel", true );
		business.createArtist( "Aluminium Maiden", true );

		business.subscribePortalToArtist( "Headbangers", "Dark Steel" );
		business.subscribePortalToStyle( "Headbangers", "Metal" );

		createMasterFile( "lead.wav", 30 );
		business.createNewTrack( "Dark Steel", "Lead", "lead.wav" );
		createMasterFile( "lost.wav", 40 );
		business.createNewTrack( "Aluminium Maiden", "Lost in frost", "lost.wav" );
		business.associateStyleWithTrack( "Metal", "Aluminium Maiden", "Lost in frost" );

		ASSERT_EQUALS(
			"<?xml version='1.0' encoding='ISO-8859-15'?>\n"
			"<!DOCTYPE rss PUBLIC '-//Netscape Communications//DTD RSS 0.91//EN'\n"
			"'http://my.netscape.com/publish/formats/rss-0.91.dtd'>\n"
			"<rss version='0.91'>\n"
			"<channel>\n"
			"<title>SingAlong: Headbangers</title>\n"
			"<link>http://www.singalong.com/Headbangers</link>\n"
			"<description>A portal for heavy metal fans</description>\n"
			"<item>\n"
			"<title>New track: 'Lead' by 'Dark Steel'</title>\n"
			"<link>http://www.singalong.com/infoTrack?artist='Dark Steel'&title='Lead'</link>\n"
			"</item>\n"
			"<item>\n"
			"<title>New track: 'Lost in frost' by 'Aluminium Maiden'</title>\n"
			"<link>http://www.singalong.com/infoTrack?artist='Aluminium Maiden'&title='Lost in frost'</link>\n"
			"</item>\n"
			"</channel>\n"
			"</rss>\n",
			business.rssByPortal( "Headbangers" )
		);
	}
	*/
};

REGISTER_FIXTURE( AdvancedSubscriptionTests )


