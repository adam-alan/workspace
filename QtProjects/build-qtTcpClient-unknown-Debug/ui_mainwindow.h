/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *hostLineEdit;
    QLineEdit *portLineEdit;
    QLabel *messageLabel;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(658, 487);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 170, 67, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 220, 67, 17));
        hostLineEdit = new QLineEdit(centralWidget);
        hostLineEdit->setObjectName(QStringLiteral("hostLineEdit"));
        hostLineEdit->setGeometry(QRect(160, 170, 113, 25));
        portLineEdit = new QLineEdit(centralWidget);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        portLineEdit->setGeometry(QRect(160, 220, 113, 25));
        messageLabel = new QLabel(centralWidget);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        messageLabel->setGeometry(QRect(70, 290, 81, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 310, 89, 25));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\344\270\273\346\234\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243", Q_NULLPTR));
        messageLabel->setText(QApplication::translate("MainWindow", "\346\224\266\345\210\260\347\232\204\344\277\241\346\201\257", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\350\257\267\346\261\202\350\277\236\346\216\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
