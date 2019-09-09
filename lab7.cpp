#include <bits/stdc++.h> 
using namespace std; 
vector<string> a;

void swp(string* s1,string* s2)
{string temp=*s1;
*s1=*s2;
*s2=temp;
}


int partition (vector<string>&a, int low, int high) 
{ 
	string pivot = a[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high - 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (a[j] > pivot) 
		{ 
			i++; // increment index of smaller element 
			swp(&a[i],&a[j]); 
		} 
	} 
	swp(&a[i + 1],&a[high]); 
	return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(vector<string>&a, int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(a, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(a, low, pi - 1); 
		quickSort(a, pi + 1, high); 
	} 
} 


int main()
{int t,n;
string s="",s1="";
cin>>t;
vector<string> a;
int i,j;
for(i=0;i<t;i++)
{cin>>n;
	for(j=0;j<n;j++)
		{cin>>s1;
			a.push_back(s1);}
	int low=0,high=n-1;
	quickSort(a,low,high);
	for(j=0;j<n;j++)
		s=s+a[j];
cout<<s<<endl;
	s.clear();
	s1.clear();
	a.clear();	}
					}
	
