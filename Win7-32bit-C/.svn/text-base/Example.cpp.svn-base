// win_cDemo.cpp : 定义控制台应用程序的入口点。
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
{//分词演示

	//初始化分词组件
	if(!ICTCLAS_Init())
	{
		printf("ICTCLAS INIT FAILED!\n");
		return ;
	}

	ICTCLAS_SetPOSmap(ICT_POS_MAP_SECOND);
	
	char sSentence[2000];
	const char * sResult;

	printf("Input sentence now('q' to quit)!\n");
	strcpy(sSentence,"张艺谋导演的《三枪拍案惊奇》由孙红雷、小沈阳、闫妮主演。");
	//张艺谋导演的《三枪拍案惊奇》小沈阳、
	sResult=ICTCLAS_ParagraphProcess(sSentence,1);
	int nCount;
	ICTCLAS_ParagraphProcessA(sSentence,&nCount);
	printf("nCount=%d\n",nCount);
	ICTCLAS_ParagraphProcessA(sSentence,&nCount);
	printf("nCount=%d\n",nCount);
	ICTCLAS_ParagraphProcessA(sSentence,&nCount);
	printf("nCount=%d\n",nCount);


	ICTCLAS_AddUserWord("孙红雷 yym");//添加孙红雷，作为演员名称
	sResult = ICTCLAS_ParagraphProcess(sSentence,1);
	printf("%s\n", sResult);
	ICTCLAS_AddUserWord("小沈阳 yym");//添加小沈阳，作为演员名称
	sResult = ICTCLAS_ParagraphProcess(sSentence,1);
	printf("%s\n", sResult);
	ICTCLAS_AddUserWord("闫妮 yym");//添加闫妮，作为演员名称
	sResult = ICTCLAS_ParagraphProcess(sSentence,1);
	printf("%s\n", sResult);
	ICTCLAS_AddUserWord("三枪拍案惊奇 dym");//添加三枪拍案惊奇，作为电影名称
	sResult = ICTCLAS_ParagraphProcess(sSentence,1);
	printf("%s\n", sResult);
	

	while(_stricmp(sSentence,"q")!=0)
	{
		sResult = ICTCLAS_ParagraphProcess(sSentence,0);
		printf("%s\nInput string now('q' to quit)!\n", sResult);
		scanf("%s",sSentence);
	}
	
	//导入用户词典前
	printf("未导入用户词典：\n");
	sResult = ICTCLAS_ParagraphProcess(sInput, 0);
	printf("%s\n", sResult);

	//导入用户词典后
	printf("\n导入用户词典后：\n");
	nCount = ICTCLAS_ImportUserDict("userdic.txt");//userdic.txt覆盖以前的用户词典
	//保存用户词典
	ICTCLAS_SaveTheUsrDic();
	printf("导入%d个用户词。\n", nCount);
	
	sResult = ICTCLAS_ParagraphProcess(sInput, 1);
	printf("%s\n", sResult);

	//动态添加用户词
	printf("\n动态添加用户词后：\n");
	ICTCLAS_AddUserWord("计算机学院   xueyuan");
	ICTCLAS_SaveTheUsrDic();
	sResult = ICTCLAS_ParagraphProcess(sInput, 1);
	printf("%s\n", sResult);

	//文件分词
	 ICTCLAS_FileProcess("E:\\ictclas2010\\反馈\\Input.TXT","E:\\ictclas2010\\反馈\\Input-res.TXT",1);
	
	//
	//释放分词组件资源
	ICTCLAS_Exit();
}

void KeyExtract(const char *sInput)
{

	//初始化分词组件
	if(!ICTCLAS_Init())
	{
		printf("ICTCLAS INIT FAILED!\n");
		return ;
	}

	printf("\n关键词提取：\n");
	int nCount = ICTCLAS_GetParagraphProcessAWordCount(sInput);

	//分词。提取关键词
	result_t *result =(result_t*)malloc(sizeof(result_t)*nCount);
	ICTCLAS_ParagraphProcessAW(nCount,result);//获取结果存到客户的内存中

	//关键词提取，须在ICTCLAS_ParagraphProcessAW函数执行完后执行
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
	


	//释放分词组件资源
	ICTCLAS_Exit();
}

void FingerPrint(const char *sInput)
{
	//初始化分词组件
	if(!ICTCLAS_Init())
	{
		printf("ICTCLAS INIT FAILED!\n");
		return ;
	}

	int nCount = ICTCLAS_GetParagraphProcessAWordCount(sInput);

	//分词。提取关键词
	result_t *result =(result_t*)malloc(sizeof(result_t)*nCount);
	ICTCLAS_ParagraphProcessAW(nCount,result);//获取结果存到客户的内存中
	
	
	//指纹提取，须在ICTCLAS_ParagraphProcessAW函数执行完后执行
	unsigned long lFinger = ICTCLAS_FingerPrint();

	char buf[100];
	memset(buf, 0, 100);
	sprintf(buf, "%x", lFinger);
	printf("指纹：%s\n", buf);


	//释放分词组件资源
	ICTCLAS_Exit();
}
int main()
{



	const char *sInput = "张华平2009年底调入北京理工大学计算机学院。";
	//分词
	Split(sInput);
	//关键词提取
	KeyExtract(sInput);
	//指纹提取
	FingerPrint(sInput);
	char bufTmp[100];
	scanf("%s", bufTmp);
	
	return 1;
}

