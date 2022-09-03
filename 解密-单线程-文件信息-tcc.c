#include<stdio.h>
#include <stdlib.h>
#include<time.h>

long long qpow(long long int a,long long int b,long long int p) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p, b >>= 1;
  }
  return res;
}

int main()
{    printf("文件路径>>");
    
    char FilePath[1024];
scanf("%s",&FilePath);
    time_t start_t = time(NULL);

    int d;
    int n;
    FILE *fp;
    FILE *of;
    FILE *_tfp;
    unsigned int abyte;
    unsigned char achar;
    static char fname[256];
    static char ext[256] = {'\0'};
    static char fullname[512] = {'\0'};
    fp = fopen(FilePath,"r");
    if(fp == NULL){
        printf("error");
        exit(-1);
    }
    printf("\n密钥>>");
    scanf("%x-%x",&n,&d);
    //n = 33277;
    //d = 5091;
    _tfp = fopen(FilePath,"r");
    fread(fname,256,1,_tfp);
    fread(ext,256,1,_tfp);
    fclose(_tfp);
    sprintf(fullname,"%s%s",fname,ext);
	  of = fopen(fullname,"wb");
	  fseek(fp,512,SEEK_SET);
    while (fscanf(fp,"%x",&abyte) != EOF)
    {
        achar = qpow(abyte,d,n);
        fprintf(of,"%c",achar);
    }
    time_t end_t = time(NULL);
int size = ftell(of);
    fclose(of);
    fclose(fp);
    remove(FilePath);
    printf("总计%d秒,共处理%d字节,速度%.2fKb/s\n",end_t-start_t,size,(float)size/1024/(end_t-start_t));
    system("pause");
}
