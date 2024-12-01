# Projet Transitscan

## Description du Projet
Le projet **Transitscan** est un programme qui simule la gestion des files d'attente avec des algorithmes d'ordonnancement, principalement `NEQLI` et `FANEQLI`. Ces algorithmes ont pour objectif de minimiser le temps d'attente et les déplacements du scanner entre différentes files d'attente. Ce projet est conçu pour appliquer des conventions strictes de programmation en C++ tout en assurant une logique claire et optimisée.

## Structure du Dépôt
Le dépôt est organisé de la manière suivante :

- `src/` : Contient les fichiers source (.cc) avec les implémentations des différentes fonctions.
  - `NEQLI.cc` : Implémentation de l'algorithme NEQLI.
  - `FANEQLI.cc` : Implémentation de l'algorithme FANEQLI.
  - `main.cc` : Point d'entrée du programme.
- `include/` : Contient les fichiers d'en-tête (.h).
  - `NEQLI.h` : Déclaration des fonctions relatives à l'algorithme NEQLI.
  - `FANEQLI.h` : Déclaration des fonctions relatives à l'algorithme FANEQLI.
- `tests/` : Contient les tests unitaires.
  - `test_transitscan.cc` : Tests des fonctions `run_NEQLI` et `run_FANEQLI` pour valider leur comportement.
- `Makefile` : Fichier pour automatiser la compilation du projet.

## Algorithmes Principaux
### NEQLI (Non-Empty Queue with Lowest Index)
L'algorithme `NEQLI` cherche à traiter la première file non vide avec l'indice le plus bas. Le scanner se déplace entre les files pour minimiser le déplacement total.

### FANEQLI (Fair and Non-Empty Queue with Lowest Index)
L'algorithme `FANEQLI` met en place une logique de "tour équitable" où chaque file non vide est traitée une fois par tour avant de recommencer, afin de garantir une équité entre les files.

## Compilation et Exécution
Pour compiler le projet, exécutez la commande suivante dans le terminal :

```sh
make
```

Pour exécuter le programme compilé :

```sh
./transitscan
```

## Tests
Les tests sont écrits en utilisant **Google Test** et se trouvent dans le répertoire `tests/`. Pour exécuter les tests :

```sh
make test
./transitscan_test
```

Ces tests couvrent des scénarios variés afin de valider les algorithmes d'ordonnancement et vérifier la cohérence des sorties.

## Conventions de Programmation
Le projet suit des conventions de programmation strictes pour assurer la lisibilité et la maintenabilité du code :
- **Noms des Variables** : Minuscule avec des underscores (`snake_case`).
- **Constantes** : Majuscule avec des underscores (`CONSTANTE_EXEMPLE`).
- **Documentation** : Les fonctions doivent être documentées pour expliquer leurs paramètres, leur rôle et leur sortie.
- Pour plus de détails, consultez le fichier `CONTRIBUTING.md`.

## Collaboration
- **Branches** : Créez des branches spécifiques pour chaque fonctionnalité ou correctif (évitez de travailler directement sur `main`).
- **Pull Requests** : Pour contribuer, créez une **pull request** et sollicitez une revue avant de fusionner dans `main`.

## Auteurs
- Projet initié par [Votre Nom] et coordonné avec l'aide de plusieurs chatbots pour développer, tester, et optimiser chaque partie du code.

## Licence
Ce projet est sous licence MIT - voir le fichier `LICENSE` pour plus de détails.

