#ifndef _WRITEMEMORY_H_
#define _WRITEMEMORY_H_
#include <iostream>
using namespace std;

class RectF
{
public:
	float left;
	float top;
	float width;
	float height;
};

class WriteMemory
{
public:
	WriteMemory(void* src);
	WriteMemory();
	~WriteMemory();

public:
	void writeMemory(const bool& other);

	void writeMemory(const unsigned char& other);
	void writeMemory(const signed char& other);

	void writeMemory(const unsigned short& other);
	void writeMemory(const signed short& other);

	void writeMemory(const unsigned int& other);
	void writeMemory(const signed int& other);

	void writeMemory(const unsigned long long& other);
	void writeMemory(const signed long long& other);

	void writeMemory(const float& other);
	void writeMemory(const double& other);

	void writeMemory(const long& other);

	void writeMemory(const wchar_t& other);

	void writeMemory(const string& str);
	void writeMemory(const wstring& wstr);

	void writeMemory(const RectF other);

	void writeMemory(const void* memory, signed int memorySize);

	void* getDestination();
	int getCurtPos();
	void moveCurtPos(int offset);
private:
	void* des;
	int curtpos;
};
#endif // _WRITEMEMORY_H_