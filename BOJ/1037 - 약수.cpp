#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int arr[51];

int main()
{
	int N;
	long long temp, result;

	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+N);
	
	cout << arr[0]*arr[N-1];
	return 0;
}
