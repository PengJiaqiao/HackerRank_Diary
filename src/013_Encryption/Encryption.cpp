#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    float l = sqrt(s.size());
    int h = (int) l;
    int w = (int) ceil(l);
    string res = "";
        
    for(int i = 0; i < w; ++i) {
        int j = i;
        while(j < s.size()) {
            res += s[j];
            j += w;
        }
        res += " ";
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

