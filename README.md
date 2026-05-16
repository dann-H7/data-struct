
# Data Structures in C / C++

[![Status](https://img.shields.io/badge/status-in%20development-orange)]()
[![Language](https://img.shields.io/badge/language-C%20%7C%20C%2B%2B-blue)]()
[![License](https://img.shields.io/badge/license-MIT-green)]()

> Implémentation progressive de structures de données classiques en **C** et **C++**, avec une approche pédagogique, modulaire et orientée qualité de code.

---

## Aperçu

Ce dépôt rassemble plusieurs implémentations de structures de données fondamentales, développées pas à pas pour :

- comprendre les mécanismes internes des structures de données,
- pratiquer le C et le C++ de manière rigoureuse,
- construire une base solide pour des projets plus avancés en algorithmique, systèmes et IA,
- documenter une évolution progressive du code vers une architecture plus propre, plus testable et plus réutilisable.

Le projet est **en cours d’évolution**.  
Chaque dossier correspond à une implémentation autonome avec son propre `makefile`, ses fichiers d’en-tête, ses sources et un programme de démonstration.

---

## Structures disponibles

### `basic_queue`

Implémentation d’une file simple.

Fonctionnalités typiques :
- insertion en file,
- suppression en tête,
- consultation de l’état de la file,
- affichage de démonstration...

### `stack`

Implémentation d’une pile.

Fonctionnalités typiques :
- empilement,
- dépilement,
- lecture du sommet,
- vérification de vacuité...

### `linked-list`

Implémentation d’une liste chaînée.

Fonctionnalités typiques :
- insertion,
- suppression,
- parcours,
- manipulation de nœuds...

### `binary-tree`

Implémentation d’un arbre binaire.

Fonctionnalités typiques :
- insertion,
- parcours,
- recherche,
- base pour enrichissements futurs : arbre de recherche, équilibrage, suppression avancée.

---

## Arborescence du dépôt

```bash
data-struct.git/
├── .gitignore
├── LICENSE
├── README.md
├── basic_queue
│   ├── include
│   │   └── queue.h
│   ├── makefile
│   └── src
│       ├── main.c
│       └── queue.c
├── binary-tree
│   ├── include
│   │   └── binary_tree.h
│   ├── makefile
│   └── src
│       ├── binary_tree.c
│       └── main.c
├── linked-list
│   ├── include
│   │   └── list.h
│   ├── makefile
│   └── src
│       ├── list.c
│       └── main.c
├── stack
│   ├── include
│   │   └── stack.h
│   ├── makefile
│   └── src
│       ├── main.c
│       └── stack.c
└── struct_project_gen.py
```
