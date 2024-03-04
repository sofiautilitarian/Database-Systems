
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std ;

int bucketSize = 1 ;
int bucketNum = 2 ;
vector<vector<string>>data(bucketNum);



void reallocate()
{

    bucketNum += 1;
    data.resize(bucketNum);
}

int conversion (string str)
{
    int val = 0;
    val+=(int)str[0]+(int)str[1]+(int)str[2];
    return val;
}

int hashFunction(int n)
{
    return n % bucketNum ;
}



void insertItem(string n)
{
    int index = hashFunction(conversion(n)) ;

    if(data[index].size() < bucketSize)
    {
        data[index].push_back(n) ;
        cout << "Successfully inserted" << endl ;
    }

    else if (data[index].size() == bucketSize || index == bucketNum || index > bucketNum)
    {
        index = data.size();
        reallocate();
        data[index].push_back(n);
    }

    else
    {
        cout << "Bucket Overflow, insertion failed" << endl ;
    }
}

int searchItem(string n)
{
    int index = hashFunction(conversion(n)) ;
    for(int i = 0 ; i < data[index].size() ; i++)
    {
        if(data[index][i] == n)
        {
            cout << "found at: " << index << " " << i << endl ;
            return i ;
        }
    }
    return -1 ;
}


void deleteItem(string n)
{
    int index = hashFunction(conversion(n));
    int position = searchItem(n);

    if (position != -1)
    {
        vector<string>::iterator it;
        it = data[index].begin() + position;
        data[index].erase(it) ;
        cout << "Successfully deleted value: " << n << endl;
    }
    else
    {
        cout << "Value " << n << " not found, deletion is not possible" << endl;
    }
}




void view()
{
    for(int i = 0 ; i < bucketNum ; i++)
    {
        if(data[i].size() > 0)
        {
            cout << "Bucket " << i << ": " ;
            for(int j = 0 ; j < data[i].size() ; j++)
            {
                cout << data[i][j] << " " ;
            }
            cout<<endl ;
        }

    }
}
int main()
{
    int choice ;
    string dept;

    while(true)
    {
        cout << "Press 1 for insert 2 for search 3 for view 4 for delete and any key for exit" << endl ;
        cout << "Choice: " ;
        cin >> choice ;
        if(choice == 1)
        {

            cout<< "Department: " ;
            cin >> dept ;

            insertItem(dept) ;
        }
        else if(choice == 2)
        {
            cout << "search Key: " ;
            cin >> dept ;

            int n = searchItem(dept) ;
            if(n == -1) cout << "Not Found" << endl ;
        }

        else if(choice == 3)
        {
            view() ;
        }
        else if(choice == 4)
        {
            cout << "search Key: " ;
            cin >> dept ;

            deleteItem(dept) ;
        }
        else return 0 ;
    }

    return 0;
}

