#include <iostream>
#include <vector>
#include "writeMemory.h"

using namespace std;

class Student
{
public:
	Student(int Age, bool IsBoy, string Name, float Height, float Weight);

	void serializeMemory(WriteMemory& writeMemory);
public:
	int age;
	bool isBoy;
	string name;
	float height;
	float weight;
};

class Classss
{
public:
	Classss(std::wstring Name, vector<Student> vec_student);
	void serializeMemory(WriteMemory& writeMemory);
public:
	std::wstring className;
	vector<Student> students;
};