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

void LoadContact(Contact* pc){
    FILE * pf = fopen("contact.dat","r");
     if(pf == NULL)
     {
         perror("LoadContact");
         return;
     }
     //读文件
     PeoInfo tmp = {0};
     while(fread(&tmp,sizeof(PeoInfo),1,pf)){
         //考虑增容
         CheckCapacity(pc);
         pc->data[pc->sz] = tmp;
         pc->sz++;
     }
     //关闭文件
    fclose(pf);
    pf = NULL;
}

//动态版本初始化
void InitContact(Contact* pc){
    pc->data = (PeoInfo*)malloc(DEFAULT_SZ*sizeof(PeoInfo));
    if(pc->data == NULL){
        perror("InitContact");
        return;
    }
    pc->sz = 0;//初始化后默认是0
    pc->capacity = DEFAULT_SZ;

    //加载文件
    LoadContact(pc);
}

void SaveContact(Contact* pc)
{
    //打开文件
    FILE* pf = fopen("Contact.dat","w");
    if(pf == NULL)
    {
        perror("SaveContact");
        return;
    }
    //写文件
    int i = 0;
    for(i=0;i<pc->sz;i++)
    {
        fwrite(pc->data+i,sizeof(PeoInfo),1,pf);
    }
    //关闭文件
    fclose(pf);
    pf = NULL;
    printf("save successful");
}



void DestoryContact(Contact* pc){
    //把data所指向的空间释放掉
    free(pc->data);
    pc->data = NULL;
    pc->sz = 0;
    pc->capacity = 0;
}

void CheckCapacity(Contact* pc){
    //考虑增容
    if(pc->sz==pc->capacity){
        PeoInfo*ptr = realloc(pc->data,(pc->capacity + INC_SZ)*sizeof(PeoInfo));
        if(ptr!=NULL){
            pc->data = ptr;
            pc->capacity += INC_SZ;
        }
        else{
            perror("AddContact");
            printf("fail ——");
            return;
        }
    }
}

void AddContact(Contact* pc){
    //考虑增容
    CheckCapacity(pc);
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
    printf("OK\n");
}