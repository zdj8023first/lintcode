#include <iostream>
#include <vector>
// define statement should not end with a semicolon
#define CUTOFF 0
using namespace std;

// swap a and b
void swap_self(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// the insertion sort
void insert_sort(int a[],int n){
    //from 1 to n-1
    for(int i = 1; i< n; i++){
        //save value to insert
        int tmp = a[i];
        int j;
        //if a[j] is bigger than value , move it backwards
        for(j = i-1;j>=0 && a[j]>tmp; j--)
            a[j+1] = a[j];
        //insert a[i] at the porper position
        a[j+1] = tmp;
    }
}

// the quicksort routin
// the partition part
int partition_self(int a[],int low, int high){
    int pivot = a[low], l= low+1, h = high;
    while(l<=h){
        //这里if的顺序如果颠倒，结果是完全不一样的，这是为什么呢！！！！！！！！fuck
        if(a[l]>pivot && a[h]<pivot)
            swap(a[l++],a[h--]);
        if(a[l]<=pivot) ++l;
        if(a[h]>=pivot) --h;

    }
    swap(a[low],a[h]);
    return h;
}

//C++'s array range should be [low, up], the same as [low, up+1)
// this is correct
int partition_another(int vi[], int low, int up)
{
	int pivot = vi[up];
	int i = low-1;
	for (int j = low; j < up; j++)
	{
		if(vi[j] <= pivot)
		{
			i++;
			swap(vi[i], vi[j]);
		}
	}
	swap(vi[i+1], vi[up]);
	return i+1;
}
int PartSort(int a[],int left,int right)
{
	int key = a[right];
	while(left < right)
	{
		while(left < right && a[left] <= key)
		{
			++left;
		}
		while(left < right && a[right] >= key)
		{
			--right;
		}
		swap(a[left],a[right]);
	}
	swap(a[left],key);
	return left;
}

//this is clearly no problem
void quicksort(int a[],int low, int high){

    if(low<high){
        int position = partition_another(a,low,high);
        quicksort(a,low,position-1);
        quicksort(a,position+1,high);
    }
//    else
//        insert_sort(a+low,high-low+1);
}

void print_array(int a[],int n){
    for(int i = 0; i<n;i++)
        printf("%d%c",a[i],(i==n-1?'\n':' '));
}

int main(){
    int n=10;
    int a[] = {2,3,1,4,8,5,10,9,7,6};

    //test insertion sort
    //insert_sort(a,n);

    //test quick sort

    quicksort(a,0,n-1);
    print_array(a,n);


//    int x=4, y=3;
//
//    // test for swap
//    swap(x,y);
//    printf("%d  %d",x,y);
    return 0;
}
