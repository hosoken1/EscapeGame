#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAP_Length 10//マップの大きさ
#define X 1
#define Y 0
void MAP_init();
void MAP_print();
void Player_Move(char);
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
int PlayerTrans[2] = {0,1};//プレイヤーの位置を表す（y,x）
int GoalTrans[2] = {9,9};//ゴールの位置を表す
int main(void){
    char input;
    while(1){
        MAP_print();//マップの描画
        if(PlayerTrans[X] == GoalTrans[X] && PlayerTrans[Y] == GoalTrans[Y]){
            printf("ゴールしました！");
            break;
        }
        scanf(" %c",&input);
        if(input == 'q'){
            printf("ゲームを終了します。");
            break;
        }
        Player_Move(input);
    }
    Sleep(3000);
    return 0;
}

void MAP_print(){
    system("cls");
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

void Player_Move(char input){
    MAP[PlayerTrans[Y]][PlayerTrans[X]] = 1;//プレイヤーのいた位置を１に初期化する
    if(input == 'w'){
        if(PlayerTrans[Y]-1 >= 0 && MAP[PlayerTrans[Y]-1][PlayerTrans[X]] != 0)PlayerTrans[Y]-=1;
    }
    else if(input == 's'){
        if(PlayerTrans[Y]+1 < MAP_Length && MAP[PlayerTrans[Y]+1][PlayerTrans[X]] != 0)PlayerTrans[Y]+=1;
    }
    else if(input == 'a'){
        if(PlayerTrans[X]-1 >= 0 && MAP[PlayerTrans[Y]][PlayerTrans[X]-1] != 0)PlayerTrans[X]-=1;
    }
    else if(input == 'd'){
        if(PlayerTrans[X]+1 >= 0 && MAP[PlayerTrans[Y]][PlayerTrans[X]+1] != 0)PlayerTrans[X]+=1;
    }
    MAP[PlayerTrans[Y]][PlayerTrans[X]] = 2;
}