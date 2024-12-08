#pragma once

#include <string>

template <typename T, typename F>
void iter(T *array, size_t len, F func)
{
	if (!array || !func)
		return;

	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}
