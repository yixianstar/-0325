#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生结构体
typedef struct Student {
    int id; // 学号
    char name[20]; // 姓名
    float score; // 成绩
    struct Student* next; // 指向下一个学生的指针
} Student;

// 函数声明
void add_student(Student** head, int id, char* name, float score);
void delete_student(Student** head, int id);
void update_student(Student* head, int id, float score);
void display_students(Student* head);

int main() {
    Student* head = NULL; // 初始化链表头
    int choice, id;
    char name[20];
    float score;

    while (1) {
        printf("
            学生成绩管理系统
            ");
            printf("1. 添加学生信息
                ");
                printf("2. 删除学生信息
                    ");
                    printf("3. 修改学生成绩
                        ");
                        printf("4. 显示所有学生信息
                            ");
                            printf("5. 退出
                                ");
                                printf("请输入您的选择：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("请输入学生学号：");
            scanf("%d", &id);
            printf("请输入学生姓名：");
            scanf("%s", name);
            printf("请输入学生成绩：");
            scanf("%f", &score);
            add_student(&head, id, name, score);
            break;
        case 2:
            printf("请输入要删除的学生学号：");
            scanf("%d", &id);
            delete_student(&head, id);
            break;
        case 3:
            printf("请输入要修改的学生学号：");
            scanf("%d", &id);
            printf("请输入新的学生成绩：");
            scanf("%f", &score);
            update_student(head, id, score);
            break;
        case 4:
            display_students(head);
            break;
        case 5:
            exit(0);
        default:
            printf("无效的选择，请重新输入！
                ");
        }
    }

    return 0;
}

// 添加学生信息
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

// 删除学生信息
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
        printf("未找到学号为 %d 的学生信息！
            ", id);
            return;
    }

    prev->next = temp->next;
    free(temp);
}

// 修改学生成绩
void update_student(Student* head, int id, float score) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            temp->score = score;
            return;
        }
        temp = temp->next;
    }
    printf("未找到学号为 %d 的学生信息！
        ", id);
}

// 显示所有学生信息
void display_students(Student* head) {
    Student* temp = head;
    if (temp == NULL) {
        printf("暂无学生信息！
            ");
            return;
    }
    printf("学号\t姓名\t成绩
        ");
        while (temp != NULL) {
            printf("%d\t%s\t%.2f
                ", temp->id, temp->name, temp->score);
                temp = temp->next;
        }
}
