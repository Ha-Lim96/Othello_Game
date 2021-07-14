#include "Game.hpp"
#include <CppUTest/CommandLineTestRunner.h>


TEST_GROUP(GroupGame) { };

TEST(GroupGame, test_game_1) {
    
	Game g1;
	bool b1 = false;
    for(int i=0; i<7; i++){
		b1 = g1.checkExistCase(i,i);
	}
	CHECK_EQUAL(b1,true); //test de la taille réelle de la table
    
    bool b2;
    b2 = g1.checkCanAdd(7,7); //choisissons i et j en random mais qui sont vide en initial
    CHECK_EQUAL(b2,true);
    
    bool b3;
    b3 = g1.tablePleine(); //test d'une table vide 
    CHECK_EQUAL(b3,false);
    
    
}

TEST(GroupGame, test_game_2) {
    Game g2;
	bool b1 = true;
	b1 = g2.checkExistCase(8,9);

	CHECK_EQUAL(b1,false); //test des valeurs qui dépassent la taille de la table
    
    bool b2;
    b2 = g2.checkCanAdd(3,4); //choisissons i et j d'une case déja remplie
    CHECK_EQUAL(b2,false);
    
    bool b3 = false;
    g2.setBoard(PLAYER_BLACK); //remplir toute la table par des pièrres noirs (par examples)
	 
	 b3 = g2.tablePleine();
	 CHECK_EQUAL(b3,true); // test de la fonction dans le cas ou la table est pleine
	 
}



