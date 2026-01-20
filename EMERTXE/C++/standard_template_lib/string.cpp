#include <iostream>
#include<string.h>
#include <strings.h>

using namespace std;
class STRING{

    unsigned int len;
    char* ptr;

public:
    STRING(const char* input = "" ){

        len = strlen(input);

        ptr = new char[len+1];

        strcpy(ptr,input);
    }

    int length(){

        return len;
    }


    STRING(STRING &oref){

        this->len = oref.len;

        this->ptr = new char[oref.len + 1];

        strcpy(this->ptr,oref.ptr);
    }

    ~STRING(){

        delete[] ptr;
    }

    char at(int index){

        return ptr[index];

    }

    void print(){

        cout<<ptr<<endl;
    }

    STRING operator + (const STRING & obj){

        STRING temp;

        temp.len = this->len + obj.len;
        temp.ptr = new char[temp.len+1];

        strcpy(temp.ptr,this->ptr);
        strcat(temp.ptr,obj.ptr);

        return temp;
    }
};

int main(){

    STRING object1 = "Hello";

    STRING object2 = " World";

    STRING object3 = object1 + object2;

    object3.print();
    
}
