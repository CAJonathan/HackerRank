#include<iostream>
#include<vector>
#include<ctime>
#include<cmath>

using namespace std;

int T;
const int N = 100000;
int *testCase = new int[T];
vector <int> prime;

bool isPrime(int number)
{
	int count = 0;
	for(int i = 1 ; i <= (int)sqrt(number) ; i ++)
	{
		if(number % i == 0)
		{
			count ++;
		}
	}
	if(count > 1) return false;
	return true;
}

void createPrime()
{
	bool *number = new bool[N];
	for(int i = 0 ; i < N ; i ++)
	{
		number[i] = true;
	}
	number[0] = number[1] = false;
	int count = N - 2;
	
	for(int i = 2 ; i < N ; i ++)
	{
		if(number[i] == false)
		{
			continue;
		}
		
		if(!isPrime(i))
		{
			number[i] = false;
			count --;
		}else{
			count --;
		}
		
		for(int j = i + 1 ; j < N ; j ++)
		{
			if(j % i != 0 || number[j] == false)
			{
				continue;
			}
			number[j] = false;
			count --;
		}
	}
	
	for(int i = 0 ; i < N ; i ++)
	{
		if(number[i] == true)
		{
			prime.push_back(i);
		}
	}
		
	if(count == 0)
	{
		return;
	}
}

int main()
{
	clock_t t = clock();
	createPrime();
	t = clock() - t;
	cout << prime.size() << endl;
	cout << t;
	return 0;
}
