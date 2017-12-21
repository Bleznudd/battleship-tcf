//gestore degli errori

#ifndef ERROR_H
#define ERROR_H

#include <string>

using namespace std;

class Error{

private:

    static string errorMessage;

public:

    Error();
    ~Error();
    static void set(string);
    static string get();

};

#endif
