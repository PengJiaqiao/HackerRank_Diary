#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    if(n == 1) cout << '1' << endl;
    else
    {
        vector<int> v;
        v.push_back(1); 
        for(int i = 2; i <= n; ++i) { 
            for(int j = 0; j < v.size();++j) v[j] *= i;
            int carry = 0;
            for(int j = v.size() - 1; j >= 0; --j){
                int tmp = carry + v[j];
                carry = tmp / 10;
                v[j] = tmp % 10;
            } 
            while(carry) { 
                v.insert(v.begin(), carry % 10);
                carry /= 10; 
            }
        }
        for(int i = 0; i < v.size(); ++i) cout << v[i];
        cout << endl;
        v.clear();
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}

