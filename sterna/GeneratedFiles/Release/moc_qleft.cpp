/****************************************************************************
** Meta object code from reading C++ file 'qleft.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qleft.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qleft.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QLeft[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    7,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,    6,    6,    6, 0x08,
      78,   76,    6,    6, 0x08,
     126,   76,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QLeft[] = {
    "QLeft\0\0i\0updatePrinterStatus(QWidget*)\0"
    "on_treeWidget_itemSelectionChanged()\0"
    ",\0on_treeWidget_itemPressed(QTreeWidgetItem*,int)\0"
    "on_treeWidget_itemClicked(QTreeWidgetItem*,int)\0"
};

void QLeft::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QLeft *_t = static_cast<QLeft *>(_o);
        switch (_id) {
        case 0: _t->updatePrinterStatus((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->on_treeWidget_itemSelectionChanged(); break;
        case 2: _t->on_treeWidget_itemPressed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_treeWidget_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QLeft::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QLeft::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QLeft,
      qt_meta_data_QLeft, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QLeft::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QLeft::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QLeft::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QLeft))
        return static_cast<void*>(const_cast< QLeft*>(this));
    return QWidget::qt_metacast(_clname);
}

int QLeft::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QLeft::updatePrinterStatus(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
