#include "MiniCppUnit.hxx"
#include "Track.hxx"
class TrackTests : public TestFixture<TrackTests>
{
public:
	TEST_FIXTURE( TrackTests )
	{
		TEST_CASE( testTitle_byDefault );
		TEST_CASE( testTitle_afterModifying );
		//TEST_CASE( testDuration_byDefault );
		//TEST_CASE( testDuration_afterModifying );
		//TEST_CASE( testMaster_byDefault );
		//TEST_CASE( testMaster_afterModifying );
	}
	
	void testTitle_byDefault()
	{
		Track track;
		ASSERT_EQUALS( "-- Untitled --", track.title() );
	}
	void testTitle_afterModifying()
	{
		Track track;
		track.title( "A Title" );
		ASSERT_EQUALS( "A Title", track.title() );
	}
	/*void testDuration_byDefault()
	{
		Track track;
		ASSERT_EQUALS( 0u, track.duration() );
	}
	void testDuration_afterModifying()
	{
		Track track;
		track.duration( 120u );
		ASSERT_EQUALS( 120u, track.duration() );
	}
	void testMaster_byDefault()
	{
		Track track;
		ASSERT_EQUALS( "", track.master() );
	}
	void testMaster_afterModifying()
	{
		Track track;
		track.master( "masters/AFile.wav" );
		ASSERT_EQUALS( "masters/AFile.wav", track.master() );
	}
	*/
};

REGISTER_FIXTURE( TrackTests )


