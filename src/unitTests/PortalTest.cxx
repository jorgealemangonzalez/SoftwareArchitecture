#include "MiniCppUnit.hxx"
#include "Portal.hxx"

class PortalTest : public TestFixture<PortalTest>
{
public:
	TEST_FIXTURE( PortalTest )
	{
		TEST_CASE( portalTest_default );
		TEST_CASE( portalTest_changedName );
		TEST_CASE( portalTest_changedDescription );
		//TEST_CASE( portalTest_resumeOfPortal);
	}
	
	void portalTest_default()
	{
		Portal p;
		ASSERT_EQUALS(
			"NONE NODESCRIPTION",
			p.name() +" "+ p.description()
		);
	}
	
	void portalTest_changedName(){
		Portal p;
		p.name("Portal de pepito");
		ASSERT_EQUALS(
			"Portal de pepito",
			p.name()
		);
	}
	
	void portalTest_changedDescription(){
		Portal p;
		p.description("Nueva descripcion");
		ASSERT_EQUALS(
			"Nueva descripcion",
			p.description()
		);
	}
	/*
	void portalTest_resumeOfPortal(){
		Portal p;
		p.name("Portal de pepito");
		p.description("Nueva descripcion");
		ASSERT_EQUALS(
			"Portal de pepito\n"
			"\tNueva descripcion\n",
			p.resume()
		);
	}
	*/
};

REGISTER_FIXTURE( PortalTest )


