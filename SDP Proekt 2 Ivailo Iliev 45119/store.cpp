#include "store.h"
#include "hashes.h"
#include <fstream>
#include "fileExists.h"
#include <iostream>
using namespace std;
const unsigned UNSIGNED_INT_LENGTH = 10;


unsigned store(const unsigned char* pBlock, size_t size)
{
	if (0 == size)
	{
		cout << "You can't add blocks with size 0\n";
		return 0;
	}

	//Find hash value
	unsigned h = additiveHash(pBlock, size); //you can change used hash to be used here
	char strH[UNSIGNED_INT_LENGTH + 1];
	itoa(h, strH, 10);


	//Check where to put file(handling collisions)
	
	unsigned num;
	while (fileExists(strH))
	{
		num = atoi(strH);
		++num;
		itoa(num, strH, 10);
	}

	ofstream file(strH, ios::binary);
	file.write((char*)pBlock, size);
	file.close();

	return h;
}