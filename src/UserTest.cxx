#include "MiniCppUnit.hxx"
#include "User.hxx"
class UserTest : public TestFixture<UserTest>
{
public:
	TEST_FIXTURE( UserTest )
	{
		TEST_CASE( testName_byInitialize);
		TEST_CASE( testEmail_afterModifying);
	}
	
	void testName_byInitialize(){
		User user("Jorge","jorge@gmail.com");
		ASSERT_EQUALS("Jorge",user.getName());
	}

	void testEmail_afterModifying()
	{
		User user("Jorge","jorge@gmail.com");
		user.setEmail("arnau@gmail.com");
		ASSERT_EQUALS( "arnau@gmail.com", user.getEmail() );
	}
};

REGISTER_FIXTURE( UserTest )