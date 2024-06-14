#pragma once

#ifndef _DYNAMIC_ARRAY_HXX_
#define _DYNAMIC_ARRAY_HXX_

template <class T>
T* MakeDynamicArray(size_t _size, T _allocator) {
	T* result = new T[_size];

	for (int i = 0; i < _size; i++) {
		result[i] = _allocator;
	}

	return result;
}

template <class T>
T** Make2DimDynamicArray(size_t _sizeY, size_t _sizeX, T _allocator) {
	T** result = new T*[_sizeY];

	for (int i = 0; i < _sizeY; i++) {
		result[i] = new T[_sizeX];

		for (int j = 0; j < _sizeX; j++) {
			result[i][j] = _allocator;
		}
	}

	return result;
}


#endif