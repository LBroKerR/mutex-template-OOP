#include "char_list.h"

char_list::char_list() {
	String=nullptr;
}
char_list::char_list(char* param){
    unsigned i=0;
    if(param!=nullptr){
        String=new char[(*param/sizeof(char))];
        for (; i < (*param/sizeof(char)); i++){
            String[i]=param[i];
        }
        String[i]='\0';
    }
    else{
        String=nullptr;
    }
}
char_list::~char_list(){
    if(String!=nullptr){
        delete[] String;
    }
    String=nullptr;
}

char* char_list::string(){
    return String;
}

bool char_list::operator==(char_list other){
    char *tmp= other.string();
    if(String!=nullptr && tmp!=nullptr){
        if((*String/sizeof(char)) == (*tmp/sizeof(char))){
            for (unsigned i = 0; String[i]!='\0'; i++){
                if(String[i]!=tmp[i]){
                    return false;
                }
            }
        }
    }
    return true;
}
bool char_list::operator==(char* other){
    char *tmp= other;
    if(String!=nullptr && tmp!=nullptr){
        if((*String/sizeof(char)) == (*tmp/sizeof(char))){
            for (unsigned i = 0; String[i]!='\0'; i++){
                if(String[i]!=tmp[i]){
                    return false;
                }
            }
        }
    }
    return true;
}
bool char_list::operator!=(char_list other){
    return !(*this==other);
}
bool char_list::operator!=(char* other){
    return !(String==other);
}
char_list& char_list::operator+=(char_list other){
    char *tmp=  other.string();
    char *newArray;
    unsigned i=0;
    unsigned lenght=0;
    if(String==nullptr){
        lenght=*tmp/sizeof(char);
        String = new char[lenght];
        for (; i < lenght; i++){
            String[i]=tmp[i];
        }
        String[lenght]='\0';
    }
    else if(String !=nullptr){
        newArray=new char[(*String/sizeof(char))+(*tmp/sizeof(char))];
        for(; i<(*String/sizeof(char));i++){
            newArray[i]=String[i];
        }
        for (; i < (*String/sizeof(char))+(*tmp/sizeof(char)); i++){
            newArray[i]=tmp[i];
        }
        delete[] String;
        String=newArray;
        String[(*String/sizeof(char))+(*tmp/sizeof(char))]='\0';
    }
    return *this;
}
char_list& char_list::operator+=(char other){
    unsigned i = 0;
    char* tmp_string=new char[(*String/sizeof(char))+1];
    if(tmp_string==nullptr){
       delete[] String;
    }
    if(String!=nullptr){
        for (; i <(*String/sizeof(char)); i++){
            tmp_string[i]=String[i];
        }
    tmp_string[i]=other;
    tmp_string[i+1]='\0';
    delete[] String;
    String=tmp_string;
    }
    return *this;
}

char_list& char_list::operator=(char_list other){
    char *tmp=  other.string();
    unsigned i=0;
    if(String!=nullptr){
        delete String;
    }
    if(tmp!=nullptr){
        String=new char[(*tmp/sizeof(char))];
        for (; i < (*tmp/sizeof(char)); i++){
            String[i]=tmp[i];
        }
        String[i]='\0';
    }
    else{
        String=nullptr;
    }
    return *this;
}
char_list& char_list::operator=(const char other[]){
    unsigned i=0;
    if(String!=nullptr){
        delete String;
    }
    if(other!=nullptr){
        String=new char[(*other/sizeof(char))];
        for (; i < (*other/sizeof(char)); i++){
            String[i]=other[i];
        }
        String[i]='\0';
    }
    else{
        String=nullptr;
    }
    return *this;
}
char char_list:: operator[](unsigned index){
    if (String != nullptr && index < lenght()) {
        return String[index];
    }
    return '\0';
}

int char_list::lenght(){
    if(String != nullptr){
        return (*String/sizeof(char));
    }
    return NAN;
}
unsigned char_list::to_uint(unsigned* number){
    unsigned i=0;
    unsigned result=0;
    if(String==nullptr){
        return NAN;
    }
    for (; String[i]!='\0'; i++){
        if(String[i]<'0' || String[i]>'9'){
            return NAN;
        }
        result=result*10+(String[i]-'0');
    }
    *number=result;
    return NUMBER;
}
unsigned char_list::to_float(float*number){
    unsigned i=0;
    bool dot=false;
    float result=0.0f;
    unsigned decimal=10;
    if(String==nullptr){
        return NAN;
    }
    for (; String[i]!='\0'; i++){
        if(String[i]<'0' || String[i]>'9'){
            return NAN;
        }
        else if (String[i]=='.'){
            dot=true;
        }
        if(!dot){
            result=result*decimal+(String[i]-'0');
        }
        else{
            result=result+(String[i]-'0')/decimal;
            decimal*=10;
        }
    }
    *number=result;
    return NUMBER;
}

void char_list::to_char_list(float number, unsigned granularity){
    int intPart = (int)number;
    float fracPart = number - intPart;
    if (fracPart < 0){
        fracPart = -fracPart;
    }
    char_list intStr;
    intStr.to_char_list(intPart);
    float scale = 1;
    for(unsigned i = 0; i < granularity; ++i) {
        scale *= 10;
    }
    int fracInt = (int)(fracPart * scale + 0.5f);
    char* fracBuffer = new char[granularity + 2];
    fracBuffer[0] = '.';
    for (int i = granularity - 1; i >= 0; --i) {
        fracBuffer[i + 1] = '0' + (fracInt % 10);
        fracInt /= 10;
    }
    fracBuffer[granularity + 1] = '\0';
    char_list fracStr(fracBuffer);
    delete[] fracBuffer;
    *this = intStr;
    *this += fracStr;
}
void char_list::to_char_list(int number){
    int temp = number;
    int len = 0;
    bool isNegative = false;
    if (temp == 0) {
        len = 1;
    }
    if (temp < 0) {
        isNegative = true;
        temp = -temp;
        len++;
    }
    while (temp > 0) {
        temp /= 10;
        len++;
    }
    if (String != nullptr) {
        delete[] String;
    }
    String = new char[len + 1];
    String[len] = '\0';
    temp = (number < 0) ? -number : number;
    for (int i = len - 1; i >= 0; --i) {
        String[i] = '0' + (temp % 10);
        temp /= 10;
    }
    if (isNegative){
        String[0] = '-';
    }
}
char_list operator+(char_list String, char_list other){
    char_list new_list=other;
    String+=new_list;
    return  String;
}
char_list operator+(char_list String, char* other){
    char *c=other;
    for (unsigned i = 0; c[i]!='\0'; i++){
        String+=c[i];
    }
    return  String;
}
char_list convert_to_char_list(void* variable, unsigned type){
    char_list result;
    switch (type) {
        case CHAR_LIST:
            result = *(char_list*)variable;
            break;
        case CHAR:
            result=(char*)variable;
            break;
        case INT:
            result.to_char_list(*(int*)variable);
            break;
        case FLOAT:
            result.to_char_list(*(float*)variable);
            break;
        case BOOL:
            if((bool*)variable){
                result="True";
            }
            else{
                result="False";
            }
        default:
            break;
    }
    return result;
}

char* char_list::get_String()const{
    return String;
}

char_list to_char_list(float param, unsigned granularity=2){
    char_list result;
    result.to_char_list(param, granularity);
    return result;
}
char_list to_char_list(int param){
    char_list result;
    result.to_char_list(param);
    return result;
}