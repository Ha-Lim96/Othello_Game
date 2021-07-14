#include "Game.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


Game::Game(): _scoreBlack(2), _scoreWhite(2)
{
	//remplir la table avec des -1 pour la mettre en vide 
	 for(int i=0; i<8; i++){ 
		for(int j=0; j<8; j++)
			_board[i][j] = PLAYER_EMPTY;
	 }
	 
	 //remplir les 4 cases par les pions White et black
	_board[3][3] = PLAYER_BLACK;
	_board[3][4] = PLAYER_WHITE;
	_board[4][3] = PLAYER_WHITE;
	_board[4][4] = PLAYER_BLACK;
	 
}

void Game :: setBoard(Players val){ //methode implémentée juste pour un tests unitaires
	for(int i=0; i<8; i++){ 
		for(int j=0; j<8; j++)
		_board[i][j] = val;
	}
}


void Game :: afficherBoard(){
	std::cout<<"Board : "<<std::endl;
		
	int i,j;
	int nv_scoreBlack = 0;
	int nv_scoreWhite = 0;
	
	//affichage de la table dans la console
	for(i=0; i<8; i++){ 
		for(j=0; j<8; j++)
			if(_board[i][j] == PLAYER_EMPTY)
				printf(". ");
			else if(_board[i][j] == PLAYER_BLACK){
				printf("B ");
				nv_scoreBlack++; //incrémentation de score du player0 pour chaque pion trouvé 
			}
			else if(_board[i][j] == PLAYER_WHITE){
				printf("W ");
				nv_scoreWhite++; //incrémentation de score du player1 pour chaque pion trouvé 
			}
				printf("\n");
	}
	
	_scoreBlack = nv_scoreBlack;
	_scoreWhite = nv_scoreWhite;
	std::cout<<"score black: "<<_scoreBlack<<std::endl;
	std::cout<<"score white: "<<_scoreWhite<<std::endl;
	
	bool pouvoirJouer = tablePleine();
	if(pouvoirJouer == true)
		std::cout<<"terminated = 0 "<<std::endl;
	else
		std::cout<<"terminated = 1 "<<std::endl;
	
	if(_scoreBlack > _scoreWhite)
		std::cout<<"winner: 0"<<std::endl;
	else
		if(_scoreBlack < _scoreWhite)
			std::cout<<"winner: 1"<<std::endl;
		else 
			std::cout<<"winner: 2"<<std::endl;
}



bool Game:: checkCanAdd(int i, int j)const{
	return (_board[i][j] == PLAYER_EMPTY); //true si la case Board[i][j] est vide
}



bool Game:: checkExistCase(int i, int j)const{	
	return ((i>=0)&&(i<=7)&&(j>=0)&&(j<=7)); //vrai si la case existe
}

bool Game:: tablePleine()const{
	for(int i=0; i<8; i++){ 
		for(int j=0; j<8; j++)
			if(_board[i][j] == PLAYER_EMPTY)
				return false;
	}
	return true; //vrai si la table est pleine 
}

