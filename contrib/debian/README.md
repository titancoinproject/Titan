
Debian
====================
This directory contains files used to package titancoind/titancoin-qt
for Debian-based Linux systems. If you compile titancoind/titancoin-qt yourself, there are some useful files here.

## titancoin: URI support ##


titancoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install titancoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your titancoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/titancoin128.png` to `/usr/share/pixmaps`

titancoin-qt.protocol (KDE)

