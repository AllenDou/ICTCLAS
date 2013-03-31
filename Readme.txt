				          Readme
一、欢迎使用汉语词法分析系统ICTCLAS2012
    我们在多年研究工作积累的基础上，研制出了汉语词法分析系统ICTCLAS，主要功能包括中文分词；词性标注；命名实体识别；新词识别；用户词典功能，同时支持GBK编码、UTF8编码、BIG5编码。我们先后精心打造五年，内核升级9次，目前已经升级到了ICTCLAS 2012。
    访问http://www.nlpir.org (自然语言处理与信息检索共享平台)，您可以获取ICTCLAS的最新版本，并欢迎您关注张华平博士的新浪微博 @ICTCLAS张华平博士 交流具体的技术问题。
 		ICTCLAS2012升级包括：
 		1.增加了CICTCLAS部分函数;
 		2.修正了部分再UTF-8下计算位移偏移量的Bug.
 		3.ICTCLAS完全兼容开源搜索引擎Sphinx，具体可以访问Sphinx官网；
 		4.为保障用户使用的便利，从本版开始，调用的dll的名称一律为ICTCLAS2011.dll，不再变化，一般用户只需要变更dll及对应的.user授权文件，无需重新编译自己的程序，即可兼容新版本分词程序。
            
二、文件包介绍
ICTCLAS2012_SDK        
│   Configure.xml:配置管理文件
│   Example.cpp: C示例程序
│   Example.cs:  C#示例程序
│   Example.exe：C#示例程序生成的可执行文件
│   ICTCLAS2011.dll：ICTCLAS2011动态链接库，用于C调用
│   ICTCLAS2011.h: ICTCLAS2011头文件，用于C调用
│   ICTCLAS2011.lib: ICTCLAS2011 Library，用于C调用
│   ICTCLAS2012.log: ICTCLAS2012日志文件，用于出错调试使用
│   ICTCLAS2012.user: 授权文件，不可删除
│   ICTCLAS2012_demo.exe：ICTCLAS2012 Windows界面演示程序
│   Input.txt: 		测试使用的文本输入文件
│   Input_result.txt: 测试文件的处理结果
│   License.dll: 授权动态链接文件，不可删除
│   Readme.txt: 本说明文档
│   userdic.txt: 测试使用的用户词典
│   WinCExample.exe: C示例程序Windows下可执行程序
│
├───Data:ICTCLAS2011的数据文件
│       BIG2GBK.map
│       BIG5.pdat
│       BIG5.wordlist
│       BiWord.big
│       charset.type
│       CoreDict.pdat
│       CoreDict.pos
│       CoreDict.unig
│       FieldDict.pdat
│       FieldDict.pos
│       GBK.pdat
│       GBK.wordlist
│       GBK2BIG.map
│       GBK2UTF.map
│       GranDict.pdat
│       GranDict.pos
│       ICTCLAS30.ctx
│       ICTCLAS_First.map
│       ICTPOS.map
│       nr.ctx
│       nr.fsa
│       nr.role
│       PKU.map
│       PKU_First.map
│       UserDict.pdat
│       UTF2GBK.map
│       UTF8.pdat
│       UTF8.wordlist
│
├───Linux-32bit-C：     		如果在Linux 32位下使用C调用，需要将本文件夹中的文件Copy到上层目录
│   │   libICTCLAS2011.a：  Linux下调用的静态库文件
│   │   Readme─其他文件与Linux64下C接口一样.txt
│   │
│   └───so库                Linux下调用的动态库文件
│           libICTCLAS2011.so
│           调用方法.txt
│
├───Linux-64bit-C       如果在Linux 64位下使用C调用，需要将本文件夹中的文件Copy到上层目录
│   │   Example.cpp				Linux下示例程序
│   │   ICTCLAS2011.h			Linux下调用的头文件
│   │   ICTCLAS2011.user
│   │   Input.txt
│   │   libICTCLAS2011.a	Linux下调用的库文件
│   │   Makefile					Linux下示例程序编译使用的Makefile
│   │   test							Linux下示例程序生成的可执行文件
│   │   Test.TXT
│   │   testBIG.txt
│   │   testGBK.txt
│   │   testUTF.txt
│   │   userdic.txt
│   │
│   └───so库						Linux下调用的动态库文件
│           libICTCLAS2011.so
│           调用方法.txt
│
├───Linux-bit32─JNI				如果在Linux 32位下使用Java调用，需要将本文件夹中的文件Copy到上层目录
│       libICTCLAS2011.so			Linux下调用的库文件
│       Readme─其他文件与Linux64下C接口一样.txt
│
├───Linux-bit64─JNI							如果在Linux 64位下使用Java调用，需要将本文件夹中的文件Copy到上层目录
│   │   Configure.xml
│   │   ICTCLAS2011.user
│   │   libICTCLAS2011.so						Linux下调用的库文件
│   │   lingjoin.user
│   │   TestICTCLAS2011.class				Linux下示例程序生成的结果  
│   │   TestICTCLAS2011.java				Linux下示例程序  
│   │   调用方法.txt								调用方法说明
│   │
│   └───ICTCLAS
│       └───kevin
│           └───zhang
│                   ICTCLAS2010.class
│                   ICTCLAS2010.java
│                   ICTCLAS2011.class
│                   ICTCLAS2011.java
│
├───Win7-bit32-C#
│       Configure.xml
│				Example.cs
│       ICTCLAS2010.dll
│       ICTCLAS2011.dll
│       ICTCLAS2011.user
│       Input.txt
│       License.dll
│       Test.TXT
│       userdic.txt
│
├───Win7-bit32-C
│       Example.cpp
│       ICTCLAS2011.dll
│       ICTCLAS2011.h
│       ICTCLAS2011.lib
│       License.dll
├───Win7-bit64-C#
│       Configure.xml
│				Example.cs
│       ICTCLAS2010.dll
│       ICTCLAS2011.dll
│       ICTCLAS2011.user
│       Input.txt
│       License.dll
│       Test.TXT
│       userdic.txt
│
├───Win7-bit64-C
│       Example.cpp
│       ICTCLAS2011.dll
│       ICTCLAS2011.h
│       ICTCLAS2011.lib
│       License.dll│
├───Windows-C#					如果在Windows下使用C#调用，需要将本文件夹中的文件Copy到上层目录            
│       Example.cs						Win下示例程序
│       ICTCLAS2010CSharpDemo.exe	 Win下示例程序生成的可执行文件  
│       ICTCLAS2011.dll				Win下调用的动态链接库文件
│       ICTCLAS2011.h					Win下调用的头文件
│       ICTCLAS2011.lib				Win下调用的库文件
│       License.dll
│
├───Windows-C				如果在Windows下使用C调用，需要将本文件夹中的文件Copy到上层目录
│       Example.cpp						 Win下示例程序 
│       ICTCLAS2011.dll        Win下调用的动态链接库文件 
│       ICTCLAS2011.h          Win下调用的头文件                       
│       ICTCLAS2011.lib        Win下调用的库文件 
│       testBIG.txt                                    
│       testGBK.TXT
│       TestUTF.txt
│       WinCExample.exe	      Win下示例程序生成的可执行文件
│
├───Windows-JNI
│   │   ICTCLAS2011.dll
│   │   ICTCLAS2011.user
│   │   License.dll
│   │   TestICTCLAS2011.java
│   │
│   └───ICTCLAS
│       └───kevin
│           └───zhang
│                   ICTCLAS2011.class
│                   ICTCLAS2011.java
│
│
└───文档
        ICTCLAS2011接口文档.doc
        ICTPOS3.0.doc
        JAVA调用ICTClAS多线程的示例文档.doc
        ICTCLAS的性能评估.doc
        
