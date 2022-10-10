//Nathanael Kim 887582997

#include <bits/stdc++.h>
using namespace std;
vector<int>fib;

int i;
void *runn(void *arg)
{
    if(i==0) //fib[0] and fib[1] are already preset
    {
        fib[i]=0;
        pthread_exit(0);
    }
    else if(i==1)
    {
        fib[i]=1;
        pthread_exit(0);
    }
    else  //every number after 1 follows this formula
    {
        fib[i] = fib[i-1]+fib[i-2];
        pthread_exit(0);
    }
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1])+1;

    if(n<=0)//if the input number is less than 0, the programs gives and error and exits
    {

        cout<<"Input number should be > 0\n";
        return -1;

    }
    fib.resize(n);
    pthread_t *threads = (pthread_t *) malloc(n * sizeof(pthread_t));

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for(i = 0;i < n;i++)
    {

        pthread_create(&threads[i], &attr, runn, NULL);
        pthread_join(threads[i], NULL);

    }

    for(int j=0; j<n; j++)
    {
        cout << fib[j] <<' '; //print sequence

    }
    cout << endl;
    return 0;
}