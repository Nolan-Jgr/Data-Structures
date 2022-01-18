//Nolan jaeger
//CS 3305
//Spring 2021
//Dr.Haddad
//Assigment11
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
void HF1(int t[][2], int k[]);
void HF2(int t[][2],int k[]);
void HF3(int t[][2], int k[]);
int sumProbes(int t[][2]);

int main()
{
    int keys[] = {1234,8234,7867,1009,5438,4312,3420,9487,5418,5299,5078,8239,1208,5098,5195,5329,4543,3344,7698,5412,5567,5672,7934,1254,6091,8732,3095,1975,3843,5589,5439,8907,4097,3096,4310,5298,9156,3895,6673,7871,5787,9289,4553,7822,8755,3398,6774,8289,7665,5523};
    string menu = "-----MAIN MENU-----\n0 - Quit Program\n1 - Run HF1(Division Method with linear probing)\n2 - Run HF2(Division Method with Quadratic Probing)\n3 - Run HF3(Division Method with Double Hashing)";
    int Table[50][2];
	for(int i = 0; i < sizeof(Table)/sizeof(Table[0]);i++){
		Table[i][0] = 0;
		Table[i][1] = 0;
	}
    cout << menu << endl;
    int input;
    cin >> input;
        switch(input){
			case 0:{
				return EXIT_SUCCESS;
			}break;
            case 1:{
                HF1(Table,keys);
				cout << "Index\t\tKey\t\tProbes" << endl;
				cout << "------------------------" << endl;
				for(int j = 0; j < (sizeof(Table)/sizeof(Table[0]));j++){
					cout << j << "\t\t" << Table[j][0] << "\t\t" << Table[j][1] << endl;
				}
				cout << "------------------------" << endl;
				cout << "Sum of Probes = " << sumProbes(Table);
            }break;
            case 2:{
                HF2(Table,keys);
				cout << "Index\t\tKey\t\tProbes" << endl;
				cout << "------------------------" << endl;
				for(int j = 0; j < (sizeof(Table)/sizeof(Table[0]));j++){
					cout << j << "\t\t" << Table[j][0] << "\t\t" << Table[j][1] << endl;
				}
				cout << "------------------------" << endl;
				cout << "Sum of Probes = " << sumProbes(Table);
            }break;
            case 3:{
                HF3(Table,keys);
				cout << "Index\t\tKey\t\tProbes" << endl;
				cout << "------------------------" << endl;
				for(int j = 0; j < (sizeof(Table)/sizeof(Table[0]));j++){
					cout << j << "\t\t" << Table[j][0] << "\t\t" << Table[j][1] << endl;
				}
				cout << "------------------------" << endl;
				cout << "Sum of Probes = " << sumProbes(Table);
            }break;
            default:
                cout << "Invalid Input" << endl;
        }
    
    return EXIT_SUCCESS;
}
int sumProbes(int t[][2]){
    int sum = 0;
	int tsize = 50;
    for(int i = 0; i < tsize;i++)
    {
        sum += t[i][1];
    }
    return sum;
}
void HF1(int t[][2], int k[]){
	int tsize = 50;
    for(int i = 0;i < tsize;i++)
    {
        int index = k[i] % tsize;
        int probe = 0;
		if(index >= tsize){
			index = index % tsize;
		}
		for(int ind = index; ind <= tsize;ind++){
			if(ind == tsize){
				ind  = 0;
			}
			if(t[ind][0] == 0){
				t[ind][0] = k[i];
				t[ind][1] = probe;
				break;
			}
			else{
				probe++;
			}
		}
    }
}

void HF2(int t[][2],int k[]){
	int tsize = 50;
    for(int i = 0;i < tsize ;i++){
        int index = k[i] % tsize;
		if(index == tsize){
			index = 0;
		}
        int probe = 0;
		int ind = index;
        while(ind != tsize){
			if(ind > tsize){
				ind = ind % tsize;
			}
			if(t[ind][0] == 0){
				t[ind][0] = k[i];
				t[ind][1] = probe;
				break;
			}
			else{
				probe++;
			}
			if((index + (probe*probe) == tsize)){
				ind = 0;
				continue;
			}
			ind = (index + (probe*probe))%tsize;
			
			
		}
    }
    
}
void HF3(int t[][2], int k[]){
	int tsize = 50;
    for(int i = 0;i < tsize;i++){
        int index = k[i] % tsize;
		if(index == tsize){
			index = 0;
		}
        int index2 = 30 - k[i] % 25;
        int probe = 0;
		int ind = index;
		while(ind != tsize){
			if(ind > tsize){
				ind = ind % tsize;
			}
			if(t[ind][0] == 0){
				t[ind][0] = k[i];
				t[ind][1] = probe;
				break;
			}
			else{
				probe++;
			}
			if(probe > tsize){
				cout << "Unable to hash key " << k[i] << " into table" << endl;
				break;
			}
			if((index + (index+probe*index2)) == tsize)
			{
				ind = 0;
				continue;
			}
			ind = (index + probe * index2)%tsize;
		}
	}
}