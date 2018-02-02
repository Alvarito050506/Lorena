#!/bin/sh

wget https://www.github.com/paquim/Lorena/releases/download/v0.4.0/Lorena.deb && sudo dpkg --install ./Lorena.deb
sudo grub-mkconfig
sudo update-grub
sleep 5
reboot