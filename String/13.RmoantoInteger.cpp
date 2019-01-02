#include "stdio.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	int romanToInt(string s){
		map<char,int> r_map={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
		int num = 0;
		for(auto it = s.begin();it!=s.end();++it){
			int c = r_map[*it];
			num+=((it!=s.end()-1)&&c<r_map[*(it+1)])?-c:c;
		}		
		return num;
	}
/*
	int romanToInt(string s){
		vector<string> roman_vec;
		roman_vec.push_back("M");
		roman_vec.push_back("CM");
		roman_vec.push_back("D");
		roman_vec.push_back("CD");
		roman_vec.push_back("C");
		roman_vec.push_back("XC");
		roman_vec.push_back("L");
		roman_vec.push_back("XL");
		roman_vec.push_back("X");
		roman_vec.push_back("IX");
		roman_vec.push_back("V");
		roman_vec.push_back("IV");
		roman_vec.push_back("I");
		
		map<string,int> roman_map;
		roman_map["M"]=1000;		
		roman_map["CM"]=900;		
		roman_map["D"]=500;		
		roman_map["CD"]=400;		
		roman_map["C"]=100;		
		roman_map["XC"]=90;		
		roman_map["L"]=50;		
		roman_map["XL"]=40;		
		roman_map["X"]=10;		
		roman_map["IX"]=9;		
		roman_map["V"]=5;
		roman_map["IV"]=4;		
		roman_map["I"]=1;		
	
		vector<string>::iterator v_it;
		string rm_s = s;
		int num = 0;
		for(v_it = roman_vec.begin();v_it!=roman_vec.end();v_it++)
		{

			string k = *v_it;
			string sub_k = s.substr(0,k.size());
		
			cout <<"key:"<<k<<endl;
	//		cout <<"sub:"<<s.substr(0,k.size()).c_str()<<endl;			
	//		cout <<"value:"<<roman_map[k]<<";"<<endl;
			
			cout<<"cmp:"<<strcmp(k.c_str(),sub_k.c_str())<<endl;	
	
			while(0==strcmp(k.c_str(),s.substr(0,k.size()).c_str())){
				num+=roman_map[k];
				s = s.substr(k.size(),s.size());
				cout<<"inner:sub:"<<s<<";"<<endl;
			}
		}
	
		
		cout <<num<<endl;

		return num;	
	}
*/
};

int main(){

	string input1="III";
	string input2="IV";
	string input3="IX";
	string input4="LVIII";	
	string input5="MCMXCIV";

	Solution so1;
	int num1 = so1.romanToInt(input1);

	Solution so2;
	int num2 = so2.romanToInt(input2);

	Solution so3;
	int num3 = so3.romanToInt(input3);

	Solution so4;
	int num4 = so4.romanToInt(input4);
	
	Solution so5;
	int num5 = so5.romanToInt(input5);

	cout << "num1:"<< num1 << endl;
	return 0;
}
