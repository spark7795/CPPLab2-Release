//---------------------------------------------------------------------------
//�������� ��������
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#define VERTEXES 9	//����� ������ � �����
using namespace std;
class Graph {
public:
	int v;
	int infinity = 1000;                     
	int p = VERTEXES;	
	int a[VERTEXES][VERTEXES] =
	{
		0, 1, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 1, 0, 0, 1, 0, 0, 0,
		0, 1, 0, 1, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 1, 1, 0, 1,
		0, 0, 1, 0, 0, 1, 1, 1, 0,
		0, 1, 0, 1, 1, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 0, 0, 1, 1,
		0, 0, 0, 0, 1, 0, 1, 0, 1,
		0, 0, 0, 1, 0, 0, 1, 1, 0,

	};
	
	int s=0; // ����� �������� �������
	int g=VERTEXES-1; // ����� �������� �������
	int x[VERTEXES]; //������, ���������� ������� � ���� ��� ������ �������,
					 // x[i]=0 - ��� �� ������ ���������� ���� � i-� �������,
					 // x[i]=1 - ���������� ���� � i-� ������� ��� ������
	int t[VERTEXES];  //t[i] - ����� ����������� ���� �� ������� s � i
	int h[VERTEXES];  //h[i] - �������, �������������� i-� ������� �� ���������� ����
	int u;		    // ������� ������
	void ShowMatrix() {
		int i, j;
		for (i = 0; i < VERTEXES; i++) {
			for (j = 0; j < VERTEXES; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	void ShortestWay(){
	for (u = 0; u < p; u++)
	{
		t[u] = infinity; //������� ��� ���������� ���� �� s � i ����� �������������
		x[u] = 0;        // � ��� ����������� ���� �� ��� ����� �������
	}
	h[s] = 0; // s - ������ ����, ������� ���� ������� ������ �� ������������
	t[s] = 0; // ���������� ���� �� s � s ����� 0
	x[s] = 1; // ��� ������� s ������ ���������� ����
	v = s;    // ������ s ������� ��������

	while (1)
	{
		// ���������� ��� �������, ������� v, � ���� ��� ��� ���������� ����
		for (u = 0; u < p; u++)
		{
			if (a[v][u] == 0) continue; // ������� u � v ���������
			if (x[u] == 0 && t[u] > t[v] + a[v][u]) 
			{
				t[u] = t[v] + a[v][u];	
				h[u] = v;
			}
		}

		
		int w = infinity;  
		v = -1;
		for (u = 0; u < p; u++) // ���������� ��� �������.
		{
			if (x[u] == 0 && t[u] < w) 
			{
				v = u; // ������� �������� ���������� u-� �������
				w = t[u];
			}
		}
		if (v == -1)
		{
			cout << "��� ���� �� ������� " << s << " � ������� " << g << "." << endl;
			break;
		}
		if (v == g) // ������ ���������� ����,
		{        // ������� ���
			cout << "���������� ���� �� ������� " << s << " � ������� " << g << ":";
			u = g;
			while (u != s)
			{
				cout << " " << u;
				u = h[u];
			}
			cout << " " << s << ". ����� ���� - " << t[g];
			break;
		}
		x[v] = 1;
	} }
	void LongestWay() {
		for (u = 0; u < p; u++)
		{
			t[u] = 0;
			x[u] = 0;       
		}
		h[s] = 0; 
		t[s] = 0; 
		x[s] = 1; 
		v = s; 

		while (1)
		{
			
			for (u = 0; u < p; u++)
			{
				if (a[v][u] == 0) continue; 
				if (x[u] == 0 && t[u] < t[v] + a[v][u]) 
				{
					t[u] = t[v] + a[v][u];  
					h[u] = v; 
				}
			}
			int w = 0;  
			v = -1;
			for (u = 0; u < p; u++) 
			{
				if (x[u] == 0 && t[u] > w) 
				{
					v = u;
					w = t[u];
				}
			}
			if (v == -1)
			{
				cout << "��� ���� �� ������� " << s << " � ������� " << g << "." << endl;
				break;
			}
			if (v == g) 
			{        
				cout << "����������� ���� �� ������� " << s << " � ������� " << g << ":";
				u = g;
				while (u != s)
				{
					cout << " " << u;
					u = h[u];
				}
				cout << " " << s << ". ����� ���� - " << t[g];
				break;
			}
			x[v] = 1;
		}
	}
	void Exclude() {
		int i, j, k;
		for (i = 0; i < VERTEXES; i++) {
			for (j = 0; j < VERTEXES; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		int exc_num;
		cout << "How many points be excluded: "; cin >> exc_num; cout << endl;
		int *exc = new int[exc_num];
		for (k = 0; k < exc_num; k++) {
			cout << "Enter point #" << k << ": "; cin >> exc[k];
		}
		for (k = 0; k < exc_num; k++) {
			for (j = 0; j < VERTEXES; j++) {
				a[exc[k]][j] = 0;
			}
			for (i = 0; i < VERTEXES; i++) {
				a[i][exc[k]] = 0;
			}
		}
		for (i = 0; i < VERTEXES; i++) {
			for (j = 0; j < VERTEXES; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	void Choose() {
		int i, j, k;
		ShowMatrix();
		int rows[VERTEXES];
		for (i = 0; i < VERTEXES; i++) { rows[i] = i; }
		int exc_num;
		cout << "How many points be choosen: "; cin >> exc_num; cout << endl;
		int *exc = new int[exc_num];
		for (i = 0; i < exc_num; i++) {
			cout << "Enter point #" << i << ": "; cin >> exc[i];
		}
		
		// ��������� ��������
		for (k = 0; k < VERTEXES; k++) {
			if ((std::count(exc, exc + VERTEXES, rows[k])) != 1) {
			//cout << rows [k] << "\t" << (std::count(exc, exc+VERTEXES, rows[k])) << endl; DEBUG INFO
				for (j = 0; j < VERTEXES; j++) { a[rows[k]][j] = 0;	}
				for (i = 0; i < VERTEXES; i++) { a[i][rows[k]] = 0;	}
			}
		}
		cout << endl << endl;
		// ����� �������� �������
		ShowMatrix();
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	system("cls");
	cout << "1. Only find shortest way\n";
	cout << "2. Only find longest way\n";
	cout << "3. Exclude points from the way and find shortest way\n";
	cout << "4. Exclude points from the way and find longest way\n";
	cout << "5. Use only choosen points and find shortest way\n";
	cout << "6. Use only choosen points and find longest way\n";
	int N;
	cin >> N;
	Graph findw;
	switch (N) {
	case 1: findw.ShortestWay(); break;
	case 2: findw.LongestWay(); break;
	case 3: findw.Exclude(); findw.ShortestWay(); break;
	case 4: findw.Exclude(); findw.LongestWay(); break;
	case 5: findw.Choose(); findw.ShortestWay(); break;
	case 6: findw.Choose(); findw.LongestWay(); break;
	default:
		cout << "Wrong item.\n";
		break;
	}
	system("pause");
	return 0;
}
