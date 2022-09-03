#include<stdio.h>
#include<fstream>
#include<iostream>
#include <cstring>
#include<sys/timeb.h>

using namespace std;

long long int qpow(long long int a,long long int b,long long int p) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p, b >>= 1;
  }
  return res;
}

int main(int argc, char const *argv[])
{
    //页面初始化
    system("chcp 65001");

    //变量初始化
    char FilePath[1024];
    int d;
    int n;
    int size;
    FILE *fp = nullptr;
    unsigned int abyte;
    unsigned char achar;
    fstream outFile;
    static char fname[256];
    static char ext[256] = {'\0'};
    static char fullname[512] = {'\0'};

    printf("被加密文件的地址>>>");
    cin >> FilePath;

    timeb start_t;
    ftime(&start_t);

    fp = fopen(FilePath,"r");
    if(fp == nullptr){
        printf("error");
        exit(-1);
    }

    n = 33277;
    d = 5091;

    ifstream _tfp(FilePath);
    _tfp >> fname;
    _tfp >> ext;
    _tfp.close();

    sprintf(fullname,"%s%s",fname,ext);
    outFile.open(fullname,ios::out | ios::binary);
	fseek(fp,514,SEEK_SET);
    
    while (fscanf(fp,"%x",&abyte) != EOF)
    {
        achar = qpow(abyte,d,n);
        outFile << achar;
    }
    size = outFile.tellg();
    fclose(fp);
    outFile.close();
    timeb end_t;
    ftime(&end_t);
    printf("总计%.2f秒,共处理%d字节,速度%.2fKb/s\n",(float)(end_t.time-start_t.time)+(float)(end_t.millitm-start_t.millitm)/(float)1000,size,(float)size/(float)1024/((float)(end_t.time-start_t.time)+(float)(end_t.millitm-start_t.millitm)/(float)1000));
    remove(FilePath);
    system("pause");
    return 0;
}
