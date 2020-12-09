# Spaceships & Aliens
![](https://i.imgur.com/7isqjd1.gif)
A game where you must fight against an onslaught of alien spaceships with your very own attack spaceship.

## Dependencies
#### This game has only been tested on Arch Linux.

- [gcc] or [clang]
- [cmake]
- [Cinder]

### Arch Linux

```console
$ sudo pacman -S gcc cmake
$ git clone --recursive https://github.com/cinder/Cinder.git
$ cd Cinder
$ mkdir build && cd build
$ cmake ..
$ make -j 8
```


## Quick Start
### Linux
Clone the project in a directory named "my-projects" within the folder containing Cinder.

Ex: `/home/user/Cinder/my-projects`
#### CMake
```console
$ mkdir build
$ cd build/
$ cmake ..
$ make
$ cd Debug
$ cd shooter-app
$ ./shooter-app
```

## Controls

### Game

#### Keyboard

| Key       | Action                                                      |
|---------- |-------------------------------------------------------------|
| `W`       | Move up                                           |
| `A`       | Move left                                            |
| `S`       | Move down                                                        |
| `D`       | Move right                                          |
| `R`       | Restart game (on "Game Over" screen)                                          |

#### Mouse

| Button       | Action                 |
|--------------|------------------------|
| `Left Click` | Shoot bullet |
