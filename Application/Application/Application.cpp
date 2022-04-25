#include "Application.h"

Application::Application(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

/*******************************************Image process Initialize*******************************************************************/

	//connect button commands to slots
	connect(ui.btn_startGrab, SIGNAL(clicked()), this, SLOT(btn_startGrab_clicked()));
	connect(ui.btn_stopGrab, SIGNAL(clicked()), this, SLOT(btn_stopGrab_clicked()));
	//	connect(ui.actionZoomIn, SIGNAL(triggered()), this, SLOT(zoomIn_clicked()));
	//	connect(ui.actionZoomOut, SIGNAL(triggered()), this, SLOT(zoomOut_clicked()));
	//	connect(ui.actionNormalSize, SIGNAL(triggered()), this, SLOT(normalSize_clicked()));
	connect(ui.exitButton, SIGNAL(clicked()), this, SLOT(exitButton_clicked()));
	connect(ui.btn_saveImage, SIGNAL(clicked()), this, SLOT(saveImageButton_clicked()));
	connect(ui.btn_reset, SIGNAL(clicked()), this, SLOT(resetButton_clicked()));
	//connect(ui.btn_light, SIGNAL(clicked()), this, SLOT(lightButton_clicked()));
	//connect(ui.btn_LED1, SIGNAL(clicked()), this, SLOT(LED1Button_clicked()));
	//connect(ui.btn_LED2, SIGNAL(clicked()), this, SLOT(LED2Button_clicked()));
	connect(ui.btn_rotate, SIGNAL(clicked()), this, SLOT(rotateButton_clicked()));
	connect(ui.Btn_Axile1_Enable, SIGNAL(clicked()), this, SLOT(Btn_Axile1_Enable_clicked()));
	connect(ui.Btn_JogIncrease, SIGNAL(pressed()), this, SLOT(Btn_JogIncrease_pressed()));
	connect(ui.Btn_JogIncrease, SIGNAL(released()), this, SLOT(Btn_JogIncrease_released()));
	connect(ui.Btn_JogDecrease, SIGNAL(pressed()), this, SLOT(Btn_JogDecrease_pressed()));
	connect(ui.Btn_JogDecrease, SIGNAL(released()), this, SLOT(Btn_JogDecrease_released()));

	connect(ui.Btn_Home, SIGNAL(clicked()), this, SLOT(Btn_Home_clicked()));
	connect(ui.Btn_LoadPos, SIGNAL(clicked()), this, SLOT(Btn_LoadPos_clicked()));
	connect(ui.Btn_MeasurePos, SIGNAL(clicked()), this, SLOT(Btn_MeasurePos_clicked()));

	//	connect(camera,SIGNAL(sendGrabResultSigal(CGrabResultPtr)), this, SLOT(imageGrabbed(CGrabResultPtr)));

	//ui.label->setFixedHeight(531);
	//ui.label->setFixedWidth(591);
	imageLabel[0] = ui.label;
	HTuple handle;
	//create window handles
	for (int i = 0; i < DEVICE_NUM; i++) {
		windowID[i] = imageLabel[i]->winId();
		//	windowID[0] = ui.label->winId();

		OpenWindow(0, 0, ui.label->width(), ui.label->height(), windowID[i], "visible", "", &windowHandle[i]);

		SetLineWidth(windowHandle[i], 2);
		SetColor(windowHandle[i], "red");
		int height = imageLabel[i]->height();
		int width = imageLabel[i]->width();
		//SetPart(windowHandle[0], 0, 0, height, width);

	}

	camera[0] = new TeleDyneCamera(NULL);
	camera[0]->textEdit = ui.textEdit_status;
	camera[0]->mtx = &mtx_camera;

	//set HMI camera status icon color

	if (camera[0]->initialize()) {
		ui.textEdit_status->append("camera initialize success.");
	}
	else {
		ui.textEdit_status->append("camera initialize failed.");
	}

	if (camera[0]->isOpened)   ui.Indicator_Camera->setStyleSheet("background-color:rgb(0,255,127)");
	else ui.Indicator_Camera->setStyleSheet("background-color:rgb(128,138,135)");



	//if (camera[1]->m_bOpenDevice)  ui.Indicator_Camera2->setStyleSheet("background-color:rgb(0,255,127)");
	//else ui.Indicator_Camera2->setStyleSheet("background-color:rgb(128,138,135)");
	//if (camera[2]->m_bOpenDevice)  ui.Indicator_Camera3->setStyleSheet("background-color:rgb(0,255,127)");
	//else ui.Indicator_Camera3->setStyleSheet("background-color:rgb(128,138,135)");

/*******************************************ModbusTCP communication Initialize*******************************************************************/


/*******************************************SQLite Initialize*******************************************************************/
		////show table grid 
		//ui.table_static1->setShowGrid(true);
		////set table grid line to DashLine or DotLine
		//ui.table_static1->setGridStyle(Qt::DashLine);
		//ui.table_static1->setSortingEnabled(true);
		//model_sql_data = new QStandardItemModel();
		//QStringList labels_2 = QObject::trUtf8("TIME,TOTAL,OK_TOTAL,NG_TOTAL,OK_RATE,SHIFT").simplified().split(",");
		//model_sql_data->setHorizontalHeaderLabels(labels_2);

		//ui.table_static1->setModel(model_sql_data);
		//ui.table_static1->setShowGrid(true);
		//ui.table_static1->show();

	ui.table_statistic->setModel(&product_stat.model_productData);
	sql = new SQLite(NULL);
	sql->textEdit = ui.textEdit_status;
	sql->mtx = &this->mtx_sql;

	connect(sql, &SQLite::sendQueryResult, this, &Application::query_returned);

	sql->initialize();

	if (sql->sql_open)
		ui.Indicator_Database->setStyleSheet("background-color:rgb(0,255,127)");
	else ui.Indicator_Database->setStyleSheet("background-color:rgb(128,138,135)");


	//show table grid 
	ui.table_statistic->setModel(&product_stat.model_productData);
	ui.table_statistic->setShowGrid(true);
	ui.table_statistic->show();

/*******************************************GTS_800 Module Initialize*******************************************************************/
	model_alarms = new QStandardItemModel();
	QStringList labels2 = QObject::trUtf8("Time,Device,Discript").simplified().split(",");
	model_alarms->setHorizontalHeaderLabels(labels2);
	ui.table_alarm->setModel(model_alarms);
	ui.table_alarm->setShowGrid(true);

	ui.table_alarm->show();
	
	controller = new Controller(NULL);
	connect(controller, &Controller::HMI_update, this, &Application::controller_data_update);
	connect(controller, &Controller::raiseAlarm, this, &Application::showAlarm);

	controller->mtx = &this->mtx_ioc0640;
	controller->textEdit = ui.textEdit_status;
	controller->pc_done = true;

	int rt=controller->initialize();

	if (!rt) {
		ui.textEdit_status->append("gts_800 initialize failed");

	}
	else {
		controller->gts_800_Connected = true;
		//solenoid_rotateStation = new Valve((char*)"valve1", &timer[0], 5000);
		ui.textEdit_status->append(QString::QString("gts_800 initialize success"));
	}
	controller->lauchControllerThread();
}





