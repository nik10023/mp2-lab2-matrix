// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

int main()
{
	TMatrix<int> m(3);
	TMatrix<int> m1(3);

	m[1][1] = 1;
	m[1][2] = 2;
	m[1][3] = 3;
	m[2][2] = 5;
	m[2][3] = 6;
	m[3][3] = 7;
	
	m1[1][1] = 1;
	m1[1][2] = 2;
	m1[1][3] = 3;
	m1[2][2] = 5;
	m1[2][3] = 6;
	m1[3][3] = 7;

	m = m + m1;

	std::cout << m;
	return 0;
}
//---------------------------------------------------------------------------
