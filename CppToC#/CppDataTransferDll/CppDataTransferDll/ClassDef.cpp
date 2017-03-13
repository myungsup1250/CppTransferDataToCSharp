#include "ClassDef.h"

Student::Student(int Age, bool IsBoy, string Name, float Height, float Weight)
{
	age = Age;
	isBoy = IsBoy;
	name = Name;
	height = Height;
	weight = Weight;
}

void Student::serializeMemory(WriteMemory& writeMemory)
{
	writeMemory.writeMemory(age);
	writeMemory.writeMemory(isBoy);
	writeMemory.writeMemory(name);
	writeMemory.writeMemory(height);
	writeMemory.writeMemory(weight);
}

Classss::Classss(std::wstring Name, vector<Student> vec_student)
{
	className = Name;
	students.assign(vec_student.begin(),vec_student.end());
}

void Classss::serializeMemory(WriteMemory& writeMemory)
{
	writeMemory.writeMemory(className);
	writeMemory.writeMemory(students.size());
	for (int i = 0; i < students.size(); i++)
	{
		students[i].serializeMemory(writeMemory);
	}
}
