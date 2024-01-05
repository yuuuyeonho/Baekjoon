#include<iostream>
using namespace std;

int gcd(int a, int b) // 유클리드 호제법
{
	return b ? gcd(b, a%b) : a;
}

int main(){
    int num1, num2;
    cin >> num1 >> num2;

    int gcdnum = gcd(num1,num2);
    int lcmnum = num1*num2/gcdnum;
    cout << gcdnum << endl << lcmnum;
    return 0;
}