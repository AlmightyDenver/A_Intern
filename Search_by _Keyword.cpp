#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h> //strtok_s
#include <vector>
#include <map>
#include <algorithm> //transform
using namespace std;

//�� ���� ��
vector<int> duplication(vector<int>& a, vector<int>& b) {
	vector<int> vec;
	vector<int>::iterator ita;
	vector<int>::iterator itb;

	for (ita = a.begin(); ita != a.end(); ita++) {
		for (itb = b.begin(); itb != b.end(); itb++) {
			if (*ita == *itb) vec.push_back(*ita);
			itb++;
		}
	}
	return vec;
}

//�ҹ��� ��ȯ
char* charToLower(char* str) {
	unsigned char* mystr = (unsigned char*)str;
	while (*mystr) {
		*mystr = tolower(*mystr);
		mystr++;
	}
	return str;
}

//tokenize (�ڸ� ���ڿ�, ������, �ҹ��ڷ� ��ȯ ����)
vector<string> tokenize(char str[], const char* split, bool flag) {
	vector<string> vec;
	char* context = NULL; //�и� �� ���� ���ڿ�
	char* token = strtok_s(str, split, &context);
	while (token != NULL) {
		if (flag) {
			charToLower(token);
		}
		vec.push_back(token);
		token = strtok_s(NULL, "\n", &context);
	}
	return vec;
}

int main() {
	vector<string> findKeywords;
	vector<string> vecStrData;
	string strInput;
	map<string, vector<int>> dic;

	//DB
	char strData[] = "[1] Character Sequence OF the string.Besides the similarity of characters,\n[2] the order of characters is considered to be important in most of the string similarity metrics.\n[3] By the impact of big data studies, the timeand memory complexity of the string similarity metrics are considered to be more important.\n[4] We propose a new string similarity metric, which is built over a hashing function. \n[5] In this paper, we will briefly introduce the idea behind string similarity metricsand their applications.After the idea of string similarity, \n[6] We will introduce some of the advanced hashing functionsand their suitability on string metrics.\n[7] Finally we will introduce a novel string similarity metric and we will discuss the success rate of novel method over the current methods.\n[8] Convert uppercase letter to lowercase\n[9] Converts c to its lowercase equivalent if c is an uppercase letterand has a lowercase equivalent.\n[10] If no such conversion is possible, the value returned is c unchanged.\n[11] Notice that what is considered a letter may depend on the locale being used";
	vecStrData = tokenize(strData, "\n", false);

	//words indexing. Dict �����
	for (int i = 0; i <vecStrData.size(); ++i) {
		char* str = new char[vecStrData[i].size() + 1];
		strcpy(str, vecStrData[i].c_str());
		char* context = NULL; //�и� �� ���� ���ڿ�
		char* token = strtok_s(str, " ", &context);
		while (token != NULL) {
			//�ҹ��ڷ�
			charToLower(token);
			//dic�� �ֱ�
			if (dic.find(token) == dic.end()) {
				//������
				vector<int> index;
				index.push_back(i);
				dic[token] = index;
			}
			//������ index �߰�
			else {
				dic[token].push_back(i);
			}

			token = strtok_s(NULL, " ", &context);
		}
	}


	//tokenize input
	while (true) {
		cout << "�˻�� �Է��ϼ��� : ";
		getline(cin, strInput);
		//0�Է½� ����
		if (strInput == "0") {
			cout << "����";
			return false;
		}
		char* str = new char[strInput.size() + 1];
		strcpy(str, strInput.c_str());
		findKeywords = tokenize(str, " ", true);

		//Find common index. �� keyword �� ���� ���� ã�Ƽ� ����Ȱ� �� vecCommonIdx �� ��� 
		vector<int> vecIntersect = dic[findKeywords[0]];
		for (int i = 1; i < findKeywords.size(); ++i) {
			vecIntersect = duplication(vecIntersect, dic[findKeywords[i]]);
		}
		//�ߺ� ����
		sort(vecIntersect.begin(), vecIntersect.end());
		vecIntersect.erase(unique(vecIntersect.begin(), vecIntersect.end()), vecIntersect.end());
		
		//print
		for (int i = 0; i < vecIntersect.size(); ++i) {
			cout << vecStrData[vecIntersect[i]] << '\n';
		}
		cout << '\n';
	}

	


	return 0;
}