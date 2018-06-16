#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long TOTAL=0;
int l, n, rf, rb;

int nextRest(vector<int>& x, vector<int>& c, int start, int maxidx) {
    long long timespan;
    if (start == 0)
        timespan = (long long) x[maxidx] * (rf - rb);
    else
        timespan = (long long) (x[maxidx] - x[start-1]) * (rf - rb);

    TOTAL += c[maxidx] * timespan;

    return maxidx + 1;
}

int main () {

    ifstream fin ("reststops.in");
    ofstream fout ("reststops.out");

        fin >> l >> n >> rf >> rb;
        vector<int> x(n);
        vector<int> c(n);

        for (int i=0; i<n; i++) {
            fin >> x[i] >> c[i];
        }

        // maxidx[i] = k which c[k] is the greatest element between c[i] and c[n-1].
        vector<int> maxidx(n);
        maxidx[n-1] = n-1;
        for (int i=n-2; i>=0; i--) {
            if (c[i] > c[maxidx[i+1]])
                maxidx[i] = i;
            else
                maxidx[i] = maxidx[i+1];
        }

        //for (int i=0; i<n; i++) {
            //cout << maxidx[i] << endl;
        //}

        int start = 0; 
        while(start < n) {
            //cout << start << endl;
            //cout << maxidx[start] << endl;
            start = nextRest(x, c, start, maxidx[start]);
        }
        fout << TOTAL <<endl;

    return 0;
}
