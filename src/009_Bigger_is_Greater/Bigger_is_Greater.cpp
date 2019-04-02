#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    pair<int, int> solution = {-1, -1};

    for(int j = w.size() - 1; j >= 0; --j) {
        for(int i = j; i >= 0; --i) {
            if(w[i] < w[j] && i > solution.first) solution = {i, j};
        }
    }    

    if (solution.first == solution.second) return "no answer";
    else {
        swap(w[solution.first], w[solution.second]);
        sort(w.begin() + solution.first + 1, w.end(), less<int>());
        return w;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

