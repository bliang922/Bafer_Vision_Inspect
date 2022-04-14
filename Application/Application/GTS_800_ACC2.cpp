#include "GTS_800_ACC2.h"

bool GTS_800_ACC2::initialize() {
	
	// ���ָ��ִ�з���ֵΪ��0��˵��ָ��ִ�д���
	rt = 0;
	rt = GT_Open();
	if (rt) return false;
	rt= GT_Reset();
	if (rt) return false;
	char  configFilePath[] = ".\\config.cfg";

	//���ع̸��˶����ƿ��ŷ��������ļ�
	rt = GT_LoadConfig(configFilePath);
	if (rt) return false;
	rt = GT_ClrSts(1,2);//ʹloadConfigָ����Ч

	// ���ŷ�ʹ��
	rt = GT_AxisOn(AXIS1_LOAD);
	if (rt) return false;
	rt = GT_AxisOn(AXIS2_ROTATE);
	if (rt) return false;

	homePosition(AXIS1_LOAD);
	homePosition(AXIS2_ROTATE);

	if (rt) return false;
	else return true;
}

bool GTS_800_ACC2::homePosition(short axis) {
	// ����Home����
	rt = GT_SetCaptureMode(axis, CAPTURE_HOME);
	// �л�����λ�˶�ģʽ
	rt = GT_PrfTrap(axis);
	// ��ȡ��λģʽ�˶�����
	rt = GT_GetTrapPrm(axis, &trapPrm);
	trapPrm.acc = 0.25;
	trapPrm.dec = 0.25;
	// ���õ�λģʽ�˶�����
	rt = GT_SetTrapPrm(axis, &trapPrm);
	// ���õ�λģʽĿ���ٶȣ�����ԭ���ٶ�
	rt = GT_SetVel(axis, 10);
	// ���õ�λģʽĿ��λ�ã���ԭ����������
	rt = GT_SetPos(axis, SEARCH_HOME);
	// �����˶�
	rt = GT_Update(1 << (axis - 1));

	do
	{
		// ��ȡ��״̬
		GT_GetSts(axis, &status);
		// ��ȡ����״̬
		GT_GetCaptureStatus(axis, &capture, &pos);
		// ��ȡ�滮λ��
		GT_GetPrfPos(axis, &prfPos);
		// ��ȡ������λ��
		GT_GetEncPos(axis, &encPos);
		// ����˶�ֹͣ�����س�����Ϣ
		if (0 == (status & 0x400))
		{
			error = true;
			errorDiscript = "Homing failed.";
			return false;
		}
		// �ȴ����񴥷�
	} while (0 == capture);


	// �˶���"����λ��+ƫ����"
	rt = GT_SetPos(axis, pos+HOME_OFFSET);
	// ���˶�״̬�¸���Ŀ��λ��
	rt = GT_Update(1 << (axis - 1));

	do
	{
		// ��ȡ��״̬
		GT_GetSts(axis, &status);
		// ��ȡ�滮λ��
		GT_GetPrfPos(axis, &prfPos);
		// ��ȡ������λ��
		GT_GetEncPos(axis, &encPos);
		// �ȴ��˶�ֹͣ
	} while (status & 0x400);
	// ����Ƿ񵽴�"Home����λ��+ƫ����"
	if (prfPos != pos + HOME_OFFSET)
	{
		error = true;
		errorDiscript = "Axis move to position failed.";
		return false;
	}
	// ��ʱһ��ʱ�䣬�ȴ����ͣ��
	std::this_thread::sleep_for(std::chrono::milliseconds(200));

	// λ������
	rt = GT_ZeroPos(axis);
	// ��ȡ�滮λ��
	rt = GT_GetPrfPos(axis, &prfPos);
	// ��ȡ������λ��
	rt = GT_GetEncPos(axis, &encPos);
	// ��ȡaxis�滮λ��
	rt = GT_GetAxisPrfPos(axis, &axisPrfPos);
	// ��ȡaxis������λ��
	rt = GT_GetAxisEncPos(axis, &axisEncPos);
	return true;

}

void GTS_800_ACC2::close() {
	// �ŷ��ر�

	GT_AxisOff(AXIS1_LOAD);
	GT_AxisOff(AXIS2_ROTATE);

}


bool GTS_800_ACC2::MoveToPos(short axis,double position,double velocity) {
	rt = 0;
	rt = GT_SetCaptureMode(axis, CAPTURE_INDEX);
	// �л�����λ�˶�ģʽ
	rt = GT_PrfTrap(axis);
	// ��ȡ��λģʽ�˶�����
	rt = GT_GetTrapPrm(axis, &trapPrm);
	trapPrm.acc = 0.25;
	trapPrm.dec = 0.25;
	// ���õ�λģʽ�˶�����
	rt = GT_SetTrapPrm(axis, &trapPrm);
	// ���õ�λģʽĿ���ٶȣ�����ԭ���ٶ�
	rt = GT_SetVel(axis, velocity);
	// ���õ�λģʽĿ��λ�ã���ԭ����������
	rt = GT_SetPos(axis, position);
	// �����˶�
	rt = GT_Update(1 << (axis - 1));

	do
	{
		// ��ȡAXIS���״̬
		GT_GetSts(axis, &status);
		// ��ȡAXIS��Ĺ滮λ��
		GT_GetPrfPos(axis, &prfPos);
	} while (status & 0x400);	// �ȴ�AXIS��滮ֹͣ

	if (prfPos != position) {
		error = true;
		errorDiscript = "Move to position failed.";
		return false;
	}
	else return true;
}