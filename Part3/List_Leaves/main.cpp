
#include <iostream>

using namespace std;

#define MaxTree 10
#define MaxSize 10
#define Tree int
#define Null -1
#define ElementType int
int check[10];

typedef  struct TreeNode* pTree;
struct TreeNode{
    Tree Left;
    Tree Right;
}T1[MaxTree];
struct QNode{
    ElementType Data[MaxSize];
    int rear;
    int front;
}Q;
typedef QNode* Queue;

Queue Que = &Q;
int N;

Tree BuildTree(TreeNode *T);
void LevelOrderTraversal( int root );
Queue InitQueue(Queue Q);
void  AddQ(Queue Q,ElementType item);
ElementType DeleteQ(Queue Q);
int IsEmpty(Queue Q);

int main() {
    Tree R1;


    R1 = BuildTree(T1);

    LevelOrderTraversal(R1);

    return 0;
}


Tree BuildTree(TreeNode *T)
{
    int  i;
    Tree  Root = Null;  //初始化为空树
    char cr,cl;
    //for(i = 0;i < MaxTree;i++) check[i] = 0;


    cin >> N;
    if(N){

        for(i = 0;i < N; i++){
            cin  >> cl >> cr;
            if(cl != '-'){
                T[i].Left = cl-'0';
                check[T[i].Left] = 1;
            }
            else T[i].Left = Null;
            // /*对cr的对应处理*/
            if(cr != '-'){
                T[i].Right = cr-'0';
                check[T[i].Right] = 1;
            }
            else T[i].Right = Null;
        }
        for(i = 0;i < N; i++)
            if(!check[i]) break;
        Root = i;//T[i]中没有任何节点的left 和right(cr)指向它。只有一个
    }

    return Root;
}

void LevelOrderTraversal(int root)
{
    int T;

    if(root == Null) return ;
    InitQueue(Que);
    AddQ(Que,root);
    while (!(IsEmpty(Que))){
        T = DeleteQ(Que);
        N -= 1;
        if(T1[T].Left != Null) AddQ(Que,T1[T].Left);
        if(T1[T].Right != Null) AddQ(Que,T1[T].Right);
        if(T1[T].Right == Null && T1[T].Left == Null){
            cout << T;
            if(N) cout << " ";
        }
    }
}

Queue InitQueue(Queue Q)
{
    Q->front = Q->rear = -1;

}
void  AddQ(Queue Q,ElementType item)
{
    if((Q->rear + 1) % MaxSize == Q->front){
        cout << "队列满";
        return ;
    }
    Q->rear = (Q->rear+1) % MaxSize;
    Q->Data[Q->rear] = item;
}
ElementType DeleteQ(Queue Q)
{
    if(Q->front == Q->rear) {
        cout << "队列空";
        return 0;
    } else{
        Q->front = (Q->front+1) % MaxSize;
        return Q->Data[Q->front];
    }
}
int IsEmpty(Queue Q)
{
    if (Q->rear == Q->front) return 1;
    else return 0;
}



/*
 #include<stdio.h>
struct node{   //数组用来存储二叉树
	int data;
	int left;
	int right;
}tr[10];

int main()
{
	int N,i,M=0;
	int check[10]={0};
	scanf("%d",&N);
	getchar();                         //读入换行符
	for(i=0;i<N;i++){
		char l,r;
	    scanf("%c %c",&l,&r);        //读入左右孩子
	    getchar();
	    if(l=='-'&&r=='-')M++;        //叶子节点个数
	    tr[i].data=i;                  //节点数据
	    tr[i].left=l=='-'?-1:l-'0';
	    tr[i].right=r=='-'?-1:r-'0';
	    if(l!='-')check[l-'0']=1;     //查找根节点
	    if(r!='-')check[r-'0']=1;
	}
	int queue[10]={0},rear=-1,front=-1;   //设置队列，按层次输出
	struct node p;
	for(i=0;i<N;i++)         //根节点
	{
	    if(check[i]==0)queue[++rear]=i;    //队尾插入根节点
	}
	while(front!=rear){                       //队列不为空
		p=tr[queue[++front]];                 //队头取出节点
		if(p.left!=-1)queue[++rear]=p.left;   //队尾插入左孩子
		if(p.right!=-1)queue[++rear]=p.right; //队尾插入右孩子
		if(p.left==-1&&p.right==-1){          //输出叶子节点
		    printf("%d",p.data);
		    M--;
		    if(M)printf(" ");
		}
	}
	return 0;
}

*/