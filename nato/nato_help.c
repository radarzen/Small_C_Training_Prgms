#include "nato.h"

void getHelp() {
    printf("Usage:  nato [OPTION] [FILE]... [MESSAGE|PATTERN]\n");
    printf("Try 'nato --help' for more information.\n");
    return;
}

void getHelpExtended() {
    printf("Usage:  nato [OPTION] [FILE]... [MESSAGE|PATTERN]\n");
    printf("Converts input text to NATO phonetics, or returns \n");
    printf("  NATO phonetics back to regular text.\n");
    printf("Example: nato -w nato.txt \"Ship sails at dawn.\"\n");
    printf("PATTERN is nato phonetics separated by any white space.\n");
    printf("  Capitalization does not matter for PATTERN recognition,\n");
    printf("  but spelling and format of special characters does:\n");
    printf("  Juliet juliet jUlIeT = JJJ\n");
    printf("  <dot> <period> 'dot' = .??\n");
    printf("  (unrecognized characters returned as '?')\n\n");

    printf("MESSAGE Conversion:\n");
    printf("  -w [FILE]... [MESSAGE]   Writes new file to FILE. Uses 'nato.txt' if not\n");
    printf("                           specified. Will prompt for message if not provided.\n");
    printf("  -a [FILE]... [MESSAGE]   Appends file.  Uses nato.txt if not specified.\n");
    printf("                           prompt for message if not provided.\n");
    printf("  -rN (FILE)               Read FILE for converting to NATO phonetics.\n");
    printf("  [MESSAGE]                No switch, just a message argument to convert\n");
    printf("                           message and dump to screen.  MESSAGE may also be\n");
    printf("                           piped in.\n");
    printf("NOTE: massages may be piped in with switch and file operators as well.\n");
    printf("Example: echo \"SR71 Blackbird\" | nato -a coolplanes.txt\n\n");

    printf("PATTERN Conversion:\n");
    printf("  -rF [FILE]               Read file for converting from NATO to a message.\n");
    printf("                           If no FILE given, nato.txt in current dir assumed.\n");
    printf("  -c [PATTERN]             Convert PATTERN to message. Will prompt for\n");
    printf("                           PATTERN if one not provided.\n");
    printf("NOTE: patterns may be piped in with -c switch.\n");
    printf("Example: echo \"Papa Alpha Sierra Sierra\" | nato -c\n\n");

    printf("Multiple files may be itterated for MESSAGE conversion. Program assumes\n");
    printf("that MESSAGE conversion is intended unless specifically called for\n"); 
    printf("by PATTERN conversion options.\n\n");

    printf("Recognized NATO phonetics:\n");
    printf("Letters:\n");
    printf("Alpha, Bravo, Charlie, Delta, Echo, Foxtrot, Golf, Hotel, India, Juliette,\n");
    printf("Kilo, Lima, Mike, November, Oscar, Papa, Quebec, Romeo, Sierra, Tango,\n"); 
    printf("Uniform, Victor, Whiskey, Xray, Yankee, Zulu\n\n");

    printf("Special Characters/Numbers:\n");
    printf("<space>, <exclemation>, <d-quote>, <num>, <dollar>, <percent>,\n");
    printf("<ampersand>, <s-quote>, <o-parenthesis>, <c-parenthesis>, <asterisk>,\n");
    printf("<plus>, <comma>, <hyphen>, <dot>, <slash>, Zero, One, Two, Tree,\n");
    printf("Fower, Fife, Six, Seven, Eight, Niner, <colon>, <semi-colon>,\n");
    printf("<o-angle-brkt>, <equals>, <c-angle-brkt>, <question>, <at-sign>\n");
    printf("<o-brkt>, <backslash>, <c-brkt>, <caret>, <underscore>, <back-tic>\n");
    printf("<o-brace>, <v-bar>, <c-brace>, <tilde>\n");

    return;
}