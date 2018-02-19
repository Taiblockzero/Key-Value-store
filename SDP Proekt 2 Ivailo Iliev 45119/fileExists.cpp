#include "fileExists.h"
#include <fstream>

bool fileExists(const char* fileName)
{
	std::ifstream file(fileName);
	return file.good();
}