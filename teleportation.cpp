#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int N;
long long dsum = 0;

int main () {

    ifstream fin ("teleport.in");
    ofstream fout ("teleport.out");

    if (fin.is_open()) {
        fin >> N;
        vector<int> candidates_a;
        vector<int> candidates_b;

        for (int i=0; i<N; i++) {
            int a, b;
            fin >> a >> b;

            // go w/o teleport!
            if (abs(a) >= abs(a-b)) {
                dsum+=abs(a-b);
            } else {
                // may use teleport
                candidates_a.push_back(a);
                candidates_b.push_back(b);
            }
        }

        long long min_total_dist = LLONG_MAX;
        for (int i=0; i<candidates_b.size(); i++) {
            // assume b[i] is y.
            int y = candidates_b[i];
            
            // distance to entrance (for ith)
            long long total_dist = 0;
            for (int j=0; j < candidates_b.size(); j++) {
                total_dist += min(
                        abs(candidates_a[j]) + abs(y - candidates_b[j]), // teleport and move
                        abs(candidates_a[j] - candidates_b[j])           // go w/o teleport
                );
            }

            // update minimum total dist
            if (total_dist < min_total_dist) {
                min_total_dist = total_dist;
            }
        }
        fout << dsum + min_total_dist << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
