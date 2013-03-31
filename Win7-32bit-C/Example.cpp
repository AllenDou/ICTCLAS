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
void Split(const char *sInput);
void KeyExtract(const char *sInput);
void FingerPrint(const char *sInput);


void Split(const char *sInput)
{//�ִ���ʾ

	//��ʼ���ִ����
	if(!ICTCLAS_Init())
	{
		printf("ICTCLAS INIT FAILED!\n");
		return ;
	}

	ICTCLAS_SetPOSmap(ICT_POS_MAP_SECOND);
	
	char sSentence[2000];
	const char * sResult;

	printf("Input sentence now('q' to quit)!\n");
	strcpy(sSentence,"����ı���ݵġ���ǹ�İ����桷������ס�С�������������ݡ�");
	//����ı���ݵġ���ǹ�İ����桷С������
	sResult=ICTCLAS_ParagraphProcess(sSentence,1);
	int nCount;
	ICTCLAS_ParagraphProcessA(sSentence,&nCount);
	printf("nCount=%d\n",nCount);
	ICTCLAS_ParagraphProcessA(sSentence,&nCount);
	printf("nCount=%d\n",nCount);
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

	//�ļ��ִ�
	 ICTCLAS_FileProcess("E:\\ictclas2010\\����\\Input.TXT","E:\\ictclas2010\\����\\Input-res.TXT",1);
	
	//
	//�ͷŷִ������Դ
	ICTCLAS_Exit();
}

void KeyExtract(const char *sInput)
{

	//��ʼ���ִ����
	if(!ICTCLAS_Init())
	{
		printf("ICTCLAS INIT FAILED!\n");
		return ;
	}

	printf("\n�ؼ�����ȡ��\n");
	int nCount = ICTCLAS_GetParagraphProcessAWordCount(sInput);

	//�ִʡ���ȡ�ؼ���
	result_t *result =(result_t*)malloc(sizeof(result_t)*nCount);
	ICTCLAS_ParagraphProcessAW(nCount,result);//��ȡ����浽�ͻ����ڴ���

	//�ؼ�����ȡ������ICTCLAS_ParagraphProcessAW����ִ�����ִ��
	result_t *resultKey = (result_t*)malloc(sizeof(result_t)*nCount);
	int nCountKey;
	ICTCLAS_KeyWord(resultKey, nCountKey);

	for (int i=0; i<nCountKey; i++)
	{
		char buf[100];
		memset(buf, 0, 100);
		int index = resultKey[i].start;
		memcpy(buf,(void *)(sInput+index), resultKey[i].length);
		printf("%s\t%d\n", buf, resultKey[i].weight);
	}

	free(resultKey);
	free(result);
	


	//�ͷŷִ������Դ
	ICTCLAS_Exit();
}

void FingerPrint(const char *sInput)
{
	//��ʼ���ִ����
	if(!ICTCLAS_Init())
	{
		printf("ICTCLAS INIT FAILED!\n");
		return ;
	}

	int nCount = ICTCLAS_GetParagraphProcessAWordCount(sInput);

	//�ִʡ���ȡ�ؼ���
	result_t *result =(result_t*)malloc(sizeof(result_t)*nCount);
	ICTCLAS_ParagraphProcessAW(nCount,result);//��ȡ����浽�ͻ����ڴ���
	
	
	//ָ����ȡ������ICTCLAS_ParagraphProcessAW����ִ�����ִ��
	unsigned long lFinger = ICTCLAS_FingerPrint();

	char buf[100];
	memset(buf, 0, 100);
	sprintf(buf, "%x", lFinger);
	printf("ָ�ƣ�%s\n", buf);


	//�ͷŷִ������Դ
	ICTCLAS_Exit();
}
int main()
{



	const char *sInput = "�Ż�ƽ2009��׵��뱱������ѧ�����ѧԺ��";
	//�ִ�
	Split(sInput);
	//�ؼ�����ȡ
	KeyExtract(sInput);
	//ָ����ȡ
	FingerPrint(sInput);
	char bufTmp[100];
	scanf("%s", bufTmp);
	
	return 1;
}

