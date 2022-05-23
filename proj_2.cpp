#include<iostream>
#include <vector>
#include <iomanip>
#include <bitset>
#include<string>
using namespace std;

int main() {
	vector<char> outcome(3, 'N');//初始狀態
	vector<int>process = {0,0,0,0,0,0,0,0};//0=SN, 1=WN, 2=WT, 3=ST
	char predict;
	char c;//input outcome
	while (cin>>c ){
		//cin.ignore();
		outcome.push_back(c);
		if (cin.peek() == '\n') {
			//cin.ignore();
			break;
		}
		
	}
	for (int i = 3; i < outcome.size(); i++)
	{
		//history determination
		//000,001,010,011,100,101,110,111--> 0 ~ 7
		int history = 0;
		//往前3個的outcome來update history
		if (outcome[i - 1] == 'T') {
			history += 1;
		}
		if (outcome[i - 2] == 'T') {
			history += 2;
		}
		if (outcome[i - 3] == 'T') {
			history += 4;
		}
		
		cout<< bitset<3>(history) << "  ";
		for (int i = 0; i < 8; i++) {
			if (process[i] == 0) {
				cout << "SN" << " ";
			}
			else if (process[i] == 1) {
				cout << "WN" << " ";
			}
			else if (process[i] == 2) {
				cout << "WT" << " ";
			}
			else{
				cout << "ST" << " ";
			}
		}
		//cout << endl;
		if (process[history] == 0 || process[history] == 1) {//SN & WN
			predict = 'N';
		}
		else {
			predict = 'T';//ST & WT
		}
		if (outcome[i] == 'T' && process[history] < 3) {//process[history] = 3時 已是ST
			process[history]++;
		}
		if (outcome[i] == 'N' && process[history] > 0) {//process[history] = 0時 已是SW
			process[history]--;
		}
			
		cout << predict << " "<< outcome[i];
		cout << endl;
			
	}
}