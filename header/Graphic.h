//pacchetto grafico

#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <string>
using std::string;

namespace graphic{

    void up(int);       //posiziona il cursore in su di n righe, nel mentre cancella il contenuto precedente
    void r();           //cancella il contenuto di una riga 
    void clear();       //pulisce il terminale totalmente
    void gohome();      //posiziona il cursore in alto a sinistra

    string color(char,string);     //cambia colore alla stringa passata, aggiunge anche il grassetto per una resa migliore
    void waitUser();               //aspetta la pressione del tasto ENTER per proseguire
    void title(string);            //genera un titolo accattivante per la stringa passata

}

#endif