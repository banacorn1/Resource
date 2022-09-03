#include<time.h>
#include<stdio.h>
#include <stdlib.h>
#include <process.h>
#include <Windows.h>

int e,n;

long long int qpow(long long int a,long long int b,long long int p) {
	long long int res = 1;
	while (b) {
	if (b & 1) res = res * a % p;
	a = a * a % p, b >>= 1;
	}
	return res;
}

void enc(char *fpath){

	FILE *fp = fopen(fpath,"rb");
	char newname[256];
	sprintf(newname,"%s%s",fpath,".tmp");
	FILE *f = fopen(newname,"wb");
	if(f==NULL) {
	printf("error"); 
	return;
	}
	if(fp==NULL) {
	printf("error"); 
	return;
	}
	fseek(fp,0,SEEK_END);
	int	size= ftell(fp);
	fseek(fp,0,SEEK_SET);

	unsigned char cr;
	long int Processed;	
	for(int p = 0;p < size;p++){
	fread((char*)&cr,1,1,fp);
	Processed = qpow((int)cr,e,n);
	fprintf(f,"%x ",Processed);
	}
	fclose(f);
	fclose(fp);
	remove(fpath);
}

//__declspec(dllexport) void mainRSA(char fpath[512])
void main()
{
	char fpath[1024];
	printf("文件路径>>");
	scanf("%s",&fpath);
	time_t start_t = time(NULL);

	char outFilepath[1024];
	int size;   

	long int d;
	int mode = 0;
	char fname[_MAX_FNAME] = {' '};
	char ext[_MAX_EXT] = {' '};
	HANDLE hd[6];
	n = 33277;
	e = 71;
	d = 5091;

	_splitpath(fpath,NULL,NULL,fname,ext);

	sprintf(outFilepath,"%s%s",fpath,".EncRSA");
	FILE *fp;
	FILE *fo;
	fo = fopen(outFilepath,"wb");
	fp = fopen(fpath,"rb");
	{
		fseek(fp,0,SEEK_END);
		size = ftell(fp);
		fseek(fp,0,SEEK_SET);
	}
	fwrite(fname,_MAX_FNAME,1,fo);
	fwrite(ext,_MAX_EXT,1,fo);
	
	char c1[1];
	char c2[1];
	char c3[1];
	char c4[1];
	char c5[1];
	char c6[1];

	FILE *f = fopen("0","wb");
	for(int l = 0;l < (int)(size/6);l++){
		fread(c1,1,1,fp);
		fwrite(c1,1,1,f);
	}
	fclose(f);

	f = fopen("1","wb");
	for(int l = 0;l < (int)(size/6);l++){
		fread(c2,1,1,fp);
		fwrite(c2,1,1,f);
	}
	fclose(f);

	f = fopen("2","wb");
	for(int l = 0;l < (int)(size/6);l++){
		fread(c3,1,1,fp);
		fwrite(c3,1,1,f);
	}
	fclose(f);

	f = fopen("3","wb");
	for(int l = 0;l < (int)(size/6);l++){
		fread(c4,1,1,fp);
		fwrite(c4,1,1,f);}
	fclose(f);

	f = fopen("4","wb");
	for(int l = 0;l < (int)(size/6);l++){
	fread(c5,1,1,fp);

	fwrite(c5,1,1,f);
	}
	fclose(f);

	f = fopen("5","wb");
	for(int l = 0;l < size-(int)(size/6)*5;l++){
		fread(c6,1,1,fp);
		fwrite(c6,1,1,f);
		}

	fclose(f);
	fclose(fp);
	
	hd[0] = (HANDLE)_beginthread((void (__cdecl *) (void *))enc,0,"0");

	hd[1] = (HANDLE)_beginthread((void (__cdecl *) (void *))enc,0,"1");

	hd[2] = (HANDLE)_beginthread((void (__cdecl *) (void *))enc,0,"2");

	hd[3] = (HANDLE)_beginthread((void (__cdecl *) (void *))enc,0,"3");

	hd[4] = (HANDLE)_beginthread((void (__cdecl *) (void *))enc,0,"4");

	hd[5] = (HANDLE)_beginthread((void (__cdecl *) (void *))enc,0,"5");

	WaitForMultipleObjects(6, hd, TRUE, INFINITE);
	//Sleep(10);

	int _tsize;
	FILE *_tfo = fopen("0.tmp","rb");
	char _tc[1];

	fseek(_tfo,0,SEEK_END);
	_tsize = ftell(_tfo);
	fseek(_tfo,0,SEEK_SET);
	for(int l = 0;l < _tsize;l++){
		fread(_tc,1,1,_tfo);
		fwrite(_tc,1,1,fo);
	}
	fclose(_tfo);
	remove("0.tmp");
	Sleep(10);
	
	_tfo = fopen("1.tmp","rb");
	fseek(_tfo,0,SEEK_END);
	_tsize = ftell(_tfo);
	fseek(_tfo,0,SEEK_SET);
	for(int l = 0;l < _tsize;l++){
		fread(_tc,1,1,_tfo);
		fwrite(_tc,1,1,fo);
	}
fclose(_tfo);
	remove("1.tmp");
	Sleep(10);

	_tfo = fopen("2.tmp","rb");
	fseek(_tfo,0,SEEK_END);
	_tsize = ftell(_tfo);
	fseek(_tfo,0,SEEK_SET);
	for(int l = 0;l < _tsize;l++){
		fread(_tc,1,1,_tfo);
		fwrite(_tc,1,1,fo);
	}
fclose(_tfo);
	remove("2.tmp");
	Sleep(10);

	_tfo = fopen("3.tmp","rb");
	fseek(_tfo,0,SEEK_END);
	_tsize = ftell(_tfo);
	fseek(_tfo,0,SEEK_SET);
	for(int l = 0;l < _tsize;l++){
		fread(_tc,1,1,_tfo);
		fwrite(_tc,1,1,fo);
	}
fclose(_tfo);
	remove("3.tmp");
	Sleep(10);

	_tfo = fopen("4.tmp","rb");
	fseek(_tfo,0,SEEK_END);
	_tsize = ftell(_tfo);
	fseek(_tfo,0,SEEK_SET);
	for(int l = 0;l < _tsize;l++){
		fread(_tc,1,1,_tfo);
		fwrite(_tc,1,1,fo);
	}
fclose(_tfo);
	remove("4.tmp");
	Sleep(10);

	_tfo = fopen("5.tmp","rb");
	fseek(_tfo,0,SEEK_END);
	_tsize = ftell(_tfo);
	fseek(_tfo,0,SEEK_SET);
	for(int l = 0;l < _tsize;l++){
		fread(_tc,1,1,_tfo);
		fwrite(_tc,1,1,fo);
	}
fclose(_tfo);
	remove("5.tmp");
	Sleep(10);


	time_t end_t = time(NULL);
	
	
	printf("时间:%d秒,处理 %d字节,速度%.2fKb/s\n",end_t-start_t,size,(float)size/1024/(end_t-start_t));
	printf("密钥:%x-%x\n",n,d);
	fclose(fo);
	system("pause");
}