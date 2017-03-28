# OfxApps

Ce répertoire regroupe les applications développées avec [OpenFramework](http://openframeworks.cc/) du cours [paccpp2](https://github.com/paccpp/paccpp2).

## Applications

| Nom                             | Déscription                         |
|---------------------------------|-------------------------------------|
|[OfxDummy](./OfxDummy)           | A dummy OF Applications             |

## Installation

Pour compiler les applications de ce répertoire vous pouvez

- Créez un nouveau dossier sur votre machine (par exemple `OpenFrameworks`).
- Téléchargez la dernière version stable d'OpenFrameworks correspondant à votre OS [ici](http://openframeworks.cc/download/).
- Placez le **contenu** du dossier téléchargé dans un dossier nommé `OfxLib` dans le dossier `OpenFrameworks`.
- Téléchargez ensuite ce répertoire et placez le juste à côté du dossier `OfxLib` dans le dossier `OpenFrameworks`.

Vous devriez avoir une arborescence qui ressemble à:

```
├── OpenFrameworks
│   ├── OfxApps
│   │   ├── README.md
│   │   ├── OfxDummy
│   │   │   ├── ...
│   │   │   ├── ...
│   │   ├── ...
│   ├── OfxLib
│   │   ├── README.md
│   │   ├── addons
│   │   ├── apps
│   │   ├── ...
│   │   ├── libs
│   │   ├── ...
```

Vous pouvez maintenant ouvrir un projet `Xcode` ou `Visual Studio` contenu dans un des dossiers de `OfxApps` pour compiler et faire tourner une application.

## Project Generator

Vous pouvez vous servir du générateur de projet contenu dans le dossier `OfxLib` pour, générer un nouveau projet, régénérer ou configurer un projet existant.

Pour plus d'informations vous pouvez vous reporter à cette [page](http://openframeworks.cc/learning/01_basics/create_a_new_project/) ou cette [vidéo](https://www.youtube.com/watch?v=4k2ZcvC0YEA) qui expliquent comment se servir du générateur de projet d'**OF**

### Liens utiles

- [ofBook - how OpenFramework works](http://openframeworks.cc/ofBook/chapters/how_of_works.html)
- [ofBook - Sound chapter](http://openframeworks.cc/ofBook/chapters/sound.html).
