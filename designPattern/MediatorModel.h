#pragma once
#include <string>
#include <iostream>
#include "BaseClasses.h"
class Colleague;

class Mediator
{
public:
	virtual void send(std::string  msg, Colleague* p) = 0;
};

class Colleague
{
protected:
	Mediator* m_mediator;
public:
	Colleague(Mediator* p)
	{
		m_mediator = p;
	}
	virtual void send(std::string msg) = 0;
	virtual void notify(std::string msg) = 0;
};

class ConcreteColleague_0 : public Colleague
{
public:
	ConcreteColleague_0(Mediator* p) : Colleague(p) {}
	void send(std::string msg)
	{
		m_mediator->send(msg, this);
	}
	void notify(std::string msg)
	{
		std::cout << "���� �յ�����Ϣ��" << msg << std::endl;
	}
};

class ConcreteColleague_1 : public Colleague
{
public:
	ConcreteColleague_1(Mediator* p) : Colleague(p) {}
	void send(std::string msg)
	{
		m_mediator->send(msg, this);
	}
	void notify(std::string msg)
	{
		std::cout << "�ο� �յ�����Ϣ��" << msg << std::endl;
	}
};

class ConcreteMediator : public Mediator
{
private:
	// ����Ҳ������һ���б�
	Colleague* m_p1;
	Colleague* m_p2;
public:
	void addColleague(Colleague* p1, Colleague* p2)
	{
		m_p1 = p1;
		m_p2 = p2;
	}
	void send(std::string msg, Colleague* p)
	{
		// �����������һ��ͬ�·���������Ϣ������Ӧ�ø�˭Ҫ����������
		// ����֪ʶһ���ܼ򵥵�Ӧ�á���������ܿ��������������С�
		// һ�������ǿͻ���һ�������ǿͷ�
		if (p == m_p1)
			m_p2->notify(msg);
		else
			m_p1->notify(msg);
	}
};
class MediatorManager : public CommandReceiver {
private:
	std::string str;
	MediatorManager() : CommandReceiver("mediator") {}
protected:
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		ConcreteMediator* p = new ConcreteMediator();
		Colleague* pCol1 = new ConcreteColleague_0(p);
		Colleague* pCol2 = new ConcreteColleague_1(p);
		p->addColleague(pCol1, pCol2);
		removeBlank(cmd);
		if (subCmd == "make") {
			cout << "����-�н�-�ο��ѹ�����" << endl;
			return true;
		}
		else if (subCmd == "sendmessage") {
			std::string paramTag1 = sliceCommand(cmd);
			if ((paramTag1.length() != 1) || (paramTag1[0] != '1'&&paramTag1[0] != '2'))
				return false;
			int a1 = std::stoi(paramTag1);
			removeBlank(cmd);

			std::string paramTag2 = sliceCommand(cmd);
			removeBlank(cmd);
			if (a1 == 1)
			{
				pCol1->send(paramTag2);
			
			}
			if (a1 == 2)
				pCol2->send(paramTag2);
			return true;
		}
		else {
			return false;
		}
		
	}
	virtual void printHelp(int level) {
		__super::printHelp(level);
		level++;
		std::string head(level * 3, '-');
		std::cout << head + "make " << std::endl;	//�����ָ��
		std::cout << head + "sendmessage 1/2(���ͷ���1��������2�����ο�) message(Ҫ˵�Ļ�)" << std::endl;	//�����ָ��
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	MediatorManager(const MediatorManager&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	MediatorManager& operator=(const MediatorManager&) = delete;
	/*��ȡ��ǰ������������
	* ��ȡȫ��Ψһ��ǰ��������ʵ�������ã�����ʵ�ֵ�����
	* @return TestSpot& ��ǰ������������
	*/
	static MediatorManager& getInstance() {
		static MediatorManager reciver;
		return reciver;
	}
};