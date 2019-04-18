/********************************************************************************
** Form generated from reading UI file 'PcapSplit_GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCAPSPLIT_GUI_H
#define UI_PCAPSPLIT_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PcapSplit_GUIClass
{
public:
    QWidget *centralWidget;
    QPushButton *Start_Btn;
    QPushButton *Stop_Btn;
    QPushButton *Save_Btn;
    QTextEdit *Save_Text;
    QTextEdit *Time_Text;
    QTextEdit *Port_Text;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *DeviceNo_comboBox;
    QProgressBar *PBar_PS;
    QLabel *show_label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PcapSplit_GUIClass)
    {
        if (PcapSplit_GUIClass->objectName().isEmpty())
            PcapSplit_GUIClass->setObjectName(QStringLiteral("PcapSplit_GUIClass"));
        PcapSplit_GUIClass->resize(602, 474);
        centralWidget = new QWidget(PcapSplit_GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Start_Btn = new QPushButton(centralWidget);
        Start_Btn->setObjectName(QStringLiteral("Start_Btn"));
        Start_Btn->setGeometry(QRect(180, 280, 75, 23));
        Stop_Btn = new QPushButton(centralWidget);
        Stop_Btn->setObjectName(QStringLiteral("Stop_Btn"));
        Stop_Btn->setGeometry(QRect(330, 280, 75, 23));
        Save_Btn = new QPushButton(centralWidget);
        Save_Btn->setObjectName(QStringLiteral("Save_Btn"));
        Save_Btn->setGeometry(QRect(60, 230, 75, 23));
        Save_Text = new QTextEdit(centralWidget);
        Save_Text->setObjectName(QStringLiteral("Save_Text"));
        Save_Text->setGeometry(QRect(140, 220, 411, 41));
        Time_Text = new QTextEdit(centralWidget);
        Time_Text->setObjectName(QStringLiteral("Time_Text"));
        Time_Text->setGeometry(QRect(140, 170, 231, 41));
        Port_Text = new QTextEdit(centralWidget);
        Port_Text->setObjectName(QStringLiteral("Port_Text"));
        Port_Text->setGeometry(QRect(140, 120, 231, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 175, 61, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 130, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 75, 91, 31));
        DeviceNo_comboBox = new QComboBox(centralWidget);
        DeviceNo_comboBox->setObjectName(QStringLiteral("DeviceNo_comboBox"));
        DeviceNo_comboBox->setGeometry(QRect(140, 70, 411, 41));
        PBar_PS = new QProgressBar(centralWidget);
        PBar_PS->setObjectName(QStringLiteral("PBar_PS"));
        PBar_PS->setEnabled(true);
        PBar_PS->setGeometry(QRect(60, 320, 501, 23));
        PBar_PS->setMaximum(100);
        PBar_PS->setValue(0);
        PBar_PS->setTextVisible(false);
        show_label = new QLabel(centralWidget);
        show_label->setObjectName(QStringLiteral("show_label"));
        show_label->setGeometry(QRect(170, 350, 201, 41));
        PcapSplit_GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PcapSplit_GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 31));
        PcapSplit_GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PcapSplit_GUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PcapSplit_GUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PcapSplit_GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PcapSplit_GUIClass->setStatusBar(statusBar);

        retranslateUi(PcapSplit_GUIClass);
        QObject::connect(Start_Btn, SIGNAL(clicked()), PcapSplit_GUIClass, SLOT(Btn_Start_Click()));
        QObject::connect(Stop_Btn, SIGNAL(clicked()), PcapSplit_GUIClass, SLOT(Btn_Stop_Click()));
        QObject::connect(Save_Btn, SIGNAL(clicked()), PcapSplit_GUIClass, SLOT(Btn_Save_Click()));
        QObject::connect(DeviceNo_comboBox, SIGNAL(currentIndexChanged(QString)), PcapSplit_GUIClass, SLOT(Combox_Click()));

        QMetaObject::connectSlotsByName(PcapSplit_GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *PcapSplit_GUIClass)
    {
        PcapSplit_GUIClass->setWindowTitle(QApplication::translate("PcapSplit_GUIClass", "PcapSplit_GUI", Q_NULLPTR));
        Start_Btn->setText(QApplication::translate("PcapSplit_GUIClass", "Start", Q_NULLPTR));
        Stop_Btn->setText(QApplication::translate("PcapSplit_GUIClass", "Stop", Q_NULLPTR));
        Save_Btn->setText(QApplication::translate("PcapSplit_GUIClass", "Save", Q_NULLPTR));
        label->setText(QApplication::translate("PcapSplit_GUIClass", "Interval", Q_NULLPTR));
        label_2->setText(QApplication::translate("PcapSplit_GUIClass", "Port", Q_NULLPTR));
        label_3->setText(QApplication::translate("PcapSplit_GUIClass", "DeviceN.", Q_NULLPTR));
        show_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PcapSplit_GUIClass: public Ui_PcapSplit_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCAPSPLIT_GUI_H