四、两步傻瓜式操作就可以使用ICTCLAS2012

1.选择您需要的API形式，主要由您的开发环境和操作系统来定，比如你选择了Windows下的C调用，则您需要选择Windows下的C接口；
2.将相应文件夹内容拷贝到上层目录；编译执行即可。
最后恭喜你，您可以正常使用ICTCLAS2012了！
3.如果没有编程基础，也不愿意进行二次开发。可以直接点击当前目录下的ICTCLAS2012_demo.exe，使用ICTCLAS2012 Windows演示程序，具体的使用方法，可以参考“文档”目录下的，ICTCLAS2012 Windows演示程序用户手册.doc
五、联系方式
	张华平 博士 副研究员 硕导
北京理工大学网络搜索挖掘与安全实验室 主任
地址：北京海淀区中关村南大街5号 100081
电话：+86-10-68918642
Email:kevinzhang@bit.edu.cn
MSN:  pipy_zhang@msn.com;
网站: http://www.nlpir.org (自然语言处理与信息检索共享平台)
博客:http://hi.baidu.com/drkevinzhang/
微博:http://www.weibo.com/drkevinzhang/
 
Dr. Kevin Zhang  (张华平，Zhang Hua-Ping)
Associate Professor, Graduate Supervisor
Director, Web Search,Mining and Security Lab.
Beijing Institute of Technology 
Add: No.5, South St.,Zhongguancun,Haidian District,Beijing,P.R.C  PC:100081
Tel: +86-10-68918642
Email:kevinzhang@bit.edu.cn
MSN:  pipy_zhang@msn.com;
Website: http://www.nlpir.org (Natural Language Processing and Information Retrieval Sharing Platform)
Blog:http://hi.baidu.com/drkevinzhang/
Twitter: http://www.weibo.com/drkevinzhang/