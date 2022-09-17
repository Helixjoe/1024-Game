#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//functions used
void display(int arr[4][4]);
void UP(int arr[4][4]);
int quitcheck(int arr[4][4]);
void spawn(int arr[4][4]);

int main(){
    int i,j,arr[4][4],choice,cont = 1;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            arr[i][j] = 0;
        }
    }
    spawn(arr);
    
    display(arr);
    
    while(cont==1)
    {
        scanf("%d",&choice);
        if (choice == 1)
        {
            UP(arr);
            display(arr);
            spawn(arr);
        }
        else if(choice == 4){
            cont = 0;
        }

        if (quitcheck(arr)==0){
            cont = 0;
            printf("GAME OVER");
            }
    
    }

    return 0;

}

void display(int arr[4][4]){
int i,j;
for(i=0;i<4;i++){

        printf("\n");
        for(j=0;j<4;j++){
            printf("| %d ",arr[i][j]);
        }
        printf("|\n");
    }
    
    printf("\n");
}

void UP(int arr[4][4]){
    int r,c,next;
    for(r=3;r>0;r--)
    {
            
        for(c=0;c<4;c++)
        {
            next = arr[r-1][c];
            if (next == arr[r][c]){
                arr[r-1][c] = 2 * arr[r][c];
                arr[r][c] =  0; 
            }
            else if(next == 0){
                arr[r-1][c] = arr[r][c];
                arr[r][c] =  0; 
            }
            else
                continue;
        }
    }
    
}

int quitcheck(int arr[4][4])
{
    int i,j,count=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(arr[i][j]!=0)
                count+= 1;
        }
    }
    if(count == 16)
        return 0;
    else 
        return 1;
}

void spawn(int arr[4][4]){
    int i,x,y,x1,y1;
    srand(time(0));
    for(i =0;i<2;i++){
    x = rand()%3;  
    y = rand()%3;
    if(x1 == x && y1 == y)
        if(x<3 && y<3)
        {
            x += 1;  
            y += 1;
        }
        else{
            x -= 1;  
            y -= 1;
        }

    arr[x][y] = 2;
    x1 = x;
    y1 = y;
    }
}