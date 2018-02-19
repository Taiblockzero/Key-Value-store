#include "hashes.h"


unsigned additiveHash(const unsigned char* key, size_t len)
{
	unsigned h = 0;

	for (size_t i = 0; i < len; ++i)
	{
		h += key[i];
	}

	return h;
}