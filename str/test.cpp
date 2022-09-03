#include"str.h"
#include"str.cpp"

int main(int argc, char const *argv[])
{
    str *s = new str(3.1415926535897938);
    str *s1= new str(3.1415926535897938);
    // *s = *s + *s1;  //OK
    // s->print('\0');
    // *s += *s1;  //Ok
    // s->print('\0');
    // printf("%d",s->getlength());    //OK
    // string a = s->ToStdString();    //OK
    
    // for (auto &c:s->split('.')){ //OK
    //     c.print();
    // }
    
    //s1->close(); OK
    //s1->print(); OK
    //bool a = s1->StringCmp(*s1,*s); //OK


    return 0;
}

