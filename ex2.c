#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct serie {
    char serieName[20];
    int numSeasons;
    int rank;
    int* watchingDetails;
    int id;
}serie;

int showMenu();
int managFirstOption();
int getValues(FILE*, char*, int*, int*, char*);
int unifyDatabase(FILE*, FILE*);
serie** getUnifyDatabaseDetails(int, serie*);
void sortById(serie**, int);
void printSeriesList(serie**, int);
int isSerieExc(serie**, int, int);
serie* getSerieById(serie**, int, int);
void getWatchingDetails(serie**, int);
void printWatchingDetails(int);
void sortByRank(serie**, int);
int getMaxRank(serie**, int);
void printSeriesByPtr(serie*);
void printSeriesByRank(serie**, int);
void makeSeriesFileSortedByRank(serie**, int);
void freeMalloc(serie**, int, serie* ptr_serie);
void printRes(int fl);
FILE* openFileR(char*);





int showMenu() { //show and mannage the input
    int input;
    int fl;
    printf("%s", "**********Main Menu **************\n");
    printf("%s", "1. Unify Database.\n");
    printf("%s", "2. Get Unify Database Details.\n");
    printf("%s", "3. Print The Series List Sorted By Code.\n");
    printf("%s", "4. Get Watching Details.\n");
    printf("%s", "5. Show All Watching Details.\n");
    printf("%s", "6. Print Series Sorted By Rank.\n");
    printf("%s", "7. Make Series File Sorted By Rank.\n");
    printf("%s", "8. Exit.\n");
    printf("%s", "Enter Your Selection:");
    fflush(stdin);
    fl = scanf("%d", &input);
    return input;
}

int getValues(FILE* file, char* name_series, int* id, int* season_num, char* is_active) { // get the values from the series file
    int EOH = fscanf(file, "%20[^,] %*c %3d %*c %2d %*c %c %*[\n]", name_series, id, season_num, is_active);
    return EOH;
}

int unifyDatabase(FILE* file1, FILE* file2) { //unify the series files to one list 
    char name_series1[20], name_series2[20];
    int series_num = 0;
    int id1, id2;
    int season_num1, season_num2;
    char is_active1, is_active2;
    FILE* series_file;
    int EOH1;
    int EOH2;
    series_file = fopen("series.txt", "w");
    EOH1 = getValues(file1, name_series1, &id1, &season_num1, &is_active1);
    EOH2 = getValues(file2, name_series2, &id2, &season_num2, &is_active2);

    while (EOH1 != -1 || EOH2 != -1) {
        if (EOH1 == -1 || id1 > id2) {
            if (is_active2 == 'Y') {
                fprintf(series_file, "%s,%d,%d\n", name_series2, id2, season_num2);
                series_num++;
            }
            EOH2 = getValues(file2, name_series2, &id2, &season_num2, &is_active2);
        }
        else if (EOH2 == -1 || id2 > id1) {
            if (is_active1 == 'Y') {
                fprintf(series_file, "%s,%d,%d\n", name_series1, id1, season_num1);
                series_num++;
            }
            EOH1 = getValues(file1, name_series1, &id1, &season_num1, &is_active1);
        }
        else {
            int season_num;
            if (is_active1 == 'Y' || is_active2 == 'Y') {
                if (is_active1 == 'Y' && is_active2 == 'Y') {
                    if (season_num1 > season_num2) season_num = season_num1;
                    else season_num = season_num2;
                }
                else {
                    if (is_active1 == 'Y') season_num = season_num1;
                    else season_num = season_num2;
                }
                fprintf(series_file, "%s,%d,%d\n", name_series1, id1, season_num);
                series_num++;
            }
            EOH1 = getValues(file1, name_series1, &id1, &season_num1, &is_active1);
            EOH2 = getValues(file2, name_series2, &id2, &season_num2, &is_active2);
        }
    }
    fclose(series_file);
    return series_num;
}

