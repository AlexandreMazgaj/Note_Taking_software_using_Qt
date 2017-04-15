#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QLayout>
#include <QFileDialog>

#include "notes.h"
#include "articleediteur.h"

int main(int argc, char *argv[]) {
    //QApplication app(argc, argv);
/*    QWidget fenetre;
    fenetre.resize(300, 300);

    // Creation des widgets
    QLabel idl("identificateur", &fenetre);
    QLabel titlel("titre", &fenetre);
    QLabel textl("texte", &fenetre);

    QLineEdit* id = new QLineEdit(&fenetre);
    QLineEdit* titre = new QLineEdit(&fenetre);

    QTextEdit* text = new QTextEdit(&fenetre);

    QPushButton* save = new QPushButton("save", &fenetre);

    QHBoxLayout* layoutId = new QHBoxLayout;
    QHBoxLayout* layoutTitle = new QHBoxLayout;
    QHBoxLayout* layoutText = new QHBoxLayout;
    QVBoxLayout* layoutCouche = new QVBoxLayout;


    // Question 1
    // Dimension des widgets (en absolu)
    id->setFixedWidth(180);
    titre->setFixedWidth(180);
    text->setFixedSize(180, 110);
    save->setFixedWidth(80);

    // Position des widgets
    idl.move(10,10);
    titlel.move(10,45);
    textl.move(10,80);
    id->move(100,10);
    titre->move(100,45);
    text->move(100,80);
    save->move(200,200);

    // Question 2
    layoutId->addWidget(&idl);
    layoutId->addWidget(id);

    layoutTitle->addWidget(&titlel);
    layoutTitle->addWidget(titre);

    layoutText->addWidget(&textl);
    layoutText->addWidget(text);

    layoutCouche->addLayout(layoutId);
    layoutCouche->addLayout(layoutTitle);
    layoutCouche->addLayout(layoutText);
    layoutCouche->addWidget(save);


    fenetre.setLayout(layoutCouche);


    // Question 3
    QString filename = QFileDialog::getOpenFileName();
    // récupération de l'instance unique
    NotesManager& m = NotesManager::getManager();
    m.setFilename(filename);
    m.load();
    Article& a = m.getArticle("id:to_read");
    id->setText(a.getId());
    titre->setText(a.getTitle());
    text->setText(a.getText());
    id->setReadOnly(true);   */

    //fenetre.show();
//return app.exec();


    QApplication app(argc, argv);
    QString fichier = QFileDialog::getOpenFileName();
    NotesManager& m=NotesManager::getManager();
    m.setFilename(fichier);
    m.load();
    Article& a=m.getArticle("id:citation_babage");
    ArticleEditeur fenetre(a);
    fenetre.show();
    return app.exec();

}
