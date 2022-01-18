//Nolan Jaeger 
//CS 3305
//Spring 2021
//Dr.Haddad
//Assignment 12
#include<iostream>

using namespace std;

int main(){
        int choice, inputmode = 0;
        int nodes, i, j, sum;
        int A1[5][5] = {0};
        int A2[5][5] = {0};
        int A3[5][5] = {0};
        int A4[5][5] = {0};
        int A5[5][5] = {0};

        
        while(1){
                cout<<"---MAIN MENU---------"<<endl;
                cout<<"0 - Exit Program"<<endl;
                cout<<"1 - Enter Graph Data"<<endl;
                cout<<"2 - Print Outputs"<<endl;
                cout<<"Enter choice >> ";
                cin >> choice;
                if(choice == 0)
                        break;
                else if(choice == 1){
                        cout<<"Enter the no of nodes: ";
                        cin >> nodes;
                        for(i = 0; i < nodes; i++){
                                for(j = 0; j < nodes; j++){
                                        cout<<"Enter A1["<<i<<", "<<j<<"]: ";
                                        cin>>A1[i][j];
                                }
                        }
                        inputmode = 1;
                }
                else if(choice == 2){
                        if(inputmode == 0){
                                cout<<"\nError: Graph data not found! Enter graph data first\n"<<endl;
                                continue;
                        }
                        
                        cout<<"In-degrees: "<<endl;
                        for(i = 0; i < nodes; i++){
                                cout<<"Node "<<i+1<<" in-degree is ";
                                sum = 0;
                                for(j = 0; j < nodes; j++)
                                        sum += A1[j][i];
                                cout<<sum<<endl;
                        }
                        cout<<endl;
                        
                        cout<<"Out-degrees: "<<endl;
                        for(i = 0; i < nodes; i++){
                                cout<<"Node "<<i+1<<" in-degree is ";
                                sum = 0;
                                for(j = 0; j < nodes; j++)
                                        sum += A1[i][j];
                                cout<<sum<<endl;
                        }
                        cout<<endl;
                        
                        sum = 0;
                        cout<<"Total number of self-loops: ";
                        for(i = 0; i < nodes; i++){
                                sum += A1[i][i];
                        }
                        cout<<sum<<endl;
                        
                        
                        inputmode = 0;
                                
                }
                else
                        cout<<"Error! Wrong Input"<<endl;
        }
        
}