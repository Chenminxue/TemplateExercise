#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray {
private:
	T* pAddress;

	int m_Cap;

	int m_Size;
public:
	MyArray(int capacity) {
		cout << "Constructor" << endl;
		m_Cap = capacity;
		m_Size = 0;
		pAddress = new T[m_Cap];
	}

	MyArray(const MyArray& arr) {
		cout << "Copy" << endl;
		m_Cap = arr.m_Cap;
		m_Size = arr.m_Size;

		pAddress = new T[arr.m_Cap];

		for (int i = 0; i < m_Size; i++) {
			pAddress[i] = arr.pAddress[i];
		}
	}

	MyArray& operator=(const MyArray& arr) {
		cout << "Operator" << endl;
		if (pAddress != NULL) {
			delete[] pAddress;
			pAddress = NULL;
			m_Cap = 0;
			m_Size = 0;
		}
		m_Cap = arr.m_Cap;
		m_Size = arr.m_Size;
		pAddress = new T[arr.m_Cap];
		for (int i = 0; i < m_Size; i++) {
			pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	~MyArray() {
		if (pAddress != NULL) {
			cout << "Deconstructor" << endl;
			delete[] pAddress;
			pAddress = NULL;
		}
	}
};

