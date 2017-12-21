//implementazione di Error

#include "../header/Error.h"

Error::Error(){
    
}

Error::~Error(){

}

void Error::set(string err){
    errorMessage = err;
}

string Error::get(){
    return errorMessage;
}

