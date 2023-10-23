# CPP_ZZ3
Git pour les tp de cpp de zz3

## Tp_1
### Exo 1
##### Tests 1-11
1. [x] Définir une classe Point proposant une méthode abstraite afficher(). Dériver deux classes,
Cartesien et Polaire, représentant un point sous forme de coordonnées respectivement  
cartésiennes et polaires (angle en degrés). Offrir un jeu de fonctionnalités minimal à ces classes.
##### Tests 12
2. [x] Surcharger les opérateurs vers les flux d'entrée (std::cin) et de sortie (std::cout) de manière à ce
qu'ils exploitent l'héritage défini précédemment (cf. méthode afficher()).
##### Tests 13-17
3. [x] Proposer des passerelles de conversion entre les deux classes concrètes. Deux approches sont
possibles, il vous est demandé de les implémenter :
   - [x] Proposer des méthodes virtuelles dans la classe Point et ses filles pour convertir un point
dans chacun des types Cartesien et Polaire. Tests 13-15
   - [x] Proposer un constructeur dans chacune des deux classes concrètes qui permette la
conversion à partir de l'autre classe. Tests 16-17

4. [x] Dans le programme principal, stocker des instances de Cartesien et de Polaire dans un vecteur STL et afficher son contenu. Essayer vector<Point> et vector<Point *>.
##### Tests 18-19

5. [x] Aux vues de la question précédente, définir une classe Nuage utilisant la classe vector et
contenant un ensemble de points (qui peuvent être de types différents). Cette classe devra
fournir des itérateurs, à la manière STL (méthodes begin() et end(), type iterator). Tests 18-19
##### Tests 20-22
6. [x] Proposer une fonction qui calcule le barycentre d'un nuage de points. Proposer une version
foncteur de cette fonction. Tests 20-22

### Exo 2
1.  [x] Définir une classe Vecteur conservant des entiers dans un tableau dynamique. Proposer les
méthodes nécessaires au fonctionnement de cette classe, en particulier celles de la forme
normale de Coplien (constructeur par défaut, constructeur par copie, destructeur et opérateur de
copie).

2. [x] Ajouter des opérateurs pour l’insertion sur le flux en sortie (<<), la concaténation (+), l’accès
direct ([], accès lecture ou lecture/écriture) et le produit scalaire (*).
3. [x] Définir une classe Iterateur pour parcourir un vecteur avec les mécanismes élémentaires :
- itérateur au début du vecteur (fourni par le vecteur) : Iterateur begin()
- itérateur à la fin du vecteur (fourni par le vecteur) : Iterateur end()
- passage à l'élément suivant (préfixé) : Iterateur & operator ++ ()
- passage à l'élément suivant (postfixé) : Iterateur operator ++ (int)
- accès à l'élément pointé : int operator * ()
- comparaison entre deux itérateurs : bool operator == (const Iterateur &)
## Tp1_cha
-   Fais par Charlotte
## Tp_2
##### Test 1-2
1. [x] Définir la classe Nuage, générique sur le type de points à contenir. Utiliser la classe std::vector
pour stocker les points. Cette classe devra fournir des itérateurs, à la manière STL (méthodes
begin() et end(), type iterator).

##### Test 3-4a
2. [x] Définir une fonction générique barycentre_v1() prenant en argument un nuage de points et
retournant le barycentre, supposé du même type que les points. Proposer une solution générique
qui s'appuie sur la formule connue pour les cartésiens (utiliser des conversions).

##### Test 4b
3. [x] Cette première version générique nécessite la conversion systématique en cartésien de tous les
points, ce qui a un coût lorsqu'on manipule des polaires. En supposant qu'on dispose de la
formule du barycentre en coordonnées polaires, proposer une spécialisation pour les polaires de
la fonction générique barycentre_v1().


##### Test 5-7
4. [x] On souhaite que la fonction de barycentre s'affranchisse aussi du type du conteneur de points.
Pour cela, la classe Nuage propose une interface similaire aux conteneurs STL, à savoir des
méthodes begin() et end(), ainsi qu'un type interne iterator. Proposer une fonction barycentre_v2()
qui puisse fonctionner indifféremment sur les principaux conteneurs STL et la classe Nuage.
## Tp_3