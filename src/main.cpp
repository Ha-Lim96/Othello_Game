
/**
 * \mainpage application de jeu reversi version 1 (version console)
 */



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Game.hpp"

/*!
 * \brief main la fonction principale contient l'instantiation de la classe Game et l'appel de la fonction jouer() qui deroule le jeu.
 * \return
 */

int main(){
	Game nv_board;
	
	//nv_board.afficherBoard();
	//std::cout<<nv_board.checkExistCase(3,5)<<std::endl;
	nv_board.jouer();
	
	//getchar();
	return 0;
}
