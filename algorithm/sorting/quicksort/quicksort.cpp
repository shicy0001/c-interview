#include<vector>
#include<iostream>
using namespace std;

void swap(vector<int> &a, int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(vector<int> &a, int low, int high)
{
    int i = low,j = high,base = a[low];
    while(i<j)
    {
        while(a[j] >= base && i<j) j--;
        while(a[i] <= base && i<j) i++;

        if(i<j)
            swap(a,i,j);
    }

    swap(a,low,j);
    return j;
}

void quicksort(vector<int> &a, int low, int high)
{
    if(low >= high) return;

    int base = partition(a, low, high);
    quicksort(a, low, base -1);
    quicksort(a, base+1, high);
}

int main()
{
    vector<int> a ={6,1,2,7,9,3,4,5,10,8};

    quicksort(a, 0, a.size() -1);
    vector<int>::iterator iter = a.begin();
    while(iter != a.end())
    {
	cout<<*iter<<endl;    
	iter++;
    }
    return 0;
}


