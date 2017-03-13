#include "writeMemory.h"
#include "ClassDef.h"

bool SDK_LoadClassDataByMemory(void* memoryData)
{
	WriteMemory writeMemory(memoryData);
	Student A(18, true, "Jack", 175.6, 70.3), B(17, false, "Lily", 165.7, 98.7);
	vector<Student> Vec_students;
	Vec_students.push_back(A);
	Vec_students.push_back(B);
	Classss myClass(L"北京国际学校", Vec_students);
	myClass.serializeMemory(writeMemory);
	return true;
}