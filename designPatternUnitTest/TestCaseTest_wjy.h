#pragma once
#include "pch.h"

//��namespace�����Է�ֹ������ͻ
namespace wjy {
	class TestMap :public testing::Test
	{
	public:
		std::string* str;
		static void SetUpTestCase()
		{
			std::cout << "SetUpTestCase" << std::endl;
		}
		static void TearDownTestCase()
		{
			std::cout << "TearDownTestCase" << std::endl;
		}
		virtual void SetUp()
		{
			str = new std::string("abaaba");
			std::cout << "SetUp" << std::endl;	
		}
		virtual void TearDown()
		{
			std::cout << "TearDown" << std::endl;
			S_DELETE(str);
		}
	};
	/*TEST_F��������һ�����Ե�Ԫ
	* ���Ե�ԪΪ���Ե���С��λ��ͨ��һ�����Ե�Ԫ��Ӧһ�����һ���ӿڣ�public�ĺ�����
	* @param param1 ���Ե�Ԫ��������������
	* @param param2 ���Ե�Ԫ��
	* ����Զ����ɼ̳���param1����Ϊparam1_param2���������ڲ���
	* �ʲ����������Ͳ��Ե�Ԫ���о����ܳ����»���
	*/
	TEST_F(TestMap, Compare)
	{
		//����param1��param2��ȣ��������ʱ��ֹ��������
		ASSERT_EQ(str->compare("abaaba"), 0);
	}
	TEST_F(TestMap, Size)
	{
		//�ڴ�param1��param2��ȣ��������ʱ�������λ�ú����飬�����������
		EXPECT_EQ(str->size(), 6);
	}
}
