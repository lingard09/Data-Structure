#include <iostream>
#include <string>
using namespace std;

class node{
    public:
        string name;
        double score;
        node *link;
        void set_data(string s, int n){
            name = s;
            score = n;
        }
};

class my_list{
    node *head, *tail;
    public:
        my_list(){
            head = NULL;
            tail = NULL;
        }
        void add_to_head(node t){
            node *p;
            p = new node;
            *p = t;
            p -> link = head;
            head = p;
            if(tail == NULL){
                tail = p;
            }
        }
        void add_to_tail(node t){
            node *p;
            p = new node;
            *p = t;
            p -> link = NULL;
            if(tail != NULL){
                tail -> link = p;
            }
            else{
                head = p;
            }
            tail = p;
        }
        node delete_from_head(){
            node temp;
            node *t;
            t = head;
            temp = *head;
            delete t;
            if(head == NULL){
                tail = NULL;
            }
            return temp;
        }
        int num_nodes(){
            node *t;
            int count = 0;
            for(t = head; t != NULL; t = t -> link){
                count ++;
            }
            return count;
        }
        bool list_empty(){
            if(head == NULL){
                return true;
            }
            else{
                return false;
            }
        }
        int score_sum(){
            node *t;
            int sum = 0;
            for(t = head; t != NULL; t = t -> link){
                sum += (t -> score);
            }
            return sum;
        }
        int get_score(string t_name){

        }
        bool remove_a_node(string t_name){
            if(){
                return 1;
            }
            else{
                return 0;
            }
        }
};

int main(){
    my_list a;
    node tmp;
    
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp); //head 위치로 2개의 원소 추가

    cout << a.num_nodes() << ":" << a.score_sum() << "\n"; //1단계 점검

    tmp.set_data("Park", 91.3);
    a.add_to_tail(tmp); //tail 위치로 1개의 원소 추가

    cout << a.num_nodes() << ":" << a.score_sum() << "\n"; //2단계 점검
    tmp = a.delete_from_head();
    cout  << tmp.name << "is deleted.\n"; //3단계 점검
    
    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);
    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp); //2개의 원소 추가
    
    cout << a.num_nodes()<< ":" << a.score_sum() << "\n";
    cout << "Park’s score : " << a.get_score("Park")<< "\n"; //4단계 점검
    if(a.remove_a_node("Kim") == 1){
        cout << "Kim is deleted from the list. \n"; //5단계 점검
    }

    cout << a.num_nodes()<< ":" << a.score_sum() << "\n"; //최종 점검
    return 0;

}