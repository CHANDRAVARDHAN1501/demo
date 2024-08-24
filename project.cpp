#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quicksort(int balance[], int user_id[], int low, int high) {
    if (low<high) {
        int pivot=balance[high];
        int i=(low-1);
        for (int j=low;j<=high-1;j++) {
            if (balance[j]<=pivot) {
                i++;
                swap(balance[i],balance[j]);
                swap(user_id[i],user_id[j]);
            }
        }

        swap(balance[i+1],balance[high]);
        swap(user_id[i+1],user_id[high]);

        quicksort(balance,user_id,low,i);
        quicksort(balance, user_id,i+2,high);
    }
}


int main() {
    int n;
    cin>>n;

    int user_id[n],balance[n];
    for(int i=0;i<n;i++)
        cin>>user_id[i]>>balance[i];

    int t;
    cin>>t;
    string result[t];
    int result_index=0;
    while(t--){
        int sender_index=-1,reciever_index=-1;
        int from_userID,to_userID,amount;
        cin>>from_userID>>to_userID>>amount;
        for(int i=0;i<n;i++){
            if(user_id[i]==from_userID)
            {
                sender_index=i;
            }
            else if(user_id[i] == to_userID)
            {
                reciever_index=i;
            }
        }
            if(sender_index!=-1 && reciever_index!=-1 && balance[sender_index]>=amount)
            {
                balance[sender_index]-=amount;
                balance[reciever_index]+=amount;
               // cout<<"Success"<<"\n";
                result[result_index++]="Success";
            }
            else
            {
                //cout<<"Failure"<<"\n";
                result[result_index++]="Failure";
            }
        }


        quicksort(balance,user_id,0,n-1);
        for(int i=0;i<result_index;i++){
        cout<<result[i]<<endl;
        }
        cout<<endl;
        for (int i=0; i<n;i++) {
        cout<<user_id[i]<<" "<< balance[i]<<endl;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

