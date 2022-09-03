#include<vector>
#include<fstream>
#include<iostream>
#include<sys/timeb.h>
#include<thread>
#include<stdio.h>
#include<windows.h>
#include<string>
#include <stdlib.h>

using namespace std;

vector<unsigned char>vec;
string fpath;   //文件地址
int size;   //文件大小
long int n;
int e;
long int d;
int mode = 0;
char fname[_MAX_FNAME] = {' '};
char ext[_MAX_EXT] = {' '};

long long int qpow(long long int a,long long int b,long long int p) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p, b >>= 1;
  }
  return res;
}

void enc(vector<unsigned char>&a,int p){
    long int Processed;
    fstream FileOut(to_string(p)+"",ios::binary | ios::app);
    for(int i = 0;i < a.size();i++){
        Processed = qpow((int)a[i],e,n);
        FileOut << hex <<Processed;
        FileOut << " ";
    }
    FileOut.close();
    mode++;
    return;
}

void send(){
    char chr;
    fstream fp(fpath,ios::binary | ios::in);
    fp >> noskipws;

    if (!fp.is_open()){       //检查是否存在
        cout <<"error";
        exit(-1);
    }

    {
        fp.seekg(0,ios::end);
        size = fp.tellg();
        fp.seekg(0,ios::beg);
    }   //获取文件大小;

    for(int i = 0;i < size;i++){
        fp >> chr;
        vec.push_back(chr);
    }
    fp.close();

    vector<unsigned char>vec1;
    vector<unsigned char>vec2;
    vector<unsigned char>vec3;
    vector<unsigned char>vec4;
    vector<unsigned char>vec5;
    vector<unsigned char>vec6;
    vector<unsigned char>vec7;
    vector<unsigned char>vec8;

    for(int i = 0;i < size;i++){
        if(vec1.size() < size/8){vec1.push_back(vec[i]);continue;}
        if(vec2.size() < size/8){vec2.push_back(vec[i]);continue;}
        if(vec3.size() < size/8){vec3.push_back(vec[i]);continue;}
        if(vec4.size() < size/8){vec4.push_back(vec[i]);continue;}
        if(vec5.size() < size/8){vec5.push_back(vec[i]);continue;}
        if(vec6.size() < size/8){vec6.push_back(vec[i]);continue;}
        if(vec7.size() < size/8){vec7.push_back(vec[i]);continue;}
        {vec8.push_back(vec[i]);continue;}
    }


    thread th1(enc,std::ref(vec1),1);
    Sleep(100);
    thread th2(enc,std::ref(vec2),2);
    Sleep(100);
    thread th3(enc,std::ref(vec3),3);
    Sleep(100);
    thread th4(enc,std::ref(vec4),4);
    Sleep(100);
    thread th5(enc,std::ref(vec5),5);
    Sleep(100);
    thread th6(enc,std::ref(vec6),6);
    Sleep(100);
    thread th7(enc,std::ref(vec7),7);
    Sleep(100);
    thread th8(enc,std::ref(vec8),8);

    printf("\n");
    while (1)
    {
        
        Sleep(750);
        if(mode == 8){
            
            break;
            }else{;}
    }
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();
    return;

}//准备写

int main()
{
    system("chcp 65001");
    

    n = 33277;
    e = 71;
    d = 5091;
	
	cout <<"成功了...\n";
	//printf("(public)n:%d;(private)d:%d;\n>>>",n,d);
    printf("ps:1.使用本软件意味着加密后文件仅可通过本软件对应的解密软件解密\n2.本软件为追求效率密钥仅采用16位加密,安全性较低\n3.使用本软件将意味着加密文件将扩大4-5倍\n4.速度大概在1mb/s左右\n要求:1.文件名不能带空格\n2.文件名以及路径不能带中文\n>>>",n,d);


    cin >> fpath;

    _splitpath(fpath.c_str(),nullptr,nullptr,fname,ext);
    timeb start_t;
    ftime(&start_t);
    send();
    
    Sleep(1000);
    char c;
    ofstream f(string(fpath)+".EncRSA");
    for(int i = 0;i <_MAX_FNAME ;i++){
        f << fname[i];
    }
    f << ' ';
    for(int i = 0;i <_MAX_EXT ;i++){
        f << ext[i];
    }
    f << ' ';

    ifstream f1("1");
    f1>> noskipws;
    while(f1>>c){
        f<<c;
    }
    f1.close();
    Sleep(10);
    remove("1");

    ifstream f2("2");
    f2>> noskipws;
    while(f2>>c){
        f<<c;
    }
    f2.close();
    Sleep(10);
    remove("2");

    ifstream f3("3");
    f3>> noskipws;
    while(f3>>c){
        f<<c;
    }
    f3.close();
    Sleep(10);
    remove("3");

    ifstream f4("4");
    f4>> noskipws;
    while(f4>>c){
        f<<c;
    }
    f4.close();
    Sleep(10);
    remove("4");

    ifstream f5("5");
    f5>> noskipws;
    while(f5>>c){
        f<<c;
    }
    f5.close();
    Sleep(10);
    remove("5");

    ifstream f6("6");
    f6>> noskipws;
    while(f6>>c){
        f<<c;
    }
    f6.close();
    Sleep(10);
    remove("6");

    ifstream f7("7");
    f7>> noskipws;
    while(f7>>c){
        f<<c;
    }
    f7.close();
    Sleep(10);
    remove("7");

    ifstream f8("8");
    f8>> noskipws;
    while(f8>>c){
        f<<c;
    }
    f8.close();
    Sleep(10);
    remove("8");

    f.close();
    timeb end_t;
    ftime(&end_t);
    printf("总计%.2f秒,共处理%d字节,速度%.2fKb/s\n",(float)(end_t.time-start_t.time)+(float)(end_t.millitm-start_t.millitm)/(float)1000,size,(float)size/(float)1024/((float)(end_t.time-start_t.time)+(float)(end_t.millitm-start_t.millitm)/(float)1000));
    system("pause");
}