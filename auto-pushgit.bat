@ echo off
@ title bat push gitlab server

cd %~dp0
git add .
git commit -am "HP-Win10 %date:~0,4%-%date:~5,2%-%date:~8,2% Commit"
git push -u origin master
