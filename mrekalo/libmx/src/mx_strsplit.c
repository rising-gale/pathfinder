#include "libmx.h"

char **mx_strsplit(char const *s, char c);
char **mx_strsplit(char const *s, char c){
    if(s==NULL) return NULL;
    int cw = mx_count_words(s,c);
    int i=0, k=0;
    char **res = (char**)malloc(16 * cw);
    int letters = 0;
    int start =0;
    while(s[i]!='\0'){
        
        if(s[i]!=c){
            
            letters++;
            if(s[i+1]=='\0' && letters > 0){
            char *word = mx_strnew(letters);
            int f=0;
            for (int j=start;j<letters+start;j++)
            {
                word[f]=s[j];
                f++;
            }
            start = 0;
            res[k] = word;
            k++;
            letters = 0;
        }
            if(start==0) start = i;
        } 
        else if(s[i]==c){
            if(letters > 0){
            char *word = mx_strnew(letters);
            int f=0;
            for (int j=start;j<letters+start;j++)
            {
                word[f]=s[j];
                f++;
            }
            start = 0;
            res[k] = word;
            k++;
            letters = 0;
        }
        } 
        i++;
    }
    res[k]=NULL;
    return res;
}
