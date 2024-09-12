# Connect Four Game in C
## Principe du jeu
Le jeu puissance 4 se joue à l’aide d’une grille verticale de sept colonnes sur six lignes. Chaque joueur dispose de vingt et un jetons d’une couleur. A tour de rôle, les joueurs placent un jeton dans une colonne à la position la plus basse possible dans ladite colonne. Pour gagner le jeu, un joueur doit aligner quatre jetons de la même couleur verticalement, horizontalement ou en oblique. Si, alors que toutes les cases de la grille de jeu sont remplies, aucun des deux joueurs n'a réalisé un tel alignement, la partie est déclarée nulle.

## Présentation du projet
Ce projet implémente un puissance 4 en C. Ce jeu peut être joué par 2 joueurs ou un seul. Si un seul joueur joue, l'autre joueur sera l'ordinateur. Attention, l'ordinateur ne vous fera pas de cadeaux ! Il est possible d'arrêter le jeu à tout moment en appuyant sur F. Attention, aucune sauvegarde n'est réalisée !

## Structure du projet
Le projet est découpé en plusieurs fichiers sources et headers :
<ul>
<li>grid.c: gestion de la grille et des jetons (affichage + logique)</li>
<li>interactions.c: gestion des intéractions de l'utilisateur et utilisation des fonctions de grid.c pour modifier l'emplacement des jetons dans la grille</li>
<li>computer.c: comportement de l'ordinateur face à un joueur humain</li>
<li>human_game.c: défini la boucle principale du jeu dans le cas où 2 humains jouent. Cette boucle est réutilisée dans le fichier main.c dans le cas où l'utilisateur choisit de jouer sans l'ordinateur.</li>
<li>computer_game.c: défini la boucle principale du jeu dans le cas où 1 humain joue contre l'ordinateur. Cette boucle est réutilisée dans le fichier main.c dans le cas où l'utilisateur choisit de jouer avec l'ordinateur.</li>
<li>main.c: boucle principale du programme qui demande à l'utilisateur de choisir s'il veut jouer avec ou sans ordinateur et applique la bonne boucle en conséquence.</li>
<li>constants.c: définit les constantes correspondant aux codes d'erreur.</li>
<li>winning_combinations.c: tests pour s'assurer que la fonction de vérification du statut du jeu (jeu terminé ou non) est correcte</li>
</ul>

## Points à retenir
<ul>
<li>Pour une boucle utilisant un unsigned short, la condition d'arrêt est :
for (unsigned short index = 10; index != (unsigned short) - 1; index--)
</li>
<li>La fonction abort produit un core file</li>
<li>Pour utiliser des constantes dans plusieurs fichiers sans avoir à les déclarer à chaque fois, utiliser le mot-clé extern.</li>
<li>Pour lire un fichier core, utiliser la commande gdb ./prog ./core_file</li>
<li>Définir les enums dans un .h et pas dans un .c</li>
<li>Ne pas mettre le mot-clé const pour les enums</li>
</ul>