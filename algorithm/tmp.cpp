#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

const ll N=5000010;
const double pi=acos(-1);
string s;
ll n,m,limit,c[N];
struct complex{
    double real,imag;
    complex(double X=0,double Y=0){real=X; imag=Y;}
}a[N],b[N];
inline complex operator +(complex a,complex b){return complex(a.real+b.real,a.imag+b.imag);}
inline complex operator -(complex a,complex b){return complex(a.real-b.real,a.imag-b.imag);}
inline complex operator *(complex a,complex b){return complex(a.real*b.real-a.imag*b.imag,a.real*b.imag+a.imag*b.real);}

void FFT(complex *a,ll op){
    for(ll i=0; i<limit; i++){
        if(i<c[i]) swap(a[i],a[c[i]]);
    }
    for(ll mid=1; mid<limit; mid<<=1){
        complex W(cos(pi/mid),op*sin(pi/mid));
        for(ll r=mid<<1,j=0; j<limit; j+=r){
            complex w(1,0);
            for(ll l=0; l<mid; l++,w=w*W){
                complex x=a[j+l],y=w*a[j+mid+l];
                a[j+l]=x+y; a[j+mid+l]=x-y;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); 
    cin>>s; n=s.size()-1;
    for(ll i=0; i<=n; i++) a[n-i].real=s[i]-48;
    cin>>s; m=s.size()-1;
    for(ll i=0; i<=m; i++) b[m-i].real=s[i]-48;
    limit=1; ll l=0;
    while(limit<=n+m){
        limit<<=1;
        l++;
    }
    for(ll i=0; i<limit; i++) c[i]=(c[i>>1]>>1)|((i&1)<<(l-1));

    for (int i = 0; i < limit; i++)
	cout << c[i] << " ";
    cout << endl;
    FFT(a,1); FFT(b,1);
    for(ll i=0; i<=limit; i++) a[i]=a[i]*b[i];
    FFT(a,-1);

    for (int i = 0; i < limit; i++)
	cout << a[i].real << " " << ' ' << a[i].imag;
    cout << endl;
    for (int i = 0; i < limit; i++)
	cout << b[i].real << " " << ' ' << b[i].imag;
    cout << endl;

    //上面都是FFT板子，不解释
    memset(c,0,sizeof(c));//c数组要清零，因为前面有赋值
    for(ll i=0; i<=n+m+1; i++) c[i]=a[i].real/limit+0.5;//模仿FFT输出时赋值
    for(ll i=0; i<=n+m; i++){//进位
    	c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	limit=n+m+1;
	while(c[limit]){//还有前面没有处理的
		c[limit+1]+=c[limit]/10;
		c[limit]%=10;
		limit++;
	}
    for(ll i=limit-1; i>=0; i--) cout<<c[i];//输出
    return 0;
}
