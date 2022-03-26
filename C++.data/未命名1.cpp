#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char    id[15];
    char    name[15];
    int     score;
}Data;
/* 二叉排序树的节点结构定义 */
typedef struct BiTNode
{
    Data student;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Data buff[7];       //结构体数组，用来存放中序输出的节点内容
int N = 0;          //设定全局迭代变量
char ID[7][15];     //用来存放文本文件导入的序号
char Name[7][15];   //用来存放文本文件导入的名字
int Sum[7];         //用来存放文本文件导入的成绩

//声明函数
void ImportData();       //文件的输入
int SearchBST(BiTree T, int score, BiTree f, BiTree *p);//节点的查找
int InsertBST(BiTree *T, char id[],char name[],int score);//节点的查找
void Preface_order(BiTree t);                   //二叉排序树的先序输出
void Middle_order(BiTree t);                    //二叉排序树的中序输出
void Last_order(BiTree t);                      //二叉排序树的后续输出
void WriteBinary();                             //写入二进制文件
void ReaderBinary();                            //读出二进制文件内容
void destroy_BSTree(BiTree t);                  //销毁二叉排序树

int main()
{

    int i = 0;
    BiTree T = NULL;
    ImportData();            //将文件内容导入数组中  
    for (i = 0; i < 7; i++) {
        InsertBST(&T,ID[i],Name[i],Sum[i]);//在排序二叉树中添加节点
    }

    printf("先序遍历二叉排序树：\n");
    Preface_order(T);               //先序输出
    printf("中序遍历二叉排序树：\n");
    Middle_order(T);               //中序输出
    printf("后序遍历二叉排序树：\n");
    Last_order(T);               //后序输出

    WriteBinary();               //写入二进制文件
    printf("输出二进制文件：\n");
    ReaderBinary();              //读取二进制文件

    destroy_BSTree(T);           //销毁树
}

//二叉排序树查找算法
int SearchBST(BiTree T, int score, BiTree f, BiTree *p) {
    //如果 T 指针为空，说明查找失败，令 p 指针指向查找过程中最后一个叶子结点，并返回查找失败的信息
    if (!T) {
        *p = f;
        return 0;
    }
    //如果相等，令 p 指针指向该关键字，并返回查找成功信息
    else if (score == T->student.score) {
        *p = T;
        return 1;
    }
    //如果 key 值比 T 根结点的值小，则查找其左子树；反之，查找其右子树
    else if (score < T->student.score) {
        return SearchBST(T->lchild, score, T, p);
    }
    else {
        return SearchBST(T->rchild, score, T, p);
    }
}

int InsertBST(BiTree *T, char id[],char name[],int score) {
    BiTree p = NULL;
    //如果查找不成功，需做插入操作
    if (!SearchBST((*T), score, NULL, &p)) {
        //初始化插入结点
        BiTree s = (BiTree)malloc(sizeof(BiTNode)); 
        strcpy(s->student.id, id);
        strcpy(s->student.name,name);
        s->student.score = score;
        s->lchild = s->rchild = NULL;
        //如果 p 为NULL，说明该二叉排序树为空树，此时插入的结点为整棵树的根结点
        if (!p) {
            *T = s;
        }
        //如果 p 不为 NULL，则 p 指向的为查找失败的最后一个叶子结点，只需要通过比较 p 和 e 的值确定 s 到底是 p 的左孩子还是右孩子
        else if (score < p->student.score) {
            p->lchild = s;
        }
        else {
            p->rchild = s;
        }
        return 1;
    }
    //如果查找成功，不需要做插入操作，插入失败
    return 0;
}

void Preface_order(BiTree t)//先序输出
{
    if (t == NULL) {
        return;
    }
    printf("%s %s %d\n",t->student.id,t->student.name,t->student.score);
    Preface_order(t->lchild);
    Preface_order(t->rchild);
}
void Middle_order(BiTree t)//中序输出
{
    if (t == NULL) {
        return ;
    }
    Middle_order(t->lchild);
    printf("%s %s %d\n",t->student.id,t->student.name,t->student.score);
    //将中序输出内容存放到结构体数组中
    strcpy(buff[N].name,t->student.name); 
    strcpy(buff[N].id,t->student.id); 
    buff[N].score = t->student.score;
    N++;

    Middle_order(t->rchild);
}
void Last_order(BiTree t)//后序输出
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
        printf("找不到文件！");
        exit(0);
    }
    int i;
    for(i=0;i<7;i++)
    {
        if(fwrite(&buff[i],sizeof(Data),1,pFile)!=1)
            printf("文件读写错误！\n");
    }
    printf("数据写入成功！");
    fclose (pFile);
}

void ReaderBinary()
{
    FILE * fp = fopen("BinaryTree.txt","rb");
    Data per;
    if(!fp)
    {
      printf("找不到文件！");
      exit(0);
    }
    
    printf("数据读入成功：");
    while(fread(&per,sizeof(Data),1,fp)==1)   //如果读到数据，就显示；否则退出
    {
        printf("%s %s %d\n",per.id,per.name,per.score);
    }
    fclose(fp);
}

void destroy_BSTree(BiTree t)       //销毁树
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


void ImportData() {          //将文件数据的内容存放到数组中
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
