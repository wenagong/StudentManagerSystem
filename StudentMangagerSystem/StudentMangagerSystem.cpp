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
			PrintStudent();
			break;
		case'3'://保存学生信息
			SaveStudent();
			break;
		case'4'://读取学生信息
			ReadStudent();
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
	printf("*\t\t4.读取学生信息\t\t\t*\n");
	printf("*\t\t5.统计所有学生信息\t\t*\n");
	printf("*\t\t6.查找学生信息\t\t\t*\n");
	printf("*\t\t7.修改学生信息\t\t\t*\n");
	printf("*\t\t8.删除学生信息\t\t\t*\n");
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
void PrintStudent() {
	printf("*************************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统v1.0\t*\n");
	printf("*************************************************\n");
	printf("*\t学号\t*\t姓名\t*\t年龄\t*\t成绩*\n");
	printf("*************************************************\n");

	//遍历列表
	Node *p = g_pHead;
	while (p != NULL) {
		printf("*\t%d\t*\t%s\t*\t%d\t*\t%d*\n",
			p->stu.stuNum,
			p->stu.name,
			p->stu.age,
			p->stu.score );
		p = p->pNext;
	}
	printf("*************************************************\n");
	system("pause");  //暂停
	system("cls");  //清屏
}
//保存学生信息
void SaveStudent() {
	//打开文件
	FILE *fp = fopen("stuinfo.txt","w");
	if (fp == NULL) {
		printf("打开文件失败.\n");
		return;
	}
	Node *p = g_pHead;
	while (p != NULL) {
		fwrite(&p->stu, 1, sizeof(Student),fp);
		p = p->pNext;
	}
	//关闭文件
	fclose(fp);
	printf("\n数据保存文件成功.\n");
	printf("*************************************************\n");
	system("pause");  //暂停
	system("cls");  //清屏
}
//读取学生信息
void ReadStudent() {
	FILE*fp = fopen("stuinfo.txt", "r");
	if (fp == NULL) {
		printf("打开文件失败.\n");
		return;
	}
	//读文件
	while (!feof(fp)) {
		//创建一个新节点
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		fread(&pNewNode->stu,1,sizeof(Student),fp);
		pNewNode->pNext = NULL;

		//头插法
		if (g_pHead == NULL) {
			g_pHead = pNewNode;
		}
		else {
			pNewNode->pNext = g_pHead;
			g_pHead = pNewNode;
		}
	}
	fclose(fp);
	printf("加载数据成功.\n");
	system("pause");
	system("cls");
}