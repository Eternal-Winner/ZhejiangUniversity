
#include <iostream>
using namespace std;

typedef struct polyNode* polynomial;
struct polyNode{    //polynomial
    int coef;   //coefficient
    int expo;   //exponent
    polynomial next;
};

void Attach(polynomial *polyRear,int coef,int expo);   //Attaching a term to poly.
polynomial readPoly();
polynomial multiplyPoly(polynomial poly1,polynomial poly2);
polynomial sumPoly(polynomial poly1, polynomial poly2);
void printPoly(polynomial P);

int main() {
    polynomial P1,P2,P3,P4;
    P1 = readPoly();
    P2 = readPoly();
    P3 = multiplyPoly(P1,P2);
    P4 = sumPoly(P1,P2);
    printPoly(P3);
    cout << endl;
    printPoly(P4);

    return 0;
}

polynomial readPoly()
{
    polynomial P, Tear,temp;
    int amount,coef,expo;

    cin >> amount;
    P = new polyNode; Tear = P; Tear->next = nullptr;
    for(int i = 0; i < amount; i++){
        cin >> coef >> expo;
        Attach(&Tear,coef,expo);
    }
    temp = P;
    P = P->next;
    delete temp;

    return P;
}

void Attach(polynomial *polyRear,int coef,int expo)
{
    polynomial tempPoly = new polyNode;//malloc()
    tempPoly->coef = coef;
    tempPoly->expo = expo;
    tempPoly->next = nullptr;//NULL
    (*polyRear)->next = tempPoly;
    *polyRear = tempPoly;
}

polynomial multiplyPoly(polynomial poly1,polynomial poly2)
{
    polynomial t1, t2, temp,front, rear;
    t1 = poly1;   t2 = poly2;
    int coef,expo;
    front = new polyNode;    front->next = nullptr;
    rear = front;

    if(!poly1 || !poly2)  return nullptr;   //如果有一个多项式为0；返回空指针

    while (t1){
        rear = front;   t2 = poly2;
        while(t2){
            coef = t1->coef * t2->coef;
            expo = t1->expo + t2->expo;
            while (rear->next && rear->next->expo > expo)
                rear = rear->next;
            if(rear->next && rear->next->expo == expo){
                if(coef + rear->next->coef) {  //系数相加不为0
                    rear->next->coef += coef;
                }
                else{
                    temp = rear->next;
                    rear->next = rear->next->next;
                    delete temp;
                }
            }
            else{//rear->next-expo < expo
                temp = new polyNode;
                temp->coef = coef;  temp->expo = expo;
                temp->next = rear->next;
                rear->next = temp;      //将指针尾移动到temp的位置
                rear = rear->next;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    temp = front;
    front = front->next;
    delete temp;

    return front;
}

polynomial sumPoly(polynomial poly1, polynomial poly2)
{
    polynomial front, rear, temp;
    int sum;
    front = new polyNode;   front->next = nullptr;  front->expo = 0; front->coef = 0;
    rear = front;

    while (poly1 && poly2){
        if(poly1->expo > poly2->expo){
            Attach(&rear,poly1->coef,poly1->expo);
            poly1 = poly1->next;
        }
        else if(poly1->expo == poly2->expo){
            sum = poly1->coef + poly2->coef;
            if(sum) Attach(&rear,sum,poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1->expo < poly2->expo){
            Attach(&rear,poly2->coef,poly2->expo);
            poly2 = poly2->next;
        }
    }
    for(;poly1;poly1->next){ Attach(&rear,poly1->coef,poly1->expo); poly1=poly1->next;}
    for(;poly2;poly2->next){ Attach(&rear,poly2->coef,poly2->expo); poly2=poly2->next;}

    temp = front;
    front = front->next;
    delete temp;


    return  front;

}

void printPoly(polynomial P)
{
    polynomial temp = P;

    if(!P) cout << "0 0";

    while(temp){

        if(!temp->next){
            cout << temp->coef <<" "<< temp->expo;
        }//为指针的最后一项，输出结果后不再输入空格
        else{
            cout << temp->coef <<" "<< temp->expo << " ";
        }

        temp = temp->next;
    }
}


/*这是失败的代码
 * polynomial temp1 = poly1, temp2 = poly2, temp = nullptr;
    polynomial  result = new polyNode; result->next = nullptr;
    temp1 = temp1->next;    temp2 = temp2->next;  //Jumping the first void-node;

    for(temp1 && temp2){ //  If the temp1 and temp2 is not-nullptr,being compared two polynomial and move the pointer afterward;
        if(temp1->expo > temp2->expo){//The temp1 as a result return;
            result->next = temp1; temp1 = temp1->next;
            result->next = nullptr;
        }
        else if(temp1->expo == temp2->expo){
            if(temp1->coef + temp2->coef == 0){ //指数相同的两个多项式系数相加为0，释放空间并且将指针向后移动
                temp = temp1; temp1 = temp1->next; delete temp;
                temp = temp2; temp2 = temp2->next; delete temp;
            }else{
                temp1->coef = temp1->coef + temp2->coef;
                result = temp1; temp1 = temp1->next;
                result->next = nullptr;
                temp = temp2; temp2 = temp2->next; delete temp;
            }
        }
        else{//temp->expo < temp2->expo;
            result->next = temp2;   temp2 = temp2->next;
        }
    }
    if(temp1){result->next = temp1;}
    if(temp2){result->next = temp2;}
    return result;
 * */



