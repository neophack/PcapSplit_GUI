
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
#include "DataCollection.h"
#include "QMessageBox.h"
#include <math.h>


#define LINE_LEN 16
#define PCAP_ERRBUF_SIZE 256
#define LINKTYPE_ETHERNET   DLT_EN10MB  /* also for 100Mb and up */
//#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


	void DataCollection::run()
	{

		try
		{
			//qDebug("bbbb");
			//cout << "begin to read live pcap data" << endl;
			bool PCAPorCSV = true;//pcap
								  //Logger logger;
			pcap_t *fp;
			pcap_dumper_t *ffp = NULL;
			pcap_t *p = NULL;
			//char* dev;
			pcap_if_t *alldevs, *ads, *temdev;
			char errbuf[PCAP_ERRBUF_SIZE];
			//char source[PCAP_BUF_SIZE];
			struct bpf_program bp;
			char filter_exp[] = "port 2368";
			//char filter_exp[9] = { 0 };
			//string sstr = "port " + str2;

			for (int i = 0; i < str2.length(); i++)
			{
				filter_exp[i + 5] = str2[i];
			}

			bpf_u_int32 mask, net;
			pcap_pkthdr *header = 0;
			const u_char *pkt_data = 0;
			//u_int i = 0;
			int res;
			int packet = 1;
			int c = 0;
			int frameIndex = 0;
			int laser_id = 0;

			u_char *pkt_temp_data;
			int pointIndex = 0;
			int count = 0;
			int fra = 0;
			int tempIndex1 = 0;
			int mod = -1;
			time_t ti;
			struct tm local;


			unsigned int packetCount = 0;//data packet
										 //unsigned int positionCount = 0;//position packet

			//cout << "search device" << endl;
			//if (pcap_findalldevs(&alldevs, errbuf) == -1)
			//{
			//	cout << "no devices" << endl;
			//}
			//else
			//{
			//for (ads = alldevs; ads; ads = ads->next)
			//{
			//cout << ads->name << endl;
			//}
			//}
/*
			//dev = pcap_lookupdev(errbuf);
			switch (devN)
			{
			case 1:
				dev = (alldevs)->name;
				break;
			case 2:
				dev = (alldevs->next)->name;
				break;
			case 3:
				dev = (alldevs->next->next)->name;
				break;
			case 4:
				dev = (alldevs->next->next->next)->name;
				break;
			}
		*/

		//if (dev == NULL)
		//{
		//	printf("unable to find device");
		//}

			cout << "search network" << endl;
			if (pcap_lookupnet(Dev, &net, &mask, errbuf) == -1)
			{
				printf("unable to find network");
				throw errbuf;
				net = 0;
				mask = 0;
			}

			cout << "capture live data" << endl;
			/* Open the capture file */
			if ((fp = pcap_open_live(Dev, 65536, 1, 0, errbuf)) == NULL)
				//if ((fp = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf)) == NULL)
				//if ((fp = pcap_open_live(dev, 1248, 1, 0, errbuf)) == NULL)
			{
				printf("unable to open");
				throw errbuf;
			}

			cout << "compile" << endl;
			if (pcap_compile(fp, &bp, filter_exp, 0, net) == -1)
			{
				printf("unable to compile");
				throw errbuf;
			}

			cout << "filter" << endl;
			if (pcap_setfilter(fp, &bp) == -1)
			{
				printf("unable to filter");
			}

			int count11 = 0;

			while ((res = pcap_next_ex(fp, &header, &pkt_data)) >= 0)
			{
				count11++;
				if (count11 == 1)
				{
					//qDebug("aaaa");
					//QMessageBox::information(tr("info"), "No devices !");
					//Pui->PBar_PS->setVisible(true);

					emit returnResult(count11);
				}
				if (header->caplen != 554 && header->caplen < 1248)
				{
					cout << header->caplen << endl;
				}
				//cout << header->caplen << endl;  int pcap_setbuff(fp,256*1248) pcap_setuserbuffer 
				//if (header->caplen == 554)//position packet
				//{
				//	pcap_dump((u_char *)ffp, header, pkt_data);
				//}
				//else//data packet
				{
					time(&ti);
					localtime_s(&local, &ti);
					//auto times = ((pkt_data[1245] << 24) | (pkt_data[1244] << 16) | (pkt_data[1243] << 8) | (pkt_data[1242]));
					//int t1 = (int)(times / 1000000);
					//int mod=t1 % 1800;
					//int wind = 10;//10min
					//int mod1 = t1 / (wind*60);
					int mod1 = local.tm_min / (wind);
					//cout << t1 << endl;
					if (mod == mod1)
					{
						pcap_dump((u_char *)ffp, header, pkt_data);
					}
					else
					{


						//std::string f = static_cast<std::string>(filename);
						//f.erase(f.end() - 5, f.end());
						std::string outputFilename = filename + "/";
						outputFilename.append(to_string(local.tm_year + 1900));
						outputFilename.append("-");
						outputFilename.append(to_string(local.tm_mon + 1));
						outputFilename.append("-");
						outputFilename.append(to_string(local.tm_mday));
						outputFilename.append("-");
						outputFilename.append(to_string(local.tm_hour));
						outputFilename.append("-");
						outputFilename.append(to_string(mod1*wind));
						//outputFilename.append(to_string(count+1));
						outputFilename.append(".pcap");
						const char* fileN = outputFilename.c_str();
						p = pcap_open_dead(LINKTYPE_ETHERNET, 0x0000ffff);
						if (NULL == p)
						{
							printf("pcap_open_dead failed.\n");
						}

						ffp = pcap_dump_open(p, fileN);
						if (NULL == ffp)
						{
							printf("pcap_dump_open failed.\n");
						}

						mod = mod1;
						//count++;
						pcap_dump((u_char *)ffp, header, pkt_data);
					}

				}

				

				if (status_Split)
				{
					break;
				}
			}
			pcap_dump_close(ffp);
			//StoporNot = true;
			
			emit returnResult(count11);
			
		}

		catch (bad_alloc)
		{

			exit(1);
		}
		//system("PAUSE");
		//return true;

	}



	/*
private:
	const char *infilename;
	string filename;
	string str2;
	int wind;
	int devN;
	char* Dev;
	bool status_Split;
	bool StoporNot = false;
	Ui::PcapSplit_GUIClass *Pui;
	*/

	void DataCollection::data_convert_live(string filename1, string str21, int wind1, char*dev1)//, Ui::PcapSplit_GUIClass *ui1)
	{
		//infilename =  "E:/LiDAR/Raw Data/RENO/Baring Blvd/Site1/2018-11-15-07-48-24_Velodyne-HDL-32-Data.pcap";
		filename = filename1;
		str2 = str21;// "C:/LiDAR/Output";
		wind = wind1;
		//devN=devN1;
		Dev = dev1;
		status_Split = false;
		//Pui = ui1;
		this->start();
	}


	void DataCollection::threadStop()
	{
		status_Split = true;
		//this->exit();	
	}

