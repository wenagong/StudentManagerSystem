// StudentMangagerSystem.cpp: 定义控制台应用程序的入口点。
//
#include"StudentManagerSystem.h"

int main()
{
	while (1) {
		Welcome();

		//从键盘接受一个字符
		//scanf
		//getch
		//getchar();
		char ch = _getch(); //需要读取字符

		switch (ch) 
		{
		case'1'://录入学生信息
			InputStudent();
			break;
		case'2'://打印学生信息
			break;
		case'3'://保存学生信息
			break;
		case'4'://读取学生信息
			break;
		case'5'://统计学生信息
			break;
		case'6'://查找学生信息
			break;
		case'7'://修改学生信息
			break;
		case'8'://删除学生信息
			break;
		case'0'://退出系统
			break;
		}
	}
    return 0;
}

void Welcome() {
	printf("*************************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统v1.0\t*\n");
	printf("*************************************************\n");
	printf("*\t\t请选择功能列表\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.录入学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");
	printf("*\t\t3.保存学生信息\t\t\t*\n");
	printf("*\t\t4.统计学生信息\t\t\t*\n");
	printf("*\t\t5.查找学生信息\t\t\t*\n");
	printf("*\t\t6.修改学生信息\t\t\t*\n");
	printf("*\t\t7.删除学生信息\t\t\t*\n");
	printf("*\t\t0.退出学生信息\t\t\t*\n");
	printf("*************************************************\n");
}
void InputStudent() {
	//创建一个新节点
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;

	//头插法、尾插法
	//头插法
	if (g_pHead == NULL) {
		g_pHead = pNewNode;
	}
	else {
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}

	printf("请输入学生姓名: \n");
	scanf("%s", pNewNode->stu.name);
	printf("请输入学生年龄: \n");
	scanf("%d", &pNewNode->stu.age);
	printf("请输入学生学号: \n");
	scanf("%d", &pNewNode->stu.stuNum);
	printf("请输入学生成绩: \n");
	scanf("%d", &pNewNode->stu.score);
	printf("学生信息录入成功.  \n");
	
	system("pause");  //暂停
	system("cls");  //清屏

}