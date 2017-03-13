using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CSharpReadData
{
    class Program
    {
        [DllImport("CppDataTransferDll.dll", EntryPoint = "SDK_LoadClassDataByMemory", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SDK_LoadClassDataByMemory(IntPtr info);
        static void Main(string[] args)
        {
            IntPtr pv = Marshal.AllocHGlobal(1024);
            SDK_LoadClassDataByMemory(pv);
            Classss myClass = new Classss();
            ReadClass.ReadMyClass(pv, myClass);
            Console.WriteLine("ClassName:{0}", myClass.ClassName);
            foreach (var item in myClass.StudentList)
            {
                Console.WriteLine($"Student: Name:{item.name} age:{item.age} SEX:{item.isBoy}" );
            }
            Console.Read();

        }
    }
}
