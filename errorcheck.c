

status check_if_its_integer ( char* str1, char* str2 ) {

    int i = 0;

    while (str1[i]) {
        if ( (str1[i] >= 'a' && str1[i] <= 'z') || (str1[i]>= 'A' && str1[i] <= 'Z') ) {
            printf("Error enter integer only\n");
            exit(EXIT_FAILURE);
        }
        i+=1;
    }
    i = 0;

    while (str2[i]) {
        if ( (str2[i] >= 'a' && str2[i] <= 'z') || (str2[i]>= 'A' && str2[i] <= 'Z') ) {
            printf("Error enter integer only\n");
            exit(EXIT_FAILURE);
        }
        i+=1;
    }

    return SUCCESS;
}
