#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 5000 + 10;
#define LL long long
int n,m,x1,y1,x2,y2;
int P,Q;
int ans[maxn];
struct rec{
	int x1,x2;
	int kk,id;
	double k;
	bool operator<(const rec &cmp) const{
		return x1 < cmp.x1;
	}
}line[maxn];
double query(rec &a){
	return 1.0 * (Q - y1 - a.k * P + a.k * a.x1);
}
int main()
{
	//freopen("1.in","r",stdin);
	while(1){
		scanf("%d",&n); if (!n) break;
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		for (int i = 1;i <= n;i++){
			int U,L; scanf("%d%d",&U,&L);
			line[i].x1 = U; line[i].x2 = L; line[i].kk = i;
			if (U == L){
				line[i].id = 1;
			}else{
				line[i].k = (1.0 * (y2 - y1)) / (1.0 * (L - U));
				line[i].id = 0;
			}
		}
		
		//cout<<line[n].x1<<" "<<line[n].x2<<" "<<line[n].kk<<" "<<line[n].id<<" "<<line[n].k<<endl;
		memset(ans,0,sizeof(ans));
		int num[maxn];
		for (int i = 1;i <= n;i++) num[i] = i;
		for (int i = 0;i < m;i++){
			scanf("%d%d",&P,&Q); 
			//cout<<query(line[n])<<"!"<<endl;
			int L = 1,R = n;
			while(L <= R){
				int mid = (L + R) >> 1;
				int flag = 0;
				if (line[mid].id){
					if (P < line[mid].x1) flag = 1;
				}else if (line[mid].k > 0){
					if (query(line[mid]) > 1.0 * 0) flag = 1;
				}else{
					if (query(line[mid]) < 1.0 * 0) flag = 1;
				}
				if (flag) R = mid - 1; else L = mid + 1;
			}
		//	cerr <<ø L << " " << R << endl;
			ans[R]++;
			/*
			for (int j = 1;j <= n;j++){
				if (line[j].id){
					if (P < line[j].x1){
						ans[j - 1]++; break;
					}
				}else if (line[j].k > 0){
					if (query(line[j]) > 1.0 * 0){
						ans[j - 1]++; break;
					}
				}else{
					if (query(line[j]) < 1.0 * 0){
						ans[j - 1]++; break;
					}
				}
				if (j == n) ans[j]++;
			}
		*/
		}
		for (int j = 0;j <= n;j++) printf("%d: %d\n",j,ans[j]);
		cout<<endl;
	}
	return 0;
}