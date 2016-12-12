/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <glwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *exposure_spin;
    QDoubleSpinBox *red_threshold_spin;
    QLabel *label_3;
    QDoubleSpinBox *green_threshold_spin;
    QLabel *label_4;
    QDoubleSpinBox *blue_threshold_spin;
    QLabel *label_5;
    QCheckBox *apply_bloom_check;
    GLWidget *gl_widget;
    QLabel *label_6;
    QPushButton *start_button;
    QLabel *label_7;
    QDoubleSpinBox *gravitational_constant_spin;
    QLabel *label_8;
    QDoubleSpinBox *softening_factor_spin;
    QPushButton *pause_button;
    QDoubleSpinBox *particle_size_spin;
    QLabel *label_9;
    QComboBox *initial_conditions_box;
    QLabel *label_10;
    QPushButton *stop_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1080);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1660, 90, 201, 16));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral(""));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1690, 10, 221, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        exposure_spin = new QDoubleSpinBox(centralwidget);
        exposure_spin->setObjectName(QStringLiteral("exposure_spin"));
        exposure_spin->setGeometry(QRect(1850, 90, 61, 22));
        exposure_spin->setReadOnly(false);
        exposure_spin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        exposure_spin->setMaximum(10);
        exposure_spin->setSingleStep(0.05);
        red_threshold_spin = new QDoubleSpinBox(centralwidget);
        red_threshold_spin->setObjectName(QStringLiteral("red_threshold_spin"));
        red_threshold_spin->setGeometry(QRect(1850, 140, 61, 22));
        red_threshold_spin->setReadOnly(false);
        red_threshold_spin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        red_threshold_spin->setMaximum(1);
        red_threshold_spin->setSingleStep(0.01);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1660, 140, 201, 16));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral(""));
        label_3->setTextFormat(Qt::AutoText);
        label_3->setAlignment(Qt::AlignCenter);
        green_threshold_spin = new QDoubleSpinBox(centralwidget);
        green_threshold_spin->setObjectName(QStringLiteral("green_threshold_spin"));
        green_threshold_spin->setGeometry(QRect(1850, 190, 61, 22));
        green_threshold_spin->setReadOnly(false);
        green_threshold_spin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        green_threshold_spin->setMaximum(1);
        green_threshold_spin->setSingleStep(0.01);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1660, 190, 201, 16));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral(""));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);
        blue_threshold_spin = new QDoubleSpinBox(centralwidget);
        blue_threshold_spin->setObjectName(QStringLiteral("blue_threshold_spin"));
        blue_threshold_spin->setGeometry(QRect(1850, 250, 61, 22));
        blue_threshold_spin->setReadOnly(false);
        blue_threshold_spin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        blue_threshold_spin->setMaximum(1);
        blue_threshold_spin->setSingleStep(0.01);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1650, 250, 201, 16));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral(""));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignCenter);
        apply_bloom_check = new QCheckBox(centralwidget);
        apply_bloom_check->setObjectName(QStringLiteral("apply_bloom_check"));
        apply_bloom_check->setGeometry(QRect(1700, 40, 191, 31));
        apply_bloom_check->setFont(font);
        apply_bloom_check->setChecked(true);
        gl_widget = new GLWidget(centralwidget);
        gl_widget->setObjectName(QStringLiteral("gl_widget"));
        gl_widget->setEnabled(true);
        gl_widget->setGeometry(QRect(0, -1, 1650, 1080));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gl_widget->sizePolicy().hasHeightForWidth());
        gl_widget->setSizePolicy(sizePolicy);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1670, 280, 221, 20));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        start_button = new QPushButton(centralwidget);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(1660, 520, 131, 31));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1650, 320, 161, 16));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral(""));
        label_7->setTextFormat(Qt::AutoText);
        label_7->setAlignment(Qt::AlignCenter);
        gravitational_constant_spin = new QDoubleSpinBox(centralwidget);
        gravitational_constant_spin->setObjectName(QStringLiteral("gravitational_constant_spin"));
        gravitational_constant_spin->setGeometry(QRect(1840, 310, 71, 31));
        gravitational_constant_spin->setReadOnly(false);
        gravitational_constant_spin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        gravitational_constant_spin->setDecimals(5);
        gravitational_constant_spin->setMaximum(1);
        gravitational_constant_spin->setSingleStep(1e-5);
        gravitational_constant_spin->setValue(0.005);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1650, 370, 201, 16));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral(""));
        label_8->setTextFormat(Qt::AutoText);
        label_8->setAlignment(Qt::AlignCenter);
        softening_factor_spin = new QDoubleSpinBox(centralwidget);
        softening_factor_spin->setObjectName(QStringLiteral("softening_factor_spin"));
        softening_factor_spin->setGeometry(QRect(1850, 360, 61, 22));
        softening_factor_spin->setReadOnly(false);
        softening_factor_spin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        softening_factor_spin->setMinimum(0.01);
        softening_factor_spin->setMaximum(10000);
        softening_factor_spin->setSingleStep(20);
        softening_factor_spin->setValue(100);
        pause_button = new QPushButton(centralwidget);
        pause_button->setObjectName(QStringLiteral("pause_button"));
        pause_button->setGeometry(QRect(1800, 520, 101, 31));
        particle_size_spin = new QDoubleSpinBox(centralwidget);
        particle_size_spin->setObjectName(QStringLiteral("particle_size_spin"));
        particle_size_spin->setGeometry(QRect(1830, 410, 81, 22));
        particle_size_spin->setReadOnly(false);
        particle_size_spin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        particle_size_spin->setDecimals(5);
        particle_size_spin->setMinimum(0.0001);
        particle_size_spin->setMaximum(0.25);
        particle_size_spin->setSingleStep(0.01);
        particle_size_spin->setValue(0.01);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1650, 410, 201, 16));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral(""));
        label_9->setTextFormat(Qt::AutoText);
        label_9->setAlignment(Qt::AlignCenter);
        initial_conditions_box = new QComboBox(centralwidget);
        initial_conditions_box->setObjectName(QStringLiteral("initial_conditions_box"));
        initial_conditions_box->setGeometry(QRect(1830, 450, 81, 22));
        initial_conditions_box->setFocusPolicy(Qt::ClickFocus);
        initial_conditions_box->setEditable(false);
        initial_conditions_box->setCurrentText(QStringLiteral(""));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(1650, 450, 181, 16));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral(""));
        label_10->setTextFormat(Qt::AutoText);
        label_10->setAlignment(Qt::AlignCenter);
        stop_button = new QPushButton(centralwidget);
        stop_button->setObjectName(QStringLiteral("stop_button"));
        stop_button->setGeometry(QRect(1740, 560, 101, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        initial_conditions_box->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Exposure ", 0));
        label_2->setText(QApplication::translate("MainWindow", "Bloom Parameters", 0));
        label_3->setText(QApplication::translate("MainWindow", "Red Threshold", 0));
        label_4->setText(QApplication::translate("MainWindow", "Green Threshold", 0));
        label_5->setText(QApplication::translate("MainWindow", "Blue Threshold", 0));
        apply_bloom_check->setText(QApplication::translate("MainWindow", "Apply Bloom", 0));
        label_6->setText(QApplication::translate("MainWindow", "NBody Parameters", 0));
        start_button->setText(QApplication::translate("MainWindow", "Start", 0));
        label_7->setText(QApplication::translate("MainWindow", "Gravitational Constant", 0));
        label_8->setText(QApplication::translate("MainWindow", "Softening Factor", 0));
        pause_button->setText(QApplication::translate("MainWindow", "Pause", 0));
        label_9->setText(QApplication::translate("MainWindow", "Particle Size", 0));
        label_10->setText(QApplication::translate("MainWindow", "Initial Condition", 0));
        stop_button->setText(QApplication::translate("MainWindow", "Stop", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
