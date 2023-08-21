/****************************************************************************
** Meta object code from reading C++ file 'settingw.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tweeterak/settingw.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingw.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSettingWENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSettingWENDCLASS = QtMocHelpers::stringData(
    "SettingW",
    "Send_Current_User",
    "",
    "User*",
    "on_btn_change_clicked",
    "on_btn_headerchange_clicked",
    "on_btn_changepic_clicked",
    "on_btn_delaccount_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSettingWENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[9];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[22];
    char stringdata5[28];
    char stringdata6[25];
    char stringdata7[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSettingWENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSettingWENDCLASS_t qt_meta_stringdata_CLASSSettingWENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "SettingW"
        QT_MOC_LITERAL(9, 17),  // "Send_Current_User"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 5),  // "User*"
        QT_MOC_LITERAL(34, 21),  // "on_btn_change_clicked"
        QT_MOC_LITERAL(56, 27),  // "on_btn_headerchange_clicked"
        QT_MOC_LITERAL(84, 24),  // "on_btn_changepic_clicked"
        QT_MOC_LITERAL(109, 25)   // "on_btn_delaccount_clicked"
    },
    "SettingW",
    "Send_Current_User",
    "",
    "User*",
    "on_btn_change_clicked",
    "on_btn_headerchange_clicked",
    "on_btn_changepic_clicked",
    "on_btn_delaccount_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSettingWENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   47,    2, 0x08,    3 /* Private */,
       5,    0,   48,    2, 0x08,    4 /* Private */,
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SettingW::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSSettingWENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSettingWENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSettingWENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SettingW, std::true_type>,
        // method 'Send_Current_User'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<User *, std::false_type>,
        // method 'on_btn_change_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_headerchange_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_changepic_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_delaccount_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SettingW::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingW *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Send_Current_User((*reinterpret_cast< std::add_pointer_t<User*>>(_a[1]))); break;
        case 1: _t->on_btn_change_clicked(); break;
        case 2: _t->on_btn_headerchange_clicked(); break;
        case 3: _t->on_btn_changepic_clicked(); break;
        case 4: _t->on_btn_delaccount_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< User* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SettingW::*)(User * );
            if (_t _q_method = &SettingW::Send_Current_User; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *SettingW::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingW::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSettingWENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SettingW::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SettingW::Send_Current_User(User * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
