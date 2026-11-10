#include <stdio.h>
#define TABLE_SIZE 7
int hashTable[TABLE_SIZE];
int isOccupied[TABLE_SIZE] = {0};
int hashFunction(int key)
{
  return key % TABLE_SIZE; 
}
void insert(int key)
{
  int index = hashFunction(key); 
  int probes = 0; while (isOccupied[index]) 
  {
    printf("Collision at index %d for ID %d -> probing next slot\n", index, key); 
    index = (index + 1) % TABLE_SIZE; probes++;
    if (probes == TABLE_SIZE) { printf("Hash Table is Full! Cannot insert ID %d\n", key);
                               return;
                              }
  }
  hashTable[index] = key; 
  isOccupied[index] = 1;
  printf("Student ID %d stored at index %d\n", key, index); 
} 
int search(int key)
{
  int index = hashFunction(key); 
  int probes = 0; while (isOccupied[index])
    {
      if (hashTable[index] == key)
        return index; 
      index = (index + 1) % TABLE_SIZE; 
      probes++; if (probes == TABLE_SIZE) 
        break;
    }
  return -1; 
}
void display()
{
  printf("\nHash Table:\n"); 
  for (int i = 0; i < TABLE_SIZE; i++) 
  {
    if (isOccupied[i]) printf("Index %d -> Student ID %d\n", i, hashTable[i]);
    else 
      printf("Index %d -> empty\n", i);
  }
}
int main()
{
  int ids[] = {101, 108, 115, 102, 122};
  int n = 5; for (int i = 0; i < n; i++)
    insert(ids[i]);
  display(); 
  int key = 115; 
  int result = search(key); 
  if (result != -1)
    printf("\nStudent ID %d found at index %d\n", key, result);
  else 
    printf("\nStudent ID %d not found\n", key);
return 0;
} 
Output:
Student ID 101 stored at index 3
Collision at index 3 for ID 108 -> probing next slot
Student ID 108 stored at index 4
Collision at index 3 for ID 115 -> probing next slot
Collision at index 4 for ID 115 -> probing next slot
Student ID 115 stored at index 5
Collision at index 4 for ID 102 -> probing next slot
Collision at index 5 for ID 102 -> probing next slot
Student ID 102 stored at index 6
Collision at index 3 for ID 122 -> probing next slot
Collision at index 4 for ID 122 -> probing next slot
Collision at index 5 for ID 122 -> probing next slot
Collision at index 6 for ID 122 -> probing next slot
Student ID 122 stored at index 0

Hash Table:
Index 0 -> Student ID 122
Index 1 -> empty
Index 2 -> empty
Index 3 -> Student ID 101
Index 4 -> Student ID 108
Index 5 -> Student ID 115
Index 6 -> Student ID 102

Student ID 115 found at index 5


