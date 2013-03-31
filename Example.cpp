// win_cDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "ICTCLAS2011.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef OS_LINUX
#pragma comment(lib, "ICTCLAS2011.lib")
#endif

//Linux
#ifdef OS_LINUX
	#define _stricmp(X,Y) strcasecmp((X),(Y))
	#define _strnicmp(X,Y,Z) strncasecmp((X),(Y),(Z))
	#define strnicmp(X,Y,Z)	strncasecmp((X),(Y),(Z))
	#define _fstat(X,Y)     fstat((X),(Y))
	#define _fileno(X)     fileno((X))
	#define _stat           stat
	#define _getcwd         getcwd
	#define _off_t          off_t
	#define PATH_DELEMETER  "/"
#else
	#pragma warning(disable:4786)
	#define PATH_DELEMETER  "\\"
#endif
void SplitGBK(const char *sInput);
void SplitBIG5();
void SplitUTF8();

void SplitGBK(const char *sInput)
{//�ִ���ʾ

	//��ʼ���ִ����
	if(!ICTCLAS_Init())//�����ڵ�ǰ·���£�Ĭ��ΪGBK����ķִ�
	{
		printf("ICTCLAS INIT FAILED!\n");
		return ;
	}

	ICTCLAS_SetPOSmap(ICT_POS_MAP_SECOND);

	char sSentence[2000]="��ǹ�İ������������Ա��������ס�С���������ݵȣ�����Ϊ����ı";
	const char * sResult;

	int nCount;
	ICTCLAS_ParagraphProcessA(sSentence,&nCount);
	printf("nCount=%d\n",nCount);

	ICTCLAS_AddUserWord("����� yym");//�������ף���Ϊ��Ա����
	sResult = ICTCLAS_ParagraphProcess(sSentence,1);
	printf("%s\n", sResult);
	ICTCLAS_AddUserWord("С���� yym");//���С��������Ϊ��Ա����
	sResult = ICTCLAS_ParagraphProcess(sSentence,1);
	printf("%s\n", sResult);
	ICTCLAS_AddUserWord("���� yym");//������ݣ���Ϊ��Ա����
	sResult = ICTCLAS_ParagraphProcess(sSentence,1);
	printf("%s\n", sResult);
	ICTCLAS_AddUserWord("��ǹ�İ����� dym");//�����ǹ�İ����棬��Ϊ��Ӱ����
	sResult = ICTCLAS_ParagraphProcess(sSentence,1);
	printf("%s\n", sResult);
	

	while(_stricmp(sSentence,"q")!=0)
	{
		sResult = ICTCLAS_ParagraphProcess(sSentence,0);
		printf("%s\nInput string now('q' to quit)!\n", sResult);
		scanf("%s",sSentence);
	}
	
	//�����û��ʵ�ǰ
	printf("δ�����û��ʵ䣺\n");
	sResult = ICTCLAS_ParagraphProcess(sInput, 0);
	printf("%s\n", sResult);

	//�����û��ʵ��
	printf("\n�����û��ʵ��\n");
	nCount = ICTCLAS_ImportUserDict("userdic.txt");//userdic.txt������ǰ���û��ʵ�
	//�����û��ʵ�
	ICTCLAS_SaveTheUsrDic();
	printf("����%d���û��ʡ�\n", nCount);
	
	sResult = ICTCLAS_ParagraphProcess(sInput, 1);
	printf("%s\n", sResult);

	//��̬����û���
	printf("\n��̬����û��ʺ�\n");
	ICTCLAS_AddUserWord("�����ѧԺ   xueyuan");
	ICTCLAS_SaveTheUsrDic();
	sResult = ICTCLAS_ParagraphProcess(sInput, 1);
	printf("%s\n", sResult);


	//���ļ����зִ�
	ICTCLAS_FileProcess("testGBK.txt","testGBK_result.txt",1);


	//�ͷŷִ������Դ
	ICTCLAS_Exit();
}

void SplitBIG5()
{
	//��ʼ���ִ����
	if(!ICTCLAS_Init("",BIG5_CODE))//�����ڵ�ǰ·���£�����ΪBIG5����ķִ�
	{
		printf("ICTCLAS INIT FAILED!\n");
		return ;
	}
	ICTCLAS_FileProcess("testBIG.txt","testBIG_result.txt");
	ICTCLAS_Exit();
}
void SplitUTF8()
{
	//��ʼ���ִ����
	if(!ICTCLAS_Init("",UTF8_CODE))//�����ڵ�ǰ·���£�����ΪUTF8����ķִ�
	{
		printf("ICTCLAS INIT FAILED!\n");
		return ;
	}
	ICTCLAS_FileProcess("testUTF.txt","testUTF_result.txt");
	ICTCLAS_Exit();
}
int main()
{



	const char *sInput = "�Ż�ƽ2009��׵��뱱������ѧ�����ѧԺ��";
	//�ִ�
	SplitBIG5();
	SplitGBK(sInput);

	SplitUTF8();
	
	return 1;
}

