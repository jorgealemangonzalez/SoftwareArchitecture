/****************************************************************************
** Meta object code from reading C++ file 'View.hxx'
**
** Created: Sun Jun 2 11:38:59 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'View.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_View[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      43,    6,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     124,  116,    5,    5, 0x0a,
     151,    5,    5,    5, 0x0a,
     168,  161,    5,    5, 0x0a,
     196,  190,    5,    5, 0x0a,
     223,  217,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_View[] = {
    "View\0\0action,artist,track,album,name,group\0"
    "actionExecuted(int,std::string,std::string,std::string,std::string,boo"
    "l)\0"
    "catalog\0updateContent(std::string)\0"
    "execute()\0artist\0artistSelect(QString)\0"
    "album\0albumSelect(QString)\0error\0"
    "displayError(QString)\0"
};

void View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        View *_t = static_cast<View *>(_o);
        switch (_id) {
        case 0: _t->actionExecuted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3])),(*reinterpret_cast< const std::string(*)>(_a[4])),(*reinterpret_cast< const std::string(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 1: _t->updateContent((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 2: _t->execute(); break;
        case 3: _t->artistSelect((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->albumSelect((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->displayError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData View::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject View::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_View,
      qt_meta_data_View, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &View::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_View))
        return static_cast<void*>(const_cast< View*>(this));
    return QWidget::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void View::actionExecuted(int _t1, const std::string & _t2, const std::string & _t3, const std::string & _t4, const std::string & _t5, bool _t6)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