/*******************************************Image *******************************************************************/
void Application::exitButton_clicked() {

	QApplication::quit();
}

void Application::resetButton_clicked() {

	//ioc0640->solenoid_rotateStation->cmdReset = true;
	for (int i = 0; i < AXIS_NUM; i++) {
	
		controller->axis[i]->reset();

	}
	//change the alarm texts back to normal
	for (int i = 0; i < model_alarms->rowCount(); i++) {
		for (int j = 0; j < model_alarms->columnCount(); j++) {
			if (model_alarms->item(i, j)->foreground().color() == red)
				model_alarms->item(i, j)->setForeground(black);
		}

	}
}

void Application::saveImageButton_clicked() {

	for (int i = 0; i < DEVICE_NUM; i++) {
			std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

			std::string s(30, '\0');
			std::strftime(&s[0], s.size(), "%Y%m%d_%H%M%S", std::localtime(&now));

			//WriteImage(image[i], "bmp", 0, "D:\\Projects\\BackLightInspect\\QWidget_Halcon_LoadImage\\pic\\pic1.bmp" );

			string filename = ".\\pic\\camera" + std::to_string(i) + "_" + s;
			const char * p = filename.data();
			WriteImage(image[i], "bmp", 0, (HTuple)(p));
			ui.textEdit_status->append(QString::QString("Camera ") + std::to_string(i).data() + " Save Image Success!");

	}

}

void Application::btn_startGrab_clicked() {
	camera[0]->startGrab();

}

void Application::btn_stopGrab_clicked()
{
	camera[0]->stopGrab();
}


void Application::Btn_Axile1_Enable_clicked() {
	
	if(controller->axis[0]->enable==false)
	controller->axis[0]->enableAxis();
	else controller->axis[0]->disableAxis();

}

void Application::Btn_JogIncrease_pressed() {

	controller->axis[0]->jogIncrease();
}

void Application::Btn_JogIncrease_released() {

	controller->axis[0]->jogStop();

}

void Application::Btn_JogDecrease_pressed() {
	controller->axis[0]->jogDecrease();


}

void Application::Btn_JogDecrease_released() {

	controller->axis[0]->jogStop();

}

