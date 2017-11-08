#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
using namespace std;

int x1,y1,x2,y2;
int **map;
bool** mark;
pair<int, int>** prev;
queue<pair <int,int> > q;
int rows,columns;


void adj(int a,int b){

	if(a-1<rows && a-1>0&&b<columns&&b>0&&map[a-1][b]==0) {mark[a-1][b]=true;q.push({a-1,b});}
	if(a+1<rows&&a+1>0&&b<columns&&b>0&&map[a+1][b]==0) {mark[a+1][b]=true;q.push({a+1,b});}
	if(a<rows&&a>0&&b-1<columns&&b-1>0&&map[a][b-1]==0) {mark[a][b-1]=true;q.push({a,b-1});}
	if(a<rows&&a>0&&b+1<columns&&b+1>0&&map[a][b+1]==0) {mark[a][b+1]=true;q.push({a,b+1});}
	if(a-1<rows&&a-1>0&&b-1<columns&&b-1>0&&map[a-1][b-1]==0) {mark[a-1][b-1]=true;q.push({a-1,b-1});}
	if(a+1<rows&&a+1>0&&b+1<columns&&b+1>0&&map[a+1][b+1]==0) {mark[a+1][b+1]=true;q.push({a+1,b+1});}
	if(a-1<rows&&a-1>0&&b+1<columns&&b+1>0&&map[a-1][b+1]==0) {mark[a-1][b+1]=true;q.push({a-1,b+1});}
	if(a+1<rows&&a+1>0&&b-1<columns&&b-1>0&&map[a+1][b-1]==0) {mark[a+1][b-1]=true;q.push({a+1,b-1});}

}

void bfs(){
	cout << "bfs!"<<endl;

	
	q.push({x1,y1});
	mark[x1][y1]=true;
	prev[x1][y1]={x1,y1};
	// adj(x1,y1);
	pair <int,int> tempPrev ={x1,y1};
	while(!q.isEmpty()){
		pair<int,int> t=q.front();
		q.pop();
		prev[t.first][t.second]=tempPrev;
		adj(t.first,t.second);
		tempPrev=t;
	}
	int a=x2;int b=y2;
	cout <<"path is"<<endl;
	while(prev[a][b]!={x1,y1}){
		cout << prev[a][b].first <<" "<<prev[a][b].second<<endl;
		a=prev[a][b].first;
		b=prev[a][b].second;
	}

}


int main(){

	fstream file;
	char* a;
	cin >> a;
	file.open(a);
	
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;



	char c;

	string s;file >>s;cout << s<<endl;
	string delimiter = ",";
	int pos=s.find(delimiter);
	cout << pos <<endl<<s.length();
	stringstream bob(s.substr(0,pos));
	bob >> rows ;
	cout << s.substr(pos,s.length()) << endl;
	stringstream bob2(s.substr(pos+1,s.length()));
	bob2 >> columns;

	cout << "row is :" << rows <<endl <<"column is :" <<columns <<endl;
	

	// int map[rows][columns];
	map=new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		map[i]=new int[columns];
	}

	mark=new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		mark[i]=new int[columns];
	}

	prev=new pair<int,int>*[rows];
	for (int i = 0; i < rows; ++i)
	{
		prev[i]=new pair<int,int>[columns];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{	

			file >> c;
			while(c==',') file >> c;
			map[i][j] =c-48;
		}
	}


	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{	
			cout << map[i][j] <<"  ";
		}cout <<endl;
	}




	return 0;
}