#include<iostream>
#include<vector>
#include "BaseClasses.h"
using namespace std;
//Observer.h
class Observer
{
public:
	Observer() {};
	virtual ~Observer()
	{

	};
	virtual void update() = 0;

};

//Subject.h
class Subject
{
public:
	Subject() {};
	virtual ~Subject() {};
	void addObserver(Observer* observer);
	void deleteObserver(Observer* observer);
	void notifyObservers();
	virtual int getStatus() = 0;

	virtual void setStatus(int status) = 0;
private:
	vector<Observer*> m_observers;
};
//Subject.cpp
void Subject::addObserver(Observer* observer)
{
	m_observers.push_back(observer);
}
void Subject::deleteObserver(Observer* observer)
{
	for (vector<Observer*>::iterator iter = m_observers.begin(); iter != m_observers.end(); iter++)
	{
		if (*iter == observer)
		{
			m_observers.erase(iter);
			return;
		}
	}
}
void Subject::notifyObservers() {
	for (vector<Observer*>::iterator iter = m_observers.begin(); iter != m_observers.end(); iter++)
	{
		(*iter)->update();
	}
}
//ConcreteObserver.h
class ConcreteObserver : public Observer
{
public:
	ConcreteObserver(string name, Subject* subject) :m_observerName(name), m_subject(subject) {};
	~ConcreteObserver() {};
	void update();

private:
	string m_observerName;
	Subject* m_subject;
};
//ConcreteSubject.h
class ConcreteSubject : public Subject
{
public:
	ConcreteSubject(string name) : m_subjectName(name) {};
	~ConcreteSubject() {};
	void setStatus(int status);
	int getStatus();

private:
	string m_subjectName;
	int m_status = 0;
};
//ConcreteObserver.cpp
void ConcreteObserver::update()
{
	cout << m_observerName << "����״̬Ϊ" << m_subject->getStatus() << endl;
}
//ConcreteSubject.cpp
void ConcreteSubject::setStatus(int status)
{
	m_status = status;
	cout << m_subjectName << "����״̬Ϊ" << status << endl;
}
int ConcreteSubject::getStatus()
{
	return m_status;
}

Subject* subject1 = new ConcreteSubject("ѩ��1");
Subject* subject2 = new ConcreteSubject("ѩ��2");