void Application::Btn_Home_clicked() {

	controller->axis[0]->homePosition();

}

void Application::Btn_LoadPos_clicked() {

	controller->axis[0]->MoveToPos( LOAD_POSITION, LOAD_UNLOAD_VELOCITY);
}

void Application::Btn_MeasurePos_clicked() {

	controller->axis[0]->MoveToPos(MEASURE_POSITION, LOAD_UNLOAD_VELOCITY);
}

void Application::imageGrabbed(uint8_t * imgBufferPtr, int imgWidth, int imgHeight, int cameraNum) {

	//Basler Camera
	/*//ֱ����halcon����ת��ΪHObject ��ʽ	(������ֻ���õ���ͨ��)
	 const uint8_t *pImageBuffer = (uint8_t *)ptrGrabResult->GetBuffer();
	GenImage1(&image, "byte", (Hlong)ptrGrabResult->GetWidth(), (Hlong)ptrGrabResult->GetHeight(), (Hlong)pImageBuffer);
	GetImageSize(image, &imgWidth, &imgHeight);*/

	//Luster Camera
	GenImage1(&image[cameraNum], "byte", (Hlong)imgWidth, (Hlong)imgHeight, (Hlong)imgBufferPtr);
	//WriteImage(img, 'tiff', 0, "D://1.tif");
	//WriteImage(image[cameraNum], "bmp", 0, "D:\\1.bmp");
	SetPart(windowHandle[cameraNum], 0, 0, imgHeight, imgWidth);

	if (image[cameraNum].IsInitialized()) {

		DispObj(image[cameraNum], windowHandle[cameraNum]);
		algorithm[cameraNum]->image = image[cameraNum];
		algorithm[cameraNum]->lauchCamera_Thread();
		//algorithm[cameraNum]->processImage();
	}

}

void Application::showImage(int cameraNum) {


	DispObj(algorithm[cameraNum]->imageInvert, windowHandle[cameraNum]);
}

/*******************************************SQLite*******************************************************************/
void Application::query_returned(int argc, char **argv, char **azColName) {

	QStandardItem *item = 0;

	//int i;
//for (i = 0; i < argc; i++) {
//	printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//}
//printf("\n");


	//for (int i = 0; i < argc; i++) {

	//	item = new QStandardItem(QString::QString(argv[i]));
	//	model_sql_data->setItem(sql->resultCount, i, item);
	//}
	//sql->resultCount++;
//	ui.table_static1->update();
}




/*******************************************Contorller*******************************************************************/

void Application::measure() {

	this->btn_startGrab_clicked();
	product_stat.addOneProduct(std::string("LCM01").data(), MEASURE_RESULT_OK);
	controller->pc_done = true;
	//ui.table_statistic->update();
}

void Application::controller_data_update() {
	ui.label_pos->setText(QString::number(controller->axis[0]->prfPos));
	ui.label_encPos->setText(QString::number(controller->axis[0]->encPos));

	bitset<32> bits(controller->axis[0]->status);

	if (controller->axis[0]->enable)
				ui.Btn_Axile1_Enable->setStyleSheet("background-color:green");
	else ui.Btn_Axile1_Enable->setStyleSheet("background-color:white");

	//32λstatus�ֵ�һλ ��������������5λ-����λ����6λ-����λ
	if(controller->axis[0]->status& 0x02)
		ui.toolButton_1->setStyleSheet("background-color:red");
	else ui.toolButton_1->setStyleSheet("background-color:white");

	if (controller->axis[0]->status & 0x020)
		ui.toolButton_2->setStyleSheet("background-color:red");
	else ui.toolButton_2->setStyleSheet("background-color:white");	
	
	if (controller->axis[0]->status & 0x040)
		ui.toolButton_3->setStyleSheet("background-color:red");
	else ui.toolButton_3->setStyleSheet("background-color:white");
}

void Application::rotateButton_clicked() {
	controller->AUTO_MODE = false;

	if (controller->solenoid_rotateStation->in_closed)
		controller->step1_loadPart = true;
	else if (controller->solenoid_rotateStation->in_opened)
		controller->step2_reload = true;
}

void Application::showAlarm(const char* deviceName, const char* discription) {

	QList<QStandardItem *> items;	//QList is the list of items in one row in the model_alarms

	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	std::string s(30, '\0');
	std::strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

	QStandardItem *time = new QStandardItem(QString::fromStdString(s));
	time->setForeground(red);
	QStandardItem *device = new QStandardItem(QString::QString(deviceName));
	device->setForeground(red);
	QStandardItem *discrp = new QStandardItem(QString::QString(discription));
	discrp->setForeground(red);

	items.append(time);
	items.append(device);
	items.append(discrp);

	model_alarms->appendRow(items);


}
