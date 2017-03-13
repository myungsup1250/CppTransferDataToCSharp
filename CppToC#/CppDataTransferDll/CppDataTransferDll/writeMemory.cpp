#include "writeMemory.h"

WriteMemory::WriteMemory(void* src)
{
	des = src;
	curtpos = 0;
}

WriteMemory::WriteMemory()
{
	des = NULL;
	curtpos = 0;
}

WriteMemory::~WriteMemory()
{

}

void WriteMemory::writeMemory(const bool& other)
{
	memcpy((char*)des + curtpos, (char*)&other, sizeof(bool));
	curtpos += sizeof(bool);
}

void WriteMemory::writeMemory(const unsigned char& other)
{
	memcpy((char*)des + curtpos, &other, sizeof(unsigned char));
	curtpos += sizeof(unsigned char);
}

void WriteMemory::writeMemory(const signed char& other)
{
	memcpy((char*)des + curtpos, (char*)&other, sizeof(signed char));
	curtpos += sizeof(signed char);
}

void WriteMemory::writeMemory(const unsigned short& other)
{
	memcpy((char*)des + curtpos, &other, sizeof(unsigned short));
	curtpos += sizeof(unsigned short);
}

void WriteMemory::writeMemory(const signed short& other)
{
	memcpy((char*)des + curtpos, &other, sizeof(signed short));
	curtpos += sizeof(signed short);
}


void WriteMemory::writeMemory(const unsigned int& other)
{
	memcpy((char*)des + curtpos, (char*)&other, sizeof(unsigned int));
	curtpos += sizeof(unsigned int);
}

void WriteMemory::writeMemory(const signed int& other)
{
	memcpy((char*)des + curtpos, (char*)&other, sizeof(signed int));
	curtpos += sizeof(signed int);
}

void WriteMemory::writeMemory(const unsigned long long& other)
{
	memcpy((char*)des + curtpos, (char*)&other, sizeof(unsigned long long));
	curtpos += sizeof(unsigned long long);
}

void WriteMemory::writeMemory(const signed long long& other)
{
	memcpy((char*)des + curtpos, (char*)&other, sizeof(signed long long));
	curtpos += sizeof(signed long long);
}

void  WriteMemory::writeMemory(const float& other)
{
	memcpy((char*)des + curtpos, (char*)&other, sizeof(float));
	curtpos += sizeof(float);
}

void  WriteMemory::writeMemory(const double& other)
{
	memcpy((char*)des + curtpos, (char*)&other, sizeof(double));
	curtpos += sizeof(double);
}

void WriteMemory::writeMemory(const wchar_t& other)
{
	memcpy((char*)des + curtpos, (char*)&other, sizeof(wchar_t));
	curtpos += sizeof(wchar_t);
}

void WriteMemory::writeMemory(const long& other)
{
	memcpy((char*)des + curtpos, (char*)&other, sizeof(long));
	curtpos += sizeof(long);
}

void WriteMemory::writeMemory(const std::string& str)
{
	writeMemory(str.length());
	memcpy((char*)des + curtpos, str.c_str(), str.length());
	curtpos += str.length();
}

void WriteMemory::writeMemory(const std::wstring& wstr)
{
	writeMemory(wstr.length() * 2);
	memcpy((char*)des + curtpos, wstr.c_str(), wstr.length() * 2);
	curtpos += wstr.length() * 2;
}

void WriteMemory::writeMemory(const RectF other)
{
	memcpy((char*)des + curtpos, (char*)&other, sizeof(float) * 4);
	curtpos += sizeof(float) * 4;

}

void WriteMemory::writeMemory(const void* memory, signed int memorySize)
{
	memcpy((char*)des + curtpos, (char*)memory, memorySize);
	curtpos += memorySize;
}

void* WriteMemory::getDestination()
{
	return des;
}

int WriteMemory::getCurtPos()
{
	return curtpos;
}

void WriteMemory::moveCurtPos(int offset)
{
	curtpos += offset;
}
