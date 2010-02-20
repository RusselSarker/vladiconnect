#include "FenPrincipale.h"

int FenPrincipale::ping(QString ip, int numero_m_liste, int parametre) {
    static int numero_ping = 0;
    QProcess *process = new QProcess;
    QString arguments;

    //Limiter � un ping
    if(ENVIRONNEMENT == 1) {    //Windows
        arguments="ping "+ip+" -n 1 -w 1";
    } else {
        arguments="ping "+ip+" -c 1 -w 1";   //Linux
    }

    process->start(arguments);

    //pour retrouver le processus apres
    process->setObjectName(QString::number(numero_ping));
    process->setProperty("parametre",parametre);
    process->setProperty("numero_m_liste", numero_m_liste);

    m_liste_processus.insert(numero_ping,process);

    QObject::connect(m_liste_processus[numero_ping],
                     SIGNAL(finished(int,QProcess::ExitStatus)), this,
                     SLOT(fin_processus(int,QProcess::ExitStatus)));

    numero_ping++;
    return numero_ping;
}

void FenPrincipale::fin_processus(int exitCode,QProcess::ExitStatus exitStatus) {

    QObject *monObjet = sender();
    QString nom(monObjet->objectName());
    QProcess *monProcessus = new QProcess;
    int trouve = 0;
    for(int i=0 ; i<m_liste_processus.count() ; i++) {
        if(nom == m_liste_processus[i]->objectName()) {
            monProcessus = m_liste_processus[i];
            trouve = 1;
            i = m_liste_processus.count(); //fin de la boucle
        }
    }

    if(trouve == 0) {
        QMessageBox::critical(this, "Fin de processus",
                              "Le processus n'a pas �t� retrouv�");
        exit(-1);
    }

        int numero_m_liste = monProcessus->property("numero_m_liste").toInt();
        int parametre = monProcessus->property("parametre").toInt();
        if(exitCode == 0) {
            m_liste[numero_m_liste].setConnecte(true);

            //mise en forme dans le QListWidget
            liste_serveur->item(numero_m_liste)->setIcon(QIcon(
                    QCoreApplication::applicationDirPath() +
                    "/images/network-transmit-receive.png"));

            if(parametre == 1) {
                //mise en forme des donn�es pour le fomulaire
                maj_formulaire_action("Connexion", "Ping termin�. Machine connect�e",
                                      100, QCoreApplication::applicationDirPath()
                                      + "/images/network-transmit-receive.png");
            } else if(parametre == 2 && numero_m_liste !=0) {

            } else if(parametre == 3 && numero_m_liste !=0) {
                m_liste[numero_m_liste].setConnecte(true);
                action_etat->setText("Connect�");
                action_nom->setText("V�rification de connexion");
                action_etat_pixmap->setPixmap(
                        QPixmap(QCoreApplication::applicationDirPath()
                                + "/images/network-transmit-receive.png"));
                action_progression->setValue(100);
                bouton_arreter->setEnabled(true);
                bouton_redemarrer->setEnabled(true);
                bouton_demarrer->setEnabled(false);
            }

        } else {
            m_liste[numero_m_liste].setConnecte(false);

            //mise en forme dans le QListWidget
            liste_serveur->item(numero_m_liste)->setIcon(QIcon(
                    QCoreApplication::applicationDirPath()
                    + "/images/network-offline.png"));

            if(parametre == 1) {
                //mise en forme des donn�es pour le fomulaire
                maj_formulaire_action("Connexion", "Ping termin�. Machine d�connect�e",
                                      1, QCoreApplication::applicationDirPath()
                                      + "/images/network-offline.png");
            } else if(parametre == 3 && numero_m_liste !=0) {
                bouton_arreter->setEnabled(false);
                bouton_redemarrer->setEnabled(false);
                bouton_demarrer->setEnabled(true);
            }
        }
        monProcessus->close();

}



