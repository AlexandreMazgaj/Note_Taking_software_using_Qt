#ifndef ARTICLEEDITEUR_H
#define ARTICLEEDITEUR_H

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QLayout>

#include "notes.h"

class ArticleEditeur : public QWidget{
    Q_OBJECT  //Marqueur pour indiquer au moc que on a des signaux et des slots, ce qui va lui faire générer du code supp
    QHBoxLayout* cid;
    QHBoxLayout* ctitre;
    QHBoxLayout* ctext;
    QVBoxLayout* couche;

    QLabel* idl;
    QLabel* titrel;
    QLabel* textl;

    QPushButton* save;

    QLineEdit* id;
    QLineEdit* titre;
    QTextEdit* text;
    Article* article;

public:
    ArticleEditeur(Article& a, QWidget* parent=0);

signals:

public slots:
    //Les slots sont avant out des méthodes qui peuvent être appelés normalement
    void saveArticle();
    void activerSave();
};

#endif // ARTICLEEDITEUR_H
