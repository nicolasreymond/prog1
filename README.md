# Recueil de Code

Ce projet est un recueil de code fait en cours, comprenant des exercices et des labos.

## Structure du projet

- `exercises/` : Contient les fichiers source des exercices.
- `labos/` : Contient les dossiers pour chaque labo, avec leurs fichiers source et Makefiles respectifs.
- `Makefile` : Fichier Makefile à la racine pour compiler tous les exercices et labos.
- `README.md` : Documentation du projet.

## Compilation

Pour compiler tous les exercices et labos, exécutez :

```sh
make
```

Pour nettoyer les fichiers compilés, exécutez :

```sh
make clean
```

Pour compiler un exercice spécifique, exécutez :

```sh
make -C exercises/<nom_exercice>
```

Pour compiler un labo spécifique, exécutez :

```sh
make -C labos/<nom_labo>
```
