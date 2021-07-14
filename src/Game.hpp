#ifndef GAME_HPP
#define GAME_HPP
#include <array>


enum Players{PLAYER_BLACK = 0, PLAYER_WHITE = 1, PLAYER_EMPTY = -1};
using Board = std::array<std::array<Players,8>,8>;	

/**
 * \brief la classe Game est la classe qui contient tout les attributs et les méthodes pour le deroulement du jeu.
 */
class Game {
	
	
	private:
	
		/**
         * \brief Board represente la table de jeu
         * c'est un tableau array  de 8X8 cases : contient -1 quand elle est vide, et 1 quand il s'agit d'un pion blanc, et contient 0 quand il s'agit d'un pion noir
         */
         Board _board;

        /*!
         * \brief _scoreBlack est un int represente le score du jouer 0
         */
        int _scoreBlack;

        /**
         * \brief _scoreWhite est un int represente le score du jouer 1
         */
        int _scoreWhite;
		
			
	public:

        /**
         * \brief Game constructeur de la classe Game
         */
		Game(); 

        /**
         * \brief afficherBoard fonction qui affiche la table de jeu dans la console
         */
		void afficherBoard();

        /**
         * \brief checkExistCase fonction qui verifie si une case donnee existe ou pas
         * \param i indice de ligne
         * \param j indice de colonne
         * \return boolean qui confirme ou affirme l'existance de la case
         */
		bool checkExistCase(int i, int j)const; 

        /**
         * \brief checkCanAdd fonction qui verifie si une case donnee est vide ou occupee par un pion
         * \param i indice de ligne
         * \param j indice de colonne
         * \return boolean qui confirme ou affirme la disponibilité de la case
         */
		bool checkCanAdd(int i, int j)const; 

        /**
         * \brief tablePleine fonction qui verfifie si la table contient de la place pour ajouter des pions.
         * \return boolean confirme ou affirme si la table est pleine.
         */
		bool tablePleine()const; 

        /**
         * \brief checkPlacePiter verifie si un coup donnee est valide selon les regles de jeu.
         * \param tour le tour represente le numero du player
         * \param lig l'indice ligne.
         * \param col l'indice colonne.
         * \return boolean qui envoie la reponse qui fait le coup.
         */
		bool checkPlacePiter(Players tour, int lig, int col)const;

        /**
         * \brief setBoard remplie la table du jeu pour executer un test unitaire
         * \param val une valeur quelconque pour la mettre dans toutes les cases de la table.
         */
        void setBoard(Players val);

        /**
         * \brief placerPion executer un coup pour un player et tourne tout les pions qui doivent tourner.
         * \param tour represente un des deux jouers.
         * \param lig indice ligne de la case a mettre le pion.
         * \param col indice colonne de la case a mettre le pion.
         */
		void placerPion(Players tour,int lig,int col); 

        /**
         * \brief jouer utilise et organise toutes les fonctions et les attributs pour le deroulement du jeu.
       */
        void jouer();
		
};

#endif


