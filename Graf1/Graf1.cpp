//---------------------------------------------------------------------------
//Алгоритм Дейкстры
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#define VERTEXES 9	//Число вершин в графе
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
	
	int s=0; // Номер исходной вершины
	int g=VERTEXES-1; // Номер конечной вершины
	int x[VERTEXES]; //Массив, содержащий единицы и нули для каждой вершины,
					 // x[i]=0 - еще не найден кратчайший путь в i-ю вершину,
					 // x[i]=1 - кратчайший путь в i-ю вершину уже найден
	int t[VERTEXES];  //t[i] - длина кратчайшего пути от вершины s в i
	int h[VERTEXES];  //h[i] - вершина, предшествующая i-й вершине на кратчайшем пути
	int u;		    // Счетчик вершин
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
		t[u] = infinity; //Сначала все кратчайшие пути из s в i равны бесконечности
		x[u] = 0;        // и нет кратчайшего пути ни для одной вершины
	}
	h[s] = 0; // s - начало пути, поэтому этой вершине ничего не предшествует
	t[s] = 0; // Кратчайший путь из s в s равен 0
	x[s] = 1; // Для вершины s найден кратчайший путь
	v = s;    // Делаем s текущей вершиной

	while (1)
	{
		// Перебираем все вершины, смежные v, и ищем для них кратчайший путь
		for (u = 0; u < p; u++)
		{
			if (a[v][u] == 0) continue; // Вершины u и v несмежные
			if (x[u] == 0 && t[u] > t[v] + a[v][u]) 
			{
				t[u] = t[v] + a[v][u];	
				h[u] = v;
			}
		}

		
		int w = infinity;  
		v = -1;
		for (u = 0; u < p; u++) // Перебираем все вершины.
		{
			if (x[u] == 0 && t[u] < w) 
			{
				v = u; // текущей вершиной становится u-я вершина
				w = t[u];
			}
		}
		if (v == -1)
		{
			cout << "Нет пути из вершины " << s << " в вершину " << g << "." << endl;
			break;
		}
		if (v == g) // Найден кратчайший путь,
		{        // выводим его
			cout << "Кратчайший путь из вершины " << s << " в вершину " << g << ":";
			u = g;
			while (u != s)
			{
				cout << " " << u;
				u = h[u];
			}
			cout << " " << s << ". Длина пути - " << t[g];
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
				cout << "Нет пути из вершины " << s << " в вершину " << g << "." << endl;
				break;
			}
			if (v == g) 
			{        
				cout << "Критический путь из вершины " << s << " в вершину " << g << ":";
				u = g;
				while (u != s)
				{
					cout << " " << u;
					u = h[u];
				}
				cout << " " << s << ". Длина пути - " << t[g];
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
		
		// Зануление ненужных
		for (k = 0; k < VERTEXES; k++) {
			if ((std::count(exc, exc + VERTEXES, rows[k])) != 1) {
			//cout << rows [k] << "\t" << (std::count(exc, exc+VERTEXES, rows[k])) << endl; DEBUG INFO
				for (j = 0; j < VERTEXES; j++) { a[rows[k]][j] = 0;	}
				for (i = 0; i < VERTEXES; i++) { a[i][rows[k]] = 0;	}
			}
		}
		cout << endl << endl;
		// Вывод конечной матрицы
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
