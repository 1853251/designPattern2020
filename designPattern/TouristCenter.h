#pragma once
#include"BaseClasses.h"

#include"Consult.h"
#include"Adapter.h"
//�ο����� �� ��ѯ--���ģʽ / ��Ҷһ�--������ģʽ ��
class TouristCenter : public CommandReciver {
private:
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"tourist"
	* @return void
	*/
	TouristCenter() : CommandReciver("tourist") {}

protected:
	bool executeCommand(std::string cmd) {
		std::cout << cmd << std::endl;
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "consult") {
			std::cout << "��ѡ��Ҫ��ѯ�����ݣ�1Ϊ������Ŀ��2Ϊ԰����ʩ��3Ϊ��ʳס�ޣ� 0Ϊ���أ���\n";
			Facade* pFacade = new Facade();
			pFacade->start();
			return true;
		}
		else if (subCmd == "currency") {
			std::cout << "������Ҫ�һ��Ļ��������Լ��������Կո�ָ�, ��\"quit\"��������\n";
			Adapter* pAdapter = new Adapter();
			pAdapter->start();
			return true;
		}
		else
			return false;
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	TouristCenter(const TouristCenter&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	TouristCenter& operator=(const TouristCenter&) = delete;
	/*��ȡ��ǰ������������
	* ��ȡȫ��Ψһ��ǰ��������ʵ�������ã�����ʵ�ֵ�����
	* @return PlanManager& ��ǰ������������
	*/
	static TouristCenter& getInstance() {
		static TouristCenter reciver;
		return reciver;
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
		std::cout << head + "consult" << std::endl;						//�����ָ��
		std::cout << head + "currency" << std::endl;					//�����ָ��

	}
};