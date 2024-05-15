 //通讯录
 //1.通讯录中能够存放1000个人的信息
 //每个人的信息：
 //名字+年龄+性别+电话+地址
 //2.增加人的信息
 //3.删除指定人的信息
 //4.修改指定人的信息
 //5.查找指定人的信息
 //6.排序通讯录的信息
#include "test.h"
void InitContact(Contact* pc){
    pc->sz = 0;
    memset(pc->data,0,sizeof(pc->data));
}

void AddContact(Contact* pc){
    if(pc->sz==MAX){
        printf("FULL\n");
        return;
    }
    //增加一个人的信息
     printf("name:");
     scanf("%s",pc->data[pc->sz].name);
     printf("age:");
     scanf("%d",&(pc->data[pc->sz].age));
     printf("gender:");
     scanf("%s",pc->data[pc->sz].sex);
     printf("phone number:");
     scanf("%s",pc->data[pc->sz].tele);
     printf("address:");
     scanf("%s",pc->data[pc->sz].addr);
     pc->sz++;
     printf("success!\n");
}

void PrintContact(const Contact* pc){
    int i = 0;
    //打印标题
     printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n","name","age","gender","phone number","address");
    //打印数据
    for(i=0;i<pc->sz;i++){
        printf("%-10s\t%-5d\t%-5s\t%-12s\t%-20s\n",
               pc->data[i].name,
               pc->data[i].age,
               pc->data[i].sex,
               pc->data[i].tele,
               pc->data[i].addr);
    }
}

static int FindByName(Contact* pc,char name[]){
    int i = 0;
    for(i=0;i<pc->sz;i++){
        if(strcmp(pc->data[i].name,name)==0){
            return i;
        }
    }
    return -1;//找不到
}

void DelContact(Contact* pc){
    char name[MAX_NAME] = {0};

    if(pc->sz==0){
        printf("Empty File");
        return;
    }
     printf("name:");
    scanf("%s",name);
    //1.查找要删除的人
    //有/没有
    int pos = FindByName(pc,name);
    if(pos == -1){
        printf("non-existent\n");
        return;}
    //删除
    int i = 0;
    for(i=pos;i<pc->sz-1;i++){
       pc->data[i] = pc->data[i+1];
    }
    pc->sz--;
     printf("delete successful!\n");
}

void SearchContact(Contact* pc){
    char name[MAX_NAME] = {0};

    printf("name:");
    scanf("%s",name);
    //1.查找人
    //有/没有
    int pos = FindByName(pc,name);
    if(pos == -1){
        printf("non-existent\n");
        return;}
    else{
        printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n","name","age","gender","phone number","address");
        //打印数据
            printf("%-10s\t%-5d\t%-5s\t%-12s\t%-20s\n",
                   pc->data[pos].name,
                   pc->data[pos].age,
                   pc->data[pos].sex,
                   pc->data[pos].tele,
                   pc->data[pos].addr);
    }
}

 void ModifyContact(Contact* pc){
     char name[MAX_NAME] = {0};

     printf("name:");
     scanf("%s",name);
     //1.查找人
     //有/没有
     int pos = FindByName(pc,name);
     if(pos == -1){
         printf("non-existent\n");
         return;}
     else{
         printf("name:");
         scanf("%s",pc->data[pos].name);
         printf("age:");
         scanf("%d",&(pc->data[pos].age));
         printf("gender:");
         scanf("%s",pc->data[pos].sex);
         printf("phone number:");
         scanf("%s",pc->data[pos].tele);
         printf("address:");
         scanf("%s",pc->data[pos].addr);
         printf("success!\n");
     }

}

 void BubbleSort(Contact* pc)
{
    int i, j;
    int yxx = 0;
    PeoInfo tmp = {0};
     for (i = 0; i < pc->sz - 1; i++) {
         for (j = 0; j < pc->sz - i - 1; j++) {
             yxx = strcmp(pc->data[j].name , pc->data[j+1].name);
             if (yxx>0){
                 tmp = pc->data[j];
                 pc->data[j] = pc->data[j+1];
                 pc->data[j+1] = tmp;
             }
         }
     }
     printf("OK");
}
