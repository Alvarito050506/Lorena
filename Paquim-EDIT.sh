#!/bin/sh

ed=$(zenity --text-info --title="Lorena Config EDitor" --filename="/lorena/root/config.paquim" --editable)
echo $ed > /lorena/root/config.paquim