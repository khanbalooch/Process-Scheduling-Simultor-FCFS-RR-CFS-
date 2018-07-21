#ifndef IBRAHIM
#define IBRAHIM
#include <iostream>
#include <ctime>
using namespace std;

class Time
{

  public:
	int hrs, min, sec, ms;
	int ah, am, as, ams;

	void gettime();
	void settime(Time);
	void showptime();
	void showatime();
};

/*_____________________________________________________*/
/*________________________FCFS_________________________*/
class FCFS
{
  private:
  public:
	Time *t;
	int *served;
	int *remaining;
	int *queueArray;
	int queueSize;
	int front;
	int rear;
	int numItems;

	FCFS(int);
	~FCFS(void);
	void prop();
	void process();
	void setsize(int);
	void enqueue(int, Time);
	int dequeue(Time &m);
	bool isEmpty(void);
	bool isFull(void);
	void clear(void);
};

/*_____________________________________________________*/
/*________________________CFS__________________________*/

struct Node;
typedef struct Node *Position;
typedef struct Node *AvlTree;

class Element
{
  public:
	int id, hrs, min, sec, ms, ah, am, as, ams, total;

	void settime(Time);
	void showptime();
	void showatime();
};

struct Node
{

	Element element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

class Tree
{
  public:
	AvlTree root;
	int Height(Position P);
	AvlTree MakeEmpty(AvlTree T);
	Position Find(Element X, AvlTree T);
	Position FindMin(AvlTree T);
	Position FindMax(AvlTree T);
	AvlTree Insert(int, int, int, int, int, int, int, int, int, int, AvlTree T);
	AvlTree Delete(Element X, AvlTree T);
	Element Retrieve(Position P);
	Position DoubleRotateWithRight(Position K1);
	Position DoubleRotateWithLeft(Position K3);
	Position SingleRotateWithLeft(Position K2);
	Position SingleRotateWithRight(Position K1);
	int Max(int x, int y);
	void Balance(Node *t);
};

#endif
