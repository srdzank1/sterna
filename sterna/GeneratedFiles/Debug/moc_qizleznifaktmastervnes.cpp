/****************************************************************************
** Meta object code from reading C++ file 'qizleznifaktmastervnes.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qizleznifaktmastervnes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qizleznifaktmastervnes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QIzleznifaktmasterVnes[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,
      35,   33,   23,   23, 0x05,
      69,   33,   23,   23, 0x05,
     100,   33,   23,   23, 0x05,
     134,   23,   23,   23, 0x05,
     145,   23,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
     157,   23,   23,   23, 0x08,
     183,   23,   23,   23, 0x08,
     209,   23,   23,   23, 0x08,
     235,   23,   23,   23, 0x08,
     261,   23,   23,   23, 0x08,
     287,   23,   23,   23, 0x08,
     311,   23,   23,   23, 0x08,
     336,   33,   23,   23, 0x08,
     378,   23,   23,   23, 0x08,
     402,   23,   23,   23, 0x08,
     426,   23,   23,   23, 0x08,
     450,   23,   23,   23, 0x08,
     474,   23,   23,   23, 0x08,
     487,   23,   23,   23, 0x08,
     507,  501,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QIzleznifaktmasterVnes[] = {
    "QIzleznifaktmasterVnes\0\0closeW()\0,\0"
    "scallKomintenti(QWidget*,QString)\0"
    "scallArtikli(QWidget*,QString)\0"
    "scallfaktmaster(QWidget*,QString)\0"
    "editCell()\0closeCell()\0on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButtonA_clicked()\0"
    "selectionChanged(QModelIndex,QModelIndex)\0"
    "on_plineEdit3_Pressed()\0on_plineEdit4_Pressed()\0"
    "on_plineEdit6_Pressed()\0on_plineEdit7_Pressed()\0"
    "openEditor()\0closeEditor()\0a,b,c\0"
    "procSectionResized(int,int,int)\0"
};

void QIzleznifaktmasterVnes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QIzleznifaktmasterVnes *_t = static_cast<QIzleznifaktmasterVnes *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->scallKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->scallArtikli((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->scallfaktmaster((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->editCell(); break;
        case 5: _t->closeCell(); break;
        case 6: _t->on_pushButton_4_clicked(); break;
        case 7: _t->on_pushButton_5_clicked(); break;
        case 8: _t->on_pushButton_6_clicked(); break;
        case 9: _t->on_pushButton_3_clicked(); break;
        case 10: _t->on_pushButton_2_clicked(); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->on_pushButtonA_clicked(); break;
        case 13: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 14: _t->on_plineEdit3_Pressed(); break;
        case 15: _t->on_plineEdit4_Pressed(); break;
        case 16: _t->on_plineEdit6_Pressed(); break;
        case 17: _t->on_plineEdit7_Pressed(); break;
        case 18: _t->openEditor(); break;
        case 19: _t->closeEditor(); break;
        case 20: _t->procSectionResized((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QIzleznifaktmasterVnes::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QIzleznifaktmasterVnes::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QIzleznifaktmasterVnes,
      qt_meta_data_QIzleznifaktmasterVnes, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QIzleznifaktmasterVnes::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QIzleznifaktmasterVnes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QIzleznifaktmasterVnes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QIzleznifaktmasterVnes))
        return static_cast<void*>(const_cast< QIzleznifaktmasterVnes*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QIzleznifaktmasterVnes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void QIzleznifaktmasterVnes::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QIzleznifaktmasterVnes::scallKomintenti(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QIzleznifaktmasterVnes::scallArtikli(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QIzleznifaktmasterVnes::scallfaktmaster(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QIzleznifaktmasterVnes::editCell()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QIzleznifaktmasterVnes::closeCell()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
