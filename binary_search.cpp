#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int key)
{
    int s=0;
int e=n;
while(s<=e)
{
    int mid=(s+e)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key)
    {
        e=mid-1;
    }
    else
    {
        s=arr[mid]+1;
    }
}
    return -1;
}

int main()
{
    int n;
   cout<<"enter the size of array";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in array";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   int key;
   cout<<"enter the element u want  to search";
   cin>>key;
   cout<<binarySearch(arr,n,key)<<endl;
   return 0;
}
