MODULE IMAGE by les power rangers mariam aleyna et mimi ( 12102825, 11908500, 12100162)

#### Prérequis: 

- Sur Windows, il sera nécessaire d'activer WSL (Windows Subsystem for Linux) et installer la distribution Linux de votre choix. Ensuite les commandes seront les memes que sur Linux.

- installer le compilateur gcc:
 	- sur macOS: taper dans le terminal la commande suivante : $> brew install gcc
 	- sur Linux/Windows: taper dans le terminal la commande suivante: $> sudo apt install gcc
 	
- installer la librairie SDL:
	- sur macOs : taper dans le terminal la commande suivante: $> brew install sdl2
	- sur Linux/Windows : taper dans le terminal la commande suivante: $> sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
	
- installer doxygen:
	- sur macOS : taper dans le terminal la commande suivante : $> brew install doxygen
	- sur Linux/Windows : $> sudo apt install doxygen
	 
#### Présentation du module:

Ce module contient 2 classes: 
    	- la classe 'Pixel'
    	- la classe 'Image'
    	
Ces 2 classes nous permettent d'inclure une ou plusieurs images dans notre code, qui sont formatées et peuvent être colorées pixel par pixel.
    
Le module possède egalement 3 programmes:
		- mainTest.cpp : une fois exécuté, il permet de tester les classes et de vérifier qu'elles sont correctement implémentées.
        - mainExemple.cpp :  une fois exécuté, deux images seront générées et sauvegardées dans le dossier data.
        - mainAffichage.cpp : une fois éxécuté, affichera une fenêtre SDL2 avec une image à l'intérieur que nous pouvons faire agrandir et réduire. 

#### Organisation de l'archive
     
En plus de ce fichier Readme.txt, cette archive contient:
	- Le Makefile : il contient toutes les dépendances et commandes permettant la compilation du module, supprime les fichiers objets et éxécutables, et génère la documentation.
	- Un dossier src : il contient tous les fichiers sources .h et .cpp.
	- Un dossier doc : il contient le fichier de configuration doxygen ainsi que la page html (une fois générer) de la documentation.
	- Un dossier obj : il contient tous les fichier objets .o des fichiers .cpp après la compilation grâce au Makefile.
	- Un dossier bin : il contient les 3 fichiers éxécutables du module, également crées après la compilation grâce au Makefile, juste après la compilation des fichiers .o.
	- Un dossier data : il contient les images générées par les éxécutables.

### Compilation du module:

	- Ouvrir un terminal et décompresser l'archive récuperée sur Tomuss en tapant la commande suivante: $> tar -xvf 12102825_11908500_12100162.tgz 
	- Se situer sur le répertoire de l'archive une fois celle-ci décompressé.
	- Taper la commande $> make, le Makefile va se charger de tout compiler en fonction des fichiers, la compilation ne se fera pas sur les fichiers déjà à jour.
	- Pour effacer tous les fichiers "inutile" situé dans les dossiers obj et bin il vous suffira de taper la commande suivante : $> make clean

### Exécution du module:

Après la compilation du module, il faudra rester sur le repertoire de l'archive puis taper la commande $> bin/* dans le terminal avec "*" correspondant au nom de l'exécutable que l'on veut lancer: 
	- $> bin/mainTest.cpp
	- $> bin/mainExemple.cpp
	- $> bin/mainAffichage.cpp
	
### Documentation du module:

Le module image possède également une documentation doxygen qui se génere avec la commande suivante: $> doxygen doc/image.doxy 
Ceci va génerer un dossier html qui contiendra le fichier html du site où se trouve la documentation complète de notre module image.

Bien a vous,
En espérant voir s'afficher 5/5 sur Tomuss ^_^
xoxo
Mariam EL OUARRAD, Miryam ATAMNA et Aleyna YAGBASAN.
