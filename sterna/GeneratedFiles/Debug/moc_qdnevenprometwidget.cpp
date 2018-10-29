/****************************************************************************
** Meta object code from reading C++ file 'qdnevenprometwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qdnevenprometwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdnevenprometwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDnevenprometWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      58,   30,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     110,   20,   20,   20, 0x08,
     144,   20,   20,   20, 0x08,
     191,  177,   20,   20, 0x08,
     233,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QDnevenprometWidget[] = {
    "QDnevenprometWidget\0\0closeW()\0"
    "text,textName,textNameSaldo\0"
    "sDnevenprometToDokument(QString&,QString&,QString&)\0"
    "on_tableView_clicked(QModelIndex)\0"
    "on_lineEdit_textChanged(QString)\0"
    "modelX,modelY\0selectionChanged(QModelIndex,QModelIndex)\0"
    "funcEditingFinished()\0"
};

void QDnevenprometWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QDnevenprometWidget *_t = static_cast<QDnevenprometWidget *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->sDnevenprometToDokument((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 5: _t->funcEditingFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QDnevenprometWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QDnevenprometWidget::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QDnevenprometWidget,
      qt_meta_data_QDnevenprometWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDnevenprometWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDnevenprometWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDnevenprometWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDnevenprometWidget))
        return static_cast<void*>(const_cast< QDnevenprometWidget*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QDnevenprometWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
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
void QDnevenprometWidget::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QDnevenprometWidget::sDnevenprometToDokument(QString & _t1, QString & _t2, QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
