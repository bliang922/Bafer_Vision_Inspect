#include "ProductionStatistic.h"

ProductionStatistic::ProductionStatistic()
{
	QStringList labels = QObject::trUtf8("ʱ���,����,OK��,NG��,�ϸ���,���").simplified().split(",");
	model_productData.setHorizontalHeaderLabels(labels);
//��ʼ��ÿСʱͳ�����ݽṹ
	for (int i = 0; i < 24; i++) {
		hour_statistic[i].total = 0;
		hour_statistic[i].ng_total = 0;
		hour_statistic[i].ok_rate = 0;
		hour_statistic[i].ok_total = 0;
		hour_statistic[i].shift = DAY_SHIFT;
	}

//����24��QList ��Ӧ24Сʱ��ÿ��list����һ�е���Ϣ������ʼ��ֵ
	for (int i = 0; i < 24; i++) {
		QStandardItem *colum1 = new QStandardItem(QString(time_section[i].data()));
		QStandardItem *colum2 = new QStandardItem(QString::QString(""));
		QStandardItem *colum3 = new QStandardItem(QString::QString(""));
		QStandardItem *colum4 = new QStandardItem(QString::QString(""));
		QStandardItem *colum5 = new QStandardItem(QString::QString(""));
		QStandardItem *colum6 = new QStandardItem(QString::QString(""));
		
		table_row_items[i].append(colum1);
		table_row_items[i].append(colum2);
		table_row_items[i].append(colum3);
		table_row_items[i].append(colum4);
		table_row_items[i].append(colum5);
		table_row_items[i].append(colum6);
		model_productData.appendRow(table_row_items[i]);
	}

	day_statistic.ng_total = 0;
	day_statistic.ok_rate = 0;
	day_statistic.ok_total = 0;
	day_statistic.total = 0;

	QStandardItem* colum1 = new QStandardItem(QString("�ϼ�"));
	QStandardItem* colum2 = new QStandardItem(QString::QString(""));
	QStandardItem* colum3 = new QStandardItem(QString::QString(""));
	QStandardItem* colum4 = new QStandardItem(QString::QString(""));
	QStandardItem* colum5 = new QStandardItem(QString::QString(""));
	QStandardItem* colum6 = new QStandardItem(QString::QString(""));

	table_row_items[24].append(colum1);
	table_row_items[24].append(colum2);
	table_row_items[24].append(colum3);
	table_row_items[24].append(colum4);
	table_row_items[24].append(colum5);
	table_row_items[24].append(colum6);

	model_productData.appendRow(table_row_items[24]);

}

//���ز�������ʱ��Сʱ ʱ���
int ProductionStatistic::getCurrentTimeSection() {
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct tm *t1=localtime(&now);
	
	return t1->tm_hour;
}

//�趨�װ�ҹ���ʱ�䷶Χ
void ProductionStatistic::setDayShiftRange(int start, int end) {
	dayShift_start = start;
	dayShift_end = end;
}

//��ȡ��ǰСʱ�İ��
WORK_SHIFT ProductionStatistic::getWorkShift(int hour) {
	if (dayShift_start <= hour <=dayShift_end) return DAY_SHIFT;
	else return NIGHT_SHIFT;
}


//������ģ�����һ����Ʒ���Ľ��
void ProductionStatistic::addOneProduct(const char * productModel, int result) {

	int current_our = getCurrentTimeSection();

	//����Ĳ�Ʒ���Ϊ�ϸ񣬸���ͳ������
	if (result == MEASURE_RESULT_OK) {
		hour_statistic[current_our].total++;
		hour_statistic[current_our].ok_total++;
		hour_statistic[current_our].ok_rate =
						hour_statistic[current_our].ok_total / hour_statistic[current_our].total * 100;
		day_statistic.total++;
		day_statistic.ok_total++;
		day_statistic.ok_rate = day_statistic.ok_total / day_statistic.total * 100;
	
	}
	//����Ĳ�Ʒ���Ϊ���ϸ񣬸���ͳ������
	else if (result == MEASURE_RESULT_NG) {
		hour_statistic[current_our].total++;
		hour_statistic[current_our].ng_total++;
		hour_statistic[current_our].ok_rate=
						hour_statistic[current_our].ok_total / hour_statistic[current_our].total * 100;

		day_statistic.total++;
		day_statistic.ng_total++;
		day_statistic.ok_rate = day_statistic.ok_total / day_statistic.total * 100;
	}


	table_row_items[current_our].at(0)->setText(time_section[current_our].data());
	//printf(table_row_items[current_our].at(0)->data());
	table_row_items[current_our].at(1)->setText(QString::number(hour_statistic[current_our].total));
	table_row_items[current_our].at(2)->setText(QString::number(hour_statistic[current_our].ok_total));
	table_row_items[current_our].at(3)->setText(QString::number(hour_statistic[current_our].ng_total));
	table_row_items[current_our].at(4)->setText(QString::number(hour_statistic[current_our].ok_rate)+"%");
	if(hour_statistic[current_our].shift==DAY_SHIFT)
		table_row_items[current_our].at(5)->setText("�װ�");
	else if(hour_statistic[current_our].shift == NIGHT_SHIFT)
		table_row_items[current_our].at(5)->setText("ҹ��");



	//���¼������һ�е�ͳ��������
	//printf(table_row_items[current_our].at(0)->data());

	table_row_items[24].at(1)->setText(QString::number(day_statistic.total));
	table_row_items[24].at(2)->setText(QString::number(day_statistic.ok_total));
	table_row_items[24].at(3)->setText(QString::number(day_statistic.ng_total));
	table_row_items[24].at(4)->setText(QString::number(day_statistic.ok_rate) + "%");

}

