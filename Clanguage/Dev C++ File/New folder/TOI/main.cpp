#include <bits/stdc++.h>
using namespace std;
void SieveOfEratosthenes() {
    bool pno[7368788];
    memset(pno, true, sizeof(pno));
    for (int i = 2; i*i<= 7,368,787; i++) {
        if (pno[i] == true) {
            for (int j = i*2; j<= 7368788; j += i)
                pno[j] = false;
        }
    }
    int n=1;
    for (int i = 2; i<= 7368788; i++)
        if (pno[i]){
            cout <<n<<" "<< i << "\n";
            n++;
        }

}
int main() {
    SieveOfEratosthenes();
    return 0;
}
