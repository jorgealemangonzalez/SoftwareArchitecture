
#include <QApplication>
#include "Model.hxx"
#include "View.hxx"
#include "Controller.hxx"

#include "SingAlong.hxx"

int main( int argc, char *argv[] ) {
	QApplication app( argc, argv );
	Model * model;
	View view;
	Controller controller;

	SingAlong business;
	model = &business;

	QObject::connect( model, SIGNAL( modifiedCatalog( const std::string & ) ),
		              &view, SLOT( updateContent( const std::string & ) ) );
	QObject::connect( &view, SIGNAL( actionExecuted( int, const std::string &, const std::string &, const std::string &, const std::string &, bool ) ),
		              &controller, SLOT( receiveAction( int, const std::string &, const std::string &, const std::string &, const std::string &, bool ) ) );
	QObject::connect( &controller, SIGNAL( createArtist( const std::string &, bool ) ),
	                  model, SLOT( doCreateArtist( const std::string &, bool ) ) );
	QObject::connect( &controller, SIGNAL( createNewTrack( const std::string &, const std::string & ) ),
	                  model, SLOT( doCreateNewTrack( const std::string &, const std::string & ) ) );
	QObject::connect( &controller, SIGNAL( createNewAlbum( const std::string &, const std::string & ) ),
	                  model, SLOT( doCreateNewAlbum( const std::string &, const std::string & ) ) );
	QObject::connect( &controller, SIGNAL( listAlbum( const std::string &, const std::string & ) ),
	                  model, SLOT( doListAlbum( const std::string &, const std::string & ) ) );
	QObject::connect( &controller, SIGNAL( unlistAlbum( const std::string &, const std::string & ) ),
	                  model, SLOT( doUnlistAlbum( const std::string &, const std::string & ) ) );
	QObject::connect( &controller, SIGNAL( includeTrackOnAlbum( const std::string &, const std::string &, const std::string & ) ),
	                  model, SLOT( doIncludeTrackOnAlbum( const std::string &, const std::string &, const std::string & ) ) );
	QObject::connect( &controller, SIGNAL( errorMessage( const QString & ) ),
	                  &view, SLOT( displayError( const QString & ) ) );

	view.show();
	return app.exec();
}

