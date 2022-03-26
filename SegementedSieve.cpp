#include<bits/stdc++.h>
usng namespace std;
void gen_seive()
{
  seive[0]=seive[1]=0;
  for(int i=2;i<=N;i++)
  {
    seive[i]=1;
  }
  for(int i=2;i*i<=N;i++)
  {
    if(seive[i]==1)
    {
      for(int j=i*i;j<=N;j+=i)
      {
        seive[j]=0;
      }
    }
  }
}
vector<int> gen_Primes(int num)
{
  vector<int>ds;
  for(int i=2;i<=num;i++){
    if(seive[i]==1) ds.push_back(i);
  }
  return ds;
}
int main()
{
  gen_Seive();
  int T;
  while(T--){
    int l,r;
    cin>>l>>r;
    vector<int>dj=gen_Primes(sqrt(r)+1);
    vector<int>dummy(r-l+1);
    
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
