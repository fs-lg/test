#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//change in git hub 
int maxSize=10;
int role;
int row1=0;
int column1=0;
int row2=0;
int column2=0;

int rule(int row1,int column1,int row2,int column2,int  gameBoarder[][10],int&simpleSw,int &swturn){
	int i=0;
	int j=0;
	int count=0;
	
	if ((row2==row1||row2==row1+1||row2==row1-1)&&(column2==column1-1||column2==column1+1||column2==column1))
	{
		while(simpleSw){
		
	     
		  simpleSw=0;
		  return 1;
		  
	    }
	    printf("you can not have simple move! ");
	     
	    
	}
	
	if(row1==row2){
	    if( (abs(column2-column1)%2)!=0)return 0;
		    else{
		     	
		     	if (column2>column1){
				     for (i=column1+1;i<column2;i++){
			 	    if (gameBoarder[row1][i]!=0)count++;
			            }
			        if (count==1&&gameBoarder[row1][(abs(column2-column1)/2)+column1])return 1;    
			            
			        }
			    else{
				     for ( i=column2+1;i<column1;i++){
			 	    if (gameBoarder[row1][i]!=0)count++;
			            }
					if (count==1&&gameBoarder[row1][(abs(column2-column1)/2)+column2])return 1;	 
					}
			 }
                   		
			        
    }
    
    

    
    
    
	if(column1==column2){
	    if( (abs(row2-row1)%2)!=0)return 0;
		    else{
		     	
		     	if (row2>row1){
				     for ( i=row1+1;i<row2;i++){
			 	    if (gameBoarder[i][column1]!=0)count++;
			            }
			    if (count==1&&gameBoarder[((row2-row1)/2)+row1][column1])return 1;        
			    }
			    
			    else{
				     for ( i=row2+1;i<row1;i++){
			 	    if (gameBoarder[i][column1]!=0)count++;
			            } 
			        if (count==1&&gameBoarder[((row1-row2)/2)+row2][column1])return 1;    
					}
			    
               
		    }
    }
	
	
	 
    if(abs(row2-row1)==abs(column2-column1) ){
       
	  if((abs(row2-row1)%2)!=0)return 0;
      else{
		
	   
	   if (row2>row1)
	   {
	    for( i=row1+1;row1<row2;i++)
	    {
		    if (column2>column1)
		   {
		   	for( j=column1+1;j<column2;j++)
			   {
		   	     if (gameBoarder[i][j]!=0)count++;}
	   		if (count==1&&gameBoarder[(abs(row2-row1)/2)+row1][((column2-column1)/2)+column1])return 1;
	   		 else return 0; 
		      }
		
	       
	        else{
	    	
			for(j=column2+1;j<column1;j++)
		   	   {
				  if (gameBoarder[i][j]!=0)count++;}
	   	    if (count==1&&gameBoarder[((row2-row1)/2)+row1][((column1-column2)/2)+column2])return 1;
	   	     else return 0; 
		      }   
	    }
	    
	   
       }
       
       
       
        else{
	    	
	    for(i=row2+1;row2<row1;i++)
		  {
		  	if (column2>column1)
		   {
		   	for(j=column1+1;j<column2;j++)
		   	{
			    if (gameBoarder[i][j]!=0)count++;
	   		
		    }
		    if (count==1&&gameBoarder[((row1-row2)/2)+row2][((column2-column1)/2)+column1])return 1;
		     else return 0; 
		}
		    else{
	    	
			for(j=column2+1;j<column1;j++)
			{
		   	    if (gameBoarder[i][j]!=0)count++;
	   		
		    }
		    if (count==1&&gameBoarder[((row1-row2)/2)+row2][((column1-column2)/2)+column2])return 1; 
			 else return 0;        
	    }
        }
      
     		
      
        }

   }   
   return 0; 
 }
}

	
	
	
	
	
	
	
	
	
	
	
void move(int gameBoarder[][10], int turn,int &simpleSw,int &swturn)//
{ // tabe marbot be harekat mohre ha dar safhe .

 
    int sw = 0;
    if (turn == 1)
    {
        printf("The turn of the first player:\n");
    }
    else
    {
        printf("The turn of the second player:\n");
    }
    while (sw == 0) // halqe daryaft mokhtasat aval .
    {
        printf("input your first statement:\n");
        scanf("%d %d", &row1, &column1);
        if (!swturn){
        	if (row1==row2&&column1==column2){
        		if (gameBoarder[row1][column1] != 0 && gameBoarder[row1][column1] == turn) // barresi mokhtasat dade shode .
                 {
                  sw = 1;
                }
            }  
		}
  
        else{
		     if (gameBoarder[row1][column1] != 0 && gameBoarder[row1][column1] == turn)sw = 1; // barresi mokhtasat dade shode .
  
        else
        {
            printf("mokhtasat dade shode , sahih nemibashad\n"); // khata ; khone ya khalie va ya tavassote mohre harif por shode .
        }
    }
	

    if (sw == 1)
    {
        int temp = gameBoarder[row1][column1];//
        gameBoarder[row1][column1] = 0; // khali kardane khone .
        sw = 0;
        while (sw == 0) // daryafte mokhtasate dovvom
        {
            printf("input your second statement:\n");
            scanf("%d %d", &row2, &column2);
            if (gameBoarder[row2][column2] == 0&&rule(row1,column1,row2,column2,gameBoarder,simpleSw,swturn)) // barresie khali bodane khane .//
            {
                gameBoarder[row2][column2] = temp; // jay gozarie mohre dar mokhtasat jadid .
                sw = 1;
            }
            else  //(gameBoarder[row][column] !=0)
            {
                printf("mokhtasat dade shode , sahih nemibashad\n"); // khata ; khone khali nist .
            }
        }
    }
    printf("\n");
}
}
void createArray(int beadsOrder[], int sizeOrder, int gameBoarder[][10])
{    //tabe chideman avalie mohre haye jadval.
    int size1 = sizeOrder - 1;
    int flag = 1;
    // player 1(A)
    for (int row = 0; row < maxSize; row++)
    {
        for (int column = 0; column < maxSize; column++)   //shorue harekat az khane aval jadval ba estefade az do halghe
        {
            gameBoarder[row][column] = 0; //meghdar dehie valie be har khane.
            if (row < sizeOrder  && column < size1)
            {
                gameBoarder[row][column] = 1;
            }
            else if (row == sizeOrder - 1 && flag)   //akharin ghanoon role ke haman sharayet khas.
            {
                flag = 0;
                int temp = beadsOrder[row];
                for (int k = (sizeOrder - temp) / 2, k1 = (sizeOrder - temp) / 2, k2 = 1; k2 <= temp ; k++, k1++, k2++)//line khas
                {
                    gameBoarder[row - k][k1] = 1;
                }
            }
        }
        size1--;
    }
    // player 2(B)
    flag = 1;
    int size2 = sizeOrder - 1;
    for (int row = maxSize - 1; row >= 0; row--)
    {
        for (int column = maxSize - 1; column >= 0; column--)   //shorue harekat az khane akhar jadval ba estefade az do halghe.
        {
            if (row >= sizeOrder && column >= maxSize - size2)
            {
                gameBoarder[row][column] = 2;
            }
            else if (row == (maxSize - 1) - (sizeOrder - 1) && flag)   //akharin ghanoon role ke haman sharayet khas.
            {
                flag = 0;
                int temp = beadsOrder[sizeOrder - 1];
                for (int k = (sizeOrder - temp) / 2, k1 = (maxSize - 1) - (sizeOrder - temp) / 2, k2 = 1; k2 <= temp ; k++, k1--, k2++)//line khas
                {
                    gameBoarder[row + k][k1] = 2;
                }
            }
        }
        size2--;
    }
}

