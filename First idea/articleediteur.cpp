#include "articleediteur.h"
#include <QMessageBox>
#include <QObject>

ArticleEditeur::ArticleEditeur(Article& a, QWidget* parent):
    QWidget(parent),
    article(&a),
    id(new QLineEdit(this)),
    titre(new QLineEdit(this)),
    text(new QTextEdit(this)),
    save(new QPushButton("Sauvegarder", this)),
    idl(new QLabel("Identificateur", this)),
    titrel(new QLabel("Titre", this)),
    textl(new QLabel("Text", this)),
    cid(new QHBoxLayout),
    ctitre(new QHBoxLayout),
    ctext(new QHBoxLayout),
    couche(new QVBoxLayout)
{
    cid->addWidget(idl);
    cid->addWidget(id);

    ctitre->addWidget(titrel);
    ctitre->addWidget(titre);

    ctext->addWidget(textl);
    ctext->addWidget(text);

    couche->addLayout(cid);
    couche->addLayout(ctitre);
    couche->addLayout(ctext);
    couche->addWidget(save);

    id->setReadOnly(true);

    id->setText(a.getId());
    titre->setText(a.getTitle());
    text->setText(a.getText());

    // Initialement, le bouton de sauvegarde est désactivé
    save->setEnabled(false);

    setLayout(couche);

    QObject::connect(save, SIGNAL(clicked()), this, SLOT(saveArticle()));
    QObject::connect(titre, SIGNAL(textEdited(QString)), this, SLOT(activerSave()));
    QObject::connect(text, SIGNAL(textChanged()), this, SLOT(activerSave()));

}

void ArticleEditeur::saveArticle(){
    // Maj de l'objet article
    article->setTitle(titre->text());
    article->setText(text->toPlainText());
    // Sauvegarde dans le fichier XML
    NotesManager::getManager().save();
    // Affichage d'une popup d'information
    QMessageBox::information(this, "Sauvegarde", "Votre article a bien été sauvegardé");
    // Le bouton de sauvegarde est grisé
    save->setEnabled(false);
}


void ArticleEditeur::activerSave(){
    save->setEnabled(true);
}
