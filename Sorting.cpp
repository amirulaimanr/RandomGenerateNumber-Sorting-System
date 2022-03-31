#include <iostream>
#include<cstdlib>
#include<fstream>
#include <string>

using namespace std;

fstream num;

void mmenu()                    //print menu option of program
{
    cout << "\n\t\t Welcome To RnG with Sorting Algorithm " << endl;

    cout << "\n\t--------------------------------------------------------";
    cout << "\n\t HOW MANY INTEGERS YOU WISH TO GENERATE : ";
    cout << "\n\n\t\t\t1. 100 ";
    cout << "\n\n\t\t\t2. 200 ";
    cout << "\n\n\t\t\t3. 300 ";
    cout << "\n\t--------------------------------------------------------" << endl;
}

void swapping(int &a, int &b) //swapping two variable
{
   int temp;
   temp = a;          //swapping temp to a
   a = b;             //swapping a to b
   b = temp;          //swapping b to temp
}

void swap(int *a, int *b) {  //swapping two variable
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

void display(int *array, int size) {  //display array
   for(int i = 0; i<size; i++)
      cout <<array[i] << "\t";
}

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;

   int larr[nl], rarr[nr];          // Create temp arrays

   for(i = 0; i<nl; i++)            //Copy data to temp arrays larr[i]
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];       //Copy data to temp arrays rarr[j]
      larr[i] = array[l+i];
   i = 0; j = 0; k = l;            //Maintain current index of sub-arrays and main array

   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {      // Until we reach either end of either larr or rarr, pick larger among
         array[k] = larr[i];        // elements larr and rarr and place them in the correct position
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl)                 // Copy the remaining elements of larr[], if there are any
    {
      array[k] = larr[i];      // pick up the remaining elements
      i++; k++;
   }
   while(j<nr)                 // Copy the remaining elements of rarr[], if there are any
   {
      array[k] = rarr[j];      // pick up the remaining elements
      j++; k++;
   }
}

