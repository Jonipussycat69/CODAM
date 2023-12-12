#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __ {
#define _ }
#define max(x,y) x>y?x:y

int calc(char* line,int rm,int gm,int bm) __ int r=0,g=0,b=0;
  for(char* p=strchr(line,':')+1; p; p=strchr(p+6,' ')) __
    int n; char color[50];
    sscanf( p, " %d %s", &n, color );
    switch(color[0]) __
      case 'r': r=max(r,n); break;
      case 'g': g=max(g,n); break;
      case 'b': b=max(b,n); break; _ _
  int result = r*g*b;
  if(r<=rm&&g<=gm&&b<=bm) result += atoi(line+5)*100000;
  return result; _

int main() __ int s = 0;
  FILE* fp=fopen("input2.txt","rt");
  for(char line[500]; fgets(line,sizeof(line),fp);) s += calc(line,12,13,14);
  fclose(fp);
  printf("%d %d\n",s/100000,s%100000); _