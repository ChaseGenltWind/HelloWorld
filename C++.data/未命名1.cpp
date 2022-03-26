#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char    id[15];
    char    name[15];
    int     score;
}Data;
/* �����������Ľڵ�ṹ���� */
typedef struct BiTNode
{
    Data student;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Data buff[7];       //�ṹ�����飬���������������Ľڵ�����
int N = 0;          //�趨ȫ�ֵ�������
char ID[7][15];     //��������ı��ļ���������
char Name[7][15];   //��������ı��ļ����������
int Sum[7];         //��������ı��ļ�����ĳɼ�

//��������
void ImportData();       //�ļ�������
int SearchBST(BiTree T, int score, BiTree f, BiTree *p);//�ڵ�Ĳ���
int InsertBST(BiTree *T, char id[],char name[],int score);//�ڵ�Ĳ���
void Preface_order(BiTree t);                   //�������������������
void Middle_order(BiTree t);                    //�������������������
void Last_order(BiTree t);                      //�����������ĺ������
void WriteBinary();                             //д��������ļ�
void ReaderBinary();                            //�����������ļ�����
void destroy_BSTree(BiTree t);                  //���ٶ���������

int main()
{

    int i = 0;
    BiTree T = NULL;
    ImportData();            //���ļ����ݵ���������  
    for (i = 0; i < 7; i++) {
        InsertBST(&T,ID[i],Name[i],Sum[i]);//���������������ӽڵ�
    }

    printf("�������������������\n");
    Preface_order(T);               //�������
    printf("�������������������\n");
    Middle_order(T);               //�������
    printf("�������������������\n");
    Last_order(T);               //�������

    WriteBinary();               //д��������ļ�
    printf("����������ļ���\n");
    ReaderBinary();              //��ȡ�������ļ�

    destroy_BSTree(T);           //������
}

//���������������㷨
int SearchBST(BiTree T, int score, BiTree f, BiTree *p) {
    //��� T ָ��Ϊ�գ�˵������ʧ�ܣ��� p ָ��ָ����ҹ��������һ��Ҷ�ӽ�㣬�����ز���ʧ�ܵ���Ϣ
    if (!T) {
        *p = f;
        return 0;
    }
    //�����ȣ��� p ָ��ָ��ùؼ��֣������ز��ҳɹ���Ϣ
    else if (score == T->student.score) {
        *p = T;
        return 1;
    }
    //��� key ֵ�� T ������ֵС�������������������֮��������������
    else if (score < T->student.score) {
        return SearchBST(T->lchild, score, T, p);
    }
    else {
        return SearchBST(T->rchild, score, T, p);
    }
}

int InsertBST(BiTree *T, char id[],char name[],int score) {
    BiTree p = NULL;
    //������Ҳ��ɹ��������������
    if (!SearchBST((*T), score, NULL, &p)) {
        //��ʼ��������
        BiTree s = (BiTree)malloc(sizeof(BiTNode)); 
        strcpy(s->student.id, id);
        strcpy(s->student.name,name);
        s->student.score = score;
        s->lchild = s->rchild = NULL;
        //��� p ΪNULL��˵���ö���������Ϊ��������ʱ����Ľ��Ϊ�������ĸ����
        if (!p) {
            *T = s;
        }
        //��� p ��Ϊ NULL���� p ָ���Ϊ����ʧ�ܵ����һ��Ҷ�ӽ�㣬ֻ��Ҫͨ���Ƚ� p �� e ��ֵȷ�� s ������ p �����ӻ����Һ���
        else if (score < p->student.score) {
            p->lchild = s;
        }
        else {
            p->rchild = s;
        }
        return 1;
    }
    //������ҳɹ�������Ҫ���������������ʧ��
    return 0;
}

void Preface_order(BiTree t)//�������
{
    if (t == NULL) {
        return;
    }
    printf("%s %s %d\n",t->student.id,t->student.name,t->student.score);
    Preface_order(t->lchild);
    Preface_order(t->rchild);
}
void Middle_order(BiTree t)//�������
{
    if (t == NULL) {
        return ;
    }
    Middle_order(t->lchild);
    printf("%s %s %d\n",t->student.id,t->student.name,t->student.score);
    //������������ݴ�ŵ��ṹ��������
    strcpy(buff[N].name,t->student.name); 
    strcpy(buff[N].id,t->student.id); 
    buff[N].score = t->student.score;
    N++;

    Middle_order(t->rchild);
}
void Last_order(BiTree t)//�������
{
    if (t == NULL) {
        return;
    }
    Last_order(t->lchild);
    Last_order(t->rchild);
    printf("%s %s %d\n",t->student.id,t->student.name,t->student.score);
}

void WriteBinary()
{
    FILE * pFile = fopen ("BinaryTree.txt", "wb");

    if(!pFile)
    {
        printf("�Ҳ����ļ���");
        exit(0);
    }
    int i;
    for(i=0;i<7;i++)
    {
        if(fwrite(&buff[i],sizeof(Data),1,pFile)!=1)
            printf("�ļ���д����\n");
    }
    printf("����д��ɹ���");
    fclose (pFile);
}

void ReaderBinary()
{
    FILE * fp = fopen("BinaryTree.txt","rb");
    Data per;
    if(!fp)
    {
      printf("�Ҳ����ļ���");
      exit(0);
    }
    
    printf("���ݶ���ɹ���");
    while(fread(&per,sizeof(Data),1,fp)==1)   //����������ݣ�����ʾ�������˳�
    {
        printf("%s %s %d\n",per.id,per.name,per.score);
    }
    fclose(fp);
}

void destroy_BSTree(BiTree t)       //������
{
	if(t)
	{
		if(t->lchild)
			destroy_BSTree(t->lchild);
		if(t->rchild)
			destroy_BSTree(t->rchild);
		free(t);
		t = NULL;
	}
}


void ImportData() {          //���ļ����ݵ����ݴ�ŵ�������
    FILE *fp=NULL;
    int i=0,score = 0;
    char str1[15],str2[15];

    fp=fopen("DataBase.txt","r");
    while(fscanf(fp,"%s%s%d",str1,str2,&score)!=-1)
    {
        strcpy(ID[i],str1);
        strcpy(Name[i],str2);
        Sum[i]=score;
        i++;
    }  

    fclose(fp);
}
