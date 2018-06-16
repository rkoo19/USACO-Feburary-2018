#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
    int N, B;

    ifstream fin ("snowboots.in");
    ofstream fout ("snowboots.out");

    fin >> N >> B;
    vector<int> tiles(N);
    vector<int> depths(B);
    vector<int> steps(B);

    for (int i=0; i<N; i++) {
        fin >> tiles[i];
    }

    for (int i=0; i<B; i++) {
        fin >> depths[i] >> steps[i];
    }

    long long pos = 0;

    for (int boots=0; boots < B; boots++) {
        int step = steps[boots];
        int depth = depths[boots];
        long long check = pos + step;

        if (depth < tiles[pos]) {
            continue;
        }

        while(check > pos) {
            if (check >= N-1) {
                fout << boots << endl;
                return 0;
            } else {
                if (tiles[check] <= depth) {
                    // go
                    pos = check;
                    check = pos+step;
                } else {
                    check--;
                }
            }
            
        }
    }
    
    return 0;
}