serie** getUnifyDatabaseDetails(int series_num, serie* ptr_serie) { //put the details from the files in array of arrays (of series)
    FILE* series_file;
    serie** ptr;
    char serieName1[20];
    int numSeasons, id, i = 0, EOH = 0;
    int* watchingDetails;
    series_file = fopen("series.txt", "r");

    ptr_serie = (serie*)malloc(series_num * sizeof(serie));
    ptr = (serie**)malloc(series_num * sizeof(serie*));
    if (ptr_serie && ptr) {
        while (EOH != -1) {
            EOH = fscanf(series_file, "%20[^,] %*c %3d %*c %2d %*[\n]", serieName1, &id, &numSeasons);
            if (EOH != -1) {
                (ptr_serie + i)->numSeasons = numSeasons;
                (ptr_serie + i)->id = id;
                watchingDetails = (int*)malloc(numSeasons * sizeof(int));
                (ptr_serie + i)->watchingDetails = watchingDetails;
                for (int j = 0; j < (ptr_serie + i)->numSeasons; ++j) {
                    (ptr_serie + i)->watchingDetails[j] = 0;
                }
                (ptr_serie + i)->rank = 0;
                strcpy((ptr_serie + i)->serieName, serieName1);
                *(ptr + i) = ptr_serie + i;
                i++;
            }
        }
    }
    fclose(series_file);
    return  ptr;
}

void sortById(serie** ptr, int size) { //do bubble sort by id
    int fl = 1;
    serie* ser_temp;
    while (fl) {
        fl = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (ptr[i]->id > ptr[j]->id) {
                    ser_temp = ptr[i];
                    ptr[i] = ptr[j];
                    ptr[j] = ser_temp;
                    fl = 1;
                }
            }
        }
    }
}

void printSeriesList(serie** ptr, int size) { // print all the series (sorted by id)
    sortById(ptr, size);
    printf("Series List\n");
    for (int i = 0; i < size; i++) {
        printf("%03d-%s(%d)\n", ptr[i]->id, ptr[i]->serieName, ptr[i]->numSeasons);
    }
    printf("\n");
}

int isSerieExc(serie** ptr, int size, int id_ser) { // find if series code in the list
    int i = 0, fl = 0;
    while (i < size && !fl) {
        if (ptr[i]->id == id_ser)  fl = 1;
        i++;
    }
    return fl;
}

serie* getSerieById(serie** ptr, int size, int id) { // get one series from the list by ptr 
    serie* return_ptr = NULL;
    for (int i = 0; i < size; i++) {
        if (ptr[i]->id == id) {
            return_ptr = ptr[i];
        }
    }
    return return_ptr;
}

void getWatchingDetails(serie** ptr, int size) {// enter watching to one season in one series
    FILE* f = fopen("watching.txt", "a");
    int ans, id_input, ses_input;
    int fl = 1;
    printf("Insert Serie Code:");
    do {
        fflush(stdin);
        ans = scanf("%d", &id_input);
        if (ans > 0 && isSerieExc(ptr, size, id_input) == 1) {
            fl = 0;
        }
        else {
            printf("wrong serie code, try again!!!\n");
        }
    } while (fl);
    serie* ptr_by_id = getSerieById(ptr, size, id_input);
    printf("Insert Season Number (1 - %d):", ptr_by_id->numSeasons);
    fl = 1;
    do {
        fflush(stdin);
        ans = scanf("%d", &ses_input);
        if (ans > 0 && ses_input >= 1 && (ses_input <= ptr_by_id->numSeasons))  fl = 0;
        else printf("wrong season number, try again!!!");

    } while (fl);
    fprintf(f, "%d,%d\n", ptr_by_id->id, ses_input);
    ptr_by_id->watchingDetails[ses_input - 1]++;
    ptr_by_id->rank++;
    printf("series: %d, season: %d accepted!!!\n", ptr_by_id->id, ses_input);
    fclose(f);

}

void printWatchingDetails(int lines) { //print all the watching details
    FILE* watch_file;
    watch_file = fopen("watching.txt", "r");
    int* ser_code, * ser_season;
    ser_code = (int*)malloc(lines * sizeof(int));
    ser_season = (int*)malloc(lines * sizeof(int));
    printf("Watching Details\n");
    if (ser_code != NULL && ser_season != NULL) {
        for (int i = 0; i < lines; i++) {
            fscanf(watch_file, "%d,%d", ser_code + i, ser_season + i);
            printf("Series Code:%03d, Season Number:%d\n", *(ser_code + i), *(ser_season + i));
        }
    }
    free(ser_code);
    free(ser_season);
    fclose(watch_file);
}

void sortByRank(serie** ptr, int size) { //do bubble sort by rank
    int fl = 1;
    serie* ser_temp;
    while (fl) {
        fl = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (ptr[i]->rank < ptr[j]->rank) {
                    ser_temp = ptr[i];
                    ptr[i] = ptr[j];
                    ptr[j] = ser_temp;
                    fl = 1;
                }
            }
        }
    }
}

int getMaxRank(serie** ptr, int series_num) { // get max rank (max num of watching details
    int max_rank = 0;
    for (int i = 0; i < series_num; ++i) {
        if (max_rank < ptr[i]->rank) {
            max_rank = ptr[i]->rank;
        }
    }
    return max_rank;
}


