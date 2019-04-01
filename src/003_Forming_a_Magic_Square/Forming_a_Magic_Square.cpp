#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> getSquare() {
    vector<vector<int>> vSquare(3);
    for(int i=0; i < 3; ++i) {
        vSquare[i].resize(3);
        fill(vSquare[i].begin(), vSquare[i].end(), 0);
    }
    
    int iX = 0, iY = 1, iNx = 0, iNy = 0;
    vSquare[0][1] = 1;
    for(int i=2; i < 10; ++i) {
        iNx = iX - 1;
        iNy = iY - 1;
        if ( iNx < 0 )
            iNx = 2;
        if ( iNy < 0 )
            iNy = 2;
        if ( vSquare[iNx][iNy] == 0 ) {
            vSquare[iNx][iNy] = i;
        }
        else {
            iNx = iX + 1;
            iNy = iY;
            if ( iNx > 2 )
                iNx = 0;
            vSquare[iNx][iNy] = i;
        }
        iX = iNx;
        iY = iNy;
    }
    return vSquare;
}
 
vector<vector<int>> rotateSquare(vector<vector<int>> p_vOrgSquare) {
    vector<vector<int>> vCopy(p_vOrgSquare);
     
    for(int i=0; i < 3; ++i) {
        for(int j=0; j < 3; ++j) {
            if ( i == 0 ) {
                p_vOrgSquare[j][2] = vCopy[i][j];
            }
            else if ( i == 1 ) {
                p_vOrgSquare[j][i] = vCopy[i][j];
            }
            else if ( i == 2 ) {
                p_vOrgSquare[j][0] = vCopy[i][j];
            }
        }
    }
     
    return p_vOrgSquare;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    vector<vector<int>> vNormalSquare(3);
    vNormalSquare = getSquare();

    vector<vector<int>> vSymSquare(3);
    for(int i=0; i<3; ++i) {
        vSymSquare[i].resize(3);
        vSymSquare[i][0] = vNormalSquare[i][2];
        vSymSquare[i][1] = vNormalSquare[i][1];
        vSymSquare[i][2] = vNormalSquare[i][0];
    }
 
    vector<vector<vector<int>>> vMagicSquare;
    vMagicSquare.push_back(vNormalSquare);
    vMagicSquare.push_back(vSymSquare);
    
    for(int i=2; i<7; i+=2) {
        vNormalSquare = rotateSquare(vNormalSquare);
        vSymSquare = rotateSquare(vSymSquare);
        vMagicSquare.push_back(vNormalSquare);
        vMagicSquare.push_back(vSymSquare);
    }
    
    int iTotal = 0, iMin = 1000;
    for(int i=0; i<8; ++i) {
        for(int j=0; j<3; ++j) {
            for(int k=0; k<3; ++k) {
                if ( s[j][k] != vMagicSquare[i][j][k] )
                    iTotal += abs(s[j][k] - vMagicSquare[i][j][k]);
            }
        }
        iMin = min(iTotal, iMin);
        iTotal = 0;
    }
     
    return iMin;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

