#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    int M = matrix.size();
    int N = matrix[0].size();
    int numRings = min(M, N) / 2;
    for(int i = 0; i < numRings; ++i) {
        // Subtract the number of 360 degree rotations from R
        // A 360 degree rotation = rotating the same number of times as the perimeter of the current ring
        int numRotations = r%(2*(M+N-4*i)-4);
        for(int rotation = 0; rotation < numRotations; ++rotation) {
            // Rotate the ring (see the clockwise algorithm for an in-depth example of how this is done)
            // Rotate top row
            for(int j = i; j < N-i-1; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][j+1];
                matrix[i][j+1] = tmp;
            }
            // Rotate right column
            for(int j = i; j < M-i-1; ++j) {
                int tmp = matrix[j][N-i-1];
                matrix[j][N-i-1] = matrix[j+1][N-i-1];
                matrix[j+1][N-i-1] = tmp;
            }
            // Rotate bottom row
            for(int j = N-i-1; j > i; j--) {
                int tmp = matrix[M-i-1][j];
                matrix[M-i-1][j] = matrix[M-i-1][j-1];
                matrix[M-i-1][j-1] = tmp;
            }
            // Rotate left column
            for(int j = M-i-1; j > i+1; j--) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[j-1][i];
                matrix[j-1][i] = tmp;
            }
        }
    }
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) cout << matrix[i][j] << " ";
        cout<<"\n";
    }
    return;
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

