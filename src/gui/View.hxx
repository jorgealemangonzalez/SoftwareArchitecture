
#ifndef View_hxx
#define View_hxx

#include <QCheckBox>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QStringList>
#include <QWidget>

#include <iostream>
#include <map>

class View : public QWidget
{

Q_OBJECT

private:

	QStringList _artists;
	typedef std::map< QString, QStringList > MapStrings;
	MapStrings _artistTracks;
	MapStrings _albums;
	MapStrings _albumTracks;

	QGridLayout _layout;
	QComboBox _actionBox;
	QLabel _actionLabel;
	QComboBox _artistBox;
	QLabel _artistLabel;
	QComboBox _artistTrackBox;
	QLabel _artistTrackLabel;
	QComboBox _albumBox;
	QLabel _albumLabel;
	QComboBox _albumTrackBox;
	QLabel _albumTrackLabel;
	QLineEdit _textBox;
	QLabel _textLabel;
	QCheckBox _groupBox;
	QLabel _groupLabel;
	QLabel _errorLabel;
	QPushButton _execute;

	std::string nextLine( std::string & str )
	{
		int ix = str.find( '\n' );
		std::string line = str.substr( 0, ix );
		str.erase( 0, ix + 1 );
		return line;
	}

public:

	View()
		: _layout( this )
		, _actionLabel( "Action:" )
		, _artistLabel( "Artist:" )
		, _artistTrackLabel( "Track:" )
		, _albumLabel( "Album:" )
		, _albumTrackLabel( "Track on album:" )
		, _textLabel( "Name/title:" )
		, _groupLabel( "Group:" )
		, _execute( "Execute" )
	{
		_actionBox.addItem( "Create artist" );
		_actionBox.addItem( "Create track" );
		_actionBox.addItem( "Create album" );
		_actionBox.addItem( "List album" );
		_actionBox.addItem( "Unlist album" );
		_actionBox.addItem( "Include track on album" );

		_layout.addWidget( &_actionLabel, 0, 0 );
		_layout.addWidget( &_actionBox, 0, 1 );
		_layout.addWidget( &_artistLabel, 1, 0 );
		_layout.addWidget( &_artistBox, 1, 1 );
		_layout.addWidget( &_artistTrackLabel, 1, 2 );
		_layout.addWidget( &_artistTrackBox, 1, 3 );
		_layout.addWidget( &_albumLabel, 2, 0 );
		_layout.addWidget( &_albumBox, 2, 1 );
		_layout.addWidget( &_albumTrackLabel, 2, 2 );
		_layout.addWidget( &_albumTrackBox, 2, 3 );
		_layout.addWidget( &_textLabel, 3, 0 );
		_layout.addWidget( &_textBox, 3, 1 );
		_layout.addWidget( &_groupLabel, 3, 2 );
		_layout.addWidget( &_groupBox, 3, 3 );
		_layout.addWidget( &_execute, 4, 0 );
		_layout.addWidget( &_errorLabel, 4, 1 );

		QObject::connect( &_execute, SIGNAL( pressed() ),
		                  this, SLOT( execute() ) );
		QObject::connect( &_artistBox, SIGNAL( activated( const QString & ) ),
		                  this, SLOT( artistSelect( const QString & ) ) );
		QObject::connect( &_albumBox, SIGNAL( activated( const QString & ) ),
		                  this, SLOT( albumSelect( const QString & ) ) );
	}

public slots:

	void updateContent( const std::string & catalog )
	{
		_artists.clear();
		_albums.clear();
		_artistTracks.clear();
		_albumTracks.clear();
		_errorLabel.setText( "" );

		std::string copy = catalog;
		for ( std::string line = nextLine( copy ); !line.empty(); )
		{
			QString artist = QString::fromStdString( line );
			_artists.append( artist );
			for ( line = nextLine( copy ); !line.empty() && line[0] == '\t'; line = nextLine( copy ) )
			{
				QString track = QString::fromStdString( line.substr( 1, line.find( '[' ) - 2 ) );
				_artistTracks[ artist ].append( track );
				line = nextLine( copy );
			}
			for ( ; !line.empty() && line.substr( 0, 6 ) == "Album:"; line = nextLine( copy ) )
			{
				QString album = QString::fromStdString( line.substr( 7 ) );
				_albums[ artist ].append( album );
				for ( line = nextLine( copy ); line.find( '-' ) != std::string::npos; line = nextLine( copy ) )
				{
					int ix = line.find( '-' );
					QString track = QString::fromStdString( line.substr( ix + 2, line.find( '[' ) - ix - 3 ) );
					_albumTracks[ album ].append( track );
				}
			}
		}
		_artistBox.clear();
		_artistBox.addItems( _artists );
		artistSelect( _artists.first() );
	}

	void execute()
	{
		int action = _actionBox.currentIndex();

		std::string artist = _artistBox.count() ? _artistBox.currentText().toStdString() : "";
		if ( artist.size() ) artist = artist.substr( 0, artist.find( '[' ) - 1 );

		std::string artistTrack = _artistTrackBox.count() ? _artistTrackBox.currentText().toStdString() : "";

		std::string album = _albumBox.count() ? _albumBox.currentText().toStdString() : "";
		if ( album.size() ) album = album.substr( 0, album.find( '[' ) - 1 );

		std::string name = _textBox.text().toStdString();
		bool group = _groupBox.checkState() == Qt::Checked;
		emit actionExecuted( action, artist, artistTrack, album, name, group );
	}

	void artistSelect( const QString & artist )
	{
		_artistTrackBox.clear();
		if ( _artistTracks.find( artist ) != _artistTracks.end() )
			_artistTrackBox.addItems( _artistTracks[ artist ] );
		_albumBox.clear();
		if ( _albums.find( artist ) != _albums.end() )
			_albumBox.addItems( _albums[ artist ] );
		if ( _albums.size() )
			albumSelect( _albums[ artist ].first() );
	}

	void albumSelect( const QString & album )
	{
		_albumTrackBox.clear();
		if ( _albumTracks.find( album ) != _albumTracks.end() )
			_albumTrackBox.addItems( _albumTracks[ album ] );
	}

	void displayError( const QString & error )
	{
		_errorLabel.setText( error );
	}

signals:

	void actionExecuted( int action, const std::string & artist, const std::string & track, const std::string & album, const std::string & name, bool group );

};

#endif
