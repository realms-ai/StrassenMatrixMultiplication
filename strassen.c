#include<stdio.h>

int sze,cw[2][2],t;
void prnt(int c[16][16],int sz)
{
int i,j;
printf("multiplication is :\n");
for(i=1;i<=sz;i++)
{
for(j=1;j<=sz;j++)
{
printf("%d ",c[i][j]);
}
printf("\n");
}

}



void add(int ad1[][16],int ad2[][16],int w,int arr[16][16])
{
int i,j;
for(i=1;i<=w;i++)
{
for(j=1;j<=w;j++)
 {

  arr[i][j]=ad1[i][j]+ad2[i][j];


 }

}

}
void sub(int ad1[][16],int ad2[][16],int w,int sarr[16][16])
{
int i,j;
 for(i=1;i<=w;i++)
 {
 for(j=1;j<=w;j++)
  {
   sarr[i][j]=ad1[i][j]-ad2[i][j];
  }
 }
}

void strassen(int a[16][16],int b[16][16],int n,int strtmp[16][16])
{
 int a11[16][16],a12[16][16],a21[16][16],a22[16][16],b11[16][16];
 int b12[16][16],b21[16][16],b22[16][16];
 int i,j,cc11[16][16],cc12[16][16],cc21[16][16],cc22[16][16];
 int p[16][16],q[16][16],r[16][16],s[16][16],t[16][16],u[16][16],v[16][16];
 int ap,aq,ar,as,at,au,av;
 int tmpad1[16][16],tmpad2[16][16],tmpsb1[16][16],tmpsb2[16][16];
 if(n==1)
 {
  ap=(a[1][1]+a[2][2])*(b[1][1]+b[2][2]);
  aq=(a[2][1]+a[2][2])*b[1][1];
  ar=a[1][1]*(b[1][2]-b[2][2]);
  as=a[2][2]*(b[2][1]-b[1][1]);
  at=(a[1][1]+a[1][2])*b[2][2];
  au=(a[2][1]-a[1][1])*(b[1][1]+b[1][2]);
  av=(a[1][2]-a[2][2])*(b[2][1]+b[2][2]);
  cw[1][1]=ap+as-at+av;
  cw[1][2]=ar+at;
  cw[2][1]=aq+as;
  cw[2][2]=ap+ar-aq+au;
  for(i=1;i<=2;i++)
  {
    for(j=1;j<=2;j++)
    {
      strtmp[i][j]=cw[i][j];
    }
  }
  return;
 }

 for(i=1;i<=n;i++)
 {
   for(j=1;j<=n;j++)
   {
     a11[i][j]=a[i][j];
     a12[i][j]=a[i][j+n];
     a21[i][j]=a[i+n][j];
     a22[i][j]=a[i+n][j+n];
     b11[i][j]=b[i][j];
     b12[i][j]=b[i][j+n];
     b21[i][j]=b[i+n][j];
     b22[i][j]=b[i+n][j+n]; 
   }
 }

 add(a11,a22,n,tmpad1);
 add(b11,b22,n,tmpad2);
 strassen(tmpad1,tmpad2,n/2,p);    //p
 add(a21,a22,n,tmpad1);
 strassen(tmpad1,b11,n/2,q);       //q
 sub(b12,b22,n,tmpsb1);
 strassen(a11,tmpsb1,n/2,r);       //r
 sub(b21,b11,n,tmpsb1);
 strassen(a22,tmpsb1,n/2,s);       //s
 add(a11,a12,n,tmpad1);
 strassen(tmpad1,b22,n/2,t);       //t
 sub(a21,a11,n,tmpsb1);
 add(b11,b12,n,tmpad1);
 strassen(tmpsb1,tmpad1,n/2,u);    //u
 sub(a12,a22,n,tmpsb1);
 add(b21,b22,n,tmpad1);
 strassen(tmpsb1,tmpad1,n/2,v);    //v
 //other steps to unite
 add(p,s,n,tmpad1);
 add(tmpad1,v,n,tmpad2);
 sub(tmpad2,t,n,cc11);
 add(r,t,n,cc12);
 add(q,s,n,cc21);
 add(p,r,n,tmpad1);
 add(tmpad1,u,n,tmpad2);
 sub(tmpad2,q,n,cc22);
 //merging
 for(i=1;i<=n;i++)
 {
   for(j=1;j<=n;j++)
   {
     strtmp[i][j]=cc11[i][j];
     strtmp[i][j+n]=cc12[i][j];
     strtmp[i+n][j]=cc21[i][j];
     strtmp[i+n][j+n]=cc22[i][j];
   }
 }
}

void entry(int q[][16],int sz)
{
 int i,j;
 for(i=1;i<=sz;i++)
 {
   for(j=1;j<=sz;j++)
   {
     scanf("%d",&q[i][j]);
   }
 }
}

int main()
{
 int i,j;
 int ae[16][16],be[16][16],ce[16][16];
 printf("enter the size of square matrix :");
 scanf("%d",&sze);
 printf("\nENTER ELEMENT IN 1st matrix:\n");
 entry(ae,sze);
 printf("\n enter element in 2nd matrix: \n");
 entry(be,sze);
 strassen(ae,be,sze/2,ce);
 prnt(ce,sze); 
return 0;
}

