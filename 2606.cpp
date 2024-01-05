#include<iostream>
using namespace std;

int cnt=0;

void check(int s, int n, int **arr,int* list){
    for(int i=0; i<n; ++i){
        if(arr[s][i]==1){
            if(list[i]==0){
                cnt++;
                list[i]=1;
                check(i,n,arr,list);
            }
        }
    }
}

int main(){
    int n, p;
    cin >> n;
    cin >> p;
    int c1, c2;
    int** adj = new int*[n];
    for(int i=0; i<n; ++i){
        adj[i] = new int[n];
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n; ++j)
            adj[i][j] = 0;
    for(int i=0; i<p; ++i){
        cin >> c1 >> c2;
        adj[c1-1][c2-1] = 1;
        adj[c2-1][c1-1] = 1;
    }
    /*
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << adj[i][j] << "   ";
        }
        cout << endl;
    }
    */

    int* list = new int[n];
    for(int i=0; i<n; ++i)
        list[i] = 0;
    list[0] = 1;

    check(0,n,adj,list);

    cout << cnt;
    delete[] list;
    for(int i=0; i<n; ++i)
        delete[] adj[i];
}

/*
#include<iostream>
using namespace std;

struct node {
  int index;
  struct node * next;
};

#define POOL_SIZE 10000  // What is an appropriate size?  The average degree
			  // is about 5.  So this must be enough.

// pool of memory
struct node pool[POOL_SIZE];
struct node * top=pool;  // a pointer variable for stack top.

// Still use the same memory management.
void init_pool() // Initialize the pool.
{
  int i;
  struct node *r=pool;
  struct node *s;

  pool[POOL_SIZE-1].next=NULL;

  for(i=1;i<POOL_SIZE;i++) {
    s=r++;
    s->next=r;
  }
}

// When calling new_node(), make sure to check if it returns NULL.
struct node * new_node(int i)
{
  struct node *r;

  if(top==NULL)
    return NULL;

  r=top;
  top=r->next;
  r->index=i;
  return r;
}

// Push a node to the pool.
void free_node(struct node *r)
{
  r->next=top;
  top=r;
}

int cnt=0;

void check(strcut node* arr){
    while()
}

int main(){
    int n, p;
    cin >> n;
    cin >> p;
    int c1, c2;
    struct node * adj[n];
    for(int i=0; i<p; ++i){
        cin >> c1 >> c2;
        adj[c1]->next = new_node(c2);
    }
    check
}
*/