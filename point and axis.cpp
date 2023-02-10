#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<set>
#include<cstring>
using namespace std;
struct Point{
	char name[6];
	int pointx;
	int pointy;
};
struct Maxx{
		bool operator()(const Point &a1,const Point &a2){
			return a1.pointx>a2.pointx;
		}
};
struct Minx{
		bool operator()(const Point &a1,const Point &a2){
			return a1.pointx<a2.pointx;
		}
};
struct Maxy{
		bool operator()(const Point &a1,const Point &a2){
			return a1.pointy>a2.pointy;
		}
};
struct Miny{
		bool operator()(const Point &a1,const Point &a2){
			return a1.pointy<a2.pointy;
		}
};

int main(){
	vector<int> X;
	vector<int> Y;
	vector<Point> P1;
	vector<Point> P2;
	ifstream srcFilex("C:\\Users\\zhaozhenming.SMEDI_GK\\Desktop\\axis-x.txt",ios::in);
	//input x axis
	ifstream srcFiley("C:\\Users\\zhaozhenming.SMEDI_GK\\Desktop\\axis-y.txt",ios::in);
	//input y axis
	ofstream destFile("C:\\Users\\zhaozhenming.SMEDI_GK\\Desktop\\axis-x1.txt",ios::out);
	int x;
	int y;
	while(srcFilex>>x)
		X.push_back(x);
	while(srcFiley>>y)
		Y.push_back(y);
	ifstream srcFilep("C:\\Users\\zhaozhenming.SMEDI_GK\\Desktop\\point.txt",ios::in);
	//input point
	Point p;
	while(srcFilep >> p.name >> p.pointx>>p.pointy)
		P1.push_back(p);
//		for(int k=0;k<=P1.size();k++){
//		cout<<P1[k].name<<"----"<<P1[k].pointx<<" ------  "<<P1[k].pointy<<endl;}
	P2.push_back(P1[0]);
//	cout<<P2[0].name<<"----"<<P2[0].pointx<<" ------  "<<P2[0].pointy<<endl;
	int j=0;
	int maxpx;
	int minpx;
	int maxpy;
	int minpy;
	destFile<<"编号    数量（m）   数量（根）   位置"<<endl;
	for(int h=1;h<P1.size();h++){
				if((h!=P1.size()-1)&&!strcmp(P1[h].name,P1[h-1].name)){
			j++;
			P2.push_back(P1[h]);
//			cout<<P2[j].pointx<<" ------  "<<P2[j].pointy<<endl;
		}

		else {
		
			
//		cout<<P2[0].name<<endl;
		sort(P2.begin(),P2.end(),Maxx());
		int maxpx=P2.begin()->pointx;
		sort(P2.begin(),P2.end(),Minx());
		int minpx=P2.begin()->pointx;
		sort(P2.begin(),P2.end(),Maxy());
		int maxpy=P2.begin()->pointy;
		sort(P2.begin(),P2.end(),Miny());
		int minpy=P2.begin()->pointy;
		
//		destFile<<maxpx<<" "<<minpx<<" "<<maxpy<<" "<<minpy<<endl;
		int posminx=lower_bound(X.begin(),X.end(),minpx)-X.begin();
		int posmaxx=upper_bound(X.begin(),X.end(),maxpx)-X.begin()+1;
		int posminy=lower_bound(Y.begin(),Y.end(),minpy)-Y.begin()+64;
		int posmaxy=upper_bound(Y.begin(),Y.end(),maxpy)-Y.begin()+65;
		destFile<<P2[0].name<<" "<<(j+1)*2<<" "<<j+1<<"   站台层"<<posminx<<"-"<<posmaxx<<"轴和"<<char(posminy)<<"-"<<char(posmaxy)<<"之间"<<endl;
		P2.clear();
		j=0;
		P2.push_back(P1[h]);
		}
}
//
    destFile.close();
	srcFilex.close();
	srcFiley.close();
	srcFilep.close();
	return 0;
}
