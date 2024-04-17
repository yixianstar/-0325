#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ѧ���ṹ��
typedef struct Student {
    int id; // ѧ��
    char name[20]; // ����
    float score; // �ɼ�
    struct Student* next; // ָ����һ��ѧ����ָ��
} Student;

// ��������
void add_student(Student** head, int id, char* name, float score);
void delete_student(Student** head, int id);
void update_student(Student* head, int id, float score);
void display_students(Student* head);

int main() {
    Student* head = NULL; // ��ʼ������ͷ
    int choice, id;
    char name[20];
    float score;

    while (1) {
        printf("
            ѧ���ɼ�����ϵͳ
            ");
            printf("1. ���ѧ����Ϣ
                ");
                printf("2. ɾ��ѧ����Ϣ
                    ");
                    printf("3. �޸�ѧ���ɼ�
                        ");
                        printf("4. ��ʾ����ѧ����Ϣ
                            ");
                            printf("5. �˳�
                                ");
                                printf("����������ѡ��");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("������ѧ��ѧ�ţ�");
            scanf("%d", &id);
            printf("������ѧ��������");
            scanf("%s", name);
            printf("������ѧ���ɼ���");
            scanf("%f", &score);
            add_student(&head, id, name, score);
            break;
        case 2:
            printf("������Ҫɾ����ѧ��ѧ�ţ�");
            scanf("%d", &id);
            delete_student(&head, id);
            break;
        case 3:
            printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
            scanf("%d", &id);
            printf("�������µ�ѧ���ɼ���");
            scanf("%f", &score);
            update_student(head, id, score);
            break;
        case 4:
            display_students(head);
            break;
        case 5:
            exit(0);
        default:
            printf("��Ч��ѡ�����������룡
                ");
        }
    }

    return 0;
}

// ���ѧ����Ϣ
void add_student(Student** head, int id, char* name, float score) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    new_student->id = id;
    strcpy(new_student->name, name);
    new_student->score = score;
    new_student->next = NULL;

    if (*head == NULL) {
        *head = new_student;
    }
    else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_student;
    }
}

// ɾ��ѧ����Ϣ
void delete_student(Student** head, int id) {
    Student* temp = *head, * prev;

    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("δ�ҵ�ѧ��Ϊ %d ��ѧ����Ϣ��
            ", id);
            return;
    }

    prev->next = temp->next;
    free(temp);
}

// �޸�ѧ���ɼ�
void update_student(Student* head, int id, float score) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            temp->score = score;
            return;
        }
        temp = temp->next;
    }
    printf("δ�ҵ�ѧ��Ϊ %d ��ѧ����Ϣ��
        ", id);
}

// ��ʾ����ѧ����Ϣ
void display_students(Student* head) {
    Student* temp = head;
    if (temp == NULL) {
        printf("����ѧ����Ϣ��
            ");
            return;
    }
    printf("ѧ��\t����\t�ɼ�
        ");
        while (temp != NULL) {
            printf("%d\t%s\t%.2f
                ", temp->id, temp->name, temp->score);
                temp = temp->next;
        }
}
