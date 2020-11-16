#pragma once

#include<iostream>
#include<sstream>
#include "FCurrency.h"

/**
 * ��������
 * ��Ϊ��ͬ����֮��һ�����������������ʹ�õĽӿ�ת��Ϊ���õĽӿ�
 */
class Adapter : public DPObject
{
public:
	/**
	 * �������๹�캯��
	 * �ڴ����µĹ���������ʱ�ֱ𴴽��µ���Ҷ���
	 */
	Adapter()
	{
		dollar = new Dollar;
		pound = new Pound;
		yen = new Yen;
	}
	/**
	 * ��������������
	 * �ڶ����������ڽ�����ֱ�ɾ�����ͷ���Ҷ���Ŀռ�
	 */
	~Adapter()
	{
		delete dollar;
		delete pound;
		delete yen;
	}
public:
	/**
	 * �ӿ�ת��
	 * ���մ���Ļ��ҽ��num���͵�ǰ��Ҫ���еĻ��Ҷһ��������situ
	 * @param num ��������
	 * @param situ �һ��������
	 * @return void
	 */
	void exchange(float num, int situ) {
		float mid;		//�м�ֵ
		float result;	//���ֵ
		switch (situ) {	//����situ�Ĳ�ͬ�Բ�ͬ��ʽʹ�ó����ӿ�
		case 44:	//������Ƿ�ʱ����ʾ
			cout << "��������ȷ�����\n";
			break;
		case 0:		//��������ת��ǰ�������ͬʱ����ʾ
		case 11:
		case 22:
		case 33:
			cout << "��ѡ��ͬ�Ļ��ң�" << endl;
			break;
		case 1:		//��Ԫ->Ӣ��
			mid = dollar->exchange(num, true);
			result = pound->exchange(mid, false);
			cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "Ӣ��" << endl;
			break;
		case 2:		//��Ԫ->��Ԫ
			mid = dollar->exchange(num, true);
			result = yen->exchange(mid, false);
			cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "��Ԫ" << endl;
			break;
		case 3:		//��Ԫ->�����
			result = dollar->exchange(num, true);
			cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "�����" << endl;
			break;
		case 10:	//Ӣ��->��Ԫ
			mid = pound->exchange(num, true);
			result = dollar->exchange(mid, false);
			cout << "�һ���ɣ�" << num << "Ӣ���Ѷһ�Ϊ" << result << "��Ԫ" << endl;
			break;
		case 12:	//Ӣ��->��Ԫ
			mid = pound->exchange(num, true);
			result = yen->exchange(mid, false);
			cout << "�һ���ɣ�" << num << "Ӣ���Ѷһ�Ϊ" << result << "��Ԫ" << endl;
			break;
		case 13:	//Ӣ��->�����
			result = pound->exchange(num, true);
			cout << "�һ���ɣ�" << num << "Ӣ���Ѷһ�Ϊ" << result << "�����" << endl;
			break;
		case 20:	//��Ԫ->��Ԫ
			mid = yen->exchange(num, true);
			result = dollar->exchange(mid, false);
			cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "��Ԫ" << endl;
			break;
		case 21:	//��Ԫ->Ӣ��
			mid = yen->exchange(num, true);
			result = pound->exchange(mid, false);
			cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "Ӣ��" << endl;
			break;
		case 23:	//��Ԫ->�����
			result = yen->exchange(num, true);
			cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "�����" << endl;
			break;
		case 30:	//�����->��Ԫ
			result = dollar->exchange(num, false);
			cout << "�һ���ɣ�" << num << "������Ѷһ�Ϊ" << result << "��Ԫ" << endl;
			break;
		case 31:	//�����->Ӣ��
			result = pound->exchange(num, false);
			cout << "�һ���ɣ�" << num << "������Ѷһ�Ϊ" << result << "Ӣ��" << endl;
			break;
		case 32:	//�����->��Ԫ
			result = yen->exchange(num, false);
			cout << "�һ���ɣ�" << num << "������Ѷһ�Ϊ" << result << "��Ԫ" << endl;
			break;
		default:
			cout << "��������ȷ�����\n";
			return;
		}
		return;
	}

	/**
	 * ��Ҹ�����
	 * ���մ���Ļ������ƣ����ض�Ӧ�ı���Ա�����������ʹ��
	 * @param string ��������
	 * @return int ��Ӧ�Ļ��ұ��
	 */
	int Transform(string c) {
		if (c == "dollar" || c == "��Ԫ")		//ͬʱ֧����Ӣ������
			return 0;
		else if (c == "pound" || c == "Ӣ��")
			return 1;
		else if (c == "yen" || c == "��Ԫ")
			return 2;
		else if (c == "RMB" || c == "�����")
			return 3;
		else			//�Ƿ������򷵻��쳣���
			return 4;
	}

	/**
	 * ���Ҷһ�����
	 * �������ɶ�Ӧ���û����棬���ղ������û������룬��ȷ������Ӧ�ĺ���
	 * @return void
	 */
	void start() {
		string input;		//�������
		float num;			//�������
		cout << "������Ҫ�һ��Ļ��������Լ�����:\n";		//���û������������ʾ
		cout << "(����\"�������� ���л��� �������\"�ĸ�ʽ, ��\"quit\"����)\n";
		cout << "(֧����Ԫ��Ӣ������Ԫ������ҵ��໥�һ�)" << endl;	
		while (getline(cin,input)) {	//ѭ����ȡ������ʵ����Ҷһ����ܿɶ��ʹ��
			if (input == "quit") {		//���û������˳�ʱ����ѭ����������ʾ
				cout << "�ɹ��˳����Ҷһ���" << endl;
				break;
			}
			string from, to;			//ת��ǰ��Ļ�����
			stringstream ss(input);		//����������ת��Ϊ��
			ss >> num >> from >> to;	//��ת�������л�ȡ�����е���������
			exchange(num, Transform(from)*10+Transform(to));	//��������ָ����ʽ���ݸ��һ�����
		}
	}

private:
	FCurrency *dollar;	//��Ԫ�����
	FCurrency *pound;	//Ӣ�������
	FCurrency *yen;		//��Ԫ�����
};