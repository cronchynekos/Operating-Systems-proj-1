//Nathanael Kim 887582997

#include <iostream>
#include <string>
#include <pthread.h>
#include <bits/stdc++.h>
#include <cctype>
using namespace std;


stringstream read;
string word;
string input;
bool boolArray[2] = {0, 0};
void* numeric(void*);
void* alpha(void*);



int main(int argc, char* argv[]) {
    //error check
    if (argc < 2) {
        fprintf(stderr, "USAGE: %s <message string>\n", argv[0]);
        exit(-1);
    }

     //reading input from the terminal and storing it in input
    input = argv[1];
    read << input;
    read >> word;


    pthread_t p1, p2;  //create two threads for a total of 3 in all if you include parent
    pthread_create(&p1, NULL, alpha, NULL);
    pthread_create(&p2, NULL, numeric, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    return 0;
}



void* alpha(void* arg) {
    do {
        if (isalpha(word[0]) || ispunct(word[0]))
        {
            cout << "alpha: " << word << endl;
            boolArray[1] = true; //the next word will be read
        }

        else
        {
            boolArray[0] = true;
            boolArray[1] = false;
            if (!read) break;

            while (boolArray[0]) continue;
        }

        if (boolArray[1])
        {
            read >> word;
        }

    } while(read);

    boolArray[0] = true;
    pthread_exit(0);

}



void* numeric(void* arg) {
    do {
        if (isdigit(word[0]))
        {
            cout << "numeric: " << word << endl;
            boolArray[1] = true;

        }
        else
        {
            boolArray[0] = false;
            boolArray[1] = false;

            if(!read)
            {
                break;
            }
            while(!boolArray[0])
            {
                continue;
            }

        }
        if(boolArray[1])
        {

            read >> word;
        }
    } while(read);

    boolArray[0] = false;
    pthread_exit(0);
}