// Divide the array into two subarray, sort them and merge them
void mergeSort(int arr[],int l,int r){      // l is for left index and
                                             //r is right index of the sub-array of arr to be sorted */
    if(l>=r){
        return;                             // returns recursively
    }
    int m = (l+r-1)/2;                   // m is the point where the array is divided into two subarrays
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);                    // Merge the sorted subarrays
}
int partition (int arr[], int low, int high)    // Function to partition the array on the basis of pivot element
{
    int pivot = arr[high];              // selecting last element as pivot
    int i = (low - 1);                  // index of smaller element

    for (int j = low; j <= high- 1; j++)    // Put the elements smaller than pivot on the left
                                            // and greater than pivot on the right of pivot
    {
        if (arr[j] <= pivot)
        {
            i++;                            // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int QuickSort(int array[], int low, int high) {   //array[] is the array, low is starting index and
                                                  //high is the last index of array.

    if (low < high)
    {                                           // Select pivot position and put all the elements smaller
        int pi = partition(array, low, high);   // than pivot on left and greater than pivot on right
        QuickSort(array, low, pi - 1);         // Sort the elements on the left of pivot
        QuickSort(array, pi + 1, high);         // Sort the elements on the right of pivot
    }
   return 0;
}

void printArray(int array[], int size)   // Print the array
{
    int i;
    for (i=0; i < size; i++)
        cout << array[i] << "\t";
}


int main()                          // Driver program
{
    srand (191020869);              // seed generating number using matric number

    string cmd,op;
    int loop;
    int n=0;
    int array[300];
    int low = 0;
    int high = n - 1;
    int pindex;
    int  i;

    while (true)
    {
        menu:
        mmenu();
        cout << "\n\n\tEnter option : "; cin >> cmd;
        cout << "\n";

        if (cmd == "1")
        {
            n = 100;

            num.open("Generated100.txt", std::ofstream::out | std::ofstream::trunc);
            num.close();
            for (loop = 0; loop < n; loop++)
            {
                array[loop] = rand();
                cout << array[loop] << "\t";
            num.open("Generated100.txt",ios::out | ios::app);
            num<<array[loop]<<endl;
            num.close();

            }

             cout << "\n\n\t\t\t100 random numbers generated...";

            New:
            cout << "\n\nSorting RnG " << endl;
            cout << "\n\t 1. MERGE SORT " << endl;
            cout << "\n\t 2. QUICK SORT " << endl;
            cout << "\n\t 3. Back to Menu " << endl;
            cout << "\n\t Please choose your option : "; cin >> op;

            if (op == "1")
            {
                cout<<"\n\n\tMerge Sorted array is: \n"<<endl;
                mergeSort(array, 0, n);
                display (array,n);

                string again;
							cout<<"\n\n\nContinue (Y/N):        ";
							cin>>again;
							if(again == "y" || again == "Y"){
								goto New;
							}else{
								nr:
								string a;
		     					cout<<"\n\nGO BACK TO MENU (Y/N)?    ";
								cin>>a;
					     		if(a=="y" || a=="Y")
								{
								    system("cls");
			    					goto menu;
								}else if(a=="n" || a==" N")
								{
									return 0;
								}else if((a!="y" || a!="Y") || (a!="n" || a!=" N"))
								{
									cout<<"TRY AGAIN  "<<endl;
									goto nr;
								}
							}
							break;

            }

            else if (op == "2")
            {
                QuickSort(array, 0, n-1);
                printf("\n\n\tQuick Sorted array:  \n\n");
                printArray(array, n);

                string again;
							cout<<"\n\n\nContinue (Y/N):        ";
							cin>>again;
							if(again == "y" || again == "Y"){
								goto New;
							}else{
								ne:
								string a;
		     					cout<<"\n\nGO BACK TO MENU (Y/N)?    ";
								cin>>a;
					     		if(a=="y" || a=="Y")
								{
								    system("cls");
			    					goto menu;
								}else if(a=="n" || a==" N")
								{
									return 0;
								}else if((a!="y" || a!="Y") || (a!="n" || a!=" N"))
								{
									cout<<"TRY AGAIN  "<<endl;
									goto ne;
								}
							}
							break;
            }

            else
            {
            system("cls");
            goto menu;

            }

        }
        else if (cmd == "2")
        {
            n = 200;
            num.open("Generated200.txt", std::ofstream::out | std::ofstream::trunc);
            num.close();
            for (loop = 0; loop < n; loop++)
            {
                array[loop] = rand();
                cout << array[loop] <<"\t";
                num.open("Generated200.txt",ios::out | ios::app);
                num<<array[loop]<<endl;
                num.close();
            }

            cout << "\n\n\t\t\t200 random numbers generated...";

            New2:
            cout << "\n\nSorting RnG " << endl;
            cout << "\n\t 1. MERGE SORT " << endl;
            cout << "\n\t 2. QUICK SORT " << endl;
            cout << "\n\t 3. Back to Menu " << endl;
            cout << "\n\t Please choose your option : "; cin >> op;

            if (op == "1")
            {
                cout<<"\n\n\tMerge Sorted array is: \n"<<endl;
                mergeSort(array, 0, n);
                display (array,n);

                string again;
							cout<<"\n\n\nContinue (Y/N):        ";
							cin>>again;
							if(again == "y" || again == "Y"){
								goto New2;
							}else{
								nt:
								string a;
		     					cout<<"\n\nGO BACK TO MENU (Y/N)?    ";
								cin>>a;
					     		if(a=="y" || a=="Y")
								{
								    system("cls");
			    					goto menu;
								}else if(a=="n" || a==" N")
								{
									return 0;
								}else if((a!="y" || a!="Y") || (a!="n" || a!=" N"))
								{
									cout<<"TRY AGAIN  "<<endl;
									goto nt;
								}
							}
							break;

            }
            else if (op == "2")
            {
                QuickSort(array, 0, n-1);
                printf("\n\n\tQuick Sorted array:  \n\n");
                printArray(array, n);

                string again;
							cout<<"\n\n\nContinue (Y/N):        ";
							cin>>again;
							if(again == "y" || again == "Y"){
								goto New2;
							}else{
								ny:
								string a;
		     					cout<<"\n\nGO BACK TO MENU (Y/N)?    ";
								cin>>a;
					     		if(a=="y" || a=="Y")
								{
								    system("cls");
			    					goto menu;
								}else if(a=="n" || a==" N")
								{
									return 0;
								}else if((a!="y" || a!="Y") || (a!="n" || a!=" N"))
								{
									cout<<"TRY AGAIN  "<<endl;
									goto ny;
								}
							}
							break;
            }

            else
            {
            system("cls");
            goto menu;

            }
        }
        else if (cmd == "3")
        {
            n = 300;
            num.open("Generated300.txt", std::ofstream::out | std::ofstream::trunc);
            num.close();
            for (loop = 0; loop < n; loop++)
            {
                array[loop] = rand();
                cout << array[loop] <<"\t";
                num.open("Generated300.txt",ios::out | ios::app);
                num<<array[loop]<<endl;
                num.close();
            }

            cout << "\n\n\t\t\t300 random numbers generated...";

            New3:
            cout << "\n\nSorting RnG " << endl;
            cout << "\n\t 1. MERGE SORT " << endl;
            cout << "\n\t 2. QUICK SORT " << endl;
            cout << "\n\t 3. Back to Menu " << endl;
            cout << "\n\t Please choose your option : "; cin >> op;

            if (op == "1")
            {
                cout<<"\n\n\tMerge Sorted array is: \n"<<endl;
                mergeSort(array, 0, n);
                display (array,n);

                string again;
							cout<<"\n\n\nContinue (Y/N):        ";
							cin>>again;
							if(again == "y" || again == "Y"){
								goto New3;
							}else{
								na:
								string a;
		     					cout<<"\n\nGO BACK TO MENU (Y/N)?    ";
								cin>>a;
					     		if(a=="y" || a=="Y")
								{
								    system("cls");
			    					goto menu;
								}else if(a=="n" || a==" N")
								{
									return 0;
								}else if((a!="y" || a!="Y") || (a!="n" || a!=" N"))
								{
									cout<<"TRY AGAIN  "<<endl;
									goto na;
								}
							}
							break;

            }
            else if (op == "2")
            {
                QuickSort(array, 0, n-1);
                printf("\n\n\tQuick Sorted array:  \n\n");
                printArray(array, n);

                string again;
							cout<<"\n\n\nContinue (Y/N):        ";
							cin>>again;
							if(again == "y" || again == "Y"){
								goto New3;
							}else{
								nq:
								string a;
		     					cout<<"\n\nGO BACK TO MENU (Y/N)?    ";
								cin>>a;
					     		if(a=="y" || a=="Y")
								{
								    system("cls");
			    					goto menu;
								}else if(a=="n" || a==" N")
								{
									return 0;
								}else if((a!="y" || a!="Y") || (a!="n" || a!=" N"))
								{
									cout<<"TRY AGAIN  "<<endl;
									goto nq;
								}
							}
							break;
            }

            else
            {
            system("cls");
            goto menu;

            }
        }

        else
        {
            cout << "\t Warning! Invalid Input.";
            cout<<"\n\t TRY AGAIN ! Press any key to continue...\n"<<endl;
            cin.ignore();
            cin.get();
            system("CLS");

        }

    }

}

