#include "MiniCppUnit.hxx"
#include "Style.hxx"
class StyleTest : public TestFixture<StyleTest>
{
public:
	TEST_FIXTURE( StyleTest )
	{
		TEST_CASE( testName_byInitialize );
		TEST_CASE( testName_afterModifying );

	}
	
	void testName_byInitialize()
	{
		Style style("rock");
		ASSERT_EQUALS( "rock", style.getName() );
	}
	
	void testName_afterModifying()
	{
		Style style("rock");
		style.setName("blues");
		ASSERT_EQUALS( "blues", style.getName() );
	}
	
};

REGISTER_FIXTURE( StyleTest )


