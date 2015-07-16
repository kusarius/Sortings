#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

#define VECTOR_SIZE 40

void quickSort(vector<int> &a, int start, int end)
{
	int s = start, e = end;
	int v = a[start + (end - start) / 2];
	while (s <= e)
	{
		while (a[s] < v) s++;
		while (a[e] > v) e--;
		if (s <= e)
		{
			swap<int>(a[s], a[e]);
			s++;
			e--;
		}
	}
	if (start < e) quickSort(a, start, e);
	if (s < end) quickSort(a, s, end);
}

void mergeSort(vector<int> &a, int start, int end)
{
	if (end - start < 1) return;
	if (end - start == 1)
	{
		if (a[start] > a[start + 1])
			swap<int>(a[start], a[start + 1]);
		return;
	}
	
	int c = start + (end - start) / 2;
	mergeSort(a, start, c);
	mergeSort(a, c, end);
	
	int p1 = start, p2 = c;
	vector<int> temp;
	while (temp.size() < end - start)
	{
		if (p2 >= end || (p1 < c && a[p1] < a[p2]))
		{
			temp.push_back(a[p1]);
			p1++;
		}
		else
		{
			temp.push_back(a[p2]);
			p2++;
		}
	}
	
	for (int i = start; i < end; i++)
		a[i] = temp[i - start];
}

void heapify(vector<int> &a, int count, int i)
{
	int left = i * 2, right = i * 2 + 1;
	if (left >= count || right >= count) return;
	if (a[i] < a[left] || a[i] < a[right])
	{
		int maxi = a[left] > a[right] ? left : right;
		swap<int>(a[i], a[maxi]);
		heapify(a, count, maxi);
	}
}

void buildHeap(vector<int> &a)
{
	for (int i = a.size() / 2 - 1; i >= 0; i--)
		heapify(a, a.size(), i);
}

void heapSort(vector<int> &a)
{
	buildHeap(a);
	for (int i = a.size() - 1; i >= 0; i--)
	{
		swap<int>(a[0], a[i]);
		heapify(a, i, 0);
	}
}

void shuffleVector(vector<int> &a)
{
	for (int i = 0; i < a.size(); i++)
		swap<int>(a[i], a[rand() % (a.size() - i) + i]);
}

void selectionSort(vector<int> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		int i_min = i;
		for (int c = i + 1; c < a.size(); c++)
			if (a[c] < a[i_min]) i_min = c;
		swap<int>(a[i], a[i_min]);
	}
}

void printVector(vector<int> &a)
{
	cout << "[";
	for (int i = 0; i < a.size() - 1; i++)
		cout << a[i] << ", ";
	cout << a[a.size() - 1] << "]" << endl;
}

int main()
{
	srand((unsigned int)time(0));
	
	vector<int> a;
	for (int i = 1; i <= VECTOR_SIZE; i++)
		a.push_back(i);
	
	shuffleVector(a);
	printVector(a);
	
	selectionSort(a);
	printVector(a);
}