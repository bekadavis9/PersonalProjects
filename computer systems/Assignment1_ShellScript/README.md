# Automating something in your life

Let's get used to the terminal and the shell by writing a 1-2 page tutorial using unix commands and the bash scripting language. The tutorial will be embedded in a shell script comments, explaining how to do something on the terminal that is non-trivial and automates some task that is particularly useful to you. 

### How to run your script

You will run your script by typing `sh myScript.sh` on the command line as an executable shell script(sh is the GNU Bourne-Again SHell (type [man sh](https://linux.die.net/man/1/sh) on the terminal for more information).  You can look at example 'sh' scripts for inspiration on what you can achieve on the web, but you must cite them appropriately in your [README.md](./../README.md). 

### How to write your tutorial

The tutorial will be done purely in text and and within a file called [myScript.sh](./myScript.sh). You are required to type your tutorial using a terminal based text editor like 'vim', 'emacs', or 'nano' to write your tutorial (I personally use the vim text editor in my class).

Examples of a non-trivial scripts:

1. Download some data (e.g. housing prices) from the web using a program like curl or wget. It may be convenient if you can download the data in a .csv format. Sort the values in the data (perhaps a particular column in a spreadsheet), then print out the top ten values, and finally the average of that column of data.
	* You could download some sample .csv data from: [https://support.spatialkey.com/spatialkey-sample-csv-data/](https://support.spatialkey.com/spatialkey-sample-csv-data/)
	* Handy commands may include (but are not limited to): cut, wget, curl, echo, sort, and a little bit of bash scripting.
2. Write a shell script that downloads a weather webpage, and then parses it to determine what the weather is today. The script could then report what type of jacket you should wear and send you an e-mail.
	* Some handy commands may include (but are not limited to): mailx, awk, sed
3. Write a shell script that allows you to query information about your computer system from a menu of options. Users might like to know information like hard drive space, if a graphics card is available, how fast the cpu is, etc.
	* Some handy commands may include (but are not limited to): proc, lscpu
4. You can use your imagination to create other tutorials as well.


## Very Brief Example Tutorial
A very trivial example to go off of in your script. 

```
# Problem Statement: "Often I have to search for different files and directories within my computer system. 
#                     In order to do this I use the 'ls' command to help orient myself.
# Name of command: ls
# 
# Example of its usage: 
# -bash-4.2$ ls
# Lab1  README.md

# Here is the myScript.sh script that can list the directories and how many total directories are in the current folder.
# usage: sh myScript.sh

ls
ls | wc -l
```


