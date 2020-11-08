#include <bits/stdc++.h>
using namespace std;
int main ()
{
 char filename[100];
 //FILE* fp;
 string str = "grep 'cpu ' /proc/stat | awk '{usage=
($2+$4)*100/($2+$4+$5)} END {print usage \"%\"}' ";
 const char *command = str.c_str();

 FILE* fp;
 char* result = NULL;
 size_t len = 0;
 fflush(NULL);
 fp = popen(command, "r");
 if (fp == NULL) {
 printf("Cannot execute command:\n%s\n", command);

 }
 while(getline(&result, &len, fp) != -1) {
 fputs(result, stdout);
 }
 int c= atoi(result);
 if(c>70)cout<<"overloaded";
 if(c<30) cout<<"underloaded";
 else cout<<"moderately loaded";
 free(result);
 fflush(fp);
 if (pclose(fp) != 0) {
 perror("Cannot close stream.\n");
 }

 return 0;
}