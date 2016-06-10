/****************************************************************************
** Meta object code from reading C++ file 'Model.hxx'
**
** Created: Sun Jun 2 11:38:57 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Model.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Model.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Model[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,    7,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   44,    6,    6, 0x0a,
     105,   88,    6,    6, 0x0a,
     168,  147,    6,    6, 0x0a,
     210,  147,    6,    6, 0x0a,
     247,  147,    6,    6, 0x0a,
     317,  286,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Model[] = {
    "Model\0\0catalog\0modifiedCatalog(std::string)\0"
    "name,group\0doCreateArtist(std::string,bool)\0"
    "artistName,title\0"
    "doCreateNewTrack(std::string,std::string)\0"
    "artistName,albumName\0"
    "doCreateNewAlbum(std::string,std::string)\0"
    "doListAlbum(std::string,std::string)\0"
    "doUnlistAlbum(std::string,std::string)\0"
    "artistName,trackName,albumName\0"
    "doIncludeTrackOnAlbum(std::string,std::string,std::string)\0"
};

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Model *_t = static_cast<Model *>(_o);
        switch (_id) {
        case 0: _t->modifiedCatalog((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 1: _t->doCreateArtist((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->doCreateNewTrack((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 3: _t->doCreateNewAlbum((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 4: _t->doListAlbum((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 5: _t->doUnlistAlbum((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 6: _t->doIncludeTrackOnAlbum((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Model::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Model::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Model,
      qt_meta_data_Model, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Model::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Model))
        return static_cast<void*>(const_cast< Model*>(this));
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Model::modifiedCatalog(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
