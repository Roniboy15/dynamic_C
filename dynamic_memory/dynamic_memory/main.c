//
//  main.c
//  dynamic_memory
//
//  Created by Jaron Treyer on 29.12.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main(int argc, const char * argv[]) {
    char *arr, size = 5 , i;
    
    arr = malloc(size);
    
    if(!arr){
        printf("Memory allocation didn't work\n");
        return 0;
    }
    
    *arr = 10;
    *(arr+1) = 20;
    *(arr+2) = 30;
    
    printf("%p - address in Heap\n%p - next address in Heap\n%d - Value in Heap\n%d - Next value in Heap\n%d\n\n", arr, arr+1, *arr, *(arr+1),*(arr+2));
    return 0;
}
*/

/*
int main () {
    
    int size, i, num, sum = 0;
    
    printf("Tell me the size of the Array:\n");
    scanf("%d", &size);
    
    printf("Tell me the number you want to check:\n");
    scanf("%d", &num);
    
    int *p = calloc(size, sizeof(int));
    int *p1 = calloc(size, sizeof(int));

    
    if(p == NULL){
        printf("Couldn't allocate memory!");
        return 0;
    }
    
    printf("Enter the values of the array:\n");
    
    for (i = 0; i < size; i++) {
        scanf("%d", p+i);
        if(*(p+i) == num){
            sum += 1;
            *p1 = calloc(<#size_t __count#>, <#size_t __size#>)
        }
    }
    
    for (i = 0; i < sum; i++) {
        printf("%d, ", *(p1+i));
    }
    return 0;
    

}
*/


//new exercise presentation:
/*

char * checkString(char *p, char tav){
    int counter = 0;
    char * i = p;
    while (*i != '\0') {
        if(*i == tav){
            counter++;
        }
        i++;
    }
    
    char * new = calloc(counter+1, sizeof(char));
    if(new == NULL)return NULL;
    
    for (int i = 0; i < counter+1; i++) {
        if(i == counter) *(new+i) = '\0';
        else *(new+i) = tav;
    }
    return new;
}


int main () {
    char string[] = "kjwbfjbweobofjboobg";
    char tav = 'o';
    
    char *new = checkString(string, tav);
    if(new == NULL)return 1;

    char * i = new;
    while (*i != '\0') {
        printf("%c ", *i);
        i++;
    }
    
    return 0;
    
}
 */



/*
int * combineArrays(int * p, int *p1, int size, int size1){
    int *new = calloc(size+size1, sizeof(int));
    
    for (int i = 0; i < size+size1; i++) {
        if(i == size){
            for (int y = 0; y < size1; y++) {
                *(new+i+y) = *(p1+y);
            }
            break;
        }
        *(new+i) = *(p+i);
    }
    return new;
}

int main () {
    int arr[] = {1,2,12,2,1};
    int arr1[] = {4,5,6,21};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int newSize = size + size1;

    int *new = combineArrays(arr, arr1, size, size1);
    
    for (int *i = new; i < new+newSize; i++) {
        printf("%d ", *i);
    }
}
*/

//codechef https://www.codechef.com/problems/SUMTRIAN?tab=statement
/*
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
  scanf("%d", &n);

  // allocate and read the triangle
  int** triangle = (int**) malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    triangle[i] = (int*) malloc((i + 1) * sizeof(int));
    for (int j = 0; j <= i; j++) {
      scanf("%d", &triangle[i][j]);
    }
  }

  // compute the maximum sum
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
    }
  }
  int maximum_sum = triangle[0][0];

  // free memory
  for (int i = 0; i < n; i++) {
    free(triangle[i]);
  }
  free(triangle);

  printf("%d\n", maximum_sum);
    }
  
  return 0;
}
*/

//exercise from 03.01 with Arye

/*
struct student {
    char name[20];
    int id;
} typedef student_t;

struct class{
    char teacher[20];
    int studentsTotal;
    int registeredStudents;
    student_t ** students;
}typedef class_t;

struct school{
    char name[20];
    int classesTotal;
    int registeredClasses;
    class_t ** classes;
}typedef school_t;

int main () {
    int flag = 0, flag2 = 0;
    char answer;
    
    school_t s = {"Noam"};
    printf("How many classes?\n");
    scanf("%d", &s.classesTotal);
    s.classes = (class_t**)calloc(sizeof(class_t*), s.classesTotal);
    if(s.classes == NULL){
        printf("failed\n");
        return 0;
    }
    
    
    do{
        if(s.registeredClasses == s.classesTotal){
            printf("You've reached the maximum amount of classes!\n");
            break;
        }
        printf("Register a Class (Y/N)?\n");
        fflush(0);
        scanf("%c", &answer);

        if (answer == 'N' || answer == 'n') flag = 1;
        
        else{
        s.classes[s.registeredClasses] = (class_t*)calloc(1, sizeof(class_t));

        printf("Enter name of teacher and number of students:\n");
        scanf("%s %d", s.classes[s.registeredClasses] -> teacher, &s.classes[s.registeredClasses] -> studentsTotal);
            fflush(0);

            printf("Now we are going to declare the students:\n");
            flag2 = 0;
            class_t c;
            strcpy(c.teacher, s.classes[s.registeredClasses] -> teacher);
            c.studentsTotal = s.classes[s.registeredClasses] -> studentsTotal;
            c.registeredStudents = 0;
            c.students = (student_t **)calloc(sizeof(student_t*), c.studentsTotal);
                        
            if( c.students == NULL){
                printf("failed\n");
                return 0;
            }
            s.classes[s.registeredClasses] -> students = c.students;
           
            
            do{
                if (c.registeredStudents == c.studentsTotal){
                printf("Class is full!\n");
                break;
                }

                printf("Register a student (Y/N)? ");
                scanf("%c", &answer);
                if (answer == 'N' || answer == 'n')
                flag2 = 1;
                
                else{
                c.students[c.registeredStudents] = (student_t*)calloc(1, sizeof(student_t));

                printf("Enter name and id: ");
                    fflush(0);
                    scanf("%s %d", c.students[c.registeredStudents] -> name, &c.students[c.registeredStudents] -> id);
                    fflush(0);

                    c.registeredStudents++;
                    
                }
                
            } while(flag2 == 0);
                
        s.registeredClasses++;
        }

    } while (flag == 0);
        
    
}
*/

//experiment
/*
#include <stdio.h>
#include <string.h>
#include "microhttpd.h.c"

#define PORT 8888

const char *response_template = "Hello, %s!";

int handle_request(void *cls, struct MHD_Connection *connection,
                   const char *url, const char *method,
                   const char *version, const char *upload_data,
                   size_t *upload_data_size, void **ptr) {
  const char *name = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "name");
  if (name == NULL) {
    name = "World";
  }
  char response[strlen(response_template) + strlen(name) - 1];
  sprintf(response, response_template, name);
  struct MHD_Response *mhd_response = MHD_create_response_from_buffer(strlen(response), response, MHD_RESPMEM_MUST_COPY);
  int ret = MHD_queue_response(connection, MHD_HTTP_OK, mhd_response);
  MHD_destroy_response(mhd_response);
  return ret;
}

int main() {
  struct MHD_Daemon *daemon = MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, PORT, NULL, NULL,
                                                &handle_request, NULL, MHD_OPTION_END);
  if (daemon == NULL) {
    return 1;
  }
  getchar();
  MHD_stop_daemon(daemon);
  return 0;
}
*/
