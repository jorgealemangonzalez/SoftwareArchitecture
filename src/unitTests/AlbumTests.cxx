#include "MiniCppUnit.hxx"
#include "Album.hxx"
class AlbumTests : public TestFixture<AlbumTests>
{
public:
	TEST_FIXTURE( AlbumTests )
	{
		TEST_CASE( testTitle_byDefault );
		//TEST_CASE( testTitle_afterModifying );
		//TEST_CASE( testListed_byDefault );
		//TEST_CASE( testListed_afterListing );
		//TEST_CASE( testListed_afterUnlisting );
	}
        
	void testTitle_byDefault()
	{
		Album album;
		ASSERT_EQUALS( "-- Untitled --", album.title() );
	}
        /*
	void testTitle_afterModifying()
	{
		Album album;
		album.title( "A title" );
		ASSERT_EQUALS( "A title", album.title() );
	}
	void testListed_byDefault()
	{
		Album album;
		ASSERT_EQUALS( false, album.isListed() );
	}
	void testListed_afterListing()
	{
		Album album;
		album.list();
		ASSERT_EQUALS( true, album.isListed() );
	}
	void testListed_afterUnlisting()
	{
		Album album;
		album.list();
		album.unlist();
		ASSERT_EQUALS( false, album.isListed() );
	}*/
};

REGISTER_FIXTURE( AlbumTests )


