#include<bits/stdc++.h>
using namespace std;
int N =1000001;
int sieve[1000001];
void gen_seive()
{
  sieve[0]=sieve[1]=0;
  for(int i=2;i<=N;i++)
  {
    sieve[i]=1;
  }
  for(int i=2;i*i<=N;i++)
  {
    if(sieve[i]==1)
    {
      for(int j=i*i;j<=N;j+=i)
      {
        sieve[j]=0;
      }
    }
  }
}
vector<int> gen_Primes(int num)
{
  gen_seive();
  vector<int>ds;
  for(int i=2;i<=num;i++){
    if(sieve[i]==1) ds.push_back(i);
  }
  return ds;
}
int main()
{
  gen_seive();
  int T;
  while(T--){
    int l,r;
    cin>>l>>r;
    vector<int>dj=gen_Primes(sqrt(r)+1);
    vector<int>dummy(r-l+1,1);
    
    for(auto it: dj){
      int firstmul=0;
      if(l/it *it <l){
        firstmul=((l/it)+1)*it;
      }
      else firstmul=(l/it)*it;
      for(int j=max(firstmul,it*it);j<=r;j+=it){
        dummy[j-l]=0;
      }
      for(int i=0;i<r-l+1;i++){
        if(dummy[i]==1){
          cout<<l+i<<" ";
        }
      }
    }
  }
  return 0;
}
