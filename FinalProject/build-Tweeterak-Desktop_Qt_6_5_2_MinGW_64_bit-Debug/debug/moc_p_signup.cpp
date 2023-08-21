/****************************************************************************
** Meta object code from reading C++ file 'p_signup.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tweeterak/p_signup.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'p_signup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
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
struct qt_meta_stringdata_CLASSP_SignUpENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSP_SignUpENDCLASS = QtMocHelpers::stringData(
    "P_SignUp",
    "on_btn_signup_clicked",
    "",
    "Validator",
    "QString&",
    "message",
    "QValidator::State&",
    "st"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSP_SignUpENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[9];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[9];
    char stringdata5[8];
    char stringdata6[19];
    char stringdata7[3];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSP_SignUpENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSP_SignUpENDCLASS_t qt_meta_stringdata_CLASSP_SignUpENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "P_SignUp"
        QT_MOC_LITERAL(9, 21),  // "on_btn_signup_clicked"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 9),  // "Validator"
        QT_MOC_LITERAL(42, 8),  // "QString&"
        QT_MOC_LITERAL(51, 7),  // "message"
        QT_MOC_LITERAL(59, 18),  // "QValidator::State&"
        QT_MOC_LITERAL(78, 2)   // "st"
    },
    "P_SignUp",
    "on_btn_signup_clicked",
    "",
    "Validator",
    "QString&",
    "message",
    "QValidator::State&",
    "st"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSP_SignUpENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x08,    1 /* Private */,
       3,    2,   27,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject P_SignUp::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSP_SignUpENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSP_SignUpENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSP_SignUpENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<P_SignUp, std::true_type>,
        // method 'on_btn_signup_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Validator'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QValidator::State &, std::false_type>
    >,
    nullptr
} };

void P_SignUp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<P_SignUp *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_signup_clicked(); break;
        case 1: _t->Validator((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QValidator::State&>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *P_SignUp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *P_SignUp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSP_SignUpENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int P_SignUp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
