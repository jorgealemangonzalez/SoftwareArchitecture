
#ifndef Controller_hxx
#define Controller_hxx

#include <QObject>
#include <iostream>

#include "LibFileSystem.hxx"
#include "MailStub.hxx"

class Controller : public QObject
{

Q_OBJECT

public:

	Controller()
	{
		LibFileSystem::createNetDirectory( "masters" );
		LibFileSystem::createNetDirectory( "compressed" );
		LibFileSystem::createNetDirectory( "config" );
	}

	~Controller()
	{
		LibFileSystem::cleanupDirectory( "masters" );
		LibFileSystem::cleanupDirectory( "compressed" );
		LibFileSystem::cleanupDirectory( "config" );
		MailStub::theInstance().removeSent();
	}

public slots:

	void receiveAction( int action, const std::string & artist, const std::string & track, const std::string & album, const std::string & name, bool group )
	{
		switch( action )
		{
			case 0:
				if ( name == "" ) emit errorMessage( "Enter name" );
				else emit createArtist( name, group );
				break;
			case 1:
				if ( name == "" ) emit errorMessage( "Enter name" );
				else if ( artist == "" ) emit errorMessage( "No artist selected" );
				else emit createNewTrack( artist, name );
				break;
			case 2:
				if ( name == "" ) emit errorMessage( "Enter name" );
				else if ( artist == "" ) emit errorMessage( "No artist selected" );
				else emit createNewAlbum( artist, name );
				break;
			case 3:
				if ( artist == "" ) emit errorMessage( "No artist selected" );
				else if ( album == "" ) emit errorMessage( "No album selected" );
				else emit listAlbum( artist, album );
				break;
			case 4:
				if ( artist == "" ) emit errorMessage( "No artist selected" );
				else if ( album == "" ) emit errorMessage( "No album selected" );
				else emit unlistAlbum( artist, album );
				break;
			case 5:
				if ( artist == "" ) emit errorMessage( "No artist selected" );
				else if ( album == "" ) emit errorMessage( "No album selected" );
				else if ( track == "" ) emit errorMessage( "No track selected" );
				else emit includeTrackOnAlbum( artist, track, album );
				break;
		}
	}

signals:

	void errorMessage( const QString & error );
	void createArtist( const std::string & name, bool group );
	void createNewTrack( const std::string & artistName, const std::string & title );
	void createNewAlbum( const std::string & artistName, const std::string & albumName );
	void listAlbum( const std::string & artistName, const std::string & albumName );
	void unlistAlbum( const std::string & artistName, const std::string & albumName );
	void includeTrackOnAlbum( const std::string & artistName, const std::string & trackName, const std::string & albumName );

};

#endif
