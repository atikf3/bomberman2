# Bomberman

[DEPRECATED]

This software is provided as is, the project has reached the end of its development and life. Feel free to browse the code, but no support or warranties will be provided. All credits goes to original developers and associates. 

[Description]

POC for running a graphic C SDL app using X indirect rendering within a container. 

## But
Vous devez réaliser un clone du célèbre jeu Bomberman, avec support du multijoueur en réseau.

Votre application devra :
- Proposer un rendu graphique,
- Permettre de jouer en multijoueur avec un maximum de 4 joueurs,
- Permettre d'héberger une partie, et d'y participer,
- Permettre de se connecter à une partie distante,
- Disposer d'un exécutable pour le client et d'un pour le serveur.

## Requis
- Docker + xClient (x11, xQuartz, Xming, VcXsrv ...)
### ou
- gcc-8, libC, Pthreads, SDL, SDLTTF, SDLImage

# Utilisation
## Dev/Prod
- Requis pour tous:

Docker et un xClient.

### Build:
```bash
docker build -t bomberman .
```
### Windows
*Cette section est en cours de test.*

Installer Xming ou VcXsr
```powershell
set-variable -name DISPLAY -value Votre-IP:0.0
docker run -itv $(pwd):/app/ --rm -e DISPLAY=$DISPLAY bomberman sh -c "cd sdl && make all && ./bomberman res/map.txt; sh"  
```

### macOS 
Sur macOS installez xQuartz.

Une fois lancé, faites <kbd>⌘ Command</kbd> <kbd>,</kbd> pour accéder au menu de préférences et [dans l'onglet sécurité, autorisez les connections externes (2e option).](https://stackoverflow.com/a/47309184). Pensez également à activer le rendu indirect de GLX:
```bash
defaults write org.macosforge.xquartz.X11 enable_iglx -bool true
```
Redémarrez votre mac afin que les modifications prennent effet.
Faites de meme avec l'outil `xhost` et lancez l'application.
```bash
open -a XQuartz
xhost + 127.0.0.1
docker run -itv $(pwd):/app/ --rm -v /tmp/.X11-unix:/tmp/.X11-unix:rw --privileged -e DISPLAY=host.docker.internal:0 bomberman sh -c "cd sdl && make all && ./bomberman res/map.txt; sh"  
```
Un <kbd>⌃ Control</kbd> <kbd>C</kbd> ne pourra pas éteindre le conteneur, vous devrez fermer la fenetre. Si vous quittez l'application xQuartz, vous devez vous re-authentifier avec la commande `xhost`. En utilisant le `xhost`, on a pas besoin de monter le socket `.x11-unix`.


### Linux (via )
[Votre `$DISPLAY` sur Linux devrait suffire](https://wiki.archlinux.org/index.php/Xorg). Ensuite :
```bash
xhost +
docker run -itv $(pwd):/app/ --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix bomberman sh -c "cd sdl && make all && ./bomberman res/map.txt; sh"   
# ou sans docker
make all; ./bomberman res/map.txt
```

## Troubleshooting
### Debug 101:
Pour debug, la manière recommandée est la suivante:
```bash
make lazyd
gdb -q -args ./bomberman res/map.txt
```
### Adress space randomization:

En cas de souci avec l'Adress space randomization, ajoutez ces options a votre docker:
```bash
--security-opt seccomp=unconfined
```
### APT Hash mismatch on macOS
Désactivez le screen time sur macOS ainsi que toutes les restrictions.

## Additional Data
**License:**
MIT