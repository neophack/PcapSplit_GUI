
/*this class file is mainly used to split raw pcap data into multiple files according to a specific time window*/

#pragma once

#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H
#endif
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
//#include "Win32-Extensions.h"
//#include <cstddef>
//#include <chrono>

#include "pcap.h"
#include <Qthread>
#include <QMutex>
//#include "qcustomplot.h"
#include "QMessageBox.h"
#include <math.h>


#define LINE_LEN 16
#define PCAP_ERRBUF_SIZE 256
#define LINKTYPE_ETHERNET   DLT_EN10MB  /* also for 100Mb and up */
//#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//namespace Ui {	
//class PcapSplit_GUIClass;
//}

class DataCollection : public QThread
{
	Q_OBJECT


public:
	void run();

signals:
	void returnResult(int x);


private:
	const char *infilename;
	string filename;
	string str2;
	int wind;
	int devN;
	char* Dev;
	bool status_Split;
	bool StoporNot=false;
	//Ui::PcapSplit_GUIClass *Pui;

public slots:

	void data_convert_live(string filename1, string str21, int wind1, char*dev1);//, Ui::PcapSplit_GUIClass *ui1);


	void threadStop();

};

