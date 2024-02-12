/* Programmer: Ash Corcoran
   Date: 9/7/21
   Description: Header File for counterType.cpp
   Assistance Received From: C++ Programming with Advanced Data Structures by M.S Malik Chapter 10
   How To Compile:
   How To Run: n/a
*/

class counterType
{
   public:
      void initializeCounter();
      void setCounter(int = 0);
      int getCounter() const;
      void incrementCounter();
      void decrementCounter();
      void displayCounter() const;
      counterType(int);
      counterType();
   private:
      int counter;

};

