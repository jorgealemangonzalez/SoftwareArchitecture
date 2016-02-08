#include "MiniCppUnit.hxx"
#include "Artist.hxx"
class ArtistTests : public TestFixture<ArtistTests>
{
public:
	TEST_FIXTURE( ArtistTests )
	{
		TEST_CASE(testName_byDefault);
		//TEST_CASE(testName_afterModifying);
		//TEST_CASE(testArtistOrGroup_byDefault);
		//TEST_CASE(testArtistOrGroup_afterCreateGroup);
		//TEST_CASE(testArtistOrGroup_afterDisolveGroup);
		//TEST_CASE(testDescription_byDefault);
		//TEST_CASE(testDescription_afterModifying);
	}
	
	void testName_byDefault(){
		Artist artist;
		ASSERT_EQUALS("-- No name --",artist.name());
	}
	/*
	void testName_afterModifying{
		Artist artist;
		artist.name("Javi");
		ASSERT_EQUALS("Javi",artist.name());
	}
	void testArtistOrGroup_byDefault{
		Artist artist;
		ASSERT_EQUALS(false,artist.isGroup());
	}
	void testArtistOrGroup_afterCreateGroup{
		Artist artist;
		artist.createGroup();
		ASSERT_EQUALS(true,artist.isGroup());
	}
	void testArtistOrGroup_afterDisolveGroup{
		Artist artist;
		artist.createGroup();
		artist.disolveGroup();
		ASSERT_EQUALS(false,artist.isGroup());
	}
	void testDescription_byDefault{
		Artist artist;
		ASSERT_EQUALS("-- No name -- [solo]\n",artist.description());
	}
	void testDescription_afterModifying{
		Artist artist;
		artist.name("Javi");
		artist.createGroup();
		ASSERT_EQUALS("Javi [group]\n",artist.description());
	}
	*/
};

REGISTER_FIXTURE( ArtistTests )
