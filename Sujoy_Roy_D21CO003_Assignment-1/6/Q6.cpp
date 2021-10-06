#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long long b_exponent(int a, int exp) {
    long long num = a;
    long long result = 1;

    while( exp > 0) {
      int r=exp%2;
        if(r==1)
            result = result * num;
        exp = exp/2;
        num = num*num;
    }
    return result;
}

long long sme(long a, int n) {

    while(n>0)
    {
    if (n == 0)
        return 1;
    else if (n == 1)
        return a;
    else if ( n % 2 == 0)
        return sme(a*a, n/2);
    else //if(n % 2 == 1)
        return a*sme(a*a, (n-1)/2);
    }
}

long long conventional(int a,int n){
  long long r=1;
  while(n){
    r=r*a;
    n--;
  }
  return r;
}
int main(){
  int a,b;
  cout<<"Enter the base and exponent\n\n";
  cin>>a>>b;
  long long answer;
  auto start = chrono::steady_clock::now();
  for(int i=0;i<1000000;i++)
  answer=b_exponent(a,b);
  auto end = chrono::steady_clock::now();
  cout<<"Value of "<<a<<" to power"<<b<<" is:"<<answer<<endl;
  cout << "\n\nTime required by BINARY EXPONENT after 1 million iteration in nanoseconds : "
  << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
  << " ns" << endl;

  auto start1 = chrono::steady_clock::now();
  for(int i=0;i<1000000;i++)
  answer=sme(a,b);
  auto end1 = chrono::steady_clock::now();
  cout<<"Value of "<<a<<" to power"<<b<<" is:"<<answer<<endl;
  cout << "\n\nTime required by square and multiply method of exponentiation after 1 million iteration in nanoseconds : "
  << chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count()
  << " ns" << endl;

  auto start2 = chrono::steady_clock::now();
  for(int i=0;i<1000000;i++)
  answer=conventional(a,b);
  auto end2 = chrono::steady_clock::now();
  cout<<"Value of "<<a<<" to power"<<b<<" is:"<<answer<<endl;
  cout << "\n\nTime required by conventional method after 1 million iteration in nanoseconds : "
  << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count()
  << " ns" << endl;

  return 0;
}
