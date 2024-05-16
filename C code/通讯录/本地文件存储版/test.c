 //ͨѶ¼
 //1.ͨѶ¼���ܹ����1000���˵���Ϣ
 //ÿ���˵���Ϣ��
 //����+����+�Ա�+�绰+��ַ
 //2.�����˵���Ϣ
 //3.ɾ��ָ���˵���Ϣ
 //4.�޸�ָ���˵���Ϣ
 //5.����ָ���˵���Ϣ
 //6.����ͨѶ¼����Ϣ
#include "test.h"

void LoadContact(Contact* pc){
    FILE * pf = fopen("contact.dat","r");
     if(pf == NULL)
     {
         perror("LoadContact");
         return;
     }
     //���ļ�
     PeoInfo tmp = {0};
     while(fread(&tmp,sizeof(PeoInfo),1,pf)){
         //��������
         CheckCapacity(pc);
         pc->data[pc->sz] = tmp;
         pc->sz++;
     }
     //�ر��ļ�
    fclose(pf);
    pf = NULL;
}

//��̬�汾��ʼ��
void InitContact(Contact* pc){
    pc->data = (PeoInfo*)malloc(DEFAULT_SZ*sizeof(PeoInfo));
    if(pc->data == NULL){
        perror("InitContact");
        return;
    }
    pc->sz = 0;//��ʼ����Ĭ����0
    pc->capacity = DEFAULT_SZ;

    //�����ļ�
    LoadContact(pc);
}

void SaveContact(Contact* pc)
{
    //���ļ�
    FILE* pf = fopen("Contact.dat","w");
    if(pf == NULL)
    {
        perror("SaveContact");
        return;
    }
    //д�ļ�
    int i = 0;
    for(i=0;i<pc->sz;i++)
    {
        fwrite(pc->data+i,sizeof(PeoInfo),1,pf);
    }
    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    printf("save successful");
}



void DestoryContact(Contact* pc){
    //��data��ָ��Ŀռ��ͷŵ�
    free(pc->data);
    pc->data = NULL;
    pc->sz = 0;
    pc->capacity = 0;
}

void CheckCapacity(Contact* pc){
    //��������
    if(pc->sz==pc->capacity){
        PeoInfo*ptr = realloc(pc->data,(pc->capacity + INC_SZ)*sizeof(PeoInfo));
        if(ptr!=NULL){
            pc->data = ptr;
            pc->capacity += INC_SZ;
        }
        else{
            perror("AddContact");
            printf("fail ����");
            return;
        }
    }
}

void AddContact(Contact* pc){
    //��������
    CheckCapacity(pc);
    //����һ���˵���Ϣ
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
    //��ӡ����
     printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n","name","age","gender","phone number","address");
    //��ӡ����
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
    return -1;//�Ҳ���
}

void DelContact(Contact* pc){
    char name[MAX_NAME] = {0};

    if(pc->sz==0){
        printf("Empty File");
        return;
    }
     printf("name:");
    scanf("%s",name);
    //1.����Ҫɾ������
    //��/û��
    int pos = FindByName(pc,name);
    if(pos == -1){
        printf("non-existent\n");
        return;}
    //ɾ��
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
    //1.������
    //��/û��
    int pos = FindByName(pc,name);
    if(pos == -1){
        printf("non-existent\n");
        return;}
    else{
        printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n","name","age","gender","phone number","address");
        //��ӡ����
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
     //1.������
     //��/û��
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