//���ó�ʼ״̬ ѩ������ �۲�������ĸ���ÿ���۲���ֻ�ܹ۲�һ��ѩ��
void setInit(int x, int a[4])
{
	for (int i = 0; i < x; i++)
	{
		if (i == 0)
		{
			if (a[i] == 1)
			{
				Observer* observerA = new ConcreteObserver("�۲���A", subject1);
				subject1->addObserver(observerA);
				cout << "�۲���A�۲�ѩ��1" << endl;
			}
			else if (a[i] == 2)
			{
				Observer* observerA = new ConcreteObserver("�۲���A", subject2);
				subject2->addObserver(observerA);
				cout << "�۲���A�۲�ѩ��2" << endl;
			}
		}
		if (i == 1)
		{
			if (a[i] == 1)
			{
				Observer* observerB = new ConcreteObserver("�۲���B", subject1);
				subject1->addObserver(observerB);
				cout << "�۲���B�۲�ѩ��1" << endl;
			}
			else if (a[i] == 2)
			{
				Observer* observerB = new ConcreteObserver("�۲���B", subject2);
				subject2->addObserver(observerB);
				cout << "�۲���B�۲�ѩ��2" << endl;
			}
		}
		if (i == 2)
		{
			if (a[i] == 1)
			{
				Observer* observerC = new ConcreteObserver("�۲���C", subject1);
				subject1->addObserver(observerC);
				cout << "�۲���C�۲�ѩ��1" << endl;
			}
			else if (a[i] == 2)
			{
				Observer* observerC = new ConcreteObserver("�۲���C", subject2);
				subject2->addObserver(observerC);
				cout << "�۲���C�۲�ѩ��2" << endl;
			}
		}
		if (i == 3)
		{
			if (a[i] == 1)
			{
				Observer* observerD = new ConcreteObserver("�۲���D", subject1);
				subject1->addObserver(observerD);
				cout << "�۲���D�۲�ѩ��1" << endl;
			}
			else if (a[i] == 2)
			{
				Observer* observerD = new ConcreteObserver("�۲���D", subject2);
				subject2->addObserver(observerD);
				cout << "�۲���D�۲�ѩ��2" << endl;
			}
		}
	}
}
void setStatus(int sx, int status)
{
	if (sx == 1)
	{
		subject1->setStatus(status);
		subject1->notifyObservers();
	}
	if (sx == 2)
	{
		subject2->setStatus(status);
		subject2->notifyObservers();

	}
}
class SnowmanManager : public CommandReceiver {
private:
	std::string str;
	SnowmanManager() : CommandReceiver("snowman") {}
protected:
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "make") {
			if (cmd == "")
				return false;
			int a[4];
			std::string paramTag1 = sliceCommand(cmd);
			if ((paramTag1.length() != 1) || (paramTag1[0] != '1'&&paramTag1[0] != '2'))
				return false;
			a[0] = std::stoi(paramTag1);
			removeBlank(cmd);
			std::string paramTag2 = sliceCommand(cmd);
			if ((paramTag2.length() != 1) || (paramTag2[0] != '1'&&paramTag2[0] != '2'))
				return false;
			a[1] = std::stoi(paramTag2);
			removeBlank(cmd);
			std::string paramTag3 = sliceCommand(cmd);
			if ((paramTag3.length() != 1) || (paramTag3[0] != '1'&&paramTag3[0] != '2'))
				return false;
			a[2] = std::stoi(paramTag3);
			removeBlank(cmd);
			std::string paramTag4 = sliceCommand(cmd);
			if ((paramTag4.length() != 1) || (paramTag4[0] != '1'&&paramTag4[0] != '2'))
				return false;
			a[3] = std::stoi(paramTag4);
			removeBlank(cmd);
			if ((a[0] != 1 && a[0] != 2) || (a[1] != 1 && a[1] != 2) || (a[2] != 1 && a[2] != 2) || (a[3] != 1 && a[3] != 2))
				return false;

			setInit(4, a);
			return true;
		}
		if (subCmd == "update") {
			if (cmd == "")
				return false;
			std::string paramTag1 = sliceCommand(cmd);
			if ((paramTag1.length() != 1) || (paramTag1[0] != '1'&&paramTag1[0] != '2'))
				return false;
			int a1 = std::stoi(paramTag1);
			removeBlank(cmd);
			std::string paramTag2 = sliceCommand(cmd);
			if ((paramTag2.length() != 1) || (paramTag2[0] < '0'&&paramTag2[0] > '9'))
				return false;
			int a2;
			
			a2 = std::stoi(paramTag2);
			removeBlank(cmd);
			if (a1 != 1 && a1 != 2)
				return false;

			setStatus(a1, a2);
			return true;
		}
		return false;
	}
	virtual void printHelp(int level) {
		__super::printHelp(level);
		level++;
		std::string head(level * 3, '-');
		std::cout << head + "make int1 int2 int3 int4(�ĸ�intֵ��Ϊ1��2�������ĸ��۲��߷ֱ�۲��ĸ�ѩ��)" << std::endl;	//�����ָ��
		std::cout << head + "update int1(ѩ�˱��1��2) int2(����ѩ��״̬0~9)" << std::endl;	//�����ָ��
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	SnowmanManager(const SnowmanManager&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	SnowmanManager& operator=(const SnowmanManager&) = delete;
	/*��ȡ��ǰ������������
	* ��ȡȫ��Ψһ��ǰ��������ʵ�������ã�����ʵ�ֵ�����
	* @return TestSpot& ��ǰ������������
	*/
	static SnowmanManager& getInstance() {
		static SnowmanManager receiver;
		return receiver;
	}
};
