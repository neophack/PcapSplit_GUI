#include "PcapSplit_GUI.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextCodec>

#include "DataCollection.h"
PcapSplit_GUI::PcapSplit_GUI(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
	setFixedSize(this->width(), this->height());
	ui.setupUi(this);
	dc = new DataCollection;
	//ui.PBar_PS->setMaximum(100);
	//ui.PBar_PS->setValue(0);
	ui.show_label->setText("Configuration");

	//ui.PBar_PS->setVisible(false);
	
	pcap_if_t *alldevs, *temdev;
	char errbuf[PCAP_ERRBUF_SIZE];

	if (pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		//cout << "no devices" << endl;
		QMessageBox::information(this,tr("info"),"No devices !");
		ui.Start_Btn->setEnabled(false);
		ui.Stop_Btn->setEnabled(false);
	}
	else
	{
		QStringList qstr;
		temdev = alldevs;
		//int dex = 1;
		for (temdev = alldevs; temdev != NULL; temdev = temdev->next)
		{
			//qstr << QString(QLatin1String(temdev->name));
			qstr << QString(QLatin1String(temdev->description));
			devicename<< QString(QLatin1String(temdev->name));
			//qstr << QString::number(temdev->flags);
		}

		ui.DeviceNo_comboBox->addItems(qstr);
		ui.Start_Btn->setEnabled(true);
		ui.Stop_Btn->setEnabled(true);
	}

}
void PcapSplit_GUI::displayResult(int x)
{
	if (x==1)
	{
		ui.show_label->setText("Running...");
		ui.PBar_PS->setMaximum(0);
	}

	if (x == 0)
	{
		ui.show_label->setText("Cannot connect to LiDAR");
		ui.PBar_PS->setMaximum(100);
		QMessageBox msg;
	    msg.setText("Fail to connect to the LiDAR! Please check the configuration!");
	    msg.exec();
	}
	
	//qDebug("nnnn");
}

void PcapSplit_GUI::Btn_Start_Click()
{


	char* dev;
	QString str = ui.Save_Text->toPlainText();
	//QString str1 = ui.DeviceNo_Text->toPlainText();
	QString str1 = devicename.at(ui.DeviceNo_comboBox->currentIndex()); //ui.DeviceNo_comboBox->currentText();
	
	QString str2 = ui.Port_Text->toPlainText();
	QString str3 = ui.Time_Text->toPlainText();
	//msg.setText(str);
	//msg.exec();

	string c_str = str.toStdString();
	//string c_str1 = str1.toStdString();
	QByteArray ba = str1.toLatin1();
	dev = ba.data();
	//qDebug(dev);
	string c_str2 = str2.toStdString();
	string c_str3 = str3.toStdString();

	//char filter_exp[] = "port 2368";
	//if (c_str=="")
	{
		//QMessageBox msg;
		//msg.setText("Already started!");
		//msg.exec();
	}


	
	connect(dc, SIGNAL(returnResult(int)), this, SLOT(displayResult(int)));

	dc->data_convert_live(c_str, c_str2, atoi(c_str3.c_str()), dev);// , &ui);
}

void PcapSplit_GUI::Combox_Click()
{
	
}

void PcapSplit_GUI::Btn_Stop_Click()
{
	
	dc->threadStop();
	ui.show_label->setText("Stopped");
	ui.PBar_PS->setMaximum(100);
	ui.PBar_PS->setValue(0);
	//QMessageBox msg;
	//msg.setText("Already stopped!");
	//msg.exec();
	//exit(0);
}

void PcapSplit_GUI::Btn_Save_Click()
{
	//QMessageBox msg;
	//msg.setText("Save data!");
	//msg.exec();

	//QString fileName(tr("ok.txt"));
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		"/home",
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);

	//QDir d;
	//d.mkpath(dir);//
	//QFile file(dir );
	//file.open(QFile::WriteOnly);
	ui.Save_Text->setText(dir);
}

void PcapSplit_GUI::Radio_Port_Click()
{
	//ui.RadioBtn_Port->setChecked(true);
	//ui.Port_Text->setText("2368");
}

//void PcapSplit_GUI::on_RadioBtn_Port_clicked()
//{
//	ui.RadioBtn_Port->setChecked(true);
//	ui.Port_Text->setText("2368");
//}
