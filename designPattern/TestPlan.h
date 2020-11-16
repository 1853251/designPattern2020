#pragma once
#include "BaseClasses.h"
#include "TravelPlan.h"
/*���Եص�
* �̳���ָ�������������Ϊ������ʾʾ����ʵ����;
*/
class TestSpot : public CommandReceiver {
private:
	//��¼���ַ���
	std::string str;
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"test"
	* @return void
	*/
	TestSpot() : CommandReceiver("test") {}
protected:
	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "setStr") {
			std::string paramTag1 = sliceCommand(cmd);		//ͨ����Ƭ��ָ���õ�һ�������ı�ǩ
			removeBlank(cmd);								//�Ƴ�����ո�
			if (paramTag1 == "-s") {
				str = cmd;
				return true;
			}
			cmd = paramTag1 + " " + cmd;					//�����и��ָ��ƴ��ȥ
		}
		if (subCmd == "getStr") {
			std::cout << "str�д�������ǣ�" << str << std::endl;
			return true;
		}
		return false;
	}
	/*��ӡ����ָ��
	* ���ظ����麯��������level��ӡ��Ӧ��ʽ��ָ��Լ�������ָ��
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level) {
		__super::printHelp(level);				//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		level++;								//����ָ����ʾ����һ��
		std::string head(level * 3, '-');
		std::cout << head + "setStr -s:���洢���ַ���" << std::endl;	//�����ָ��
		std::cout << head + "getStr" << std::endl;	//�����ָ��
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	TestSpot(const TestSpot&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	TestSpot& operator=(const TestSpot&) = delete;
	/*��ȡ��ǰ������������
	* ��ȡȫ��Ψһ��ǰ��������ʵ�������ã�����ʵ�ֵ�����
	* @return TestSpot& ��ǰ������������
	*/
	static TestSpot& getInstance() {
		static TestSpot reciver;
		return reciver;
	}
};

/*���Լƻ�����
* �̳��ڳ���ƻ�����������Ϊ������ʾʾ����ʵ����;
*/
class TestPlanFactory : public AbstractPlanFactory {
public:
	/*����·��
	* @return Path* ���ɵ�·��
	*/
	Path* makePath() {
		Path* path = new Path();
		path->vehicle = "car";
		return path;
	}
	/*��������
	* @return Path* ���ɵ�����
	*/
	Description* makeDescription() {
		Description* des = new Description();
		des->content = "����һ���ɳ���ƻ����������ľ���ƻ������Ĳ�Ʒ����testPlan��\n\
			�ǹ���ģʽ�ͳ��󹤳�ģʽ��Ӧ�ã�\n\
			������TravelPlan.h�У�������TestPlan��";
		return des;
	}
	/*����Ŀ��ص�
	* @return Path* ���ɵ�Ŀ��ص�
	*/
	Spot* makeSpot() {
		Spot& spot = TestSpot::getInstance();
		return &spot;
	}
};

