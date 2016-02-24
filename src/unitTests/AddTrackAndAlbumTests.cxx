#include "MiniCppUnit.hxx"
#include "Artist.hxx"

class AddTrackAndAlbumTests : public TestFixture<AddTrackAndAlbumTests>
{
public:
	TEST_FIXTURE( AddTrackAndAlbumTests )
	{
		TEST_CASE( testCatalogTracks_withNoTracks );
		TEST_CASE( testCatalogTracks_withOneTrack );
		TEST_CASE( testCatalogTracks_withTwoTracks );
		TEST_CASE( testFindTrack_withTwoTracks );
		TEST_CASE( testFindTrack_whenTrackDoesNotExist );
		TEST_CASE( testDescriptionCatalog_withTracks );
		TEST_CASE( testDescriptionCatalog_withUnlistedAlbum );
		//TEST_CASE( testDescriptionCatalog_withTrackAndAlbum );
		//TEST_CASE( testDescriptionCatalog_withListedAlbum );
		//TEST_CASE( testDescriptionCatalog_withTwoAlbums );
		//TEST_CASE( testFindAlbum_whenAlbumDoesNotExist );
		//TEST_CASE( testTrackList_withNoTracks );
		//TEST_CASE( testTrackList_withOneTrack );
		//TEST_CASE( testTrackList_withTwoTracks );
	}
	
	void testCatalogTracks_withNoTracks()
	{
		Artist artist;
		ASSERT_EQUALS(
			"",
			artist.catalogTracks()
		);
	}
	
	void testCatalogTracks_withOneTrack()
	{
		Artist artist;
		artist.newTrack( "A track", 120u, "masters/AFile.wav" );
		ASSERT_EQUALS(
			"\tA track [120s]\n"
			"\t\tmasters/AFile.wav\n",
			artist.catalogTracks()
		);
	}
	void testCatalogTracks_withTwoTracks()
	{
		Artist artist;
		artist.newTrack( "Track 1", 120u, "masters/File1.wav" );
		artist.newTrack( "Track 2", 90u, "masters/File2.wav" );
		ASSERT_EQUALS(
			"\tTrack 1 [120s]\n"
			"\t\tmasters/File1.wav\n"
			"\tTrack 2 [90s]\n"
			"\t\tmasters/File2.wav\n",
			artist.catalogTracks()
		);
	}
	
	void testFindTrack_withTwoTracks()
	{
		Artist artist;
		artist.newTrack( "Track 1", 120u, "masters/File1.wav" );
		artist.newTrack( "Track 2", 90u, "masters/File2.wav" );
		Track & track = artist.findTrack( "Track 1" );
		ASSERT_EQUALS( "Track 1", track.title() );
	}
	void testFindTrack_whenTrackDoesNotExist()
	{
		Artist artist;
		try
		{
			artist.findTrack( "Does not exist" );
			FAIL( "An exception should be caught!" );
		}
		catch( std::exception & e )
		{
			ASSERT_EQUALS( "The track does not exist", e.what() );
		}
	}
	void testDescriptionCatalog_withTracks()
	{
		Artist artist;
		artist.name( "An artist" );
		artist.newTrack( "Track 1", 120u, "masters/File1.wav" );
		artist.newTrack( "Track 2", 90u, "masters/File2.wav" );
		ASSERT_EQUALS(
			"An artist [solo]\n"
			"\tTrack 1 [120s]\n"
			"\t\tmasters/File1.wav\n"
			"\tTrack 2 [90s]\n"
			"\t\tmasters/File2.wav\n",
			artist.descriptionCatalog()
		);
	}
	
	void testDescriptionCatalog_withUnlistedAlbum()
	{
		Artist artist;
		artist.name( "An artist" );
		artist.newAlbum( "An album" );
		ASSERT_EQUALS(
			"An artist [solo]\n"
			"Album: An album [unlisted]\n",
			artist.descriptionCatalog()
		);
	}
	/*void testDescriptionCatalog_withTrackAndAlbum()
	{
		Artist artist;
		artist.name( "An artist" );
		artist.newTrack( "A track", 120u, "masters/AFile.wav" );
		artist.newAlbum( "An album" );
		ASSERT_EQUALS(
			"An artist [solo]\n"
			"\tA track [120s]\n"
			"\t\tmasters/AFile.wav\n"
			"Album: An album [unlisted]\n",
			artist.descriptionCatalog()
		);
	}
	void testDescriptionCatalog_withListedAlbum()
	{
		Artist artist;
		artist.name( "An artist" );
		artist.newAlbum( "An album" );
		Album & album = artist.findAlbum( "An album" );
		album.list();
		ASSERT_EQUALS(
			"An artist [solo]\n"
			"Album: An album\n",
			artist.descriptionCatalog()
		);
	}
	void testDescriptionCatalog_withTwoAlbums()
	{
		Artist artist;
		artist.name( "An artist" );
		artist.newAlbum( "Album 1" );
		Album & album = artist.findAlbum( "Album 1" );
		artist.newAlbum( "Album 2" );
		album.list();
		ASSERT_EQUALS(
			"An artist [solo]\n"
			"Album: Album 1\n"
			"Album: Album 2 [unlisted]\n",
			artist.descriptionCatalog()
		);
	}
	void testFindAlbum_whenAlbumDoesNotExist()
	{
		Artist artist;
		try
		{
			artist.findAlbum( "Does not exist" );
			FAIL( "An exception should be caught!" );
		}
		catch( std::exception & e )
		{
			ASSERT_EQUALS( "The album does not exist", e.what() );
		}
	}
	void testTrackList_withNoTracks()
	{
		Artist artist;
		artist.newAlbum( "An album" );
		Album & album = artist.findAlbum( "An album" );
		ASSERT_EQUALS(
			"",
			album.trackList()
		);
	}
	void testTrackList_withOneTrack()
	{
		Artist artist;
		artist.newTrack( "A track", 120u, "masters/AFile.wav" );
		artist.newAlbum( "An album" );
		artist.assignTrackToAlbum( "A track", "An album" );
		Album & album = artist.findAlbum( "An album" );
		ASSERT_EQUALS(
			"1 - A track [120s]\n",
			album.trackList()
		);
	}
	void testTrackList_withTwoTracks()
	{
		Artist artist;
		artist.newTrack( "Track 1", 120u, "masters/File1.wav" );
		artist.newTrack( "Track 2", 90u, "masters/File2.wav" );
		artist.newAlbum( "An album" );
		artist.assignTrackToAlbum( "Track 1", "An album" );
		artist.assignTrackToAlbum( "Track 2", "An album" );
		Album & album = artist.findAlbum( "An album" );
		ASSERT_EQUALS(
			"1 - Track 1 [120s]\n"
			"2 - Track 2 [90s]\n",
			album.trackList()
		);
	}
	*/
};

REGISTER_FIXTURE( AddTrackAndAlbumTests )