void printfMap(int gameBoarder[][10])
{   //in tabe har bar mahal jadid har kodam az mohre ha ra chap mikonad.
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("player 1 = A       player 2 = B\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    for (int row = 0; row < maxSize; row++)
    {
        if(row<10){//chape shomare harkodam az sotun ha.
                printf(" %d  ", row);
        }else{
            printf(" %d ",row);
        }
    }
    printf("\n");
    for (int row = 0; row < maxSize; row++)
    {
        printf("+---"); //chape khotot har satr az jadval.
    }
    printf("+\n");
    for (int row = 0; row < maxSize; row++) //harekat bar ruye satr va sotun va chap vaziat har khane az jadval.
    {
        for (int column = 0; column < maxSize; column++)
        {
            if (gameBoarder[row][column] == 1)
            {
                printf("| A ");
            }
            else if (gameBoarder[row][column] == 2)
            {
                printf("| B ");
            }
            else //(gameBoarder[row][column] == 0)
            {
                printf("|   ");
            }
        }
        printf("| %d\n", row); //chape shomare harkodam az satr ha.
        for (int k = 0; k < maxSize; k++)
            printf("+---");
        printf("+\n");
    }
}


int turnGame(){ //tabe taein nobat.
  int turn;
  printf("if you want continue enter number player else enter 0:\n");
  scanf("%d",&turn);
  return turn;
}


int main()
{
    int sizeOrder;
    /*int size;
    printf("Please Enter size:\n");
    scanf("%d", &size); //size jadval.
    maxSize = size;*/
    int gameBoarder[10][10];
    printf("Please enter count role of game :\n");
    scanf("%d", &role);
    int beadsOrder[role];
    printf("Please input role of game :\n");
    for (int i = 0; i < role; i++) //halghe daryafte ghanoone chidane mohre ha.
    {
        scanf("%d", &beadsOrder[i]);
    }
    int sw = 1;
    int turn = 1;
    int simplesw=1;
    int swturn=1;
    createArray(beadsOrder, role , gameBoarder);
    printf("\n");
    printfMap(gameBoarder);
    printf("\n");
    int playcount1=1;
    int playcount2=0;
    
    while (sw != 0)
    {  //halghe tekrar bazi.
        
        move(gameBoarder, turn , simplesw,swturn);
        printfMap(gameBoarder);
        swturn=0;
        int check = turnGame();
        if (!check)
        {
            if (turn == 2)
            {
                turn = 1;
                playcount2++;
            }
            else
            {
            	turn = 2;
            	playcount1++;
            }
            
            simplesw=1;
            swturn=1;
        }
    }
    return 0;
}
