//pacchetto grafico

#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <string>
using std::string;

namespace graphic{

    void up(int);
    void clear();
    void gohome();

    string color(char,string);     //also bold for better results
    void waitUser();
    void title(string);

}

#endif