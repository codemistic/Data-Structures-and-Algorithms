// Github username: Ansh-Kushwaha
// Aim: To store and add polynomials
// Date: 05/10/2022


#include <iostream>
using namespace std;

struct term{ 
    int pow, coeff;
    term *next;
};

typedef struct polynomial{
    term* addTerm(term *first, int p, int c){  //adding term to the polynomial
        if(p<0){
            cout << "Undefined power" << endl;
            return first;
        }
        if(first == NULL){
            term *tmp = new term;
            tmp->pow = p;
            tmp->coeff = c;
            tmp->next = first;
            first = tmp;
            return first;
        }
        else{
            int pos = 1;
            term *q = first;
            term *nxt = NULL;
            while(q->next!=NULL){
                nxt = q->next;
                if(p > q->pow)
                    break;
                else if(p < q->pow && p > nxt->pow){
                    pos++;
                    break;
                }
                else{
                    q = q->next;
                    pos++;
                }

            }
            if(p < q->pow && nxt == NULL){
                pos++;
            }
            if(pos==1){
                term* tmp = new term;
                tmp->pow = p;
                tmp->coeff = c;
                tmp->next = q;
                q = tmp;
                return q;
            }
            else{
                term *tmp = new term;
                tmp->pow = p;
                tmp->coeff = c;
                tmp->next = q->next;
                q->next = tmp;
                return first;
            }
        }
        return first;
    }

    term* add(term* one, term* two, term* res){  //combining two polynomials
        while(one!=NULL && two!=NULL){
            if(one->pow == two->pow){
                res = addTerm(res, one->pow, (one->coeff+two->coeff));
                one = one->next;
                two = two->next;
            }
            else if(one->pow < two->pow){
                res = addTerm(res, two->pow, two->coeff);
                two = two->next;
            }
            else if(one->pow > two->pow){
                res = addTerm(res, one->pow, one->coeff);
                one = one->next;
            }
        }
        while(one!=NULL || two!=NULL){
            if(one!= NULL){
                res = addTerm(res, one->pow, one->coeff);
                one = one->next;
            }
            if(two!= NULL){
                res = addTerm(res, two->pow, two->coeff);
                two = two->next;
            }
        }
        return res;
    }

    void printPoly(term *first){  //function to print the stored polynomial
        char var = 'x';
        while(first!=NULL){
            cout <<first->coeff << var << "^" << first->pow << " ";
            first = first->next;
            if(!(first == NULL))
                cout << "+ ";  
        }
        cout << endl;
    }
}poly;  //Data Structure (Linked List) based polynomial addition

int main(){
    term *first1 = NULL;
    poly p1;
    first1 = p1.addTerm(first1, 0, 1);
    first1 = p1.addTerm(first1, 5, 2);
    first1 = p1.addTerm(first1, 3, 4);
    first1 = p1.addTerm(first1, 4, 9);

    term *first2 = NULL;
    poly p2;
    first2 = p2.addTerm(first2, 0, 2);
    first2 = p2.addTerm(first2, 5, 9);
    first2 = p2.addTerm(first2, 3, 10);
    first2 = p2.addTerm(first2, 7, 3);
    
    cout << "First Polynomial : " << endl;
    p1.printPoly(first1);
    cout << "Second Polynomial : " << endl;
    p2.printPoly(first2);
    cout << endl << endl;

    term *firstR = NULL;
    poly result;
    firstR = result.add(first1, first2, firstR);
    cout << "Sum of polynomials : " << endl;
    result.printPoly(firstR);
}
