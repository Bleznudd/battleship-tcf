# battleship-tcf

This is the battleship game, made for the TCF exam of 2017

Department of Physics, University of Turin.

![University of Turin's Logo](http://www.studyintorino.it/wp-content/uploads/logo-unito_imagefull.jpg "Università di Torino")

## Description
The game consists in two player deploing a predefined number of ships onto a 10x10 grid. Once that all the ships have been deployed, players attack in turns the other player's ships and the first who sink the opponent fleet wins

## Installation
Start by cloning this repository on your PC, open a terminal and
```
git clone https://github.com/Bleznudd/battleship-tcf.git
```

Once that the download has finished cd into the directory
```
cd battleship-tcf
```

And run the Makefile with the command
```
make
```

You will find and executable file in the directory called **battleship-tcf**, start the game with
```
./battleship-tcf
```

### Note for Windows users
Due to ANSI escape codes used in this project (which widnows prompt does not support) you will need ad additional step to play this game. First you will need [GnuWin](http://gnuwin32.sourceforge.net/) or [Cygwin](http://www.cygwin.com/)
and then you will need to open the Makefile, ad modify the `DR` variable from `UNIX` to `WINDOWS`.
After that you will be able to run make, and play the game as mentioned above.

## Alternative installation
Some not updated versions of the game can be downloaded from the **release** section of the github repository, or either from the links below:
- [v0.1 Linux x86_64](https://github.com/Bleznudd/battleship-tcf/releases/download/v0.1/battleship-tcf)
- [v0.1 Mac](https://github.com/Bleznudd/battleship-tcf/releases/download/v0.1/battleship-tcf/mac)

## Manteinance
As said, this is a game made for the C++ exam of TCF course of 2017, so it will not be manteined after the exam date.
Don't expect update and/or bugfix
