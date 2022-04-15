#pragma once

#include <QObject>
#include <QtWidgets>

#include <thread>
#include <mutex>
#include "Valve.h"
#include "Time_Counter.h"
#include <string>
#include <stdbool.h>
#include "GTS_800_ACC2.h"

#define INPUT_NUM 32
#define OUTPUT_NUM 32


class Controller : public QObject
{
	Q_OBJECT

public:
	Controller(QObject *parent);
	~Controller();

public:
	bool Input[INPUT_NUM];
	bool Output[OUTPUT_NUM];
	bool myInputLogic[INPUT_NUM];
	bool myOutputLogic[OUTPUT_NUM];
	// ͨ�������ȡֵ
	long lGpiValue;

	std::thread controllerThread;
	std::mutex* mtx;
	QTextEdit *textEdit;
	GTS_800_ACC2 *gts_800;
	bool gts_800_Connected = false;
	bool AUTO_MODE = false;
	void initialize();
	void lauchControllerThread();
	void IORefresh();
	void logic_Circle();
	void close();

	//field device:
	bool start_button = false;
	bool home_button = false;
	bool moveToLoad_button = false;
	bool moveToMeasure_button = false;

	bool pc_done = false;

	bool step1_loadPart = false;
	bool step2_reload = false;
	Valve *solenoid_rotateStation;
	Time_Counter timer[10];

signals:
	void loadPartDone();
	void raiseAlarm(const char*, const char*);

};

