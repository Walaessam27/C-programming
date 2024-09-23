
#include <stdio.h>
int main()
{
    // here i choose the example one and i fill the matrix 
    //char plot[5][4]  = {{'a','b','c','D'},{'#','#','#','#'},{'E','f','#','g'},{'h','i','#','j'},{'k','L','#','m'}};
    char plot[5][4] ;
    char v;
    int x , i , j;
    char str1 ;
    
    printf("*** Please Entor Polts matrix*****\n");
    for( int i=0;i<5;i++){
        printf(" Enter the row: %d\n",i+1);
            for( int j=0;j<4;j++){
              scanf("%s",&plot[i][j]); 
                
                if( !((plot[i][j]>= 'A' && plot[i][j] <= 'Z') || (plot[i][j]>= 'a' && plot[i][j] <= 'z') || plot[i][j]=='#') )
                   {
                     printf(" you entered wrong name try agine \n");
                       j = j-1;
                  }
                }
           }
           
           
    printf("Land Plot for Sale\n");
for( ; ; ){  
    int count= 0; // for # of roads
    int count_Sold = 0 ;// for 3 sold plots
    int count_ava = 0 ;// for 3 avialabel plots
    int flag = 0;
    int flag2 = 0;// for pot status
    printf("\n * Select from the Menue ****\n");
    printf("1 : print the map\n");
    printf("2 : print available plots\n");
    printf("3 : number of Sold plots\n");
    printf("4 : plot status \n");
    printf("5 : find the plot price \n");
    printf("6 : buy plot\n");
    printf("7 : sell plot \n");
    printf("8 : Exit\n");
    
    scanf("%d", &x);
    
    // Q1
    if(x==1){
        printf("***The plot map*** \n");
        for( i=0;i<5;i++){
             printf("\n");
            for(j=0;j<4;j++){
               printf("%c\t",plot[i][j]); 
           }
        }
    }// Q2
    else if(x==2){
      printf("***The avialbel plots *** \n");  
          for( i=0;i<5;i++){
            for(j=0;j<4;j++){
                if(plot[i][j]>= 'a' && plot[i][j] <= 'z'){
                   printf("%c\t",plot[i][j]); 
                }
           }
        }
        
    }
    // Q3
    else if( x== 3){
        for( i=0;i<5;i++){
            for(j=0;j<4;j++){
                if(plot[i][j]>= 'A' && plot[i][j] <= 'Z'){
                    count_Sold = count_Sold +1;
                }
           }
        }
        
        printf(" * The number of sold plots is: %d", count_Sold);
        
    }
    // Q4 
    else if( x == 4){
      printf(" Pleas Enter the plot you want the status \n");
      scanf("%s", &str1);
      
      if(str1 >= 'a' && str1 <= 'z'){
          
       for( i=0;i<5;i++){
          
            for(j=0;j<4;j++){
               
               if( plot[i][j]== str1 || plot[i][j]== str1-32 ){
                   flag2 = 1;
                    if( (i-1>=0 && i-1<=4) && (plot[i-1][j]== '#')){ 
                       count = count + 1 ;
                   }
                   if((i+1>=0 && i+1<=4) && (plot[i+1][j]== '#')){
                       count = count + 1 ;
                   }
                   if((j-1>=0 && j-1<=3) && (plot[i][j-1]== '#')){
                       count = count + 1 ;
                   }
                   if((j+1>=0 && j+1<=3) && (plot[i][j+1]== '#')){
                       count = count + 1 ;
                   }
                   
                   if((i-1>=0 && i-1<=4) && (plot[i-1][j]>= 'A' && plot[i-1][j] <= 'Z' )){ 
                       count_Sold = count_Sold + 1 ;
                   }
                   if((i+1>=0 && i+1<=4) && (plot[i+1][j]>= 'A' && plot[i+1][j] <= 'Z')){
                       count_Sold = count_Sold + 1 ;
                   }
                   if((j-1>=0 && j-1<=3) && (plot[i][j-1]>= 'A' && plot[i][j-1] <= 'Z')){
                       count_Sold = count_Sold + 1 ;
                   }
                   if((j+1>=0 && j+1<=3) && (plot[i][j+1]>= 'A' && plot[i][j+1] <= 'Z')){
                       count_Sold = count_Sold + 1 ;
                   }
                   
                   if((i-1>=0 && i-1<=4) && (plot[i-1][j]>= 'a' && plot[i-1][j] <= 'z' )){ 
                       count_ava = count_ava + 1 ;
                   }
                   if((i+1>=0 && i+1<=4) && (plot[i+1][j]>= 'a' && plot[i+1][j] <= 'z')){
                       count_ava = count_ava + 1 ;
                   }
                   if((j-1>=0 && j-1<=3) && (plot[i][j-1]>= 'a' && plot[i][j-1] <= 'z')){
                       count_ava = count_ava + 1 ;
                   }
                   if((j+1>=0 && j+1<=3) && (plot[i][j+1]>= 'a' && plot[i][j+1] <= 'z')){
                       count_ava = count_ava + 1 ;
                   }
                   
                   if (plot[i][j]>= 'a' && plot[i][j] <= 'z'){
                       flag = 1;
                   } 
                   
                   if(flag == 1){
                    printf(" the status of plot (%s) is: it is available, its surounding: %d available , %d sold , %d roads.",&str1,count_ava,count_Sold,count);   
                   }else{
                    printf(" the status of plot (%s) is: it is Sold, its surounding: %d available , %d sold , %d roads.",&str1,count_ava,count_Sold,count);   
   
                   }
                    
                   
                   
                   count_ava = count = count_Sold = flag= 0;
                   i = j = 5;
                   break;
               } 

           }
        }
        if( flag2 == 0){
            printf(" sorry this plot does not exist \n");
        }
    }else {
        printf(" you entered wrong caracter Pleas try agine\n");
    }
}
        
     // Q5
    else if( x == 5){
      printf(" Pleas Enter the plot you want \n");
      scanf("%s", &str1); 
     if(str1 >= 'a' && str1 <= 'z'){
       for( i=0;i<5;i++){
          
            for(j=0;j<4;j++){
               
               if( plot[i][j]== str1 || plot[i][j]== str1-32 ) {
                   flag2 =1;
                    if( (i-1>=0 && i-1<=4) && (plot[i-1][j]== '#')){ 
                       count = count + 1 ;
                   }
                   if((i+1>=0 && i+1<=4) && (plot[i+1][j]== '#')){
                       count = count + 1 ;
                   }
                   if((j-1>=0 && j-1<=3) && (plot[i][j-1]== '#')){
                       count = count + 1 ;
                   }
                   if((j+1>=0 && j+1<=3) && (plot[i][j+1]== '#')){
                       count = count + 1 ;
                   }
                   
                   int price = 10000 + 10000*(count/10.0);
                   printf("*** The price for this land is: %d $ ",price);
                   
                   
                   count = 0;
                   i = j = 5;
                   break;
               } 

           }
        }
        
         if( flag2 == 0){
            printf(" sorry this plot does not exist \n");
        }
        
    }else{
       printf(" you entered wrong caracter pleas try agine\n");  
    }
  }
    //Q6
    else if(x==6){
      printf(" Pleas Enter the plot you want to buy \n");
      scanf("%s", &str1);
    if(str1 >= 'a' && str1 <= 'z'){
      
        for( i=0;i<5;i++){
            for(j=0;j<4;j++){
                if( plot[i][j]== str1 || plot[i][j]== str1-32 ){
                    flag2 = 1 ;
                  if(plot[i][j]>= 'a' && plot[i][j] <= 'z'){
                    plot[i][j] = plot[i][j] -32;
                   
                   printf(" its available and you bought plot %s",&str1);
                }
                else{
                   printf(" sorry it's sold" ) ;
                }
                
                i = j = 5;
                break;
             }
           }
        }
          if( flag2 == 0){
            printf(" sorry this plot does not exist \n");
        }
    }
  
    
    else{
       printf(" you entered wrong caracter pleas try agine\n");  
    }  
    
    }
    //Q 7
    else if(x==7){
      printf(" Pleas Enter the plot you want to sell \n");
      scanf("%s", &str1);
      if(str1 >= 'a' && str1 <= 'z'){
      
        for( i=0;i<5;i++){
            for(j=0;j<4;j++){
                if( plot[i][j] == str1 || plot[i][j]== str1-32 ){
                    flag2 = 1;
                  if(plot[i][j]!= '#' && ( plot[i][j] >= 'a' && plot[i][j] <= 'z') ){
                    plot[i][j] =  plot[i][j] - 32;
                    printf(" you sell plot %s",&str1);
                i = j = 5;
                break;
             }
             
             if(plot[i][j]!= '#' && ( plot[i][j] >= 'A' && plot[i][j] <= 'Z') ){
                    plot[i][j] =  plot[i][j] ;
                    printf(" you sell plot %s",&str1);
                i = j = 5;
                break;
             }
             
             
           }
        }
    }
     if( flag2 == 0){
            printf(" sorry this plot does not exist \n");
        }
  }
  
  else{
       printf(" you entered wrong caracter pleas try agine\n");  
    } 
 }
  
  else if(x==8){
      break; 
  }
 
 else{
      printf( "error number please try agin \n");
        break;
      
  } 

    
}   
    return 0;
}