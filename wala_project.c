#include<stdio.h>
int main()
{
    char A[5][4];//={{'a','b','c','D'},{'#','#','#','#'},{'E','f','#','g'},{'h','i','#','j'},{'k','L','#','m'}};
    int r, c, n, i = 0;

    printf("*** Please Enter Polts matrix*****\n");
    for (int r = 0; r < 5;r++) {
        for (int c = 0;c < 4;c++) {
            scanf(" %c", &A[r][c]);
            if (!((A[r][c] >= 'A' && A[r][c] <= 'Z') || (A[r][c] >= 'a' && A[r][c] <= 'z') || A[r][c] == '#'))
            {
                printf("\n *** you entered wrong value ****\n");
                printf("\n *** try again ****\n");
                i = 1;
            }
            else
                i = 0;
        }
    }

    if (i == 0)
    {
        for (;;)
        {
            int n, countavb = 0, count = 0, countsold = 0, count_Sold = 0, count_ava = 0, flag = 0, flag2 = 0;
            char status;
            printf("------------------------------------------------------------------------------\n");
            printf("*** Select from the Menue ****\n");
            printf("1 : print the map\n");
            printf("2 : print available plots\n");
            printf("3 : number of Sold plots\n");
            printf("4 : plot status (enter a character) \n");
            printf("5 : find the plot price (enter a character)\n");
            printf("6 : buy plot (enter a character)\n");
            printf("7 : sell plot (enter a character)\n");
            printf("8 : Exit\n\n");
            printf("enter a number=");
            scanf(" %d", &n);

            if (!(n >= 1 && n <= 8))
                printf("\n *** you entered wrong number ****\n");

            // Q1
            else if (n == 1) {
                printf("***The plot map*** \n");
                printf("this sign(a) means available,(s) means sold, sign(r) means road  \n");
                char a = 'a';
                for (int r = 0; r < 5;r++) {
                    printf("***************************** \n");
                    for (int c = 0;c < 4;c++) {
                        if (A[r][c] >= 'a' && A[r][c] <= 'z')
                            a = 'a';
                        else if (A[r][c] == '#')
                            a = 'r';
                        else
                            a = 's';
                        printf(" %c(%c) *", A[r][c], a);
                    }
                    printf("\n");
                }
                printf("***************************** \n");
            }


            // Q2
            else if (n == 2) {
                int e = 0, countavb = 0;
                printf("***The count of avialable plots *** \n");
                for (int r = 0;r < 5;r++) {
                    for (int c = 0;c < 4;c++) {
                        if (A[r][c] >= 'a' && A[r][c] <= 'z')
                            countavb++;


                    }
                }
                printf("the count is =%d\n", countavb);

            }


            // Q3
            else if (n == 3) {
                int countsold = 0;
                printf("***The count of sold plots *** \n");
                for (int r = 0;r < 5;r++) {
                    for (int c = 0;c < 4;c++) {
                        if (A[r][c] >= 'A' && A[r][c] <= 'Z')
                            countsold++;


                    }
                }
                printf("the count is =%d\n", countsold);

            }

            // Q4
            else if (n == 4) {
                char status;
                int count_Sold = 0, count = 0, count_ava = 0, flag = 0, flag2 = 0;
                printf(" Please Enter the plot(character) you want the status \n");
                scanf(" %c", &status);
                if (status >= 'a' && status <= 'z') {
                    for (int r = 0;r < 5;r++) {
                        for (int c = 0;c < 4;c++) {

                            if (A[r][c] == status || A[r][c] == status - 32) {
                                flag2 = 1;
                                if ((r - 1 >= 0 && r - 1 <= 4) && (A[r - 1][c] == '#')) {
                                    count = count + 1;
                                }
                                if ((r + 1 >= 0 && r + 1 <= 4) && (A[r + 1][c] == '#')) {
                                    count = count + 1;
                                }
                                if ((c - 1 >= 0 && c - 1 <= 3) && (A[r][c - 1] == '#')) {
                                    count = count + 1;
                                }
                                if ((c + 1 >= 0 && c + 1 <= 3) && (A[r][c + 1] == '#')) {
                                    count = count + 1;
                                }
                                if ((r - 1 >= 0 && r - 1 <= 4) && (A[r - 1][c] >= 'A' && A[r - 1][c] <= 'Z')) {
                                    count_Sold = count_Sold + 1;
                                }
                                if ((r + 1 >= 0 && r + 1 <= 4) && (A[r + 1][c] >= 'A' && A[r + 1][c] <= 'Z')) {
                                    count_Sold = count_Sold + 1;
                                }
                                if ((c - 1 >= 0 && c - 1 <= 3) && (A[r][c - 1] >= 'A' && A[r][c - 1] <= 'Z')) {
                                    count_Sold = count_Sold + 1;
                                }
                                if ((c + 1 >= 0 && c + 1 <= 3) && (A[r][c + 1] >= 'A' && A[r][c + 1] <= 'Z')) {
                                    count_Sold = count_Sold + 1;
                                }
                                if ((r - 1 >= 0 && r - 1 <= 4) && (A[r - 1][c] >= 'a' && A[r - 1][c] <= 'z')) {
                                    count_ava = count_ava + 1;
                                }
                                if ((r + 1 >= 0 && r + 1 <= 4) && (A[r + 1][c] >= 'a' && A[r + 1][c] <= 'z')) {
                                    count_ava = count_ava + 1;
                                }
                                if ((c - 1 >= 0 && c - 1 <= 3) && (A[r][c - 1] >= 'a' && A[r][c - 1] <= 'z')) {
                                    count_ava = count_ava + 1;
                                }
                                if ((c + 1 >= 0 && c + 1 <= 3) && (A[r][c + 1] >= 'a' && A[r][c + 1] <= 'z')) {
                                    count_ava = count_ava + 1;
                                }

                                if (A[r][c] >= 'a' && A[r][c] <= 'z') {
                                    flag = 1;
                                }

                                if (flag == 1)
                                    printf(" the status of plot %c is: it is available, its surounding: %d available , %d sold , %d roads.", status, count_ava, count_Sold, count);
                                else
                                    printf(" the status of plot %c is: it is Sold, its surounding: %d available , %d sold , %d roads.", status, count_ava, count_Sold, count);
                                count_ava = count = count_Sold = flag = 0;
                                r = c = 5;
                                break;
                            }//if تحديدحالة الارض 
                        }
                    }//for matrix
                    if (flag2 == 0)
                        printf(" sorry this plot does not exist \n");


                }//if  انه المدخل حرف  
                else
                    printf(" you entered wrong character please try again\n");


            }//if n=4


             // Q5
            else if (n == 5) {
                printf(" Please Enter the plot (character) you want \n");
                scanf(" %c", &status);
                if (status >= 'a' && status <= 'z') {
                    for (int r = 0;r < 5;r++) {
                        for (int c = 0;c < 4;c++) {

                            if (A[r][c] == status || A[r][c] == status - 32) {
                                flag2 = 1;
                                if ((r - 1 >= 0 && r - 1 <= 4) && (A[r - 1][c] == '#')) {
                                    count = count + 1;
                                }
                                if ((r + 1 >= 0 && r + 1 <= 4) && (A[r + 1][c] == '#')) {
                                    count = count + 1;
                                }
                                if ((c - 1 >= 0 && c - 1 <= 3) && (A[r][c - 1] == '#')) {
                                    count = count + 1;
                                }
                                if ((c + 1 >= 0 && c + 1 <= 3) && (A[r][c + 1] == '#')) {
                                    count = count + 1;
                                }

                                int price = 10000 + 10000 * (count / 10.0);
                                printf("*** The price for this land is: %d $ ", price);
                                count = 0;
                                r = c = 5;
                                break;
                            }
                        }
                    }

                    if (flag2 == 0) {
                        printf(" sorry this plot does not exist \n");
                    }
                }
                else
                    printf(" you entered wrong character please try agian\n");
            }//if n==5

            //Q6
            else if (n == 6) {
                char status, flag2 = 0;
                printf(" Please Enter the plot you want to buy \n");
                scanf(" %c", &status);
                if (status >= 'a' && status <= 'z') {
                    for (r = 0;r < 5;r++) {
                        for (c = 0;c < 4;c++) {
                            if (A[r][c] == status || A[r][c] == status - 32) {
                                flag2 = 1;
                                if (A[r][c] >= 'a' && A[r][c] <= 'z') {
                                    A[r][c] = A[r][c] - 32;
                                    printf(" its available and you bought plot %c\n", status);
                                }
                                else
                                    printf(" sorry it's sold\n");
                                r = c = 5;
                                break;
                            }
                        }
                    }
                    if (flag2 == 0)
                        printf(" sorry this plot does not exist \n");
                }
                else
                    printf(" you entered wrong character please try agian\n");
            }//if n==6
              //Q7
            else if (n == 7) {
                char status, flag2 = 0;
                printf(" Please Enter the plot you want to sell\n");
                scanf(" %c", &status);
                if (status >= 'a' && status <= 'z') {
                    for (int r = 0;r < 5;r++) {
                        for (int c = 0;c < 4;c++) {
                            if (A[r][c] == status || A[r][c] == status - 32) {
                                flag2 = 1;
                                if (A[r][c] >= 'a' && A[r][c] <= 'z') {
                                    printf(" the plot %c is available you can't sell it\n ", status);
                                    r = c = 5;
                                    break;
                                }
                                if (A[r][c] >= 'A' && A[r][c] <= 'Z')
                                {
                                    A[r][c] = A[r][c] + 32;
                                    printf(" you sell plot %c\n", status);
                                    r = c = 5;
                                    break;
                                }
                            }
                        }
                    }
                    if (flag2 == 0)
                        printf(" sorry this plot does not exist \n");
                }
                else
                    printf(" you entered wrong character please try agian\n");
            }//if n==7

            else if (n == 8)
            {
                printf("quit from the program");
                break;
            }
            else
                printf("\n *** you entered wrong number ****\n");
        }//for infinite loop
    }//if i==0
}//main
