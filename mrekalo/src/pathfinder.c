#include "pathfinder.h"

bool mx_is_equal_mas(int *mas1, int *mas2, int len){
    bool isEqual = true;
    for (int i = 0; i < len; i++)
    {
        if(mas1[i] < 0 && mas2[i] < 0){
            break;
        }
        if(mas1[i] < 0 && mas2[i] >= 0){
            isEqual = false;
            break;
        }
            
        if(mas2[i] < 0 && mas1[i] >= 0){
            isEqual = false;
            break;
        }
            
        if(mas1[i] != mas2[i]){
            isEqual = false;
            break;
        }
            
    }
    return isEqual;
}
bool mx_combinations(int size, int *mas){
    bool perenos = false;
    bool isDone = true;
    for (int i = 0; i < size; i++)
    {
        if(mas[i] != 1){
            isDone = false;
            break;
        }
            
    }
    if(isDone){
        return isDone;
    }
    for (int i = 0; i < size; i++)
    {
        if(mas[i] == 0 && perenos == false){
            mas[i] = 1;
            break;
        }
        if(mas[i] == 0 && perenos == true){
            mas[i] = 1;
            perenos = false;
            break;
        }
        if(mas[i] == 1 && perenos == true){
            mas[i] = 0;
            perenos = true;
        }
        if(mas[i] == 1 && perenos == false){
            mas[i] = 0;
            perenos = true;
        }
    }
    return isDone;
}

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
    // printf("%s",str[0]);
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
            mx_printerr(" is not valid\n");
            exit(0); 
        }
        while(ptr[k]!='\0'){
            // mx_printint(k);
            // mx_printchar(ptr[k]);
            if(mx_isdigit(ptr[k]) && flag!=2){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i+1));
                mx_printerr(" is not valid\n");
                exit(0); 
            }
            if(!mx_isalpha(ptr[k]) && ptr[k]!='-' && ptr[k]!='\n' && flag <= 1 && ptr[k]!=','){
                
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i+1));
                mx_printerr(" is not valid\n");
                exit(0);                 
            }
            if(flag == 0 && ptr[k]!='-'){
                cntr1++;
            }
            else if(ptr[k]=='-' && flag == 0){
                if(ptr[k+1] == '-'){
                    mx_printerr("error: line ");
                    mx_printerr(mx_itoa(i+1));
                    mx_printerr(" is not valid\n");
                    exit(0);                     
                }
                flag = 1;
            } else if(flag == 1 && ptr[k]!=','){
                cntr2++;
            } else if(flag == 1 && ptr[k]==','){
                if(ptr[k+1] == ','){
                    mx_printerr("error: line ");
                    mx_printerr(mx_itoa(i+1));
                    mx_printerr(" is not valid\n");
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
            int counter_for_checks = 0;
            while(s1[iterator] != '\0'){
                counter_for_checks++;
                if(!mx_isalpha(s1[iterator])){
                    mx_printerr("error: line ");
                    mx_printerr(mx_itoa(i+1));
                    mx_printerr(" is not valid\n");
                    exit(0);                     
                }
                iterator++;
            }
            iterator = 0;
            if(counter_for_checks == 0){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i+1));
                mx_printerr(" is not valid\n");
                exit(0);                  
            }            
            while(s2[iterator] != '\0'){
                counter_for_checks++;
                if(!mx_isalpha(s2[iterator])){
                    
                    mx_printerr("error: line ");
                    mx_printerr(mx_itoa(i+1));
                    mx_printerr(" is not valid\n");
                    exit(0);                     
                }
                iterator++;
            }
            if(counter_for_checks == 0){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i+1));
                mx_printerr(" is not valid\n");
                exit(0);                  
            }
            counter_for_checks = 0;
            if(mx_atoi(s3) <= 0){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i+1));
                mx_printerr(" is not valid\n");
                exit(0);                  
            }
            if(mx_strcmp(s1,s2) == 0){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i+1));
                mx_printerr(" is not valid\n");
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
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(0);      
        }
        mat_sm[isl_1][isl_2] = mx_atoi(island_names[i+2]);
        mat_sm[isl_2][isl_1] = mx_atoi(island_names[i+2]);
    }
    // ------------------------------------------------------------------

    if(sum_all_bridges >= (long)INT_MAX){
        mx_printerr("error: sum of bridges lengths is too big\n");
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
    // printf("%c",'\n');
    int ** D = (int **)malloc(count_of_islands * sizeof(int *));
    int ** S = (int **)malloc(count_of_islands * sizeof(int *));
    for(int i = 0; i < count_of_islands; i++ ){
        D[i] = (int*)malloc(count_of_islands * sizeof(int));
        S[i] = (int*)malloc(count_of_islands * sizeof(int));
    }
    for(int i = 0; i < count_of_islands; i++ ){
        for(int j = 0; j < count_of_islands; j++){
            D[i][j]= mat_sm[i][j];
            if(mat_sm[i][j] > 0){
                S[i][j] = j;             
            } else {
                S[i][j] = -1;              
            }

        }
    }
    // printf("%c",'\n');
    // for(int i = 0; i < count_of_islands; i++ ){
    //     for(int j = 0; j < count_of_islands; j++){
    //         printf("%d",D[i][j]);
    //         printf("%c",' ');
    //     }
    //     printf("%c",'\n');        
    // }
    // printf("%c",'\n');
    // for(int i = 0; i < count_of_islands; i++ ){
    //     for(int j = 0; j < count_of_islands; j++){
    //         printf("%d",S[i][j]);
    //         printf("%c",' ');
    //     }
    //     printf("%c",'\n');        
    // }
    // printf("%c",'\n');
    int *mas_i = (int*)malloc(count_strings * sizeof(int) * 10);
    int *mas_j = (int*)malloc(count_strings * sizeof(int) * 10); 
    int *mas_k = (int*)malloc(count_strings * sizeof(int) * 10);
    for (int i = 0; i < count_strings * 10; i++)
    {
        mas_i[i] = -1;
        mas_j[i] = -1;
        mas_k[i] = -1;
    }
    int size_of_massives = 0;
    // combinations(5);


    for (int k = 0; k < count_of_islands; k++)
    {
        // printf("%c",'\n'); 
        // for(int i = 0; i < count_of_islands; i++ ){
        //     for(int j = 0; j < count_of_islands; j++){
        //         printf("%d",D[i][j]);
        //         printf("%c",' ');
        //     }
        //     printf("%c",'\n');        
        // }
        // printf("%c",'\n'); 
        // for(int i = 0; i < count_of_islands; i++ ){
        //     for(int j = 0; j < count_of_islands; j++){
        //         printf("%d",S[i][j]);
        //         printf("%c",' ');
        //     }
        //     printf("%c",'\n');        
        // }
        
        for (int i = 0; i< count_of_islands; i++)
        {
            for (int j = 0; j < count_of_islands; j++)
            {
                if((D[i][k]+ D[k][j] <= D[i][j] || D[i][j] == 0) && (D[i][k] >0 && D[k][j] > 0) && (i!=k && j!=k && i!=j)){
                    if(D[i][k]+ D[k][j] == D[i][j]){
                        // printf("%d",i);
                        // printf("%c",' ');
                        // printf("%d",j);
                        // printf("%c",' ');
                        // printf("%d",k);
                        // printf("%c",'|');
                        // printf("%d",S[i][j]);
                        // printf("%s","|");
                        // printf("%d",k);
                        // printf("%s","|| ");
                        bool isExist = false;
                        for (int e = 0; e < size_of_massives ; e++){
                            if(mas_j[e] == i && mas_i[e] == j && mas_k[e] == k){
                                isExist = true;
                            }
                        }
                        if(!isExist){
                            mas_i[size_of_massives] = i;
                            mas_j[size_of_massives] = j;
                            mas_k[size_of_massives] = k;
                            size_of_massives++;                             
                        }

                              
                        continue;
                    }
                    S[i][j] = k;
                    for (int e = 0; e < size_of_massives ; e++){
                        if(mas_i[e] == i && mas_j[e] == j){
                            // printf("%s","here");
                            mas_k[e] = k;
                        }
                    }
                        // printf("%d",i);
                        // printf("%c",' ');
                        // printf("%d",j);
                        // printf("%c",' ');
                        // printf("%d",k);
                        // printf("%s","|| ");
                    D[i][j] =  D[i][k]+ D[k][j];

                }
            }
            
            
        }
        // printf("%c",'\n');
    }
    // for (int i = 0; i < count_strings * 10; i++)
    // {
    //     if(mas_i[i] >= 0){
    //         printf("%d",mas_i[i]);
    //         printf("%c",' ');            
    // }

    // }
    // printf("%c",'\n');
    // for (int i = 0; i < count_strings * 10; i++)
    // {
    //     if(mas_j[i] >= 0){
    //         printf("%d",mas_j[i]);
    //         printf("%c",' ');            
    //     }
    // }
    // printf("%c",'\n');
    // for (int i = 0; i < size_of_massives; i++)
    // {
    //     if(mas_k[i] >= 0){
    //         printf("%d",mas_k[i]);
    //         printf("%c",' ');            
    //     }
    // }    
    // printf("%c",'\n'); 
    // for(int i = 0; i < count_of_islands; i++ ){
    //     for(int j = 0; j < count_of_islands; j++){
    //         printf("%d",mat_sm[i][j]);
    //         printf("%c",' ');
    //     }
    //     printf("%c",'\n');        
    // }    
    // printf("%c",'\n');
    // for(int i = 0; i < count_of_islands; i++ ){
    //     for(int j = 0; j < count_of_islands; j++){
    //         printf("%d",D[i][j]);
    //         printf("%c",' ');
    //     }
    //     printf("%c",'\n');        
    // }
    // printf("%c",'\n');
    // for(int i = 0; i < count_of_islands; i++ ){
    //     for(int j = 0; j < count_of_islands; j++){
    //         printf("%d",S[i][j]);
    //         printf("%c",' ');
    //     }
    //     printf("%c",'\n');        
    // }
    // printf("%c",'\n');
    int **ways = (int **)malloc(count_strings * 100 * sizeof(int *));
    int *lengthes = malloc(count_strings * 100 * sizeof(int *));
    for (int i = 0; i < count_strings * 100; i++)
    {
        lengthes[i] = 0;
    }
    
    int ways_counter = 0;
    int ** S_copy = (int **)malloc(count_of_islands * sizeof(int *));
    for(int i = 0; i < count_of_islands; i++ ){
        S_copy[i] = (int*)malloc(count_of_islands * sizeof(int));
    }
    for(int i = 0; i < count_of_islands; i++ ){
        for(int j = 0; j < count_of_islands; j++ ){
            S_copy[i][j] = S[i][j];
        }
    }
// printf("%c",'\n');
// printf("%c",'\n');
// printf("%d",size_of_massives);
// printf("%c",'\n');
// printf("%c",'\n');
// printf("%d",sizeof(int) * size_of_massives);
bool isDone = false;
bool flag = false;
int *mask_n = malloc(sizeof(int) * size_of_massives);
for (int i = 0; i < size_of_massives; i++){
    mask_n[i] = 0;
}
//BUILDING WAYS -----------------------------------------
while(isDone == false){
        // printf("%c",'\n');
        if(flag == true){
             for(int i = 0; i < count_of_islands; i++ ){
                for(int j = 0; j < count_of_islands; j++ ){
                    S_copy[i][j] = S[i][j];
                }
            }   
            isDone = mx_combinations(size_of_massives,mask_n);
            if(isDone){
                break;
            }
            // for (int i = 0; i < size_of_massives; i++){
            //     printf("%d",mask_n[i]);
            //     printf("%c",' ');
            // }
            // printf("%c",'\n');
            for (int i = 0; i < size_of_massives; i++)
            {    
                if(mas_i[i] < 0 || mas_j[i] < 0 || mas_k[i] < 0){
                    break;
                }
                if(mask_n[i] > 0){
                    S_copy[mas_i[i]][mas_j[i]] = mas_k[i];
                    S_copy[mas_j[i]][mas_i[i]] = mas_k[i];
                }
            }
            // free(mask_n);
        }
        if(flag == false){
            flag = true;
        }
        // for(int i = 0; i < count_of_islands; i++ ){
        // for(int j = 0; j < count_of_islands; j++){
        //     S_copy[i][j] = S[i][j];
        // }
        // }
        // if(iterator >= 0 ){

        // }
        
        // printf("%c",'\n');        
        // }
        // printf("%c",'\n');
        for(int n = 0; n < count_of_islands; n++ ){
        for(int m = n+1; m < count_of_islands; m++){
            int end = m;
            int i = n;
            int j;
            int *way = malloc(count_of_islands * sizeof(int *));
            for (int i = 0; i < count_of_islands; i++)
            {
                way[i] = -1;
            }
            
            int way_iter = 1;
            int length = 1;
            way[0] = n;
            // printf("%d",i);
            // printf("%c",' ');
            if(S_copy[i][end]!=end && S_copy[i][end]!=-1){
                while(S_copy[i][end]!=end){
                    j = S_copy[i][end];
                    while(S_copy[i][j]!=j){          
                        j = S_copy[i][j];
                    }
                    // printf("%d",D[i][j]);
                    // printf("%c",' ');            
                    // printf("%d",j);
                    // printf("%c",' ');
                    
                    length++;
                    way[way_iter] = j;
                    way_iter++;
                    i = j;
                }
            }
            way[way_iter] = end;
            way_iter++;
            length++;
            bool isExist = false;
            for (int l = 0; l < ways_counter; l++)
            {
                if(mx_is_equal_mas(ways[l],way,count_of_islands))
                    isExist = true;
            }
            if(!isExist){
                ways[ways_counter] = way;            
                lengthes[ways_counter] = length;
                ways_counter++;
            } else {
                free(way);
            }

            // printf("%d",D[i][end]);
            // printf("%c",' ');
            // printf("%d",end);
            // printf("%c",'\n');    
        }
        // printf("%c",'\n');
    }
    // if(mas_i[iterator] < 0 || mas_j[iterator] < 0 || mas_k[iterator] < 0){
    //     break;
    // }
        // S[mas_i[iterator]][mas_j[iterator]] = mas_k[iterator];
        // S[mas_i[iterator+1]][mas_j[iterator+1]] = mas_k[iterator+1]; 

} 
//------------------------------------------------------------


// SUMMING INDEXES OF WAYS -----------------------------------
    int *sums_indexes = malloc(ways_counter * sizeof(int *));
    for (int i = 0; i < ways_counter; i++)
    {
        if(lengthes[i] <= 0){
            break;
        }  
        int sum = 0;
        for (int j = 0; j < lengthes[i]; j++){
            sum = sum + ways[i][j];
        }
        sums_indexes[i] = sum;
        // printf("%d",sum);
        // printf("%s"," ");
    }
//-----------------------------------------------------------

// for (int i = 0; i < ways_counter; i++){
//     bool isExist = false;
//     for (int j = i+1; j < ways_counter; j++){
//         if(mx_is_equal_mas(ways[i],ways[j],count_of_islands))
//             isExist = true;
//     }
//     if(isExist){
//         ways[i] = NULL;
//         lengthes[i] = -1;
//         sums_indexes[i] = -1;
//     }
// }




// SORTING --------------------------------------------------
    for (int i = 0; i < ways_counter; i++)
    {
        if(lengthes[i] <= 0){
            break;
        }
        for (int j = i+1; j < ways_counter; j++){
            if( ways[i][0] > ways[j][0]){
                int *temp = ways[j];
                ways[j] = ways[i];
                ways[i] = temp;
                // printf("%s","swap");
                int size = lengthes[j];
                lengthes[j] = lengthes[i];
                lengthes[i] = size;

                size = sums_indexes[j];
                sums_indexes[j] = sums_indexes[i];
                sums_indexes[i] = size;
            }            
        }
    }

    for (int i = 0; i < ways_counter; i++)
    {
        if(lengthes[i] <= 0){
            break;
        }
        for (int j = i+1; j < ways_counter; j++){
            if(ways[i][0] == ways[j][0] && ways[i][lengthes[i]-1] > ways[j][lengthes[j]-1]){
                int *temp = ways[j];
                ways[j] = ways[i];
                ways[i] = temp;
                // printf("%s","swap");
                int size = lengthes[j];
                lengthes[j] = lengthes[i];
                lengthes[i] = size;

                size = sums_indexes[j];
                sums_indexes[j] = sums_indexes[i];
                sums_indexes[i] = size;
            }            
        }
    }

    for (int i = 0; i < ways_counter; i++)
    {        
        if(lengthes[i] <= 0){
            break;
        } 
        for (int j = i+1; j < ways_counter; j++)
        {
            if((sums_indexes[i] > sums_indexes[j]) || (lengthes[i]-1 < lengthes[j]-1)){
            // printf("%s","greater");
                if(ways[i][lengthes[i]-1] != ways[j][lengthes[j]-1])
                    continue;
                if(ways[i][0] != ways[j][0])
                    continue;
                int *temp = ways[j];
                ways[j] = ways[i];
                ways[i] = temp;

                int size = lengthes[j];
                lengthes[j] = lengthes[i];
                lengthes[i] = size;

                size = sums_indexes[j];
                sums_indexes[j] = sums_indexes[i];
                sums_indexes[i] = size;
                // printf("%s","swap");
        
            }
        } 
    }
//----------------------------------------------------------------  

// OUTPUT ---------------------------------------------------------
    for (int i = 0; i < ways_counter; i++)
    {
        if(lengthes[i] <= 0){
            break;
        }   
        for (int e = 0; e < 40; e++)
        {
            mx_printchar('=');
        }
        mx_printchar('\n');
        mx_printstr("Path: ");
        mx_printstr(islands[ways[i][0]].name);
        mx_printstr(" -> ");
        mx_printstr(islands[ways[i][lengthes[i]-1]].name);
        mx_printchar('\n');
        mx_printstr("Route: "); 
        for (int j = 0; j < lengthes[i]; j++)
        {
            if(ways[i][j] >= 0){
                mx_printstr(islands[ways[i][j]].name);
                if(j != lengthes[i]-1)
                    mx_printstr(" -> ");
            }
        }
        mx_printchar('\n');
        mx_printstr("Distance: ");
        bool eq_symb_needed = false;
        int sum = 0;
        for (int j = 0; j < lengthes[i]-1; j++)
        {
            if(ways[i][j] >= 0){
                mx_printint(D[ways[i][j]][ways[i][j+1]]);
                sum = sum + D[ways[i][j]][ways[i][j+1]];
                if(j != lengthes[i]-2){
                    mx_printstr(" + ");
                    eq_symb_needed = true;
                }
            }
        }
        if(eq_symb_needed){
            mx_printstr(" = ");
            mx_printint(sum);
        }

        mx_printchar('\n');
        for (int g = 0; g < 40; g++)
        {
            mx_printchar('=');
        }    
        mx_printchar('\n');        
    }
    // printf("%d",ways_counter);
}

