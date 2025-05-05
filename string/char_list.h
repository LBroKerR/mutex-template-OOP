#pragma once
#ifndef CHAR_LIST_H
#define CHAR_LIST_H


#define NAN       0
#define NUMBER    1


#define CHAR_LIST 2
#define CHAR      3
#define INT       4
#define FLOAT     5
#define BOOL      6

class char_list{
    char* String;
    char* string();
public:
    char_list();
    char_list(char*);
    ~char_list();

    bool operator==(char_list other);
    bool operator==(char* other);
    bool operator!=(char_list other);
    bool operator!=(char* other);
    char_list& operator+=(char_list other);
    char_list& operator+=(char other);
    char_list& operator=(char_list other);
    char_list& operator=(const char other[]);
    char operator[](unsigned index);

    int lenght();
    unsigned to_uint(unsigned*);
    unsigned to_float(float*);

    void to_char_list(float, unsigned granularity=2);
    void to_char_list(int);

    char* get_String()const;
   
};
char_list operator+(char_list String, char_list other);
char_list operator+(char_list String, char* other);
char_list convert_to_char_list(void* variable, unsigned type);
char_list to_char_list(float, unsigned granularity=2);
char_list to_char_list(int);
#endif /*CHAR_LIST_H*/