#include "1.h"

void Time::gettime()
{
	cout << "Enter Hrs:";
	cin >> hrs;

	cout << "Enter mins:";
	cin >> min;

	cout << "Enter secs:";
	cin >> sec;

	cout << "Enter ms:";
	cin >> ms;

	time_t g = time(NULL);
	struct tm *w = localtime(&g);

	ah = w->tm_hour;
	am = w->tm_min;
	as = w->tm_sec;
	ams = g - (ah * 3600 + am * 60 + as);
	ams = ams % 1000;
}
void Time::showptime()
{
	cout << hrs << ":" << min << ":" << sec << ":" << ms << endl;
}

void Time::settime(Time time)
{
	hrs = time.hrs;
	min = time.min;
	sec = time.sec;
	ms = time.ms;
	ah = time.ah;
	am = time.am;
	as = time.as;
	ams = time.ams;
}

void Time::showatime()
{

	cout << ah << ":" << am << ":" << as << ":" << ams;
}
/*____________________________________________________*/
/*______________________FCFS__________________________*/
/****************************************/
FCFS::FCFS(int s) //constructor
{
	t = new Time[s];
	queueArray = new int[s];
	remaining = new int[s];
	served = new int[s];
	queueSize = s;
	front = -1;
	rear = -1;
	numItems = 0;
}
void FCFS::process()
{

	Time m;
	int x;
	cout << "ID                 ARRIVAL TIME             PROCESS TIME\n";
	for (int y = numItems; y > 0; y--)
	{

		x = dequeue(m);

		cout << x << "                  ";
		m.showatime();
		cout << "              ";
		m.showptime();
	}
}

/****************************************/

FCFS::~FCFS(void) //destructor
{
	delete[] queueArray;
	delete[] t;
}

/****************************************/

void FCFS::enqueue(int num, Time time)
{

	if (isFull())
		cout << "The queue is full.\n";
	else
	{
		// Calculate the new rear position
		rear = (rear + 1) % queueSize;
		// Insert new item
		queueArray[rear] = num;
		t[rear].settime(time);
		remaining[rear] = (time.hrs * 3600 + time.min * 60 + time.sec) * 1000;
		remaining[rear] += time.ms;
		served[rear] = 0;
		// Update item count
		numItems++;
	}
}
/****************************************/
void FCFS::setsize(int s)
{

	queueArray = new int[s];
	queueSize = s;
	t = new Time[s];
	remaining = new int[s];
	served = new int[s];
}
/****************************************/

int FCFS::dequeue(Time &m)
{
	int num = 0;
	if (isEmpty())
	{
		cout << "The queue is empty.\n";
		num = 0;
	}
	else
	{
		// Move front
		front = (front + 1) % queueSize;
		// Retrieve the front item
		num = queueArray[front];
		m.hrs = t[front].hrs;
		m.min = t[front].min;
		m.sec = t[front].sec;
		m.ms = t[front].ms;

		// Update item count
		numItems--;
	}
	return num;
}

/****************************************/

bool FCFS::isEmpty(void)
{
	if (numItems)
		return false;
	else
		return true;
}

/****************************************/

bool FCFS::isFull(void)
{
	if (numItems < queueSize)
		return false;
	else
		return true;
}

/****************************************/

void FCFS::clear(void)
{
	front = -1;
	rear = -1;
	numItems = 0;
}
/****************************************/
void FCFS::prop()
{
	Time time;
	cout << "ID     served Time     Remaining time     STATUS     Arrival time\n";
	front += 1;
	while (!isEmpty())
	{

		if (front > rear)
		{
			front = 0;
		}
		cout << queueArray[front];
		cout << "     ";

		cout << "     ";
		cout << served[front];
		cout << "              ";
		cout << remaining[front];

		if (remaining[front] > 0)
		{
			cout << "         Processing    ";
			remaining[front] -= 10;
			served[front] += 10;
		}
		else
		{
			cout << "         Completed     ";
			dequeue(time);
		}

		t[front].showatime();
		cout << endl;
		front += 1;
	}
}
/*____________________________________________________*/
/*______________________RR  __________________________*/

/*____________________________________________________*/
/*______________________ CFS__________________________*/
/*______________________RR  __________________________*/
/***************************************/
int Tree::Height(Position P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height;
}
/***************************************/
AvlTree Tree::Insert(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, AvlTree T)
{

	Element X;
	X.id = a;
	X.hrs = b;
	X.min = c;
	X.sec = d;
	X.ms = e;
	X.ah = f;
	X.am = g;
	X.as = h;
	X.ams = i;
	X.total = j;

	if (T == NULL)
	{ /* Create and return a one-node tree */
		T = new Node;
		T->element = X;

		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else if (X.total < T->element.total)
	{
		T = new Node;
		T->Left = Insert(a, b, c, d, e, f, g, h, i, j, T->Left);

		if (Height(T->Left) - Height(T->Right) == 2)
			if (X.total < T->Left->element.total)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
	}
	else if (X.total > T->element.total)
	{
		T = new Node;
		T->Right = Insert(a, b, c, d, e, f, g, h, i, j, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
			if (X.total > T->Right->element.total)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
	} /* Else X is in the tree already; we'll do nothing */
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

/***************************************/
Position Tree::SingleRotateWithRight(Position K1)
{
	Position K2;

	K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	K2->Height = Max(Height(K2->Right), K1->Height) + 1;
	return K2; /* New root */
}

/***************************************/
Position Tree::SingleRotateWithLeft(Position K2)
{
	Position K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), K2->Height) + 1;
	return K1; /* New root */
}

/***************************************/
Position Tree::DoubleRotateWithLeft(Position K3)
{
	/* Rotate between K1 and K2 */
	K3->Left = SingleRotateWithRight(K3->Left);
	/* Rotate between K3 and K2 */
	return SingleRotateWithLeft(K3);
}
/***************************************/
Position Tree::DoubleRotateWithRight(Position K1)
{
	/* Rotate between K3 and K2 */
	K1->Right = SingleRotateWithLeft(K1->Right);
	/* Rotate between K1 and K2 */
	return SingleRotateWithRight(K1);
}
/***************************************/
int Tree::Max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
/*****************************************/

void Element::showptime()
{
	cout << hrs << ":" << min << ":" << sec << ":" << ms << endl;
}

void Element::showatime()
{
	cout << ah << ":" << am << ":" << as << ":" << ams;
}

void Tree::Balance(Node *t)
{
	cout << "done";

	if (t != NULL)
	{
		Balance(t->Left);
		//cout<<t->element.id<<"       ";//t->element.showptime();
		//cout<<"      ";t->element.showatime();
		//Balance(t->Right);
	}
}
