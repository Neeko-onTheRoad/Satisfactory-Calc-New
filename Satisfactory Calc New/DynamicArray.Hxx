#pragma once

#ifndef _DYNAMIC_ARRAY_HXX_
#define _DYNAMIC_ARRAY_HXX_

template <class T>

T* MakeDynamicArray(size_t size, T allocator) {
	T* result = new T[size];

	for (size_t i = 0; i < size; i++) {
		result[i] = allocator;
	}

	return result;
}


#endif