bool Game :: checkPlacePiter(Players tour, int lig, int col)const{ //verification des regles de jeu
	int i, j, ok;
	//traitement vers les case de l'haut 
	i= lig - 1;
	ok = 0;
	while(checkExistCase(i,col) && _board[i][col] != tour && _board[i][col] != PLAYER_EMPTY){
		i--;
		ok = 1;
	}
		if(checkExistCase(i,col) && _board[i][col]== tour && ok ==1){
			return true;
		}
		
	//traitement des cases du bas
	i= lig + 1;
	ok = 0;
	while(checkExistCase(i,col) && _board[i][col] != tour && _board[i][col] != PLAYER_EMPTY){
		i++;
		ok = 1;
	}
		if(checkExistCase(i,col) && _board[i][col]== tour && ok == 1){
			return true;
		}
	
	
	
	//traitement des cases horizontals vers la gauche
	j= col-1;
	ok = 0;
	while(checkExistCase(lig,j) && _board[lig][j] != tour && _board[lig][j] != PLAYER_EMPTY){
		j--;
		ok = 1;
	}
		if(checkExistCase(lig,j) && _board[lig][j]== tour && ok==1){
			return true;
		}
	
	//traitement des cases horizontals vers la droite
	j= col+1;
	ok = 0;
	while(checkExistCase(lig,j) && _board[lig][j] != tour && _board[lig][j] != PLAYER_EMPTY){
		j++;
		ok = 1;
	}
		if(checkExistCase(lig,j) && _board[lig][j]== tour && ok ==1){
			return true;
		}
	
	
		//cases de la diagonal \ vers le haut
		i= lig -1;
		j= col -1;
		ok = 0;
		while(checkExistCase(i,j) && _board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
			i--;
			j--;
			ok = 1;
		}
		if(checkExistCase(i,j) && _board[i][j] == tour && ok == 1){
			return true;
		}
		
		
	//cases de la diagonal \ vers le bas
		i= lig +1;
		j= col +1;
		ok = 0;
		
		while(checkExistCase(i,j) && _board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
			i++;
			j++;
			ok = 1 ;
		}
		if(checkExistCase(i,j) && _board[i][j] == tour){
			return true;
		}
		
		
	
	//cases de la diagonal / vers le haut
		i= lig -1;
		j = col +1;
		ok = 0;
		while(checkExistCase(i,j) && _board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
			i--;
			j++;
			ok = 1;
		}
		if(checkExistCase(i,j) && _board[i][j] == tour && ok == 1){
			return true;
		}

		
	//cases de la diagonal / vers le bas
		i= lig +1;
		j= col -1;
		ok  = 0;
		while(checkExistCase(i,j) && _board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
			i++;
			j--;
			ok = 1;
		}
		if(checkExistCase(i,j) && _board[i][j] == tour && ok == 1){
			return true;
		}
	
	return false;
}


void Game :: placerPion(Players tour, int lig, int col){
	int i; int j;
	_board[lig][col] = tour;
	
	//traitement vers les case de l'haut en cas de sandwich
	i= lig - 1;
	while(checkExistCase(i,col) && _board[i][col] != tour && _board[i][col] != PLAYER_EMPTY)
		i--;
		if(checkExistCase(i,col) && _board[i][col]== tour){
			i = lig-1;
			while(_board[i][col] != tour && _board[i][col] != PLAYER_EMPTY){
				_board[i][col] = tour;
				i--;
			}
		}
		
	//traitement des cases du bas en cas de sandwich
	i= lig + 1;
	while(checkExistCase(i,col) && _board[i][col] != tour && _board[i][col] != PLAYER_EMPTY)
		i++;
		if(checkExistCase(i,col) && _board[i][col]== tour){
			i = lig+1;
			while(_board[i][col] != tour && _board[i][col] != PLAYER_EMPTY){
			_board[i][col] = tour;
				i++;
			}
		}
	
	
	
	//traitement des cases horizontals vers la gauche
	j= col-1;
	while(checkExistCase(lig,j) && _board[lig][j] != tour && _board[i][col] != -PLAYER_EMPTY)
		j--;
		if(checkExistCase(lig,j) && _board[lig][j]== tour){
			j=col-1;
			while(_board[lig][j] != tour && _board[lig][j] != PLAYER_EMPTY){
				_board[lig][j] = tour;
				j--;
			}
		}
	
	//traitement des cases horizontals vers la droite
	j= col+1;
	while(checkExistCase(lig,j) && _board[lig][j] != tour && _board[i][col] != PLAYER_EMPTY)
		j++;
		if(checkExistCase(lig,j) && _board[lig][j]== tour){
			j=col+1;
			while(_board[lig][j] != tour && _board[lig][j] != PLAYER_EMPTY){
				_board[lig][j] = tour;
				j++;
			}
		}
	
	
		//cases de la diagonal \ vers le haut
		i= lig -1;
		j= col -1;
		
		while(checkExistCase(i,j) && _board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
			i--;
			j--;
		}
		if(checkExistCase(i,j) && _board[i][j] == tour){
			i = lig - 1;
			j = col - 1;
			while(_board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
				_board[i][j] = tour;
				i--;
				j--;
			}
		}
		
		
	//cases de la diagonal \ vers le bas
		i= lig +1;
		j= col +1;
		
		while(checkExistCase(i,j) && _board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
			i++;
			j++;
		}
		if(checkExistCase(i,j) && _board[i][j] == tour){
			i = lig + 1;
			j = col + 1;
			while(_board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
				_board[i][j] = tour;
				i++;
				j++;
			}
		}
		
		
	
	//cases de la diagonal / vers le haut
		i= lig -1;
		j = col +1;
		
		while(checkExistCase(i,j) && _board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
			i--;
			j++;
		}
		if(checkExistCase(i,j) && _board[i][j] == tour){
			i = lig - 1;
			j = col + 1;
			while(_board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
				_board[i][j] = tour;
				i--;
				j++;
			}
		}

		
	//cases de la diagonal / vers le bas
		i= lig +1;
		j= col -1;
		
		while(checkExistCase(i,j) && _board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
			i++;
			j--;
		}
		if(checkExistCase(i,j) && _board[i][j] == tour){
			i = lig + 1;
			j = col - 1;
			while(_board[i][j] != tour && _board[i][j] != PLAYER_EMPTY){
				_board[i][j] = tour;
				i++;
				j--;
			}
		}
	
}


