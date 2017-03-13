using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpReadData
{
    public class Student
    {
        public int age { get; set; }
        public bool isBoy { get; set; }
        public string name { get; set; }
        public float height { get; set; }
        public float weight { get; set; }
    }

    public class Classss
    {
        public string ClassName { get; set; }
        public List<Student> StudentList { get; set; } = new List<Student>(); 
    }

    public class RectangleF
    {
        public RectangleF(float Left, float Top, float Width, float Height)
        {
            left = Left;
            top = Top;
            width = Width;
            height = Height;
        }

        public float left;
        public float top;
        public float width;
        public float height;
    }
}
