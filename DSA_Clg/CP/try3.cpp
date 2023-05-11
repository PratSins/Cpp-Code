//#include "stdafx.h"
#include <iostream>

using namespace std;

void Pass(int arr[],int i,int N)
{
	if(i==0)
	{

		if(arr[N-1]<N)
		{
			++arr[N-1];
			--arr[i];
		}
		else
		{
			if(arr[i+1]<N)
			{
				++arr[i+1];
				--arr[i];

			}
			else
			{
				++arr[i+1];
				--arr[i];
			}
		}
	}

	if(i==(N-1))
	{

		if(arr[i-1]<N)
		{
			++arr[i-1];
			--arr[i];
		}
		else
		{
			if(arr[0]<N)
			{
				++arr[0];
				--arr[i];

			}
			else
			{
				++arr[0];
				--arr[i];
			}
		}
	}
	else
	{
		if(arr[i-1]<N)
		{
			++arr[i-1];
			--arr[i];
		}
		else
		{
			if(arr[i+1]<N)
			{
				++arr[i+1];
				--arr[i];

			}
			else
			{

				++arr[i+1];
				--arr[i];
			}
		}
	}

}
int main()
{
	int N=4;
	int arr[4]={1,3,9,7};
	int count=0;

	int flag=1;
	while(flag)
	{
		for(int i=0;i<N;i++)
		{
			if(arr[i]>N)
			{

				++count;

				Pass(arr,i,N);


			}
		}
		int j;
		for(j=0;j<N;j++)
		{
			if(arr[j]!=N)
			{
				flag=1;
				break;
			}
		}
		if(j==N)
			flag=0;
	}

	cout<<"Number of Passes"<<count;

	return 0;
}