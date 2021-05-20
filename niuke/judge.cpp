#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

int score,n,m;
long long a[2000005],sum[2000005];

void Judge(){
    std::ifstream fin("1.in");
    std::ifstream fout("1.out");
    std::ifstream fans("1.ans");
    fin>>n,fin>>m; 
    int Ans=0;
    fans>>Ans;
    if(Ans==-1){
        fout>>a[1];
        if(a[1]!=-1){
            std::cerr <<"Your answer is wrong.You should print -1.";
            cout<<0<<endl;
        }else{
            std::cerr <<"OK! Accepted! So niu bi!";
            cout<<100<<endl;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        fout>>a[i];
        if(a[i]<1||a[i]>1ll*20000000000){
            std::cerr<<"Your number is out of range[1,2e10].";
            cout<<0<<endl;
            return ;
        }
        if(i==1)sum[i]=a[i];
        else sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=m;i++){
        int x,y;
        fin>>x,fin>>y;
        if(sum[x]!=y){
            std::cerr << "Your answer is wrong.";
            cout<<0<<endl;
            return ;
        }
    }
    std::cerr<<"OK! Accepted! So niu bi!";
    cout<<100<<endl;
}

int main(int argc, char* argv[]) {
    Judge();
}
