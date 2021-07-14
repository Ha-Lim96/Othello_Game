
Sujet : Jeu (Reversi/Othello) en multi-joueur 


Règles du jeu :

riversi est un duel entre deux joueurs, un jouer a les pions blancs et l'autre il a les pions noirs 
ça se joue sur une table de "8 X 8" cases.

pour jouer il faut poser les pions en fonction des tours,
chaqu'un des jouers pose un pions de sa couleur quand c'est son tour, et c'est a lui de jouer
sachant que les pions sont réversibles.

l'objectif du jeu pour chaque jouer est d'avoir les plus grand nombre de pions de sa couleur
ce qui augmente son score.

Pour réverser un pions ou plusiers de l'adversaire il faut composer un sandwich avec ses pions 
ç'est à dire (mettre ses pions entre deux de vos pions) et comme ça votre score s'augmente automatiquement
et le score de l'adversaire baisse, jusqu'a ce que la table sera complètement pleine, 
ce qui fera la fin de la partie.  



Guide d'utilisation de jeu dans la console : 

- pour lancer le jeux: après avoir installé l'interpreteur C++,  il faut taper la commande de lancement ./riversi-cli

- une fois le jeu est lancé :
- ça commence par le player 0 (pions noirs) (règle du jeu) ,
  pour jouer (mettre votre pion sur la table, il faut taper la position ou vous souhaitez le mettre dans la table,

- pour cela tapper l'indice ligne suivi de la touche Entrer, 
  puis l'indice de colone suivi de la touche Entrer aussi, 

- si la position est bonne (accépté par rapport aux regles du jeu) le pion est ajouté, 
  et le tour sera pour le player1 (pions blanches) .... et ainsi de suites

- vous aurez les score des jouers à chaque coup joué.
  le statut de la partie "Terminated = 0" quand ce n'est pas terminée et "Terminated = 1" si la partie est finie.

- vous avez aussi la propriété "Winner = 2" quand les deux joueurs ont le même score,
  "Winner = 0" Player0 à un score plus élevé, et "Winner = 1" signifie que Player1 a un score plus élevé  
 