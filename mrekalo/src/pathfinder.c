#include "pathfinder.h"
int main(int argc, char *argv[]){
    if(argc != 2){
        mx_printerr("usage: ./pathfinder [file_name]\n");
        exit(0);
    }
    // for (int i = 0; i < argc; i++){
    //     mx_printstr(argv[i]);
    //     mx_printstr("\n");
    // }
        
    int file = open(argv[1], O_RDWR);
    if (file < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(0);
    }
    char buffer;
    int count_strings = 0;
    int count_symbols = 0;
    while(read(file, &buffer, 1)){
        // mx_printchar(buffer);
        if(buffer != '\n'){
            count_symbols++;
        }
        if(buffer == '\n')
            count_strings++;
    }
    // mx_printint(count_strings);
    // mx_printint(count_of_islands);
    if(count_strings == 0 || count_symbols == 0){
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);        
    }
    // printf("%s",mx_file_to_str(argv[1]));
    char *file_str = mx_file_to_str(argv[1]);
    // int file_str_len = mx_strlen(file_str);
    // printf("%s",file_str);
    // if(file_str[file_str_len] != '\n'){
        
    //     file_str[file_str_len] = '\n';
    //     file_str[file_str_len + 1] = '\0';
    // }
    // printf("%s",file_str);
    // int e = 0;
    // while(file_str[e] != '\0'){
    // if(file_str[e] != '\n'){
    //     count_symbols++;
    // }
    // if(file_str[e] == '\n')
    //     count_strings++;
    // e++;
    // }    
    // printf("%s",file_str);
    char **str = mx_strsplit(file_str,'\n');
    int count_of_islands = 0;
    // for (int i = 0; str[i]!=NULL; i++)
    // {
    //     printf("%s",str[i]);
    // }
    
    for (int i = 0; str[0][i]!='\0'; i++)
    {
        if((!mx_isdigit(str[0][i]) && (str[0][i]!='\n')) || (mx_atoi(str[0]) < 0)){
            mx_printerr("error: line 1 is not valid\n");
            exit(0);                
        }
    }
    count_of_islands = mx_atoi(str[0]);
    // mx_printint(count_of_islands);

    // CREATING MATRIX SMEZHNOSTI
    int **mat_sm = (int **)malloc(count_of_islands * sizeof(int *));
    for (int i = 0; i < count_of_islands; i++)
    {
        mat_sm[i] = (int*)malloc(count_of_islands * sizeof(int));
    }
    for(int i = 0; i < count_of_islands; i++ )
        for(int j = 0; j < count_of_islands; j++)
            mat_sm[i][j] = 0;
    // ------------------------------------------------------------------
    
    
    // char *ptr = str[1];
    // mx_printstr(ptr);
    // PARSING NAMES AND LENGTHS OF ISLAND AND BRIDGES
    char **island_names = (char **)malloc(sizeof(char *) * count_strings * 3);
    int i_nm_counter = 0;
    for (int i = 1; i < count_strings; i++)
    {
        int k = 0;
        // printf("%s",str[i]);
        // mx_printstr(str[i]);
        char *ptr = str[i];
        int flag = 0;            
        int cntr1 = 0;
        int cntr2 = 0;
        int cntr3 = 1;
        if(ptr == NULL){
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i+1));
            mx_printerr(" is invalid\n");
            exit(0); 
        }
        while(ptr[k]!='\0'){
            // mx_printint(k);
            // mx_printchar(ptr[k]);
            if(mx_isdigit(ptr[k]) && flag!=2){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i+1));
                mx_printerr(" is invalid\n");
                exit(0); 
            }
            if(!mx_isalpha(ptr[k]) && ptr[k]!='-' && ptr[k]!='\n' && flag <= 1 && ptr[k]!=','){
                
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i+1));
                mx_printerr(" is invalid\n");
                exit(0);                 
            }
            if(flag == 0 && ptr[k]!='-'){
                cntr1++;
            }
            else if(ptr[k]=='-' && flag == 0){
                if(ptr[k+1] == '-'){
                    mx_printerr("error: line ");
                    mx_printerr(mx_itoa(i+1));
                    mx_printerr(" is invalid\n");
                    exit(0);                     
                }
                flag = 1;
            } else if(flag == 1 && ptr[k]!=','){
                cntr2++;
            } else if(flag == 1 && ptr[k]==','){
                if(ptr[k+1] == ','){
                    mx_printerr("error: line ");
                    mx_printerr(mx_itoa(i+1));
                    mx_printerr(" is invalid\n");
                    exit(0);                     
                }
                flag = 2;
            } else if(flag == 2 && ptr[k+1]!='\0'){
                cntr3++;
            } else if(flag == 2 && ptr[k+1]=='\0'){
                flag = 3;
            }
            k++;
        }
        if(flag == 3){
            char *s1 = mx_strnew(cntr1);
            char *s2 = mx_strnew(cntr2);
            char *s3 = mx_strnew(cntr3);
            mx_strncpy(s1,str[i],cntr1);
            mx_strncpy(s2,str[i]+cntr1+1,cntr2);
            mx_strncpy(s3,str[i]+cntr1+cntr2+2,cntr3);
            int iterator = 0;
            // mx_printstr(s1);
            // mx_printchar('\n');
            // mx_printstr(s2);
            // mx_printchar('\n');
            // mx_printstr(s3);
            // mx_printchar('\n');
            while(s1[iterator] != '\0'){
                if(!mx_isalpha(s1[iterator])){
                    mx_printerr("error: line ");
                    mx_printerr(mx_itoa(i+1));
                    mx_printerr(" is invalid\n");
                    exit(0);                     
                }
                iterator++;
            }
            iterator = 0;
            while(s2[iterator] != '\0'){
                if(!mx_isalpha(s2[iterator])){
                    mx_printerr("error: line ");
                    mx_printerr(mx_itoa(i+1));
                    mx_printerr(" is invalid\n");
                    exit(0);                     
                }
                iterator++;
            }
            if(mx_atoi(s3) <= 0){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i+1));
                mx_printerr(" is invalid\n");
                exit(0);                  
            }
            if(mx_strcmp(s1,s2) == 0){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i+1));
                mx_printerr(" is invalid\n");
                exit(0);   
            }
            
            island_names[i_nm_counter] = s1;
            i_nm_counter++;
            island_names[i_nm_counter] = s2;
            i_nm_counter++;
            island_names[i_nm_counter] = s3;
            i_nm_counter++;
        }
    }
    // ------------------------------------------------------------------


    // // CREATING AND INITIALIZING MASSIVE OF ISLANDS AND INITIALIZING MATRIX SMEZHNOSTI
    island *islands = (island *)malloc(sizeof(island) * count_strings);
    int i_counter = 0;
    long sum_all_bridges = 0;
    // mx_printint(i_nm_counter);
    for (int i = 0; i < i_nm_counter; i+=3)
    {
        // mx_printint(i);
        if(i_counter > count_of_islands){
            mx_printerr("error: invalid number of islands\n");
            exit(0);          
        } 
        bool exist = false;
        int isl_1 = -1;
        int isl_2 = -1;
        for (int j = 0; j < i_counter; j++)
        {          
            if(mx_strcmp(island_names[i],islands[j].name)==0){

                exist = true;
                isl_1 = j;
            }
        }
        if(exist == false){
            islands[i_counter].name = island_names[i];
            islands[i_counter].L = -1;
            islands[i_counter].Q = -1;
            islands[i_counter].checked = false;
            isl_1 = i_counter;
            i_counter++;
            if(i_counter > count_of_islands){
                mx_printerr("error: invalid number of islands\n");
                exit(0);          
            }
        }
        exist = false;
        for (int j = 0; j < i_counter; j++)
        {        
            if(mx_strcmp(island_names[i+1],islands[j].name)==0){

                exist = true;
                isl_2 = j;
            }
                
        }
        if(exist == false){
            islands[i_counter].name = island_names[i+1];
            islands[i_counter].L = -1;
            islands[i_counter].Q = -1;
            islands[i_counter].checked = false;
            isl_2 = i_counter;
            i_counter++;
            if(i_counter > count_of_islands){
                mx_printerr("error: invalid number of islands\n");
                exit(0);          
            }
        }
        if(isl_1 < 0 || isl_2 < 0)
            continue;
        if(mat_sm[isl_1][isl_2] > 0 || mat_sm[isl_2][isl_1] > 0){
            mx_printerr("error: duplicate bridges\n");
            exit(0);  
        } 
        sum_all_bridges = sum_all_bridges + mx_atoi(island_names[i+2]);
        if(mx_atoi(island_names[i+2]) >= INT_MAX){
            mx_printerr("error: sum of all bridges lengths is too big\n");
            exit(0);      
        }
        mat_sm[isl_1][isl_2] = mx_atoi(island_names[i+2]);
        mat_sm[isl_2][isl_1] = mx_atoi(island_names[i+2]);
    }
    // ------------------------------------------------------------------

    if(sum_all_bridges >= (long)INT_MAX){
        mx_printerr("error: sum of all bridges lengths is too big\n");
        exit(0);        
    }
    // mx_printint(i_counter);
    // mx_printchar('=');
    // mx_printint(count_of_islands);
    if(i_counter != count_of_islands){
        mx_printerr("error: invalid number of islands\n");
        exit(0);          
    }

    // for (int i = 0; i < i_counter; i++)
    // {
    //     printf("%s", islands[i].name);
    //     printf("%c",'\n');
    // }
    
    // for(int i = 0; i < count_of_islands; i++ ){
    //     for(int j = 0; j < count_of_islands; j++){
    //         printf("%d",mat_sm[i][j]);
    //         printf("%c",' ');
    //     }
    //     printf("%c",'\n');        
    // }

    // // USING DIJCSTRA ALG TRYING TO FIND ALL WHE WAYS WE NEED :D
    for (int m = 0; m < count_of_islands; m++)
    {
        int other_way_l = -1;
        bool otherway = false;
        int * repeated_massive = malloc(sizeof(int) * count_of_islands);
        for (int f = 0; f < count_of_islands; f++)
        {
            repeated_massive[f] = -1;
        }
        int iterator_rm = 0;
        int n_holder = -1;
        for (int n = m+1; n < count_of_islands; n++)
        {
        
            for (int i = 0; i < count_of_islands; i++)
            {
                if(n != n_holder)
                    for (int f = 0; f < count_of_islands; f++)
                    {
                        repeated_massive[f] = -1;
                    }
                for (int f = 0; f < count_of_islands; f++)
                {
                    if(repeated_massive[f] == i && repeated_massive[f] > 0){
                        islands[i].checked = true;
                    } else
                        islands[i].checked = false;   
                }
                    islands[i].Q = -1;
                    islands[i].L = -1;                
            }
            n_holder = n;
            int l = m;
            int minID = l;
            islands[l].L = 0;
            islands[l].checked = true;
            l = m;            
            otherway = false;            
            other_way_l = -1;
            while(l < count_of_islands - 1){
 
                for (int j = 0; j < count_of_islands; j++)
                {                            
                
                    if(mat_sm[l][j] > 0 && islands[j].checked == false && (islands[j].L <= 0 || islands[j].L >= islands[l].L + mat_sm[l][j])){

                        if(islands[j].L == islands[l].L + mat_sm[l][j] && j <= n){
                            // printf("%d",islands[l].L);
                            // printf("%s"," ");
                            bool was_used = false;
                            for (int f = 0; f < count_of_islands; f++)
                            {
                                if(l == repeated_massive[f]){
                                    was_used = true;
                                    break;
                                }
                            } 
                            if(was_used){
                                // printf("%s","was used");
                                continue;
                            }
                        //     printf("%d",islands[l].Q);
                        //     printf("%s"," ");
                        //     printf("%s",islands[l].name);
                        //     printf("%s"," ");
                        //     printf("%d",islands[l].checked);
                        //     printf("%s","   ");                            
                        //     printf("%d",islands[j].L);
                        //     printf("%s"," ");
                        //     printf("%d",islands[j].Q);
                        //     printf("%s"," ");
                        //     printf("%s",islands[j].name);
                        //     printf("%s"," ");
                        //     printf("%d",islands[j].checked);
                        //     printf("%c",'\n');
                        //     printf("%d",l);
                        //     printf("%c",'\n'); 
                        //     printf("%d",islands[j].L);
                        //     printf("%s"," ");
                        //     printf("%d",islands[l].L);
                        //     printf("%s"," + ");
                        //     printf("%d",mat_sm[l][j]);
                        //     printf("%c",'\n');


                            other_way_l = l;                            
                            otherway = true;                                
                        }
                                islands[j].L = islands[l].L + mat_sm[l][j];
                                islands[j].Q = l;                                   
                    }
                }
                
                int minL, minL_id;
                for (int k = 0; k < count_of_islands; k++)
                {
                    bool was_used = false;
                    for (int f = 0; f < count_of_islands; f++)
                    {
                        if(k == repeated_massive[f]){
                            was_used = true;
                            break;
                        }
                    } 
                    if(islands[k].L > 0 && islands[k].checked == false && !was_used){
                        minL = islands[k].L;
                        minL_id = k;
                        break;
                    }
                }
                for (int k = 0; k < count_of_islands; k++)
                {
                    bool was_used = false;
                    for (int f = 0; f < count_of_islands; f++)
                    {
                        if(k == repeated_massive[f]){
                            was_used = true;
                            break;
                        }
                    } 
                    if(islands[k].L > 0 && islands[k].L < minL && islands[k].checked == false && !was_used){
                        minL = islands[k].L;
                        minL_id = k;
                    }
                }

                if(islands[minL_id].checked == false){
                    minID = minL_id;
                    islands[minL_id].checked = true;                    
                }

                if(l == minID){
                    break;
                }   
                l = minID;      
            }

        // WAY INITIALIZING
    
        l = n;
        if(islands[l].Q < 0){
            continue;        
        }
        int exit_counter = islands[l].L;
        int *way = (int *)malloc(sizeof(int)*count_of_islands);
        int j = 0;
        way[j] = n;
        j++;
        while(l != m){
            way[j] = islands[l].Q;
            l = islands[l].Q;
            j++;
        }

        // WAY PRINTING 
        bool printed_l = false;
        for (int g = 0; g < 40; g++)
        {
            mx_printchar('=');
        }
        mx_printchar('\n');
        mx_printstr("Path: ");
        mx_printstr(islands[way[j-1]].name);
        mx_printstr(" -> ");
        mx_printstr(islands[way[0]].name);
        mx_printchar('\n');
        mx_printstr("Route: ");
        for (int g = j-1; g >= 0; g--)
        {
            mx_printstr(islands[way[g]].name);
            if(g != 0)
                mx_printstr(" -> ");
                
            if(way[g] == other_way_l)
                printed_l = true;
        }
        mx_printchar('\n');
        mx_printstr("Distance: ");
        bool eq_symb_needed = false;
        for (int g = j-2; g >= 0; g--)
        {
            
            if(g < j-2){
                mx_printint(islands[way[g]].L - islands[way[g+1]].L);
                eq_symb_needed = true;
            } 
            else if (islands[way[g]].L != exit_counter)
                mx_printint(islands[way[g]].L);
            if(g != 0)
                mx_printstr(" + ");
        }
        if(eq_symb_needed)
        mx_printstr(" = ");
        mx_printint(exit_counter);
        mx_printchar('\n');
        for (int g = 0; g < 40; g++)
        {
            mx_printchar('=');
        }
        mx_printchar('\n');
        if(otherway && printed_l){
            // for (int f = 0; f < count_of_islands; f++)
            // {
            //     printf("%d",repeated_massive[f]);
            // }
            // printf("%d",other_way_l);
            repeated_massive[iterator_rm] = other_way_l;
            iterator_rm++;
        // if(otherway){
            n--;
        } 
        // free(repeated_massive);
    }
    }
}

