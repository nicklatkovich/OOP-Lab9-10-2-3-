#include "Array.h"
#include <iostream>

Array::Array(int size) {
	this->size = 0;
	element = new int[this->size];
	setSize(size);
}

Array::Array(Array& arr) : Array(arr.getSize()) {
	for (int i = 0; i < getSize(); i++) {
		setElement(i, arr.getElement(i));
	}
}

Array::Array() : Array(0) {

}

void Array::setSize(int newSize) {
	int *newArr = new int[newSize];
	int minSize = (size < newSize) ? size : newSize;
	for (int i = 0; i < minSize; i++) {
		newArr[i] = element[i];
	}
	delete element;
	size = newSize;
	element = newArr;
}

void Array::setElement(int index, int value) {
	if (index >= 0 || index < size) {
		element[index] = value;
	}
}

int Array::getElement(int index) {
	return element[index];
}

int Array::getSize() {
	return size;
}

Array::~Array() {
	delete element;
}
