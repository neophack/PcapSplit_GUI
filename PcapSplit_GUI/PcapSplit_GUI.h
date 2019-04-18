#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PcapSplit_GUI.h"
#include "DataCollection.h"

namespace Ui {
	class PcapSplit_GUIClass;
}

class PcapSplit_GUI : public QMainWindow
{
	Q_OBJECT

public:
	PcapSplit_GUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::PcapSplit_GUIClass ui;
	DataCollection *dc;
	QStringList devicename;


private slots:
	void Btn_Start_Click();

	void Btn_Stop_Click();

	void Btn_Save_Click();

	void Radio_Port_Click();

	void Combox_Click();

public slots:
	void displayResult(int x);
};