void Game::jouer(){
	
	while(!tablePleine()){ //possibilité de jouer
		int i=0; int j=0;
		Players tour = PLAYER_BLACK;
		
		afficherBoard();
		std::cout<<"Player 0 "<<std::endl;
		std::cout<<"pour mettre un pion de votre couleur tapez l'indice LIGNE puis l'indice COLONNE "<<std::endl;
		std::cout<<"pour quitter le jeux appuiyez sur les touches ctrl+c ou fermez la console"<<std::endl;
		std::cout<<"actions:"<<std::endl;
		std::cin>>i;
		std::cin>>j;
		while(!checkExistCase(i,j) ||!checkCanAdd(i,j) || !checkPlacePiter(tour,i,j)){	
			afficherBoard();
			std::cout<<"Player 0 "<<std::endl;
			std::cout<<"vous ne pouvez pas mettre un pion dans ces indices Re-tapez l'indice LIGNE puis l'indice COLONNE "<<std::endl;
			std::cout<<"pour quitter le jeux appuiyez sur les touches ctrl+c ou fermez la console "<<std::endl;
			std::cout<<"actions:"<<std::endl;
			std::cin>>i;
			std::cin>>j;
			} 
			placerPion(tour,i,j);			
			
			
			tour = PLAYER_WHITE;
			i=0; j=0;
			afficherBoard();
			std::cout<<"Player 1 "<<std::endl;
			std::cout<<"pour mettre un pion de votre couleur tapez l'indice LIGNE puis l'indice COLONNE "<<std::endl;
			std::cout<<"pour quitter le jeux appuiyez sur les touches ctrl+c ou fermez la console "<<std::endl;
			std::cout<<"actions:"<<std::endl;
			
			std::cin>>i;
			std::cin>>j;
			
			while(!checkExistCase(i,j)||!checkCanAdd(i,j)){
			afficherBoard();
			std::cout<<"Player 1"<<std::endl;
			std::cout<<"vous ne pouvez pas mettre un pion dans ces indices Re-tapez l'indice LIGNE puis l'indice COLONNE "<<std::endl;
			std::cout<<"pour quitter le jeux appuiyez sur les touches ctrl+c ou fermez la console "<<std::endl;
			std::cout<<"actions:"<<std::endl;
			
			std::cin>>i;
			std::cin>>j;
			} 
			placerPion(tour,i,j);
			//afficherBoard();
	}
			
			std::cout<<"partie finie "<<std::endl;
			afficherBoard();
	
}



