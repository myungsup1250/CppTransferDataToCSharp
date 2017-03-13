using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpReadData
{
    public class ReadClass
    {
        public static void ReadMyClass(IntPtr pv, Classss myClass)
        {
            ReadMemory readMemory = new ReadMemory(pv);
            myClass.ClassName = readMemory.ReadUniString();

            int length = readMemory.ReadInt();
            for(int i = 0; i < length; i++ )
            {
                Student temp = new Student();
                temp.age = readMemory.ReadInt();
                temp.isBoy = readMemory.ReadBool();
                temp.name = readMemory.ReadString();
                temp.height = readMemory.ReadFloat();
                temp.weight = readMemory.ReadFloat();
                myClass.StudentList.Add(temp);
            }
        }
    }
}
