#include<stdio.h>
#include<stdlib.h>
#define MAP_Length 10
void MAP_init();
void MAP_print();
// マップの情報　０が壁　１が通れるところ　
// ２がプレイヤー　３がゴール
int MAP[10][10] = {{1,2,1,0,1,0,1,1,1,1},
                   {0,1,0,0,1,1,0,1,0,1},
                   {1,1,0,0,1,0,0,1,0,0},
                   {0,1,1,1,1,1,1,1,1,1},
                   {0,1,0,0,0,0,1,0,0,0},
                   {1,1,0,1,0,0,1,0,0,1},
                   {0,1,1,1,1,1,1,1,1,1},
                   {0,1,0,0,0,1,0,0,1,0},
                   {1,1,1,1,1,1,1,0,1,0},
                   {0,1,0,1,0,0,0,0,1,3}};
int main(void){
    char input;
    while(1){
        //system("cls");//画面のクリア
        MAP_print();//マップの描画
        scanf("%c",&input);
        if(input == 'q')break;
    }
    return 0;
}

void MAP_print(){
    //system("cls");
    for(int i=0;i<MAP_Length;i++){
        for(int j=0;j<MAP_Length;j++){
            if(MAP[i][j] == 0)
            {
                printf("■");
            }
            else if(MAP[i][j] == 1){
                printf("　");
            }
            else if(MAP[i][j] == 2){
                printf("◎");
            }
            else if(MAP[i][j] == 3){
                printf("◆");
            }
        }
        printf("\n");
    }
}