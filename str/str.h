#ifndef STR
#define STR

#include<cstdio>
#include<string.h>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

class str{

private:
    vector<char>String;
    void resize();
    int length = 0;
    

public:
    str(char *);
    str(long long);
    str(unsigned long long);
    str(long);
    str(unsigned long);
    str(int);
    str(unsigned);
    str(double);
    str(void);
    ~str(){;}
    //删除
    void close(){this->~str();free(this);}

    //获取长度
    int getlength() const;  

    //转为string
    string ToStdString();

    //分割
    vector<str> split(char);
    
    //输出
    int print(char end = '\0');

    //比较
    bool StringCmp(str& str1,str& str2);

    //查找
    int StrFind(str& key);




//using : *s1 += *s2
    void operator +=(const str& str1){
        str sr;
        copy(this->String.begin(), this->String.end(), back_inserter(sr.String));
        copy(str1.String.begin(), str1.String.end(), back_inserter(sr.String));
        this->String.assign(sr.String.begin(),sr.String.end());
        resize();
    }

    str operator + (const str& str1){
        str sr;
        copy(this->String.begin(), this->String.end(), back_inserter(sr.String));
        copy(str1.String.begin(), str1.String.end(), back_inserter(sr.String));
        return sr;
    }

//using : *s1 = *s2 + *s3
    void operator =(const str& str1){
        this->String.assign(str1.String.begin(),str1.String.end());
        resize();
    }

};






#endif 