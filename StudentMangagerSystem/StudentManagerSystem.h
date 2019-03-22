#pragma once
#include "stdio.h"
#include<conio.h>
#include<stdlib.h>

//����һ��ѧ��
typedef struct _Student
{
	char name[20]; //����
	int age;  //����
	int stuNum; //ѧ��
	int score;  //�ɼ�
}Student;

//�ڵ�
typedef struct _Node
{
	Student stu;
	struct _Node* pNext; //ָ����һ���ڵ��ָ��
}Node;

//ͷ�ڵ�
Node *g_pHead = NULL;

//��ӭ
void Welcome();
//¼��ѧ����Ϣ
void InputStudent();
//��ӡѧ����Ϣ
void PrintStudent();
//����ѧ����Ϣ
void SaveStudent();
//��ȡѧ����Ϣ
void ReadStudent();