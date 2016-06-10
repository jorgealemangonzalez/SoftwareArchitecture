
#ifndef Model_hxx
#define Model_hxx

#include <QObject>
#include <fstream>
#include <iostream>

#include "LibFileSystem.hxx"

class Model : public QObject
{

Q_OBJECT

public:

	virtual ~Model() {}
	virtual std::string catalog() const = 0;
	virtual void createArtist( const std::string & name, bool group ) = 0;
	virtual void createNewTrack( const std::string & artistName, const std::string & title, const std::string & master ) = 0;
	virtual void createNewAlbum( const std::string & artistName, const std::string & albumName ) = 0;
	virtual void listAlbum( const std::string & artistName, const std::string & albumName ) = 0;
	virtual void unlistAlbum( const std::string & artistName, const std::string & albumName ) = 0;
	virtual void includeTrackOnAlbum( const std::string & artistName, const std::string & trackName, const std::string & albumName ) = 0;

public slots:

	void doCreateArtist( const std::string & name, bool group )
	{
		createArtist( name, group );
		emit modifiedCatalog( catalog() );
	}
	
	void doCreateNewTrack( const std::string & artistName, const std::string & title )
	{
		std::string master( "masters/" + title );
		std::ofstream os( master.c_str() );
		os << 120 << std::endl;

		LibFileSystem::listDirectoryInOrder( "masters" );

		createNewTrack( artistName, title, title );
		emit modifiedCatalog( catalog() );
	}

	void doCreateNewAlbum( const std::string & artistName, const std::string & albumName )
	{
		createNewAlbum( artistName, albumName );
		emit modifiedCatalog( catalog() );
	}

	void doListAlbum( const std::string & artistName, const std::string & albumName )
	{
		listAlbum( artistName, albumName );
		emit modifiedCatalog( catalog() );
	}

	void doUnlistAlbum( const std::string & artistName, const std::string & albumName )
	{
		unlistAlbum( artistName, albumName );
		emit modifiedCatalog( catalog() );
	}

	void doIncludeTrackOnAlbum( const std::string & artistName, const std::string & trackName, const std::string & albumName )
	{
		includeTrackOnAlbum( artistName, trackName, albumName );
		emit modifiedCatalog( catalog() );
	}

signals:

	void modifiedCatalog( const std::string & catalog );

};

#endif
