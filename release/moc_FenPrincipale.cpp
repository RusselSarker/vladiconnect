/****************************************************************************
** Meta object code from reading C++ file 'FenPrincipale.h'
**
** Created: Tue 22. Dec 08:55:52 2009
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FenPrincipale.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FenPrincipale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FenPrincipale[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      40,   14,   14,   14, 0x0a,
      67,   14,   14,   14, 0x0a,
      95,   14,   14,   14, 0x0a,
     122,   14,   14,   14, 0x0a,
     158,   14,   14,   14, 0x0a,
     196,   14,   14,   14, 0x0a,
     246,   14,   14,   14, 0x0a,
     289,   14,   14,   14, 0x0a,
     332,   14,   14,   14, 0x0a,
     376,   14,  372,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FenPrincipale[] = {
    "FenPrincipale\0\0on_bouton_ping_clicked()\0"
    "on_actionQuitter_clicked()\0"
    "on_bouton_arreter_clicked()\0"
    "on_bouton_editer_clicked()\0"
    "on_bouton_ajouter_serveur_clicked()\0"
    "on_bouton_supprimer_serveur_clicked()\0"
    "on_bouton_serveur_valider_modifications_clicked()\0"
    "on_bouton_configuration_importer_clicked()\0"
    "on_bouton_configuration_exporter_clicked()\0"
    "on_liste_serveur_itemSelectionChanged()\0"
    "int\0miseAJourItem()\0"
};

const QMetaObject FenPrincipale::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FenPrincipale,
      qt_meta_data_FenPrincipale, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FenPrincipale::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FenPrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FenPrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FenPrincipale))
        return static_cast<void*>(const_cast< FenPrincipale*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FenPrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_bouton_ping_clicked(); break;
        case 1: on_actionQuitter_clicked(); break;
        case 2: on_bouton_arreter_clicked(); break;
        case 3: on_bouton_editer_clicked(); break;
        case 4: on_bouton_ajouter_serveur_clicked(); break;
        case 5: on_bouton_supprimer_serveur_clicked(); break;
        case 6: on_bouton_serveur_valider_modifications_clicked(); break;
        case 7: on_bouton_configuration_importer_clicked(); break;
        case 8: on_bouton_configuration_exporter_clicked(); break;
        case 9: on_liste_serveur_itemSelectionChanged(); break;
        case 10: { int _r = miseAJourItem();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE