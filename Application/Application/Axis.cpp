#include "Axis.h"

Axis::Axis(const char *device_name,short axisNum) {
	this->axisNum = axisNum;
	this->device_name = device_name;
}

bool Axis::initialize() {
	rt = 0;
	rt = GT_ZeroPos(axisNum);
	rt = GT_AxisOn(axisNum);
	if (!rt) enable = true;
	if(!homePosition()) rt=1;
	if (rt) return false;
	else return true;
}

bool Axis::homePosition() {

	////// ����Home����
	//GT_SetCaptureMode(axisNum, CAPTURE_HOME);
	//// �л�����λ�˶�ģʽ
	//GT_PrfTrap(axisNum);
	//// ��ȡ��λģʽ�˶�����
	//rt = GT_GetTrapPrm(axisNum, &trapPrm);
	//trapPrm.acc = 0.25;
	//trapPrm.dec = 0.25;
	//// ���õ�λģʽ�˶�����
	//rt = GT_SetTrapPrm(axisNum, &trapPrm);
	//// ���õ�λģʽĿ���ٶȣ�����ԭ���ٶ�
	//rt = GT_SetVel(axisNum, 10);
	//// ���õ�λģʽĿ��λ�ã���ԭ����������
	//rt = GT_SetPos(axisNum, SEARCH_HOME);
	//// �����˶�
	//rt = GT_Update(1 << (axisNum - 1));

	//do
	//{
	//	// ��ȡ��״̬
	//	GT_GetSts(axisNum, &status);
	//	// ��ȡ����״̬
	//	GT_GetCaptureStatus(axisNum, &capture, &pos);
	//	// ��ȡ�滮λ��
	//	GT_GetPrfPos(axisNum, &prfPos);
	//	// ��ȡ������λ��
	//	GT_GetEncPos(axisNum, &encPos);
	//	// ����˶�ֹͣ�����س�����Ϣ
	//	if (0 == (status & 0x400))
	//	{
	//		error = true;
	//		errorDiscript = "Homing failed.";
	//		return false;
	//	}
	//	// �ȴ����񴥷�
	//} while (0 == capture);


	//// �˶���"����λ��+ƫ����"
	//rt = GT_SetPos(axisNum, pos+HOME_OFFSET);
	//// ���˶�״̬�¸���Ŀ��λ��
	//rt = GT_Update(1 << (axisNum - 1));

	//do
	//{
	//	// ��ȡ��״̬
	//	GT_GetSts(axisNum, &status);
	//	// ��ȡ�滮λ��
	//	GT_GetPrfPos(axisNum, &prfPos);
	//	// ��ȡ������λ��
	//	GT_GetEncPos(axisNum, &encPos);
	//	// �ȴ��˶�ֹͣ
	//} while (status & 0x400);
	//// ����Ƿ񵽴�"Home����λ��+ƫ����"
	//if (prfPos != pos + HOME_OFFSET)
	//{
	//	error = true;
	//	errorDiscript = "Axis move to position failed.";
	//	return false;
	//}
	//// ��ʱһ��ʱ�䣬�ȴ����ͣ��
	//std::this_thread::sleep_for(std::chrono::milliseconds(200));

	//// λ������
	//rt = GT_ZeroPos(axisNum);
	//// ��ȡ�滮λ��
	//rt = GT_GetPrfPos(axisNum, &prfPos);
	//// ��ȡ������λ��
	//rt = GT_GetEncPos(axisNum, &encPos);
	//// ��ȡaxis�滮λ��
	//rt = GT_GetAxisPrfPos(axisNum, &axisPrfPos);
	//// ��ȡaxis������λ��
	//rt = GT_GetAxisEncPos(axisNum, &axisEncPos);
	////return true;


	//GT_ClrSts(axisNum);
	//GT_SetPrfPos(axisNum, 0);
	//GT_AlarmOff(axisNum);
	//GT_LmtsOn(axisNum);
	//GT_Update(1 << (axisNum - 1));

	//GT_LmtSns(3);
	//GT_EncSns(1);
	//����Smart Home��ԭ�����
	GT_GetHomePrm(axisNum, &tHomePrm);
	tHomePrm.mode = 20;
	tHomePrm.moveDir = -1;
	tHomePrm.indexDir = -1;
	tHomePrm.edge = 0;
	tHomePrm.velHigh = vel_high;
	tHomePrm.velLow = vel_low;
	tHomePrm.acc = 5;
	tHomePrm.dec = 5;
	tHomePrm.smoothTime = 1;
	tHomePrm.searchHomeDistance = 0;
	tHomePrm.searchIndexDistance = 0;
	tHomePrm.escapeStep = 0;
	tHomePrm.homeOffset = home_offset;
	rt = GT_GoHome(axisNum, &tHomePrm);

	step_home = true;
	//do {
	//	GT_GetHomeStatus(axisNum,&tHomeSts);
	//} while (tHomeSts.run);
	//GT_ZeroPos(axisNum);
	return true;
}

//�趨���˶�ģʽ
void Axis::jogStop() {
	GT_Stop(1<<axisNum-1,1<<axisNum-1);

}


void Axis::jogIncrease() {

	// ��AXIS����ΪJogģʽ
	GT_PrfJog(axisNum);
	// ��ȡJog�˶�����
	GT_GetJogPrm(axisNum, &jog);
	jog.acc = 0.0625;
	jog.dec = 0.0625;
	GT_SetJogPrm(axisNum, &jog);
	
	GT_SetVel(axisNum, vel_jog);
	GT_Update(1 << (axisNum - 1));

}

void Axis::jogDecrease() {

	// ��AXIS����ΪJogģʽ
	GT_PrfJog(axisNum);
	// ��ȡJog�˶�����
	GT_GetJogPrm(axisNum, &jog);
	jog.acc = 0.0625;
	jog.dec = 0.0625;
	GT_SetJogPrm(axisNum, &jog);

	GT_SetVel(axisNum, -vel_jog);
	GT_Update(1 << (axisNum - 1));

}
void Axis::reset() {

	GT_ClrSts(axisNum);
}
void Axis::enableAxis() {

	if (GT_AxisOn(axisNum) == 0) enable = true;
}

void Axis::disableAxis() {

	if (GT_AxisOff(axisNum) == 0) enable = false;
}


bool Axis::MoveToPos(double position,double velocity) {
	rt = 0;
	pos = position;
	rt = GT_SetCaptureMode(axisNum, CAPTURE_INDEX);
	// �л�����λ�˶�ģʽ
	rt = GT_PrfTrap(axisNum);
	// ��ȡ��λģʽ�˶�����
	rt = GT_GetTrapPrm(axisNum, &trapPrm);
	trapPrm.acc = 5;
	trapPrm.dec = 5;
	// ���õ�λģʽ�˶�����
	rt = GT_SetTrapPrm(axisNum, &trapPrm);
	// ���õ�λģʽĿ���ٶȣ�����ԭ���ٶ�
	rt = GT_SetVel(axisNum, velocity);
	// ���õ�λģʽĿ��λ�ã���ԭ����������
	rt = GT_SetPos(axisNum, position);
	// �����˶�
	rt = GT_Update(1 << (axisNum - 1));
	step_p2p = true;
	step_p2p_done = false;
	//do
	//{
	//	// ��ȡAXIS���״̬
	//	GT_GetSts(axisNum, &status);
	//	// ��ȡAXIS��Ĺ滮λ��
	//	GT_GetPrfPos(axisNum, &prfPos);
	//} while (status & 0x400);	// �ȴ�AXIS��滮ֹͣ


	 return true;
}

void Axis::run() {
	if (step_home) {
	
		GT_GetHomeStatus(axisNum, &tHomeSts);
		
		if (!tHomeSts.run) {
			GT_ZeroPos(axisNum);
			step_home = false;
			in_home_pos = true;
		}
	}

	if (step_p2p) {
		// ��ȡAXIS���״̬
		GT_GetSts(axisNum, &status);
		// ��ȡAXIS��Ĺ滮λ��
		GT_GetPrfPos(axisNum, &prfPos);

		if (!(status & 0x400)) {
			step_p2p = false;
			step_p2p_done = true;
			if (prfPos != pos) {
				error = true;
				errorDiscript = "Move to position failed.";
			}
		} 
	}

	// ��ȡ�滮λ��
	rt = GT_GetPrfPos(axisNum, &prfPos);
	// ��ȡ������λ��
	rt = GT_GetEncPos(axisNum, &encPos);
	// ��ȡAXIS���״̬
	GT_GetSts(axisNum, &status);
}