/****************************************************************************
** Meta object code from reading C++ file 'qartiklikorekcija.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qartiklikorekcija.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qartiklikorekcija.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QArtikliKorekcija[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      40,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QArtikliKorekcija[] = {
    "QArtikliKorekcija\0\0succesfulEntryData()\0"
    "closeW()\0on_pushButton_clicked()\0"
};

void QArtikliKorekcija::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QArtikliKorekcija *_t = static_cast<QArtikliKorekcija *>(_o);
        switch (_id) {
        case 0: _t->succesfulEntryData(); break;
        case 1: _t->closeW(); break;
        case 2: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QArtikliKorekcija::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QArtikliKorekcija::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QArtikliKorekcija,
      qt_meta_data_QArtikliKorekcija, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QArtikliKorekcija::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QArtikliKorekcija::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QArtikliKorekcija::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QArtikliKorekcija))
        return static_cast<void*>(const_cast< QArtikliKorekcija*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QArtikliKorekcija::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QArtikliKorekcija::succesfulEntryData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QArtikliKorekcija::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
