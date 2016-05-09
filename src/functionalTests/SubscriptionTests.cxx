#include "MiniCppUnit.hxx"
#include "LibFileSystem.hxx"
#include "MailStub.hxx"
#include "SingAlong.hxx"
#include <fstream>

class SubscriptionTests : public TestFixture<SubscriptionTests>
{
public:
	TEST_FIXTURE( SubscriptionTests )
	{
		TEST_CASE( testStyleList_withOneStyle );
		TEST_CASE( testStyleList_withTwoStyles );
		TEST_CASE( testAssociateStyleWithTrack_whenStyleDoesNotExist );
		TEST_CASE( testCatalog_trackWithTwoStyles );
		TEST_CASE( testUserList_withOneUser );
		//TEST_CASE( testUserList_withTwoUsers );
		//TEST_CASE( testListSubscribedToStyle_withOneUser );
		//TEST_CASE( testListSubscribedToStyle_withTwoUsers );
		//TEST_CASE( testListSubscribedToStyle_whenUserDoesNotExist );
		//TEST_CASE( testListSubscribedToStyle_whenStyleDoesNotExist );
		// Notification Tests: 
		//TEST_CASE( testAddStyleToTrack_notifyUserSubscribedToStyle );
		//TEST_CASE( testAddStyleToTrack_notifyTwoUsersSubscribedToStyle );	
	}

	/**
	 * setUp is automatically called before each test case
	 */
	void setUp()
	{
		LibFileSystem::createNetDirectory( "masters" );
	}

	/**
	 * el metode tearDown es cridat automaticament despres de cada cas de test
	 */
	void tearDown()
	{
		LibFileSystem::cleanupDirectory( "masters" );
		MailStub::theInstance().removeSent();
	}

	void createMasterFile( const std::string & name, int duration )
	{
		std::string completeName( "masters/" );
		completeName += name;
		std::ofstream os( completeName.c_str() );
		os << duration << std::endl;
	}
	
	void testStyleList_withOneStyle()
	{
		SingAlong business;
		business.createNewStyle( "rumba" );
		ASSERT_EQUALS("rumba\n", business.styleList() );
	}
	
	void testStyleList_withTwoStyles()
	{
		SingAlong business;
		business.createNewStyle( "dub" );
		business.createNewStyle( "reggae" );
		ASSERT_EQUALS(
			"dub\n"
			"reggae\n",
			business.styleList()
		);
	}

	void testAssociateStyleWithTrack_whenStyleDoesNotExist()
	{
		SingAlong business;
		business.createArtist( "An artist", false );
		createMasterFile( "aMasterFile.wav", 30 );
		business.createNewTrack( "An artist", "A track", "aMasterFile.wav" );
		try
		{
			business.associateStyleWithTrack( "A style", "An artist", "A track" );
			FAIL( "An exception should be caught!" );
		}
		catch ( std::exception & e )
		{
			ASSERT_EQUALS( "The style does not exist", e.what() );
		}
	}
	
	void testCatalog_trackWithTwoStyles()
	{
		SingAlong business;
		business.createArtist( "An artist", false );
		createMasterFile( "aMasterFile.wav", 30 );
		business.createNewTrack( "An artist", "A track", "aMasterFile.wav" );
		business.createNewStyle( "A style" );
		business.createNewStyle( "Another style" );
		business.associateStyleWithTrack( "A style", "An artist", "A track" );
		business.associateStyleWithTrack( "Another style", "An artist", "A track" );
		ASSERT_EQUALS(
			"An artist [solo]\n"
			"\tA track [30s]\n"
			"\t\tmasters/aMasterFile.wav\n"
			"\t\tA style\n"
			"\t\tAnother style\n",
			business.catalog()
		);
	}
	void testUserList_withOneUser()
	{
		SingAlong business;
		business.createNewUser( "A user", "a@mail.org" );
		ASSERT_EQUALS( "A user <a@mail.org>\n", business.userList() );
	}
	/*void testUserList_withTwoUsers()
	{
		SingAlong business;
		business.createNewUser( "A user", "a@mail.org" );
		business.createNewUser( "Another user", "another@mail.org" );
		ASSERT_EQUALS(
			"A user <a@mail.org>\n"
			"Another user <another@mail.org>\n",
			business.userList()
		);
	}
	void testListSubscribedToStyle_withOneUser()
	{
		SingAlong business;
		business.createNewUser( "A user", "a@mail.org" );
		business.createNewStyle( "A style" );
		business.subscribeUserToStyle( "A user", "A style" );
		ASSERT_EQUALS(
			"A user\n", 
			business.listSubscribedToStyle( "A style" )
		);				
	}
	void testListSubscribedToStyle_withTwoUsers()
	{
		SingAlong business;
		business.createNewUser( "A user", "a@mail.org" );
		business.createNewUser( "Another user", "another@mail.org" );
		business.createNewStyle( "A style" );
		business.subscribeUserToStyle( "A user", "A style" );
		business.subscribeUserToStyle( "Another user", "A style" );
		ASSERT_EQUALS(
			"A user\n"
			"Another user\n",
			business.listSubscribedToStyle( "A style" )
		);
	}
	void testListSubscribedToStyle_whenUserDoesNotExist()
	{
		SingAlong business;
		try
		{
			business.subscribeUserToStyle( "A user", "A style" );
			FAIL( "An exception should be caught!" );
		}
		catch ( std::exception & e )
		{
			ASSERT_EQUALS( "The user does not exist", e.what() );
		}
	}
	void testListSubscribedToStyle_whenStyleDoesNotExist()
	{
		SingAlong business;
		business.createNewUser( "A user", "a@mail.org" );
		try
		{
			business.subscribeUserToStyle( "A user", "A style" );
			FAIL( "An exception should be caught!" );
		}
		catch ( std::exception & e )
		{
			ASSERT_EQUALS( "The style does not exist", e.what() );
		}

	}
	void testAddStyleToTrack_notifyUserSubscribedToStyle()
	{
		SingAlong business;
		business.createNewUser( "A user", "a@mail.org" );
		business.createNewStyle( "A style" );
		business.subscribeUserToStyle( "A user", "A style" );

		business.createArtist( "An artist", false );
		createMasterFile( "aMasterFile.wav", 30 );
		business.createNewTrack( "An artist", "A track", "aMasterFile.wav" );
		business.associateStyleWithTrack( "A style", "An artist", "A track" );

		ASSERT_EQUALS(
			"To: A user <a@mail.org>\n"
			"Subject: new track A track by An artist\n"
			"\n",
			MailStub::theInstance().sentMails()
		);
	}
	
	void testAddStyleToTrack_notifyTwoUsersSubscribedToStyle()
	{
		SingAlong business;
		business.createNewUser( "First user", "a@mail.org" );
		business.createNewUser( "Another user", "another@mail.org" );
		business.createNewStyle( "A style" );
		business.subscribeUserToStyle( "First user", "A style" );
		business.subscribeUserToStyle( "Another user", "A style" );

		business.createArtist( "An artist", false );
		createMasterFile( "aMasterFile.wav", 30 );
		business.createNewTrack( "An artist", "A track", "aMasterFile.wav" );
		business.associateStyleWithTrack( "A style", "An artist", "A track" );

		ASSERT_EQUALS(
			"To: Another user <another@mail.org>\n"
			"Subject: new track A track by An artist\n"
			"\n"
			"To: First user <a@mail.org>\n"
			"Subject: new track A track by An artist\n"
			"\n",
			MailStub::theInstance().sentMails()
		);
		// note: messages returned in alphabetical order
	}
	*/

};

REGISTER_FIXTURE( SubscriptionTests )

