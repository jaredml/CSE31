#include <stdio.h>

#include <stdlib.h>

#define MAXLINE 256

char *progn;

void usage(void)

{

 fprintf(stderr,"Usage: %s pattern\n",progn);

}

int pattern_match(char *pattern, char *str)

{

int pattern_count = 0;

int string_count = 0;

bool match = false;

bool temp = false;

for (string_count; match != true;) {

    if (pattern[pattern_count] == ‘\0’ || str[string_count] == ‘\0’ || str[string_count] == ‘ ‘) {

        if (pattern[pattern_count] == ‘\0’ && str[string_count] == ‘ ‘) //same size?

        {

            pattern_count = 0; //reset pattern cycle

            string_count++; //move on to next word

            if (temp == true) //if temp still = to true, meaning all chars in word match

                match == true; //at least one word matches in line

        }

       

        else if (pattern[pattern_count] == ‘\0’ && str[string_count] == ‘\0’) //end of line

        {

            //fuckyeamotherfuckersuckeggs

            if (temp == true)

                match == true;

            else

                break;

        }

        else

        {

            pattern_count = 0;

temp = false;

            while (str[string_count] != ‘ ‘ || str[string_count] != ‘\0’)

            {

                string_count++;

            }

            if (str[string_count] != ‘\0’)

                string_count++;

        }

    }


else if (pattern[pattern_count] == ‘.’ && pattern[pattern_count+1] != ‘?’) {

    pattern_count++;

string_count++;

temp = true;

}

    else if (pattern[pattern_count] == ‘.’ && pattern[pattern_count+1] == ‘?’) {

        //annoying (another function)

       

}

    else if ( ((int)pattern[pattern_count] <= 90 && (int)pattern[pattern_count] >= 30) || ((int)pattern[pattern_count] >= 97 && (int)pattern[pattern_count] <= 122) ) {

       

if (pattern[pattern_count+1] == ‘?’) {

// (another function)

}

        else

        {

            if (pattern[pattern_count] == str[string_count]) {

                pattern_count++;

string_count++;

temp = true;

}

else {

                pattern_count = 0;

                temp = false;

                while (str[string_count] != ‘ ‘ || str[string_count] != ‘\0’) {

                    string_count++;

                }

                if (str[string_count] != ‘\0’)

                    string_count++;

}

        }

    }

    else if (pattern[pattern_count] == ‘\\’) {

        if (pattern[pattern_count+1] == str[string_count]) {

            pattern_count = pattern_count + 2;

            string_count++;

        else {

            pattern_count = 0;

            temp = false;

            while (str[string_count] != ‘ ‘ || str[string_count] != ‘\0’)

            {

                string_count++;

            }

            if (str[string_count] != ‘\0’)

                string_count++;

        }

    }

}

int main(int argc, char **argv)

{

 char line[MAXLINE];

 char *pattern;

 progn = argv[0];

 

 if(argc!=2) {

   usage();

   return EXIT_FAILURE;

 }

 pattern = argv[1];

 

 while(!feof(stdin) && !ferror(stdin)) {

   if(!fgets(line,sizeof(line),stdin)) {

     break;

   }

   if(pattern_match(pattern,line)) {

     printf("%s",line);

   }

 }

 if(ferror(stdin)) {

   perror(progn);

   return EXIT_FAILURE;

 }

 return EXIT_SUCCESS;

}



