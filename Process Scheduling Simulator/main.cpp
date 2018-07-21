#include "1.h"

int main()
{

    int menuchoice1 = 0, menuchoice2 = 0, nelem = 0, *elements;

    Time *t;
    FCFS Fcfs(0);
    FCFS Rr(0);
    Tree Cfs;

    while (menuchoice1 != 3)
    {

        cout
            << "________________User Input Menu    1___________________\n"
            << "________________Schedular Menu     2___________________\n"
            << "________________Exit               3___________________\n"
            << "\n\nEnter Here:";

        cin >> menuchoice1;
        menuchoice2 = 0;
        switch (menuchoice1)
        {

        case 1:

            cout << "Enter Number of processes:";
            cin >> nelem;
            elements = new int[nelem];
            t = new Time[nelem];
            for (int i = 0; i < nelem; i++)
            {
                cout << "Enter Process ID:";
                int id;
                cin >> id;
                elements[i] = id;
                t[i].gettime();
            }

            break;

        case 2:

            while (menuchoice2 != 4)
            {
                cout
                    << "________________MENU__________________________\n\n"
                    << "________________FCFS      1___________________\n"
                    << "________________RR        2___________________\n"
                    << "________________CFS       3___________________\n"
                    << "________________EXIT      4___________________\n"
                    << "\n\nEnter Here:";
                cin >> menuchoice2;
                menuchoice1 = 0;
                switch (menuchoice2)
                {

                case 1:
                    Fcfs.setsize(nelem);

                    for (int i = 0; i < nelem; i++)
                    {
                        Fcfs.enqueue(elements[i], t[i]);
                    }
                    Fcfs.process();

                    break;

                case 2:
                    Rr.setsize(nelem);

                    for (int i = 0; i < nelem; i++)
                    {
                        Rr.enqueue(elements[i], t[i]);
                    }
                    Rr.prop();
                    break;
                case 3:

                    for (int i = 0; i < nelem; i++)
                    {
                        int x = (t[i].hrs * 3600 + t[i].min * 60 + t[i].sec) * 1000;
                        x += t[i].ms;
                        Cfs.Insert(elements[i], t[i].hrs, t[i].min, t[i].sec, t[i].ms, t[i].ah, t[i].am, t[i].as, t[i].ams, x, Cfs.root);
                    }
                    cout << "ID       Process Time          Arrival Time\n";
                    Cfs.Balance(Cfs.root);

                    break;
                }
            }

            break;
        }
    }

    return 0;
}
