nato program:  I want to combine all I've learned so far and make the nato program include both encoding (to NATO phonetic alphabetic terms)
and decoding (converting NATO phonetic terms back to english/origional text).  I want to be able to write, append, and read files.  I want to 
be able to do as much from the command-line as possible (not have to open and then select options).  The following is what I'm thinking so far:

$ nato <br>
 -opens program, provides a brief use description, and then asks for a message to convert to NATO phonetics <br>
$ nato -w [FILE.txt] <br>
 -opens protram, asks for input that writes to new file.  If no filename given in argument, write to default "nato.txt" in users current directory <br>
$ nato -a [FILE.txt] <br>
 -same as '-w', but appends file instead of write new.  If file doesn't exists, start a new one. <br>
$ nato -rN (FILE.txt) <br>
 -read file for converting to NATO.  Fail if no file given. <br>
$ nato -rF [FILE.txt] <br>
 -read file for converting From NATO.  Use "nato.txt" if no file specified.  if fail, request text input from user. <br>
$ nato "message" <br>
 -convert "message" to NATO phonetics and dump to screen. <br>
$ nato "message" -[w|a] [FILE.txt] <br>
 -convert "message" and dump to file specified (or nato.txt if none given) and exit program. <br>
$ nato -c "NATO PHONETICS" <br>
 -convert from NATO phonetics and dump to screen <br>
$ nato -h [--help] <br>
 -print helpful message of basic useage, manpage format'ish <br>
 
