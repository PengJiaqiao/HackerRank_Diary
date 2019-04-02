#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
bool isSame(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < a.size(); ++i) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

string organizingContainers(vector<vector<int>> container) {
    int n = container.size();

    vector<int> rowSums(n);
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < n; ++c) rowSums[r] += container[r][c];
    }

    vector<int> colSums(n);
    for(int c = 0; c < n; ++c) {
        for(int r = 0; r < n; ++r) colSums[c] += container[r][c];
    }

    if(isSame(rowSums, colSums)) return "Possible";
    else return "Impossible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

