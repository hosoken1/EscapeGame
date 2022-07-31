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
int MAP[MAP_Length][MAP_Length]  = {{0,0,0,0,0,0,0,0,0,0},
                                    {0,2,0,0,1,1,0,1,0,0},
                                    {0,1,0,0,1,0,0,1,0,0},
                                    {0,1,1,1,1,1,1,1,1,0},
                                    {0,1,0,0,0,0,1,0,0,0},
                                    {0,1,0,1,0,0,1,0,0,0},
                                    {0,1,1,1,1,1,1,1,1,0},
                                    {0,1,0,0,0,1,0,0,1,0},
                                    {0,1,1,1,1,1,1,0,1,3},
                                    {0,0,0,0,0,0,0,0,0,0}};
//マップの可視化情報　０：不可視　１：可視
int MAP_visible[MAP_Length][MAP_Length] =  {{0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0}};
int PlayerTrans[2] = {1,1};//プレイヤーの位置を表す（y,x）
int GoalTrans[2] = {8,9};//ゴールの位置を表す
int main(void){
    char input;
    MAP_init();
    while(1){
        MAP_print();//マップの描画
        if(PlayerTrans[X] == GoalTrans[X] && PlayerTrans[Y] == GoalTrans[Y]){
            printf("脱出成功！");
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
void MAP_init(){
    //プレイヤーを可視化
    MAP_visible[PlayerTrans[Y]][PlayerTrans[X]] = 1;
    MAP_visible[GoalTrans[Y]][GoalTrans[X]] = 1;
}

void MAP_print(){
    system("cls");
    printf("脱出口を目指せ！\nプレイヤー:◎　脱出口:◆\n");
    for(int i=0;i<MAP_Length;i++){
        for(int j=0;j<MAP_Length;j++){
            if(MAP[i][j] == 1 || MAP_visible[i][j] == 0)
            {
                printf("　");
            }
            else if(MAP[i][j] == 0){
                printf("■");
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
    printf("w a s d + Enterで移動、qで終了\n");
}

void Player_Move(char input){
    MAP[PlayerTrans[Y]][PlayerTrans[X]] = 1;//プレイヤーのいた位置を１に初期化する
    if(input == 'w'){
        MAP_visible[PlayerTrans[Y]-1][PlayerTrans[X]] = 1;
        if(PlayerTrans[Y]-1 >= 0 && MAP[PlayerTrans[Y]-1][PlayerTrans[X]] != 0)
        {
            PlayerTrans[Y]-=1;
        }
    }
    else if(input == 's'){
        MAP_visible[PlayerTrans[Y]+1][PlayerTrans[X]] = 1;
        if(PlayerTrans[Y]+1 < MAP_Length && MAP[PlayerTrans[Y]+1][PlayerTrans[X]] != 0)
        {
            PlayerTrans[Y]+=1;
        }
    }
    else if(input == 'a'){
        MAP_visible[PlayerTrans[Y]][PlayerTrans[X]-1] = 1;
        if(PlayerTrans[X]-1 >= 0 && MAP[PlayerTrans[Y]][PlayerTrans[X]-1] != 0)
        {
            PlayerTrans[X]-=1;
        }
    }
    else if(input == 'd'){
        MAP_visible[PlayerTrans[Y]][PlayerTrans[X]+1] = 1;
        if(PlayerTrans[X]+1 >= 0 && MAP[PlayerTrans[Y]][PlayerTrans[X]+1] != 0)
        {
            PlayerTrans[X]+=1;
        }
    }
    MAP[PlayerTrans[Y]][PlayerTrans[X]] = 2;
    //MAP_visible[PlayerTrans[Y]][PlayerTrans[X]] = 1;
}