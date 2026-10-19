#include <stdio.h>

struct printjobs {
    int jobID;
    char title[20];
};

struct printjobs p[6];

int front=-1,rear=-1;

int isfull(struct printjobs q[6]) {
    if ((rear+1)%6==front) {
        return 1;
    }
    else {
        return 0;
    }
}

void addjob(struct printjobs q[6]) {
    if (front==-1){
        front=0;
        rear=0;
    }
    rear = (rear + 1)%6;

    printf("Enter job ID: ");
    scanf("%d", &p[rear].jobID);

    printf("Enter the job title: ");
    scanf("%s", p[rear].title);
}

int isempty(struct printjobs q[6]) {
    if (front==-1) {
        return 1;
    }
    else {
        return 0;
    }
}

int removejob(struct printjobs q[6]) {
    int elem;
    if (rear==front){
        front=-1;
        rear=-1;
    }
    else{
        front = (front + 1)%6;
        elem = front;
        
    }
    return elem;    
}
void displayq(struct printjobs q[6]) {
    for (int i = front + 1; i <= rear; i++) {
        printf("JOB ID: %d\n", q[i].jobID);
        printf("JOB TITLE: %s\n", q[i].title);
    }
}
int main() {

    int ch, z = 0;

    while (z == 0) {

        printf("\n0. To exit\n");
        printf("1. Add to queue\n");
        printf("2. Remove from queue\n");
        printf("3. Display queue\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {

            case 0: {
                printf("Exiting\n");
                z = 1;
                break;
            }

            case 1: {

                int r = isfull(p);

                if (r == 1) {
                    printf("Queue is full\n");
                    break;
                }
                else {
                    addjob(p);
                    break;
                }
            }

            case 2: {

                int k = isempty(p);

                if (k == 1) {
                    printf("Queue is empty\n");
                }
                else {
                    int ele = removejob(p);

                    printf("Element removed:\n");
                    printf("JOB ID: %d\n", p[ele].jobID);
                    printf("JOB TITLE: %s\n", p[ele].title);

                    break;
                }
            }

            case 3: {

                displayq(p);
                break;
            }

            default: {

                printf("Invalid input!!\n");
                break;
            }
        }
    }

    return 0;
}