void printSeriesByPtr(serie* ptr) { //get ptr and print all the seies needed details
    printf("%03d-%s\n", ptr->id, ptr->serieName);
    for (int i = 0; i < ptr->numSeasons; ++i) {
        printf("Season %d:%d\n", i + 1, (ptr->watchingDetails)[i]);
    }
}

void printSeriesByRank(serie** ptr, int series_num) { // print series sorted by rank (and inside sort by id)
    int max_rank = getMaxRank(ptr, series_num);
    sortById(ptr, series_num);
    for (int i = max_rank; i >= 0; i--) {
        printf("RANK %d\n", i);
        for (int j = 0; j < series_num; j++) {
            if (ptr[j]->rank == i) {
                printSeriesByPtr(ptr[j]);
            }
        }

    }
}

void makeSeriesFileSortedByRank(serie** ptr, int series_num) { // sort the seriesRank file by rank (create/override)
    FILE* f = fopen("seriesRank.txt", "w+");
    sortByRank(ptr, series_num);
    for (int i = 0; i < series_num; i++) {
        fprintf(f, "%03d(Rank:%d)-%s\n", ptr[i]->id, ptr[i]->rank, ptr[i]->serieName);
    }
    fclose(f);
}

void freeMalloc(serie** ptr, int series_num, serie* ptr_serie) { // free all the memory allocation
    serie* z;
    for (int i = 0; i < series_num; i++) {
        z = *(ptr + i);
        free(z->watchingDetails);
    }
    free(ptr_serie);
    free(ptr);
}

FILE* openFileR(char* str_print) { //open the needed files in read condition
    FILE* serie_file;
    char f_name[21];
    printf(str_print);
    fflush(stdin);
    scanf("%s", f_name);
    serie_file = fopen(f_name, "r");
    while (serie_file == NULL) {
        printf("error in opening file %s !!!\n", f_name);
        printf(str_print);
        fflush(stdin);
        scanf("%s", f_name);
        serie_file = fopen(f_name, "r");
    }
    return serie_file;
}
int managFirstOption() {
    int series_num;
    FILE* f1, * f2, * watch_file;
    f1 = openFileR("Enter First File Name: \n");
    f2 = openFileR("Enter Second File Name: \n");
    watch_file = fopen("watching.txt", "w");
    fclose(watch_file);
    series_num = unifyDatabase(f1, f2);
    fclose(f1);
    fclose(f2);
    printf("%s", "Unify Succeeded \n");
    return series_num;
}

void printRes(int fl) { // print the right response
    if (fl)printf("You must Get Unify Database Details before using this option!!!\n");
    else  printf("You must unify database before using this option!!!\n");

}
int main() {
    serie** ptr = 0;
    serie* ptr_serie = 0;
    int input, series_num = 0, fl = 1, fl1 = 0, fl2 = 0, lines_num = 0; // fl -to the loop,fl1-if option 1 happend,fl2- if option 2 happend
    while (fl) {
        input = showMenu();
        switch (input) {
        case  1:
            if (fl1)printf("Unify Database Has Been Done Already !!!\n");
            else {
                series_num = managFirstOption();
                fl1 = 1;
            }
            break;
        case 2:
            if (fl1 && !fl2) {
                ptr = getUnifyDatabaseDetails(series_num, ptr_serie);
                fl2 = 1;
                printf("Get Unify Database Details Succeeded\n");
            }
            else if (fl1 && fl2)printf("Get Unify Database Details Has Been Done Already !!!\n");
            else  printf("You must unify database before using this option!!!\n");
            break;
        case 3:
            if (fl1 && fl2)printSeriesList(ptr, series_num);
            else  printRes(fl1);
            break;
        case 4:
            if (fl1 && fl2) {
                getWatchingDetails(ptr, series_num);
                lines_num++;
            }
            else  printRes(fl1);
            break;
        case 5:
            if (fl1 && fl2)  printWatchingDetails(lines_num);
            else  printRes(fl1);
            break;
        case 6:
            if (fl1 && fl2)  printSeriesByRank(ptr, series_num);
            else  printRes(fl1);
            break;
        case 7:
            if (fl1 && fl2)  makeSeriesFileSortedByRank(ptr, series_num);
            else  printRes(fl1);
            break;
        case 8:
            fl = 0;
            break;
        default:
            printf("Wrong Option, Try Again !!!\n");
        }
    }
    if (fl2)freeMalloc(ptr, series_num, ptr_serie);

    printf("End Of The Program...\n");
    return 0;
}
