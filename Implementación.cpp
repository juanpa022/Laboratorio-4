#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;
int lim,numero;
bool encuentra(vector<int> vec, int elem)
{
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] == elem)
            return 1;}
    return 0;
}
int exponenciacion(int x, int y, int p) 
{
    int tem = 1;
    while (y){
        if (y & 1){
            tem = int (tem * 1ll * x % p);
            --y; }
        else {
            x = int (x * 1ll * x % p);y >>= 1; } }  
    return tem;
}
vector<int> primeFactors(long long n) {
    vector<int> res;
    long long tem = 2;
    while (tem * tem <= n) {
        if (n % tem == 0)  {
            if (!encuentra(res, tem))
                res.push_back(tem);
            n /= tem;} 
        else 
          tem++; }
    if (n > 1)  {
        if (!encuentra(res, n))
            res.push_back(n);}
    return res;
}
int findPrimitive(int n){
    bool tem;
    int phi = n - 1;
    vector<int> vec = primeFactors(phi);
    for (int i = 2; i < n; i++) {
        if (std::__gcd(i, n) == 1) {
            tem = false;
            for (int j = 0; j < vec.size(); j++){
                if (exponenciacion(i, (phi/vec[j]), n) == 1){
                    tem = true;
                    break;}}
            if (!tem)
                return i;
        }
    }
    return -1;
}
int main(void)
{   
    cout << "Numero primo => ";
    cin >> numero;
    cout << "La menor raiz primitiva de " <<setw(8)<< numero << " es: " << findPrimitive(numero);
    while (exponenciacion(6, lim, 100049) != 2021) lim++;
   cout <<"\nx = "<<setw(8)<< lim;
}
