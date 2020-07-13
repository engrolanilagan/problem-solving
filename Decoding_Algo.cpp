//Problem from https://www.hackerrank.com/challenges/cipher

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the cipher function below.
vector<int> cipher(int n, int k, string s) {
    vector<int> decodedMessage;
    int arr[n];
    int res[n];

    for(int i=0; i<n; i++)
    {
        arr[i] = (int)s[i]%48;
        
        if(i==0)
            res[0]=arr[0];
        else if(i<k)
            res[i]=arr[i]^arr[i-1];
        else
            res[i]=arr[i]^arr[i-1]^res[i-k];
        
        decodedMessage.push_back(res[i]);
    }    

    return decodedMessage;
}


int main()
{
    int n, k;
    cin>> n >> k;
    string encodedMessage;
    cin>> encodedMessage;

    vector<int> decodedMessage = cipher(n, k, encodedMessage);
    for(int i=0; i<n; i++){
        cout<<decodedMessage[i];
    }
}
