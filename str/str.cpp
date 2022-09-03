#include"str.h"

str::str(long long cr){
    char p[22] = {0};
    sprintf(p,"%d",cr);
    length = strlen(p);
    for(char &c : p){
        if(c == '\0') break;
        String.push_back(c);
    }
}

str::str(long cr){
    char p[22] = {0};
    sprintf(p,"%d",cr);
    length = strlen(p);
    for(char &c : p){
        if(c == '\0') break;
        String.push_back(c);
    }
}

str::str(unsigned long cr){
    char p[22] = {0};
    sprintf(p,"%d",cr);
    length = strlen(p);
    for(char &c : p){
        if(c == '\0') break;
        String.push_back(c);
    }
}

str::str(int cr){
    char p[22] = {0};
    sprintf(p,"%d",cr);
    length = strlen(p);
    for(char &c : p){
        if(c == '\0') break;
        String.push_back(c);
    }
}

str::str(unsigned cr){
    char p[22] = {0};
    sprintf(p,"%d",cr);
    length = strlen(p);
    for(char &c : p){
        if(c == '\0') break;
        String.push_back(c);
    }
}

str::str(char *cr){
    length = strlen(cr);
    char _tcr[length];
    strcpy(_tcr,cr);
    for(char &c : _tcr){
        if(c == '\0') continue;
        String.push_back(c);
        cr++;
    }
}

str::str(unsigned long long cr){
    char p[22] = {0};
    sprintf(p,"%d",cr);
    length = strlen(p);
    for(char &c : p){
        if(c == '\0') break;
        String.push_back(c);
    }
}

str::str(double cr){
    char p[64] = {0};
    //sprintf(p,"%f",cr);
    gcvt(cr,64,p);
    length = strlen(p);
    for(char &c : p){
        if(c == '\0') break;
        String.push_back(c);
    }
}

str::str(void){
    ;
}


int str::print(char end){
    if(String.size() <= 0){
        return -1;
    }
    else{
        for(int i = 0 ; i < String.size() ; i++){
            printf("%c",String[i]);
            printf("%c",end);
        }
    }
    return 0;
}

void str::resize(){
    length = String.size();
}

int str::getlength() const {
    return String.size();
}

string str::ToStdString(){
    string _tstring;
    for(char &c:String){_tstring += c;}
    return _tstring;
}

vector<str> str::split(char sp){
    vector<str>_tStrlist;
    str *Str = new str();
    for(char &c:this->String){
        if(c == sp ){
            Str->resize();
            _tStrlist.push_back(*Str);

            Str = new str();
            continue;
        }
        Str->String.push_back(c);
    }
    _tStrlist.push_back(*Str);
    return _tStrlist;
}

bool str::StringCmp(str& str1,str& str2){
    return (str1.String == str2.String) ? true : false;
}

int str::StrFind(str& key){
    //伪KMP?
    // int index = 0;
    // for(char &c:this->String){
    //     for(int i = 0;i < key.getlength();i++){
    //         if(c== key.String[i]){
    //             continue;
    //         }else{
    //             i = 0;
    //         }
    //     }
    //}
}
