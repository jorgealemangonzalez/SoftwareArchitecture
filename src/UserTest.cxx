#include "MiniCppUnit.hxx"
#include "User.hxx"
class UserTest : public TestFixture<UserTest>
{
public:
	TEST_FIXTURE( UserTest )
	{
		TEST_CASE( testName_byInitialize);
	}
	
	void testName_byInitialize(){
		User user("Jorge","jorge@gmail.com");
		ASSERT_EQUALS("Jorge",user.getName());
	}
};

REGISTER_FIXTURE( UserTest )