#include "MiniCppUnit.hxx"
#include "Track.hxx"
class TrackTests : public TestFixture<TrackTests>
{
public:
	TEST_FIXTURE( TrackTests )
	{
		TEST_CASE( testTitle_byDefault );
		TEST_CASE( testTitle_afterModifying );
		TEST_CASE( testDuration_byDefault );
		TEST_CASE( testDuration_afterModifying );
		TEST_CASE( testMaster_byDefault );
		TEST_CASE( testMaster_afterModifying );
		TEST_CASE( testStyle_byDefault );
		TEST_CASE( testStyle_withOneStyle );
		//TEST_CASE( testStyle_withMultipleStyles );
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
	void testDuration_byDefault()
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
	
	void testStyle_byDefault(){
		Track track;
		ASSERT_EQUALS( "" , track.styles());
	}
	void testStyle_withOneStyle(){
		Track track;
		Style s("rock");
		track.addStyle(s);
		ASSERT_EQUALS("\t\trock\n",track.styles());
	}
	/*
	void testStyle_withMultipleStyles(){
		Track track;
		Style s1("rock"),s2("blues"),s3("ska");
		track.addStyle(s1);
		track.addStyle(s2);
		track.addStyle(s3);
		ASSERT_EQUALS("\t\trock\n" "\t\tblues\n" "\t\tska\n"
			,track.styles());
	}*/
};

REGISTER_FIXTURE( TrackTests )


