#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义哈希表各个位置的状态标识（解决线性探查删除断链的核心）
#define EMPTY 0
#define EXIST 1
#define DELETED 2

#define N 50  
#define M 60


typedef struct {
    int key;
    int status;
} HashEntry;

void ShowMenu();
int hash_function(int key);
void init_hash_table(HashEntry* table);
void insert_hash(HashEntry* table, int key);
int search_hash(HashEntry* table, int key, int* count);
int delete_hash(HashEntry* table, int key, int* count);
void display_hash_table(HashEntry* table);

void ShowMenu() {
    printf("\n");
    printf("1. 输出建立的哈希表\n");
    printf("2. 查找指定的关键字\n");
    printf("3. 删除指定的关键字\n");
    printf("0. 退出程序\n");
}
int hash_function(int key) {
    return key % M;
}

void init_hash_table(HashEntry* table) {
    for (int i = 0; i < M; i++) {
        table[i].status = EMPTY;
        table[i].key = 0;
    }
}

void insert_hash(HashEntry* table, int key) {
    int hash_val = hash_function(key);
    int index = hash_val;

    while (table[index].status == EXIST) {
        index = (index + 1) % M; // 循环看下一个坑
    }

    table[index].key = key;
    table[index].status = EXIST;
}
int search_hash(HashEntry* table, int key, int* count) {
    int hash_val = hash_function(key);
    int index = hash_val;
    *count = 0;
    while (table[index].status != EMPTY) {
        (*count)++;
        if (table[index].status == EXIST && table[index].key == key) {
            return index;
        }
        index = (index + 1) % M;
        if (index == hash_val) {
            break;
        }
    }
    if (table[index].status == EMPTY) {
        (*count)++; 
    }
    return -1;
}
int delete_hash(HashEntry* table, int key, int* count) {
    int index = search_hash(table, key, count);

    if (index != -1) {
        table[index].status = DELETED;
        return 1; 
    }
    return 0; 
}

void display_hash_table(HashEntry* table) {
    printf("位置\t关键字\t状态\n");
    for (int i = 0; i < M; i++) {
        if (table[i].status == EXIST) {
            printf("[%d]\t%d\t[已占用]\n", i, table[i].key);
        }
        else if (table[i].status == DELETED) {
            printf("[%d]\t%d\t[已删除]\n", i, table[i].key);
        }
        else {
            printf("[%d]\t--\t[空闲]\n", i);
        }
    }
}

int main() {
    srand((unsigned int)time(NULL));

    int A[N];
    int count = 0;
    while (count < N) {
        int rand_num = rand() % (1000 - 10 + 1) + 10;
        int is_duplicate = 0;
        for (int i = 0; i < count; i++) {
            if (A[i] == rand_num) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            A[count] = rand_num;
            count++;
        }
    }
    printf("【成功生成 %d 个互不相同的原始关键字】:\n", N);
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    HashEntry my_hash_table[M];
    init_hash_table(my_hash_table);
    for (int i = 0; i < N; i++) {
        insert_hash(my_hash_table, A[i]);
    }
    printf("\n哈希表已成功建立！（哈希函数: key %% %d，采用线性探查法解决冲突）\n", M);

    int choice;
    int target, op_count, result;

    while (1) {
        ShowMenu();
        printf("请输入您的选择 (0-3): ");
        if (scanf("%d", &choice) != 1) {
            printf("\n 输入非法！请输入数字。\n");
            while (getchar() != '\n'); 
            system("pause");
            continue;
        }

        switch (choice) {
        case 1:
            display_hash_table(my_hash_table);
            system("pause");
            break;

        case 2:
            printf("请输入要查找的整数关键字: ");
            scanf("%d", &target);
            result = search_hash(my_hash_table, target, &op_count);
            if (result != -1) {
                printf("【结论】: 查找成功！关键字 %d 存在于哈希表第 [%d] 号位置。\n", target, result);
            }
            else {
                printf("【结论】: 查找失败！哈希表中不存在关键字 %d。\n", target);
            }
            printf("【操作次数】: 本次查找共进行了 %d 次探查。\n", op_count);
            system("pause");
            break;

        case 3:
            printf("请输入要删除的整数关键字: ");
            scanf("%d", &target);
            result = delete_hash(my_hash_table, target, &op_count);
            if (result == 1) {
                printf("【结论】: 删除成功！关键字 %d 已被安全移除。\n", target);
            }
            else {
                printf("【结论】: 删除失败！未在哈希表中找到关键字 %d。\n", target);
            }
            printf("【操作次数】: 本次删除操作共定位/探查了 %d 次。\n", op_count);
            system("pause");
            break;

        case 0:
            printf("退出程序。\n");
            return 0;

        default:
            printf("\n 输入非法！请输入0-3之间的数字。\n");
            system("pause");
            break;
        }
    }
}