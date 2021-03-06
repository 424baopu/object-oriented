// WordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<regex>
#include<map>
using namespace std;

map<string, int> M;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

int countChar(char *filename)
{
	int count = 0;
	ifstream file;//创建一个输入流
	file.open(filename);//将文件和输入流关联起来
	char ch;
	while ((ch=file.get())!=EOF) count++;
	file.close();

	return count;
}

int countLines(char *filename)
{
	ifstream file;
	file.open(filename);
	string str;
	int count = 0;
	regex rx("^\\s*$");//空行表达式
	while (getline(file, str)) {
		if (!regex_match(str, rx)) count++;
	}	
	file.close();

	return count;
}

vector < pair<string, int>> ans;
void ini(char *filename)
{
	ifstream file;
	file.open(filename);
	string str;
	int count = 0;
	regex rx("\\b[a-zA-Z]{4}[a-zA-Z0-9]*");
	while (getline(file,str) ){
		smatch m;
		while (regex_search(str, m, rx)) {
			//cout << m[0] << " ";
			string s = m[0];
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] >= 'A'&&s[i] <= 'Z') s[i] += 32;
			}
			M[s]++;
			str = m.suffix().str();
		}
	}
	file.close();
}

int countWords()
{
	int count = 0;
	for (auto x : M) {
		count+=x.second;
	}

	return count;
}

void topTenWords()
{
	
	for (auto x : M) {
		ans.push_back(x);
	}
	sort(ans.begin(), ans.end(), cmp);
}

int main()
{	
	char s[105];
	cout << "input the filename: ";
	cin >> s;
	int count = 10;
	ofstream fout("result.txt");	
	fout << "characters: " << countChar(s) << endl;
	cout << "characters: " << countChar(s) << endl;
	fout << "lines: " << countLines(s) << endl;
	cout << "lines: " << countLines(s) << endl;
	ini(s);
	fout << "words: " << countWords() << endl;
	cout << "words: " << countWords() << endl;
	topTenWords();
	for (auto x : ans) {
		if (!count) break;
		fout << x.first << " " << x.second << endl;
		cout << x.first << " " << x.second << endl;
		count--;
	}
	fout.close();

	return 0;
}