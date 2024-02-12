/* Programmer: Ash Corcoran
   Date: 10/31/2022
   Class: CSC2710
   Instructor: Dr. Williams
*/

#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#define INFINITY 2000

void floyd(int);
void path(int,int);
void printArray(int[INFINITY][INFINITY],int);
using namespace std;


   int W[INFINITY][INFINITY];
   int D[INFINITY][INFINITY];
   int P[INFINITY][INFINITY];

int main()
{

   int vertices;
   int edges;
   string filename;
   
   cout << endl;
   cout << "Please enter name of data file (including file extension.)" << endl;
   cin >> filename;
   cout << endl;

   ifstream dataFile;
   dataFile.open(filename);
   
   if(dataFile.is_open())
   {
      dataFile >> vertices;
      dataFile >> edges;
      cout << "Vertices: " << vertices << endl << "Edges: " << edges << endl << endl;
     
          
     string row;
     string column;
     int weight;
     int rowFixed;
     int columnFixed;

      for(int i = 1; i<=vertices; i++)
      {
         for(int j = 1; j<=vertices; j++)
         {
             if(i==j)
             {
                W[i][i] = 0;
             }
             else
             { 
                W[i][j] = INFINITY;
             }
         }
      }

     while(!dataFile.eof())
     {
        dataFile >> row;
        if(row.substr(0,1) != "v")
        {
           break;
        }
        dataFile >> column;
        dataFile >> weight;
        
        rowFixed = stoi(row.substr(1,2));
        columnFixed = stoi(column.substr(1,2));

//        cout << rowFixed << "  " << columnFixed << "  " << weight << endl;
        W[rowFixed][columnFixed] = weight;

     }


      //printing original and Floyd Warshall Array
      cout << "Initial Array: " << endl;
      printArray(W,vertices);
      cout << endl;
      floyd(vertices);
      cout << "Final Array: " << endl;
      printArray(P,vertices);
      cout << endl;

      //pathfinding
      int paths = stoi(row);
      int vertex1;
      int vertex2;
      string temp;
      cout << "Paths: " << paths << endl;
      for(int i=1; i<=paths; i++)
      {
         dataFile >> temp;
         vertex1 = stoi(temp.substr(1,2));
         dataFile >> temp;
         vertex2 = stoi(temp.substr(1,2));
         cout << "Path from v" << vertex1 << " to v" << vertex2 << ": ";
         if(W[vertex1][vertex2] == INFINITY && P[vertex1][vertex2] == 0)
         {
            cout << "No path found" << endl;
         }
         else
         {
            cout << "v" << vertex1 << " ";
            path(vertex1,vertex2);
            cout << "v" << vertex2 << endl;
         }
      }
      cout << endl;
   }
   else
   {
      cout << "Error, could not open data file" << endl;
   }

   return 0;
}

void floyd(int n)
{
   //setting P to 0
   for(int i = 1; i<=n; i++)
   {
         for(int j = 1; j<=n; j++)
         {
            P[i][j] = 0;
         }
   }
   //D=W
   for(int a = 1; a<=n; a++)
   {
      for(int b=1; b<=n; b++)
      {
             D[a][b] = W[a][b];
      }
   }
   for(int k = 1; k<=n; k++)
   {
      for(int m = 1; m<=n; m++)
      {
         for(int o = 1; o<=n; o++)
         {
            if(D[m][k] + D[k][o] < D[m][o])
            {
               P[m][o] = k;
               D[m][o] = D[m][k] + D[k][o];
            }
         }
      }
   }
}

void path(int q, int r)
{
   if(P[q][r] != 0)
   {
      path(q, P[q][r]);
      cout << "v" << P[q][r] << " ";
      path(P[q][r], r);
   }
}

void printArray(int Arr[INFINITY][INFINITY], int size)
{

     //labels
     string label = "v";
     for(int i = 0; i<=size; i++)
     {
        if(i==0)
        {
           cout << "   ";
        }
        else
        {
        label.append(to_string(i));
        cout << right << setw(5) << setfill(' ') << label;
        label = "v";
        }
     }
     cout << endl;

     //printing array
     for(int i=1; i<=size; i++)
     {
        cout << "v" << i << ":";
        for(int j=1; j<=size; j++)
        {
           if(Arr[i][j] == INFINITY)
           {
              cout << right << setw(5) << setfill(' ') << "INF";
           }
           else
           {
              cout << right << setw(5) << setfill(' ') << Arr[i][j];
           }
        }  
        cout << endl;
     }
}
