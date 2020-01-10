#pragma once

#include<iostream>
#include<vector>

class File
{
public:
	File();
	~File();

	bool OpenFile(const char* fileName);
	void Split();
	

private:
	int GetSize();


private:
	FILE* file;
	int size;
	char* container;
	std::vector< std::vector<int>> line;
	int pos;

};

