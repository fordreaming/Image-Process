/********************************************************************************
** Form generated from reading UI file 'imghistgram.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGHISTGRAM_H
#define UI_IMGHISTGRAM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImgHistGramClass
{
public:
    QAction *actionHistgram_Equlization;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImgHistGramClass)
    {
        if (ImgHistGramClass->objectName().isEmpty())
            ImgHistGramClass->setObjectName(QString::fromUtf8("ImgHistGramClass"));
        ImgHistGramClass->resize(600, 400);
        actionHistgram_Equlization = new QAction(ImgHistGramClass);
        actionHistgram_Equlization->setObjectName(QString::fromUtf8("actionHistgram_Equlization"));
        centralWidget = new QWidget(ImgHistGramClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ImgHistGramClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImgHistGramClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        ImgHistGramClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImgHistGramClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ImgHistGramClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImgHistGramClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImgHistGramClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionHistgram_Equlization);

        retranslateUi(ImgHistGramClass);

        QMetaObject::connectSlotsByName(ImgHistGramClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImgHistGramClass)
    {
        ImgHistGramClass->setWindowTitle(QApplication::translate("ImgHistGramClass", "ImgHistGram", 0, QApplication::UnicodeUTF8));
        actionHistgram_Equlization->setText(QApplication::translate("ImgHistGramClass", "Histgram Equlization", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("ImgHistGramClass", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("ImgHistGramClass", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImgHistGramClass: public Ui_ImgHistGramClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGHISTGRAM_H
