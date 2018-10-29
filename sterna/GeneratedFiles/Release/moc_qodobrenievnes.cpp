/****************************************************************************
** Meta object code from reading C++ file 'qodobrenievnes.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qodobrenievnes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qodobrenievnes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QOdobrenieVnes[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      27,   25,   15,   15, 0x05,
      61,   25,   15,   15, 0x05,
      92,   15,   15,   15, 0x05,
     103,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     115,   15,   15,   15, 0x08,
     141,   15,   15,   15, 0x08,
     167,   15,   15,   15, 0x08,
     193,   15,   15,   15, 0x08,
     219,   15,   15,   15, 0x08,
     245,   15,   15,   15, 0x08,
     269,   25,   15,   15, 0x08,
     311,   15,   15,   15, 0x08,
     335,   15,   15,   15, 0x08,
     359,   15,   15,   15, 0x08,
     383,   15,   15,   15, 0x08,
     396,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QOdobrenieVnes[] = {
    "QOdobrenieVnes\0\0closeW()\0,\0"
    "scallKomintenti(QWidget*,QString)\0"
    "scallArtikli(QWidget*,QString)\0"
    "editCell()\0closeCell()\0on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "selectionChanged(QModelIndex,QModelIndex)\0"
    "on_plineEdit3_Pressed()\0on_plineEdit4_Pressed()\0"
    "on_plineEdit6_Pressed()\0openEditor()\0"
    "closeEditor()\0"
};

void QOdobrenieVnes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QOdobrenieVnes *_t = static_cast<QOdobrenieVnes *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->scallKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->scallArtikli((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->editCell(); break;
        case 4: _t->closeCell(); break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->on_pushButton_5_clicked(); break;
        case 7: _t->on_pushButton_6_clicked(); break;
        case 8: _t->on_pushButton_3_clicked(); break;
        case 9: _t->on_pushButton_2_clicked(); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 12: _t->on_plineEdit3_Pressed(); break;
        case 13: _t->on_plineEdit4_Pressed(); break;
        case 14: _t->on_plineEdit6_Pressed(); break;
        case 15: _t->openEditor(); break;
        case 16: _t->closeEditor(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QOdobrenieVnes::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QOdobrenieVnes::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QOdobrenieVnes,
      qt_meta_data_QOdobrenieVnes, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QOdobrenieVnes::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QOdobrenieVnes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QOdobrenieVnes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QOdobrenieVnes))
        return static_cast<void*>(const_cast< QOdobrenieVnes*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QOdobrenieVnes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void QOdobrenieVnes::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QOdobrenieVnes::scallKomintenti(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QOdobrenieVnes::scallArtikli(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QOdobrenieVnes::editCell()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QOdobrenieVnes::closeCell()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
