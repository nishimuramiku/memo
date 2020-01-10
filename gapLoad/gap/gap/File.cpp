#include "File.h"

File::File()
	:file(nullptr)
	,container(nullptr)
	,size(0)
	,pos(0)
{
}

File::~File()
{
	if (container != nullptr)
	{
		delete container;
		container = nullptr;
	}

}

bool File::OpenFile(const char* fileName)
{
	errno_t error = fopen_s(&file, fileName, "r");

	if (error != 0)
	{
		fclose(file);
		return false;
		std::cout << "error fileOpen" << std::endl;
	}

	size = GetSize();
	container = new char[size + 1];
	fread(container, sizeof(char), size / sizeof(char), file);
	container[size] = '\0';

	//printf("%s", container);

	fclose(file);
	return true;
}

int File::GetSize()
{
	if (fseek(file, 0L, SEEK_END) == 0)
	{
		fpos_t pos;
		if (fgetpos(file, &pos) == 0)
		{
			fseek(file, 0L, SEEK_SET);
			return pos;
		}
	}
}

void File::Split()
{
	std::vector<int> temp;
	int i = 0;
	for (i = 1; container[i] != '\n'; i++)
	{
	
		if (container[i] != '(' && container[i] != ')')
		{
			char c[3] = {};
			int count = 0;
			if (container[i] != ',')
			{
				c[count] = container[i];
				count++;
			}
			c[count] = '\0';
			temp.push_back(atoi(c));

		}
		i = pos;
		line.push_back(temp);

	}
		
	

	for (std::vector<int> v : line)
	{
		for (int i : v)
		{
			std::cout << i << std::endl;

		}

	}
	
	
}
