#include <bits/stdc++.h>
using namespace std;

int q[3001]={0}; // queue for node
int d[1001]={0}; // record shortest path from start to ith node
bool f[1001]={0};
int a[1001][1001]={0}; // adjacency list
int w[1001][1001]={0}; // adjacency matrix

void SPFA(int v0){
  int t,h,u,v;
  for (int i=0;i<1001;i++) d[i]=INT_MAX;
  for (int i=0;i<1001;i++) f[i]=false;
  d[v0]=0;
  h=0; t=1; q[1]=v0; f[v0]=true;
  while (h!=t){
  h++;
  if (h>3000) h=1;
  u=q[h];
  for (int j=1; j<=a[u][0];j++){
    v=a[u][j];
    if (d[u]+w[u][v]<d[v]){
        d[v]=d[u]+w[u][v];
        if (!f[v]){
          t++;
          if (t>3000) t=1;
          q[t]=v;
          f[v]=true;
        }
      }
    }
  f[u]=false;
  }
}

int main(void){
  int n=0, m=0;
  int s=0, e=0;
  cin >> n >> m;
  cin >> s >> e; // s: start, e: end
  for (int i=1;i<=m;i++){
    int x=0, y=0, z=0, aux;
    cin >> x >> y >> z >> aux; // node x to node y has weight z
    a[x][0]++;
    a[x][a[x][0]]=y;
    w[x][y]=aux;
    a[x][0]++;
    a[y][a[y][0]]=x;
    w[y][x]=aux;
  }
  SPFA(s);
  cout << d[e] << endl;
  return 0;
}





/*#include <bits/stdc++.h>
using namespace std;
typedef vector<int, int> vi;

int p[110][110];

void printPath(int i, int j) {
  if (i != j) printPath(i, p[i][j]);
  printf("%d ", j+1);
}

int main(){
  int V, a,b,c,d,e;
  double temp, length;
  cin >> V;
  cin >> a;
  cin >> b >> c;
  double AdjMat[V+5][V+5];
  double AdjMat2[V+5][V+5];
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++){
      AdjMat[i][j] = 1000000000;
      AdjMat2[i][j] = 1000000000;}

  while(a--){
    cin >> d >> e >> length >> temp;
    AdjMat[d-1][e-1] = temp;
    AdjMat2[d-1][e-1] = length;
    AdjMat[e-1][d-1] = temp;
    AdjMat2[e-1][d-1] = length;

  }


  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      p[i][j] = i;
  // initialize the parent matrix
  for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++) // this time, we need to use if statement
        if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]) {
          AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
          p[i][j] = p[k][j];
        }
  printPath(b-1,c-1);
  cout << AdjMat[b-1][c-1];
  cout << endl<<endl;
  for (int i = 0; i < V; i++){
    for (int j = 0; j < V; j++){
      cout <<AdjMat[i][j] << " ";}
    cout << endl;
  }
  return 0;
}*/
