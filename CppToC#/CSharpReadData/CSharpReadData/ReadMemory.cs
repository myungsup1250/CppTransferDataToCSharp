using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Drawing;

namespace CSharpReadData
{
    public class ReadMemory
    {
        private IntPtr _ptr;
        private int offset = 0;

        public ReadMemory(IntPtr ptr)
        {
            _ptr = ptr;
        }

        //bool
        public bool ReadBool()
        {
            byte result = Marshal.ReadByte(_ptr, offset);
            offset += 1;

            if (result > 0)
            {
                return true;
            }
            return false;
        }

        //unsigned char
        public byte ReadBtye()
        {
            byte result = Marshal.ReadByte(_ptr, offset);
            offset += 1;
            return result;
        }

        //signed char
        public sbyte ReadSbyte()
        {
            byte result = ReadBtye();

            if (result > 127)
            {
                return (sbyte)(result - 256);
            }

            return (sbyte)result;
        }

        //unsigned short
        public ushort ReadUshort()
        {
            return (ushort)ReadShort();
        }

        //short
        public short ReadShort()
        {
            short result = Marshal.ReadInt16(_ptr, offset);
            offset += 2;
            return result;
        }

        //unsigned int
        public uint ReadUint()
        {
            return (uint)ReadInt();
        }

        //int
        public int ReadInt()
        {
            int result = Marshal.ReadInt32(_ptr, offset);
            offset += 4;
            return result;
        }

        //unsigned long long
        public ulong ReadUlong()
        {
            return (ulong)ReadLong();
        }

        //signed long long
        public long ReadLong()
        {
            long result = Marshal.ReadInt64(_ptr, offset);
            offset += 4;
            return result;
        }

        //float
        public float ReadFloat()
        {
            float[] temp = new float[1];
            Marshal.Copy((IntPtr)(_ptr.ToInt32() + offset), temp, 0, 1);
            offset += 4;
            return temp[0];
        }

        //double
        public double ReadDouble()
        {
            double[] temp = new double[1];
            Marshal.Copy((IntPtr)(_ptr.ToInt32() + offset), temp, 0, 1);
            offset += 8;
            return temp[0];
        }

        //wchar_t  /  unsinged short
        public char ReadChar()
        {
            ushort temp = ReadUshort();
            return Convert.ToChar(temp);
        }

        //string
        public string ReadString()
        {
            int length = ReadInt();
            string temp = Marshal.PtrToStringAnsi((IntPtr)(_ptr.ToInt32() + offset), length);
            offset += length;
            return temp;
        }

        //wstring
        public string ReadUniString()
        {
            int length = ReadInt();
            string temp = Marshal.PtrToStringUni((IntPtr)(_ptr.ToInt32() + offset), length / 2);
            offset += length;
            return temp;
        }

        public RectangleF ReadRectangleF()
        {
            float[] temp = new float[4];
            Marshal.Copy((IntPtr)(_ptr.ToInt32() + offset), temp, 0, 4);
            offset += 16;
            return new RectangleF(temp[0], temp[1], temp[2], temp[3]);
        }
    }
}