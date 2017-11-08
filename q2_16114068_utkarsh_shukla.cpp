#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
using namespace std; 

	int* tree=new int[10000];

void insert(int t){
	int index=0;
	while(tree[index]>-1){
		if(t>tree[index]) index=index*2+2;
		else index=index*2+1;
	}
	tree[index]=t;

}

int findt(int t){
	int index=0;
	while(tree[index]!= t){
	if(t>tree[index]) index=index*2+2;
		else index=index*2+1;
		
	}

	return index;
};

int main()
{	
for (int i = 0; i < 10000; ++i)
{
	/* code */
	tree[i]=-1;
}

	string s;
	cin >> s;
	int temp;
	stringstream bob(s);
	while(bob>>temp){
		insert(temp);
	}

	cin >> s;
	stringstream bob2(s);
	int node1;
	int node2;
	bob2 >> node1;
	bob2 >> node2;
	

	int a =findt(node1);
	int b=findt(node2);


	int desc1[500];
	int desc1pos[500];
	int desc2[500];
	int desc2pos[500];

	int i=0;
	while(a>=0){
		desc1[i]=tree[a];
		desc1pos[i]=a;
		i++;a/=2;
	}


	int j=0;
	while(b>=0){
		desc1[j]=tree[b];
		desc1pos[j]=b;
		j++;b/=2;
	}

	i--;j--;
	if(desc1[i-1]==desc2[j-1]){
		cout << desc1[i-1]<<endl;
	}else{
		if(a==0 ||a==2 ||a==1 || b==0|| b==1|| b==2)    //since we know that last element of array of descendents is the root one 
			cout << desc1[i];  //if nodes of the root
		else cout<< "Not found"<<endl;
	}

	return 0;
}