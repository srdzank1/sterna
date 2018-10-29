/****************************************************************************
** Meta object code from reading C++ file 'qizvodkorekcija.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qizvodkorekcija.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qizvodkorekcija.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QIzvodKorekcija[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      28,   26,   16,   16, 0x05,
      65,   26,   16,   16, 0x05,
     102,   99,   16,   16, 0x05,
     145,   16,   16,   16, 0x05,
     156,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     168,   16,   16,   16, 0x08,
     194,   16,   16,   16, 0x08,
     220,   16,   16,   16, 0x08,
     246,   16,   16,   16, 0x08,
     272,   16,   16,   16, 0x08,
     298,   16,   16,   16, 0x08,
     322,   26,   16,   16, 0x08,
     364,   16,   16,   16, 0x08,
     388,   16,   16,   16, 0x08,
     412,   16,   16,   16, 0x08,
     425,   16,   16,   16, 0x08,
     439,   16,   16,   16, 0x08,
     465,   16,   16,   16, 0x08,
     492,   16,   16,   16, 0x08,
     519,   16,   16,   16, 0x08,
     554,   16,   16,   16, 0x08,
     570,   16,   16,   16, 0x08,
     591,   16,   16,   16, 0x08,
     611,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QIzvodKorekcija[] = {
    "QIzvodKorekcija\0\0closeW()\0,\0"
    "signBankiFromIzvod(QWidget*,QString)\0"
    "scallKomintenti(QWidget*,QString)\0,,\0"
    "signFakturiFromIzvod(QWidget*,QString,int)\0"
    "editCell()\0closeCell()\0on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "selectionChanged(QModelIndex,QModelIndex)\0"
    "on_plineEdit7_Pressed()\0on_plineEdit6_Pressed()\0"
    "openEditor()\0closeEditor()\0"
    "on_pRadioButton_Pressed()\0"
    "on_pRadioButton2_Pressed()\0"
    "on_pRadioButton8_Pressed()\0"
    "on_pDateTime_Pressed(QMouseEvent*)\0"
    "callProcBanki()\0callProcKomintenti()\0"
    "callProcLineEdit3()\0callProcLineEdit4()\0"
};

void QIzvodKorekcija::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QIzvodKorekcija *_t = static_cast<QIzvodKorekcija *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->signBankiFromIzvod((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->scallKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->signFakturiFromIzvod((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->editCell(); break;
        case 5: _t->closeCell(); break;
        case 6: _t->on_pushButton_4_clicked(); break;
        case 7: _t->on_pushButton_5_clicked(); break;
        case 8: _t->on_pushButton_6_clicked(); break;
        case 9: _t->on_pushButton_3_clicked(); break;
        case 10: _t->on_pushButton_2_clicked(); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 13: _t->on_plineEdit7_Pressed(); break;
        case 14: _t->on_plineEdit6_Pressed(); break;
        case 15: _t->openEditor(); break;
        case 16: _t->closeEditor(); break;
        case 17: _t->on_pRadioButton_Pressed(); break;
        case 18: _t->on_pRadioButton2_Pressed(); break;
        case 19: _t->on_pRadioButton8_Pressed(); break;
        case 20: _t->on_pDateTime_Pressed((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 21: _t->callProcBanki(); break;
        case 22: _t->callProcKomintenti(); break;
        case 23: _t->callProcLineEdit3(); break;
        case 24: _t->callProcLineEdit4(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QIzvodKorekcija::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QIzvodKorekcija::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QIzvodKorekcija,
      qt_meta_data_QIzvodKorekcija, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QIzvodKorekcija::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QIzvodKorekcija::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QIzvodKorekcija::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QIzvodKorekcija))
        return static_cast<void*>(const_cast< QIzvodKorekcija*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QIzvodKorekcija::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void QIzvodKorekcija::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QIzvodKorekcija::signBankiFromIzvod(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QIzvodKorekcija::scallKomintenti(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QIzvodKorekcija::signFakturiFromIzvod(QWidget * _t1, QString _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QIzvodKorekcija::editCell()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QIzvodKorekcija::closeCell()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
