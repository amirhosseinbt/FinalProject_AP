/****************************************************************************
** Meta object code from reading C++ file 're_quote_tweet.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tweeterak/re_quote_tweet.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 're_quote_tweet.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSRe_Quote_TweetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRe_Quote_TweetENDCLASS = QtMocHelpers::stringData(
    "Re_Quote_Tweet",
    "on_btn_retweet_clicked",
    "",
    "quote_message",
    "on_btn_quotetweet_clicked",
    "quote_a_mention",
    "quote_a_tweet"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRe_Quote_TweetENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[15];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[26];
    char stringdata5[16];
    char stringdata6[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRe_Quote_TweetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRe_Quote_TweetENDCLASS_t qt_meta_stringdata_CLASSRe_Quote_TweetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "Re_Quote_Tweet"
        QT_MOC_LITERAL(15, 22),  // "on_btn_retweet_clicked"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 13),  // "quote_message"
        QT_MOC_LITERAL(53, 25),  // "on_btn_quotetweet_clicked"
        QT_MOC_LITERAL(79, 15),  // "quote_a_mention"
        QT_MOC_LITERAL(95, 13)   // "quote_a_tweet"
    },
    "Re_Quote_Tweet",
    "on_btn_retweet_clicked",
    "",
    "quote_message",
    "on_btn_quotetweet_clicked",
    "quote_a_mention",
    "quote_a_tweet"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRe_Quote_TweetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Re_Quote_Tweet::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSRe_Quote_TweetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRe_Quote_TweetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRe_Quote_TweetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Re_Quote_Tweet, std::true_type>,
        // method 'on_btn_retweet_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'quote_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_quotetweet_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'quote_a_mention'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'quote_a_tweet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Re_Quote_Tweet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Re_Quote_Tweet *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_retweet_clicked(); break;
        case 1: _t->quote_message(); break;
        case 2: _t->on_btn_quotetweet_clicked(); break;
        case 3: _t->quote_a_mention(); break;
        case 4: _t->quote_a_tweet(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Re_Quote_Tweet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Re_Quote_Tweet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRe_Quote_TweetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Re_Quote_Tweet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
