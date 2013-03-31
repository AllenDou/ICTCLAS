using System;
using System.IO;
using System.Runtime.InteropServices;


namespace win_csharp
{
	[StructLayout(LayoutKind.Explicit)] 
	public struct result_t
	{ 
		[FieldOffset(0)] public int start; 
		[FieldOffset(4)] public int length;
        [FieldOffset(8)] public int sPos;
        [FieldOffset(12)] public int sPosLow;
        [FieldOffset(16)] public int POS_id; 
		[FieldOffset(20)] public int word_ID;
        [FieldOffset(24)] public int word_type;
        [FieldOffset(28)] public int weight;

	}
	/// <summary>
	/// Class1 的摘要说明。
	/// </summary>
	class Class1
	{
        const string path = @"ICTCLAS2011.dll";

		[DllImport(path,CharSet=CharSet.Ansi,EntryPoint="ICTCLAS_Init")]
		public static extern bool ICTCLAS_Init(String sInitDirPath,int encoding);		

        [DllImport(path, CharSet = CharSet.Ansi,EntryPoint = "ICTCLAS_ParagraphProcess")]
         public static extern String ICTCLAS_ParagraphProcess(String sParagraph, int bPOStagged);

		[DllImport(path,CharSet=CharSet.Ansi,EntryPoint="ICTCLAS_Exit")]
		public static extern bool ICTCLAS_Exit();
	
		[DllImport(path,CharSet=CharSet.Ansi,EntryPoint="ICTCLAS_ImportUserDict")]
		public static extern int ICTCLAS_ImportUserDict(String sFilename);

		[DllImport(path,CharSet=CharSet.Ansi,EntryPoint="ICTCLAS_FileProcess")]
		public static extern bool ICTCLAS_FileProcess(String sSrcFilename,String sDestFilename,int bPOStagged);
		
		[DllImport(path,CharSet=CharSet.Ansi,EntryPoint="ICTCLAS_FileProcessEx")]
		public static extern bool ICTCLAS_FileProcessEx(String sSrcFilename,String sDestFilename);
		
		[DllImport(path,CharSet=CharSet.Ansi,EntryPoint="ICTCLAS_GetParagraphProcessAWordCount")]
		static extern int ICTCLAS_GetParagraphProcessAWordCount(String sParagraph);
		//ICTCLAS_GetParagraphProcessAWordCount
		[DllImport(path,CharSet=CharSet.Ansi,EntryPoint="ICTCLAS_ParagraphProcessAW")]
		static extern void ICTCLAS_ParagraphProcessAW(int nCount, [Out,MarshalAs(UnmanagedType.LPArray)] result_t[] result);

        [DllImport(path, CharSet = CharSet.Ansi, EntryPoint = "ICTCLAS_AddUserWord")]
        static extern int ICTCLAS_AddUserWord(String sWord);

        [DllImport(path, CharSet = CharSet.Ansi, EntryPoint = "ICTCLAS_SaveTheUsrDic")]
        static extern int ICTCLAS_SaveTheUsrDic();


        [DllImport(path, CharSet = CharSet.Ansi, EntryPoint = "ICTCLAS_DelUsrWord")]
        static extern int ICTCLAS_DelUsrWord(String sWord);
        /// <summary>
		/// 应用程序的主入口点。
		/// </summary>
		[STAThread]
		static void Main(string[] args)
		{
			//
			// TODO: 在此处添加代码以启动应用程序
			//
            if (!ICTCLAS_Init("", 0))//可以设置为2:BIG5_CODE,1:UTF8_CODE
			{
				System.Console.WriteLine("Init ICTCLAS failed!");
				return;
			}

            ICTCLAS_ImportUserDict("userdic.txt");

            String s = "ICTCLAS在国内973专家组组织的评测中活动获得了第一名，在第一届国际中文处理研究机构SigHan组织的评测中都获得了多项第一名。";
			int count = ICTCLAS_GetParagraphProcessAWordCount(s);//先得到结果的词数


			result_t[] result = new result_t[count];//在客户端申请资源
	
			ICTCLAS_ParagraphProcessAW(count,result);//获取结果存到客户的内存中
	
           int i=1;
            foreach(result_t r in result)
            {
                String sWhichDic="";
                switch (r.word_type)
                {
                    case 0:
                        sWhichDic = "核心词典";
                        break;
                    case 1:
                        sWhichDic = "用户词典";
                        break;
                    case 2:
                        sWhichDic = "专业词典";
                        break;
                    default:
                        break;
                }
                Console.WriteLine("No.{0}:start:{1}, length:{2},POS_ID:{3},Word_ID:{4}, UserDefine:{5}, Word:{6}\n", i++, r.start, r.length, r.POS_id, r.word_ID, sWhichDic, s.Substring(r.start / 2, r.length / 2));
           }


            ICTCLAS_FileProcess("Input.txt","Input_result.txt", 1);
			String pResult;
			//音乐会上还演奏了小提琴协奏曲《梁山伯与祝英台》、

            //重新加载用户词典
            //int nCount = ICTCLAS_ImportUserDict("userdict.txt");//Import Userdict
            //System.Console.WriteLine(nCount);
            //printf("%d\n",nCount);

            pResult = ICTCLAS_ParagraphProcess("ICTCLAS在国内973专家组组织的评测中活动获得了第一名，在第一届国际中文处理研究机构SigHan组织的评测中都获得了多项第一名。", 1);
            System.Console.WriteLine("Before Userdict imported:");
            System.Console.WriteLine(pResult);
            String ss;
            Console.WriteLine("inser usr dic:");
            ss = Console.ReadLine();
            while (ss[0]!='q'&&ss[0]!='Q')
            {
                //用户词典中添加词
               int iiii = ICTCLAS_AddUserWord(ss);//词 词性 example:点击下载 vyou
                pResult = ICTCLAS_ParagraphProcess(s, 1);
                //System.Console.WriteLine("Before Userdict imported:");
                System.Console.WriteLine(pResult);
                ICTCLAS_SaveTheUsrDic(); // save the user dictionary to the file

               //删除用户词典中的词
                Console.WriteLine("delete usr dic:");
                ss = Console.ReadLine();
                iiii = ICTCLAS_DelUsrWord(ss);
                pResult = ICTCLAS_ParagraphProcess(s, 1);
                //System.Console.WriteLine("Before Userdict imported:");
                System.Console.WriteLine(pResult);
                ICTCLAS_SaveTheUsrDic();                

            }

			
			//printf("%d\n",nCount);

            //pResult = ICTCLAS_ParagraphProcess("点击下载超女纪敏佳深受观众喜爱。禽流感爆发在非典之后。",0);
            //System.Console.WriteLine("After Userdict imported:");
            //System.Console.WriteLine(pResult);



            //System.Console.WriteLine("Input Sentence Now!(q to quit)\n");
            //String sInput = System.Console.ReadLine();			
            //while (sInput.CompareTo("q")!=0)
            //{
            //    pResult = ICTCLAS_ParagraphProcess(sInput,1);
            //    System.Console.WriteLine("Resut:");
            //    System.Console.WriteLine(pResult);
            //    System.Console.WriteLine("\nInput Sentence Now!(q to quit)\n");
            //    sInput = System.Console.ReadLine();
			//}
			ICTCLAS_FileProcess("Input.txt","Input_result.txt",1);
			ICTCLAS_Exit();

		}
	}
}
