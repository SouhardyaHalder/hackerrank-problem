#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */


void sort(int arr[],int n)
{
    int key,i,j;
    for(j=1;j<n;j++)
    {
        key=arr[j];
        i=j-1;
        while(i>=0  && key<arr[i])
        {
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
}


SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

SinglyLinkedListNode *ll1=head1,*ll2=head2;

int n1=0,n2=0,n3;
while(ll1)
{
    n1++;
    ll1=ll1->next;
}
while(ll2)
{
    n2++;
    ll2=ll2->next;
}

n3=n1+n2;
int *arr1=new int[n1];
int *arr2=new int[n2];
int *arr3=new int[n1+n2];
ll1=head1;ll2=head2;

for(int i=0;i<n1;i++)
{
    arr1[i]=ll1->data;
    ll1=ll1->next;
}

for(int i=0;i<n2;i++)
{
    arr2[i]=ll2->data;
    ll2=ll2->next;
}

for(int i=0;i<n1;i++)
arr3[i]=arr1[i];

for(int i=n1,j=0;j<n2;j++,i++)
arr3[i]=arr2[j];

sort(arr3,n1+n2);
ll1=head1;ll2=head2;

while(ll1->next)
ll1=ll1->next;

ll1->next=ll2;
ll1=head1;
for(int i=0;ll1;i++)
{
    ll1->data=arr3[i];
    ll1=ll1->next;
    
}
    return head1;
}




int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}
