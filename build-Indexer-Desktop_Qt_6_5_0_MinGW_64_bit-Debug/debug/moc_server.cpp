/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Indexer/server.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSServerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSServerENDCLASS = QtMocHelpers::stringData(
    "Server",
    "indexingProgress",
    "",
    "progress",
    "serverStatusChanged",
    "status",
    "searchResults",
    "QList<QVariantMap>",
    "results",
    "pauseIndexing",
    "stopIndexing",
    "resumeIndexing",
    "searchFiles",
    "searchText",
    "onNewConnection",
    "onReadyRead",
    "onDisconnected"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSServerENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[7];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[20];
    char stringdata5[7];
    char stringdata6[14];
    char stringdata7[19];
    char stringdata8[8];
    char stringdata9[14];
    char stringdata10[13];
    char stringdata11[15];
    char stringdata12[12];
    char stringdata13[11];
    char stringdata14[16];
    char stringdata15[12];
    char stringdata16[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSServerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSServerENDCLASS_t qt_meta_stringdata_CLASSServerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Server"
        QT_MOC_LITERAL(7, 16),  // "indexingProgress"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 8),  // "progress"
        QT_MOC_LITERAL(34, 19),  // "serverStatusChanged"
        QT_MOC_LITERAL(54, 6),  // "status"
        QT_MOC_LITERAL(61, 13),  // "searchResults"
        QT_MOC_LITERAL(75, 18),  // "QList<QVariantMap>"
        QT_MOC_LITERAL(94, 7),  // "results"
        QT_MOC_LITERAL(102, 13),  // "pauseIndexing"
        QT_MOC_LITERAL(116, 12),  // "stopIndexing"
        QT_MOC_LITERAL(129, 14),  // "resumeIndexing"
        QT_MOC_LITERAL(144, 11),  // "searchFiles"
        QT_MOC_LITERAL(156, 10),  // "searchText"
        QT_MOC_LITERAL(167, 15),  // "onNewConnection"
        QT_MOC_LITERAL(183, 11),  // "onReadyRead"
        QT_MOC_LITERAL(195, 14)   // "onDisconnected"
    },
    "Server",
    "indexingProgress",
    "",
    "progress",
    "serverStatusChanged",
    "status",
    "searchResults",
    "QList<QVariantMap>",
    "results",
    "pauseIndexing",
    "stopIndexing",
    "resumeIndexing",
    "searchFiles",
    "searchText",
    "onNewConnection",
    "onReadyRead",
    "onDisconnected"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSServerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,
       6,    1,   80,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   83,    2, 0x0a,    7 /* Public */,
      10,    0,   84,    2, 0x0a,    8 /* Public */,
      11,    0,   85,    2, 0x0a,    9 /* Public */,
      12,    1,   86,    2, 0x0a,   10 /* Public */,
      14,    0,   89,    2, 0x08,   12 /* Private */,
      15,    0,   90,    2, 0x08,   13 /* Private */,
      16,    0,   91,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Server::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSServerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSServerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSServerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Server, std::true_type>,
        // method 'indexingProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'serverStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'searchResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QVariantMap> &, std::false_type>,
        // method 'pauseIndexing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopIndexing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resumeIndexing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchFiles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onNewConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->indexingProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->serverStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->searchResults((*reinterpret_cast< std::add_pointer_t<QList<QVariantMap>>>(_a[1]))); break;
        case 3: _t->pauseIndexing(); break;
        case 4: _t->stopIndexing(); break;
        case 5: _t->resumeIndexing(); break;
        case 6: _t->searchFiles((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->onNewConnection(); break;
        case 8: _t->onReadyRead(); break;
        case 9: _t->onDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QVariantMap> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Server::*)(int );
            if (_t _q_method = &Server::indexingProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Server::*)(const QString & );
            if (_t _q_method = &Server::serverStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Server::*)(const QList<QVariantMap> & );
            if (_t _q_method = &Server::searchResults; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSServerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Server::indexingProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Server::serverStatusChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Server::searchResults(const QList<QVariantMap> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
