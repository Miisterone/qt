
# Indexing client/server

## Intro

Lancer deux qt creator pour ouvrir séparement le client du server.


## Features

- Serveur et client qui communique en tcp sur le port 7007
- Le client qui peut lancer l'indextion
- Le client peut indexer un path spécial
- Le client peut chercher un fichier dans la base de donnée

## Commandes

Start indexation

```shell
indexer start
```

Recherche de fichier

```shell
search <nom du fichier avec extension>
```

exemple:

```shell
search IMG_1604.JPG
```

## Problèmes pontentiel

Si le search ne marche pas après l'indexation, il faut relancer le serveur
